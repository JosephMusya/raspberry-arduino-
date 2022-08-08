#import serial
import serial.tools.list_ports
import time
BAUDRATE = 4800
def connect(com_port):
    print("Connecting...")
    connected_devices = len(com_port)
    for i in range(0,connected_devices):
        port = str(com_port[i]).upper()
        if 'USB-SERIAL' in port:
            port_number = port.split(' ')[0]
            try:
                ser = serial.Serial(port_number,BAUDRATE)
                ser.flush()
                print(f"Connected to {port_number}")
                return ser
            except:
                print(f"Error Opening {com_port}"),
                print(" Check whether the Port is busy")
        print(f"Skipped {port}")
serial_comm = lambda ports: connect(ports)
ser = serial_comm(serial.tools.list_ports.comports())