# SPI-Minibot
For SPI communication between Pi and Arduino (should support up to 4 devices) with new PCB design

HOW TO RUN:
You type into terminal
1. cd SPI-Minibot
2. python -c 'import SPI_test; SPI_test.claw()'

NOTE: change .claw() function to whatever function you want to run
(ex. shoulder(), left(),right(),fwd(),back(),armL() [stepper], armR()[also stepper]

SPI_1.ino refers to top arduino (Closest to the raspberry pi)
SPI_A2.ino referes to bottom arduino (closest to battery)

When loading Arduino (.ino) programs:
Connect USB to serial (USB to jumper cables) and run SPI_1.ino on the top arduino
and then connect the cable to the bottom arduino and run SPI_A2.ino on the bottom one. 


When cloning this Repo (If not already loaded on the Pi):
1. Make sure you have SPI enabled (easiest way is through the GUI in NOOBS so you can just go to configuration and enable)
      Otherwise on terminal do ifconfig and select the option for serial (I think option 6, will verify later)
2. Make sure you have SCL,SDA,CE0, and CE1 wires all connected
