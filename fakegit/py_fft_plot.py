#fft and serial and graph

import serial
import struct
import time
import numpy as np
import matplotlib.pyplot as plt

# Configure serial port
serial_port = serial.Serial('COM3', 115200)  # Replace 'COMX' with the actual serial port
time.sleep(2)  # Allow time for the serial connection to stabilize
fs = 16000000/(4*260.95)  # Sampling frequency (Hz)


def do_fft(signal):
    # Generate a sample signal (replace this with your ADC data) #use receive_data function
    #t = np.arange(0, 1, 1/fs)  # Time vector
    #signal_freq = 50  # Signal frequency (Hz)
    #signal = np.sin(2 * np.pi * signal_freq * t)
    
    duration = 3.832e-3  # seconds (time for one buffer to fill)
    # Create a time vector corresponding to the duration and sampling frequency
    time = np.linspace(0, duration, len(signal))
    # Plot the signal
    plt.figure(figsize=(10, 5))
    plt.plot(time, signal)
    plt.title('Signal vs Time')
    plt.xlabel('Time (s)')
    plt.ylabel('Amplitude')
    plt.grid(True)
    plt.show()

    # Perform FFT
    fft_result = np.fft.fft(signal)
    fft_freq = np.fft.fftfreq(len(signal), d=1/fs)

    # Plot the original signal and its FFT
    plt.figure(figsize=(12, 6))

    plt.subplot(2, 1, 1)
    plt.plot(time, signal)
    plt.title('Original Signal')
    plt.xlabel('Time (s)')
    plt.ylabel('Amplitude')

    plt.subplot(2, 1, 2)
    plt.plot(fft_freq, np.abs(fft_result))
    plt.title('FFT Result')
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('Amplitude')

    plt.tight_layout()
    plt.show()
    return fft_freq


if __name__ == "__main__":
    try:
        # Example: Sending data to STM32
        #send_data(b"Hello from Python!\n")

        # Example: Receiving data from STM32
        #received_data = receive_data(2000)
        #print(f"Received data: {received_data.decode('utf-8')}")
        data_buffer=serial_port.read(1024*2)
        uint16_array = struct.unpack('1024H', data_buffer)
        print("FULL_buff received")
        freq=do_fft(uint16_array)
        print("Frequency:" + freq)

    except Exception as e:
        print(f"Error: {e}")

    finally:
        serial_port.close()