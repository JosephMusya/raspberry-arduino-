import serial.tools.list_ports
import asyncio
import time
import sys

import random as r
#com_port = '/dev/ttyACM0'
com_port = 'COM18'
baudrate = 4800
print("System Initializing...")
time.sleep(3)
def connect(com_port):
    print("Connecting...")
    connected_devices = len(com_port)
    for i in range(0,connected_devices):
        port = str(com_port[i]).upper()
        if 'USB-SERIAL' in port:
            port_number = port.split(' ')[0]
            try:
                ser = serial.Serial(port_number,baudrate)
                ser.flush()
                print(f"Connected to {port_number}")
                return ser
            except:
                print(f"Error Opening {com_port}"),
                print(" Check whether the Port is busy")
        print(f"Skipped {port}")
async def readArduino():
    return ser.read().decode()

async  def writeArduino(data):
    cmd = str(data)
    cmd = cmd+'\r'   
    ser.write(cmd.encode())
async def pick():
    for i in range(0,5):
        print("Picking...")
        await asyncio.sleep(1)
        
serial_comm = lambda ports: connect(ports)
ser = serial_comm(serial.tools.list_ports.comports())

async def main():    
    while True:
        try:
            await asyncio.create_task(writeArduino(data='ONLINE'))
            res = await asyncio.create_task(readArduino())
            print(res)
        
            if res == '1':
                await asyncio.create_task(pick())
        except:
            await asyncio.create_task(writeArduino(data='OFFLINE'))
            ser.close()
            
if __name__ == '__main__':
    print("Starting...")
    time.sleep(2)
    asyncio.run(main())