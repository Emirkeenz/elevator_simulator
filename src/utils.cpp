#include "../include/utils.hpp"

int simulate_elevator_system(
    int numFloors,
    float simulationDurationMinutes,
    int elevatorMovementTimeSeconds,
    int passengerExitWaitSeconds)
{
    int currentFloor = 1;
    std::queue<int> passengers;

    // Vector to store frequency of calls from each floor
    std::vector<int> floorCalls(numFloors, 0);
    std::vector<int> floorExits(numFloors, 0);
    int amountOfPassengers = 0;

    // Simulate passenger calls
    srand(time(nullptr)); // Seed for random number generation
    float simulationTime = 0;
    while (simulationTime < simulationDurationMinutes * 60)
    {
        int randomFloor = rand() % numFloors + 1;
        floorCalls[randomFloor - 1]++;
        std::cout << "Passenger called elevator from floor " << randomFloor << ".\n";

        // Calculate time needed for elevator movement between floors
        float timeForMovement = elevatorMovementTimeSeconds * abs(randomFloor - currentFloor);
        simulationTime += timeForMovement;

        // Update elevator current floor
        currentFloor = randomFloor;
        while (!passengers.empty())
        {
            int randomFloorExit = rand() % numFloors + 1; // Random floor for exiting elevator
            floorExits[randomFloorExit - 1]++;            // Increment exit count for the destination floor
            passengers.pop();
            std::cout << "Passenger exited elevator at floor " << randomFloorExit << ".\n";
        }

        // Simulate passenger entering elevator
        passengers.push(randomFloor);
    }
    // analyze frequency of calls from each floor
    std::cout << "\nAnalysis:\n";
    std::cout << "Frequency of calls from each floor:\n";
    for (int i = 0; i < numFloors; ++i)
    {
        std::cout << "Floor " << (i + 1) << ": " << floorCalls[i] << " calls\n";
        simulationTime += floorCalls[i] * passengerExitWaitSeconds;
        amountOfPassengers += floorCalls[i];
    }
    std::cout << "Frequency of getting out from elevator from each floor:\n";
    for(int i = 0; i < numFloors; ++i) {
        if(i == 0)
            std::cout << "Floor " << (i + 1) << ": " << floorExits[i] + 1 << " exits\n";
        else
            std::cout << "Floor " << (i + 1) << ": " << floorExits[i] << " exits\n";
        simulationTime += floorExits[i] * passengerExitWaitSeconds;
    }
    std::cout << "Total amount of passengers: " << amountOfPassengers << std::endl;
    std::cout << "Total time needed for all calls: " << simulationTime / 60 << " minutes\n"; // Convert seconds to minutes
    return 0;
}

void print_menu()
{
    std::cout << "Elevator Simulation Menu\n";
    std::cout << "1. Run simulation\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter option: ";
}

short get_menu_option()
{
    short option;
    std::cin >> option;
    return option;
}