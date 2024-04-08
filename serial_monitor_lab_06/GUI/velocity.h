import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
import serial
import struct
from threading import Thread
import queue

# Serial port configuration
serial_port = '/dev/tty.URT0'
baud_rate = 115200
ser = serial.Serial(serial_port, baud_rate, timeout=1)

# queue for velocities
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

# store velocities (initialize empty)
received_velocities = []
time_steps = []  # This will hold our time steps

def updateGraph():
    global received_velocities
    ax.clear()
    ax.set_title("Velocity Visualization")
    ax.set_xlabel("Time (s)")
    ax.set_ylabel("Velocity (units/s)")
    ax.set_ylim(0, 1.2)  # Adjust this based on expected velocity range

    if received_velocities:
        ax.plot(time_steps, received_velocities, marker='o', linestyle='-')
    canvas.draw_idle()

def update_loop():
    global current_index
    if not velocity_queue.empty():
        velocity = velocity_queue.get()  # get last velocity value from the queue
        preset_velocities.append(velocity)  # add to the velocities list
        updateGraph()
        current_index += 1
    root.after(50, update_loop)  # Check the queue

serial_thread = Thread(target=read_serial_data, daemon=True)
serial_thread.start()

root.after(50, update_loop)
root.mainloop()

ser.close()

