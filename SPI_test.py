import binascii
import spidev
import time
import RPi.GPIO as GPIO




spi = spidev.SpiDev()
device = 0
bus = 0
pin = 19

GPIO.setmode(GPIO.BCM) #use GPIO pins
GPIO.setup(pin,GPIO.OUT) #test if general GPIO functionality can work
#spi.no_cs = True #disable to use CS as normal GPIO
#spi.
spi.open(device,bus)
spi.mode = 0
spi.max_speed_hz = 115200

list = 97
hex = "c".encode("hex")
hex2 = ord('F')
#a = binascii.a2b_base64("c")
#b = binascii.hexlify(a)

#print b
a = type(hex2)
#list = [hex]

print hex
print a
try:
  while True:
#    GPIO.output(pin,GPIO.LOW)
   # resp = spi.readbytes(2)
#    tx = spi.writebytes([hex2])
    tx = spi.writebytes([hex2])
#    print('Trasmitted:'.format(binascii.hexlify(bytearray(tx))))
   # xfer = spi.xfer2(list)
   # print('Received: 0x(0)'.format(binascii.hexlify(bytearray(xfer))))
    time.sleep(10)
    rx = spi.readbytes(2)
    print('Read: 0x(0)'.format(binascii.hexlify(bytearray(rx))))
       
  
    GPIO.output(pin, GPIO.HIGH)
finally:
  spi.close()
  GPIO.cleanup()


 
def main():
  
