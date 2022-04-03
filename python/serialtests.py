import serial
import time

starttime = time.time()

serialcomm = serial.Serial('COM3', 9600)
serialcomm.timeout = 1

while True:
    print(serialcomm.readline().decode('ascii'))
    if time.time() - starttime > 15:
        break
serialcomm.close()