import serial
import time
#com_port = '/dev/ttyACM0'
com_port = 'COM18'
baudrate = 9600
if __name__ == '__main__':
    try:
        ser = serial.Serial(com_port,baudrate,timeout=5)
        ser.flush()
        print("Connected to com port ".format(com_port))
    except:
        print("Error opening the Port!")
    while True:
        i = input("CMD ").strip()
        if i.lower() == 'kill':
            print("Exit...")
            ser.close()
            break
        ser.write(i.encode())
        time.sleep(.05)
        feedback = ser.readline().decode('ascii')
    
