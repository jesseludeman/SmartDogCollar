# "Smart" Dog Collar
A project created for SIT210 - Embedded Systems Development for Deakin University. A C++ program that directly interfaces with a connected GPS that uses the gpsd program on a Raspberry Pi.

I came up with the idea of a "Smart" dog collar after bringing home another German Shepherd, to track her location in the event that she escapes. Turns out there are plenty of Smart dog collars, and building my own certainly isn't any easier.

The program was originally programmed using Python, however as the program needs to perform as quickly as possible, I decided to move it to C++. It reports how many satellites it's currently talking to, the "fix" mode, latitude, longitude, altitude and speed. Based on my current testing, it's accurate to within approximately 4 metres.

To compile this code on a Raspberry Pi, try: g++ main.cpp -o filename -lgps -lwiringPi
