import serial
import numpy as np
import cv2
import time

# --- Hardware Configuration ---
SERIAL_PORT = "COM3"       # '/dev/ttyUSB0' or '/dev/ttyACM0' on Linux
BAUD_RATE = 115200
SENSOR_WIDTH = 30          # Sensor matrix width (30x30 for ADNS-3080)
SENSOR_HEIGHT = 30
FRAME_SIZE = SENSOR_WIDTH * SENSOR_HEIGHT
UPSCALED_SIZE = (300, 300) # Output window size in pixels

def main():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=2.0)
        time.sleep(2)  # Wait for microcontroller auto-reset
        print(f"Connected to mouse sensor on {SERIAL_PORT}")
    except serial.SerialException as e:
        print(f"Error opening serial port: {e}")
        return

    print("Streaming live mouse sensor feed. Press 'q' to exit.")

    while True:
        # Request a frame from the microcontroller
        ser.write(b'G')

        # Synchronize using the 2-byte frame header (0xAA, 0xBB)
        header = ser.read(2)
        if header != b'\xAA\xBB':
            # Flush input buffer if synchronization is lost
            ser.reset_input_buffer()
            continue

        # Read the raw grayscale pixel bytes
        raw_data = ser.read(FRAME_SIZE)
        if len(raw_data) != FRAME_SIZE:
            continue

        # Convert to 2D NumPy grayscale array
        frame = np.frombuffer(raw_data, dtype=np.uint8).reshape((SENSOR_HEIGHT, SENSOR_WIDTH))

        # Normalize 6-bit sensor data (0-63) to 8-bit display dynamic range (0-255)
        frame_normalized = cv2.normalize(frame, None, alpha=0, beta=255, norm_type=cv2.NORM_MINMAX)

        # Scale up using NEAREST interpolation to inspect pixel grid without blur
        display_frame = cv2.resize(frame_normalized, UPSCALED_SIZE, interpolation=cv2.INTER_NEAREST)

        # Render display
        cv2.imshow("Optical Mouse Sensor Live View", display_frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    ser.close()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()