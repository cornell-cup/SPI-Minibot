import binascii
import spidev
import time
import RPi.GPIO as GPIO

spi = spidev.SpiDev()
device = 0
bus = 0

GPIO.setmode(GPIO.BCM) #use GPIO pins
GPIO.setup(19,GPIO.OUT) #test if general GPIO functionality can work
#spi.no_cs = True #disable to use CS as normal GPIO
spi.open(0,0)
spi.mode = 0
try:
  while True:
    GPIO.output(19,GPIO.LOW)
    resp = spi..readbytes(2)
    print('Received: 0x(0)'.format(binascii.hexlify(bytearray(resp))))
    time.sleep(1)
    GPIO.output(19, GPIO.HIGH)
finally:
  spi.close()



