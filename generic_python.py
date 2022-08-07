import serial
import asyncio
import time
import sys

import random as r
#com_port = '/dev/ttyACM0'
com_port = 'COM18'
baudrate = 4800
print("System Initializing...")
time.sleep(3)
def connect(com_port,baudrate):
    try:
        ser = serial.Serial(com_port,baudrate)
        ser.flush()
        print(f"Connected to {com_port}")
        return ser
    except:
        print(f"Error Opening {com_port}"),
        print(" Check whether the Port is busy or you entered the correct port number")
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
        
ser = connect(com_port,baudrate)

async def main():
    print("Waiting to start...")
    while True:
        try:
            await asyncio.create_task(writeArduino(data='ONLINE'))
            res = await asyncio.create_task(readArduino())
            print(res)
        
            if res == '1':
                await asyncio.create_task(pick())
        except:
            task = await asyncio.create_task(writeArduino(data='OFFLINE'))
            ser.close()
            
if __name__ == '__main__':
    asyncio.run(main())