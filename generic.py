import serial
import asyncio
import time
import sys

import random as r
#com_port = '/dev/ttyACM0'
com_port = 'COM18'
baudrate = 4800

def connect(com_port,baudrate):
    try:
        ser = serial.Serial(com_port,baudrate)
        ser.flush()
        print(f"Connected to {com_port}")
        return ser
    except:
        print(f"Error Opening the {com_port}"),
        print(" Check whether the Port is busy or you entered the correct port number")
async def readArduino():
    return ser.read().decode()

async  def writeArduino():
    i = input("CMD: ")
    cmd = i+'\r'
    ser.write(cmd.encode())
    
ser = connect(com_port,baudrate)
async def main():
    while True:
        val = r.randint(0,10)
        print(val)
        if val >= 7:
            task1 = asyncio.create_task(writeArduino())        
            task2 = asyncio.create_task(readArduino()) 
            
            feedback = await task2        
            print(feedback)      
            print("Completed task...")
            await asyncio.sleep(1)

if __name__ == '__main__':
    asyncio.run(main())