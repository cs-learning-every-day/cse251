#include <stdio.h>
#include <stdlib.h>

#include "ElevatorLib.h"

/*
 * Name :        <insert name here>
 * Description : Project 2 - The elevator controller
 */

/*
 * Name :        main()
 * Description : Program entry point.
 */
int main()
{
    /*
     * This call starts the elevator system running
     */
    printf("Elevator Startup\n");
    ElevatorStartup();

    /*
     * This loop runs until we shut the elevator system down
     * by closing the window it runs in.
     */
    while(IsElevatorRunning())
    {


    }

    /*
     * This call shuts down the elevator system
     */
    printf("Elevator Shutdown\n");
    ElevatorShutdown();
    return 0;
}


