#include <stdio.h>
#include <stdlib.h>

#include "RobotLib.h"

void OnMachineRequest(int machine);

/*
 * Name :        <insert name here>
 * Description : Robot scheduler program
 */

/*
 * Name :        main()
 * Description : Program entry point.
 */
int main()
{
    /*
     * This call starts the system running
     */
    printf("Robot System Startup\n");
    SimulatorStartup();

    SetMachineRequestHandler(OnMachineRequest);

    /*
     * This loop runs until we shut the simulator down
     * by closing the window it runs in.
     */
    while(IsSimulatorRunning())
    {



    }

    /*
     * This call shuts down the elevator system
     */
    printf("Robot System Shutdown\n");
    SimulatorShutdown();
    return 0;
}

void OnMachineRequest(int machine)
{
    printf("Robot request from machine %d\n", machine);
    RobotGoTo(machine);
}


