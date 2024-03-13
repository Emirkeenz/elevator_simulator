#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Data structures
// class Elevator {
// public:
//   int currentFloor;
//   bool movingUp;
//   queue<int> passengers;

//   Elevator() : currentFloor(1), movingUp(true) {}
// };

// Function to simulate elevator system
int simulateElevatorSystem(int numFloors, int maxPassengersPerTrip, double simulationDurationMinutes, int elevatorMovementTimeSeconds, int passengerExitWaitSeconds) {
  // Elevator elevator;
  int currentFloor = 1;
  bool movingUp = true;
  queue<int> passengers;
  
  // Vector to store frequency of calls from each floor
  vector<int> floorCalls(numFloors, 0);
  vector<int> floorExits(numFloors, 0);
  int amountOfPassengers = 0;
  // Simulate passenger calls
  srand(time(0)); // Seed for random number generation
  double simulationTime = 0;
  while (simulationTime < simulationDurationMinutes * 60) {
    int randomFloor = rand() % numFloors + 1;
    floorCalls[randomFloor - 1]++;
    cout << "Passenger called elevator from floor " << randomFloor << ".\n";

    // Calculate time needed for elevator movement between floors
    double timeForMovement = elevatorMovementTimeSeconds * abs(randomFloor - currentFloor);
    simulationTime += timeForMovement; // Добавляем время движения

    // Update elevator current floor
    // elevator.currentFloor = randomFloor;
    currentFloor = randomFloor;
    
    // Simulate passengers entering and exiting elevator
    while (!passengers.empty()) {
      int randomFloorExit = rand() % numFloors + 1; // Random floor for exiting elevator
      floorExits[randomFloorExit - 1]++; // Increment exit count for the destination floor
      passengers.pop();
      cout << "Passenger exited elevator at floor " << randomFloorExit << ".\n";
    }

    // Simulate passenger entering elevator
    passengers.push(randomFloor);

    // simulationTime += passengerExitWaitSeconds * elevator.passengers.size();
  }

  // Analyze frequency of calls from each floor
  cout << "\nAnalysis:\n";
  cout << "Frequency of calls from each floor:\n";
  for (int i = 0; i < numFloors; ++i) {
    cout << "Floor " << (i + 1) << ": " << floorCalls[i] << " calls\n";
    simulationTime += floorCalls[i]*passengerExitWaitSeconds;
    amountOfPassengers += floorCalls[i];
  }
  cout << "Frequency of getting out from elevator from each floor:\n";
  for (int i = 0; i < numFloors; ++i) {
    if (i == 0)
      cout << "Floor " << (i + 1) << ": " << floorExits[i] + 1 << " exits\n";
    else 
      cout << "Floor " << (i + 1) << ": " << floorExits[i] << " exits\n";
    simulationTime += floorExits[i]*passengerExitWaitSeconds;
  }
  cout << "Total time needed for all calls: " << simulationTime / 60 << " minutes\n"; // Convert seconds to minutes
  cout << "The amount of passengers: " << amountOfPassengers << endl;
  return 0;
}

int main() {
  cout << "Welcome to Elevator Simulation!\n";

  // Declare and initialize parameters
  int numFloors, maxPassengersPerTrip, elevatorMovementTimeSeconds, passengerExitWaitSeconds;
  double simulationDurationMinutes;

  // Input values
  cout << "Enter the number of floors: ";
  cin >> numFloors;
  cout << "Enter the maximum passengers per trip: ";
  cin >> maxPassengersPerTrip;
  cout << "Enter the simulation duration in minutes: ";
  cin >> simulationDurationMinutes;
  cout << "Enter the elevator movement time between floors in seconds: ";
  cin >> elevatorMovementTimeSeconds;
  cout << "Enter the passenger exit wait time in seconds: ";
  cin >> passengerExitWaitSeconds;

  cout << "Initializing elevator system...\n";
  cout << "Number of floors: " << numFloors << "\n";
  cout << "Maximum passengers per trip: " << maxPassengersPerTrip << "\n";
  cout << "Simulation duration: " << simulationDurationMinutes << " minutes\n";
  cout << "Elevator movement time between floors: " << elevatorMovementTimeSeconds << " seconds\n";
  cout << "Passenger exit wait time: " << passengerExitWaitSeconds << " seconds\n";
  cout << "Simulating passenger calls...\n";

  simulateElevatorSystem(numFloors, maxPassengersPerTrip, simulationDurationMinutes, elevatorMovementTimeSeconds, passengerExitWaitSeconds);

  cout << "\nSimulation completed.\n";
  cout << "Thank you for using Elevator Simulation!\n";

  return 0;
}
