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
