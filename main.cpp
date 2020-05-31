#include <iostream>
#include <string>
#include <vector>
#include <gps.h>		// Using the GPS library
#include <wiringPi.h>	// Using the Wiring Pi library
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

using namespace std;

int main()
{
	// Initialize the GPS
	int gps;
	struct gps_data_t gps_data;
	
	// Initialize WiringPi
	wiringPiSetup () ;
	pinMode (0, OUTPUT);
	
	// Set the gps integer value to local host and specify the local port
	gps = gps_open("localhost", "2947", &gps_data);
	(void)gps_stream(&gps_data, WATCH_ENABLE | WATCH_JSON, NULL);
	
	// Continuous loop
	while (true)
	{
		if (gps_waiting(&gps_data, 500)) 
		{
			errno = 0;
			// If no GPS detected, throw the error
			if (gps_read(&gps_data) == -1)
			{
				printf("Read error, exiting\n");
				exit(1);
			}
			else
			{
				// Otherwise, we have a fix
				if (gps_data.set)
				{
					// Turn the LED on
					digitalWrite (0, HIGH) ; delay (500) ;
					printf("\n-------------------- GPS Status --------------------\n");
					printf("Online status:	 		   %10.0f\n", gps_data.online);
					printf("Data status:			   %d\n", gps_data.status);
					printf("Connected satellites:	   %d\n", gps_data.satellites_used);
					printf("Fix mode:		           %d\n", gps_data.fix.mode);
					printf("Time:         			   %10.0f\n", gps_data.fix.time);
					printf("Latitude:     			   %f\n", gps_data.fix.latitude);
					printf("Longitude:    			   %f\n", gps_data.fix.longitude);
					printf("Altitude:				   %f\n", gps_data.fix.altitude);
					printf("Speed:			           %f\n", gps_data.fix.speed);
					printf("Track:			           %f\n", gps_data.fix.track);
					// Turn the LED off
					digitalWrite (0, LOW) ; delay (500) ;
				}	
			}		
		}	
	}
	return gps;
}