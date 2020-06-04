# "Smart" Dog Collar
A project created for SIT210 - Embedded Systems Development for Deakin University. A C++ program that directly interfaces with a connected GPS that uses the gpsd program on a Raspberry Pi Linux system. It's designed to simulate a GPS device attached to a dog collar so that it can track the dog's location in case it gets lost.

I came up with the idea of a "Smart" dog collar after bringing home another German Shepherd, to track her location in the event that she escapes. Turns out there are plenty of Smart dog collars, and building my own certainly isn't any easier.

The program was originally programmed using Python, however as the program needs to perform as quickly as possible, I decided to move it to C++. It reports how many satellites it's currently talking to, the "fix" mode, latitude, longitude, altitude and speed. Based on my current testing, it's accurate to within approximately 4 metres.

The program requires the libgps and wiringpi libraries to compile successfully. To compile this code on a Raspberry Pi, issue the following command in a terminal window: g++ main.cpp -o dogcollar -lgps -lwiringPi
