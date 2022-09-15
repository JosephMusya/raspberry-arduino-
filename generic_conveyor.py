import serial.tools.list_ports
import asyncio
import time
import sys

#com_port = '/dev/ttyACM0'
baudrate = 9600
print("System Initializing...")
time.sleep(3)
def connect(com_port):
    print("Connecting...")
    connected_devices = len(com_port)
    for i in range(0,connected_devices):
        port = str(com_port[i]).upper()
        if 'USB SERIAL' in port:
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
    print("Reading...")
    # ser.timeout = 5
    data = ser.read().decode()
    return data

async  def writeArduino(data):
    cmd = str(data)
    cmd = cmd+'\r'   
    ser.write(cmd.encode())
    print("Data written succesfully...")
async def pick():
    for i in range(0,5):
        print("Picking...")
        await asyncio.sleep(1)
    await asyncio.create_task(writeArduino('DONE'))
    
    
                
async def main():   
    ''' 
    usage:
        >>> if ser: asyncio.run(main())
        
        This is the main function:
        Starts by connecting to the conveyor by sending the datapacket=ONLINE
        if there was a connection
        If the connection is open, python reads the data coming from the conveyor
        When python gets a 1, it interprets that there was an object on the target 
        pos of the conveyor and initiates the sorting process
        
        During this time, the conveyor status is 1 and is only triggered to send
        another sorting action when the status changes from a 1 to 0
        
        Incase an error occurs in the python, an OFFLINE command is sent to the conveyor
        which stops the conveyor
    ''' 
    
    if ser.isOpen(): await asyncio.create_task(writeArduino(data='ONLINE'))    
    while True:  
        try:
            if ser.isOpen():
                try:
                    res = await asyncio.create_task(readArduino())
                    print(f"From Conveyor => {res}")
                
                    if res == '1':
                        await asyncio.create_task(pick())  
                except:
                    await asyncio.create_task(writeArduino('OFFLINE'))
                    ser.close()
        except Exception:
            print("Broken Communication to the conveyor")
            sys.exit()
if __name__ == '__main__':
    print("Starting...")
    serial_comm = lambda ports: connect(ports)
    ser = serial_comm(serial.tools.list_ports.comports())   
    time.sleep(3)
    if ser: asyncio.run(main())
    print("Not communication to the identified ports!")