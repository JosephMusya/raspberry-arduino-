import serial
import time
import sys
#com_port = '/dev/ttyACM0'
com_port = 'COM18'
baudrate = 4800
if __name__ == '__main__':
    try:
        ser = serial.Serial(com_port,baudrate,timeout=5)
        ser.flush()
        print("Connected to com port ".format(com_port))
    except:
        print("Error opening the Port!")
        sys.exit()
    while True:
        i = input("CMD: ").strip()
        if i.lower() == 'kill':
            print("Exit...")
            ser.close()
            sys.exit()
        else:
            cmd = i+'\r'
            print("Sending data...")
            ser.write(cmd.encode())
            feedback = ser.read().decode().strip('')
            print("Received => ",feedback)
#-----------------------------------------------#        
        # print("Sending data...")
        # ser.write('ON\r'.encode())
        # recv = ser.read().decode()
        # time.sleep(1)
        # ser.write('OFF\r'.encode())
        # time.sleep(1)
            
        
