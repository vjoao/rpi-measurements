import sys
import serial

SERIAL_PORT = '/dev/ttyACM0'
SERIAL_RATE = 115200

def main():
    f = open(str(sys.argv[1]) + '.csv', 'w+')
    ser = serial.Serial(SERIAL_PORT, SERIAL_RATE)
    ser.flush()
    while True:
        reading = ser.readline().decode('utf-8')
        print(reading)
        if reading[:3] == 'end':
            f.close()
            ser.flush()
            exit()
        f.write(reading)
if __name__ == "__main__":
    main()
