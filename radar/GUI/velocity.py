import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
import serial
import struct
from threading import Thread
import queue
import numpy as np  # For numerical operations

# Serial port configuration
serial_port = '/dev/tty.URT0'
baud_rate = 115200
ser = serial.Serial(serial_port, baud_rate, timeout=1)

# Queue for velocities
velocity_queue = queue.Queue()

def read_serial_data():
    while True:
        if ser.in_waiting > 0:
            data = ser.read(4)  # Read 4 bytes from the serial port
            if len(data) == 4:
                value = struct.unpack('<f', data)[0]  # Unpack the data
                velocity_queue.put(value)  # Put the value in the queue

# Initial setup for Tkinter GUI
root = tk.Tk()
root.geometry("1000x800")
root.title("RADAR GUI")

graph_frame = tk.Frame(root)
graph_frame.pack(expand=True, fill='both')

fig = plt.figure(figsize=(5, 4), dpi=100)
ax = fig.add_subplot(111)
ax.set_title("Velocity Visualization")

canvas = FigureCanvasTkAgg(fig, master=graph_frame)
canvas.draw()
canvas_widget = canvas.get_tk_widget()
canvas_widget.pack(expand=True, fill='both')

# Store velocities (initialize empty)
received_velocities = []

def updateGraph():
    global received_velocities
    ax.clear()
    ax.set_title("Velocity Visualization")
    ax.set_xlabel("Time (s)")
    ax.set_ylabel("Velocity (units/s)")
    ax.set_ylim(0, 1.2)  # Adjust this based on expected velocity range
    
    # Using numpy to create an array of time steps
    time_steps = np.arange(len(received_velocities))
    
    # Plot using a bar graph
    ax.bar(time_steps, received_velocities, color='blue')
    
    # Display the most recent velocity in the top right corner
    if received_velocities:
        latest_velocity = received_velocities[-1]
        ax.text(0.95, 0.95, f"Current Velocity: {latest_velocity:.2f} units/s", 
                verticalalignment='top', horizontalalignment='right', 
                transform=ax.transAxes, fontsize=10, bbox=dict(boxstyle="round", facecolor="wheat", alpha=0.5))
    
    canvas.draw_idle()

def update_loop():
    if not velocity_queue.empty():
        velocity = velocity_queue.get()  # get the last velocity value from the queue
        received_velocities.append(velocity)  # add to the velocities list
        
        # Limit the number of velocities and time steps displayed for readability
        if len(received_velocities) > 20:  # Adjust this number based on your preference
            received_velocities.pop(0)  # Remove the oldest velocity to keep the display from crowding
        
        updateGraph()
    
    root.after(500, update_loop)  # Check the queue every half second for a new velocity

serial_thread = Thread(target=read_serial_data, daemon=True)
serial_thread.start()

root.after(500, update_loop)  # Start the update loop with a delay of 500 ms (half-second)
root.mainloop()

ser.close()  # Close the serial connection when the GUI is closed
