#include "../include/utils.hpp"

int main() {
  // Declare and initialize parameters
  int numFloors, maxPassengersPerTrip, elevatorMovementTimeSeconds, passengerExitWaitSeconds;
  float simulationDurationMinutes;
  int option = 0;
  do {
    print_menu();
    option = get_menu_option();
    switch(option) {
      case 1:
        // Input values
        std::cout << "Enter the number of floors: ";
        std::cin >> numFloors;
        std::cout << "Enter the maximum passengers per trip: ";
        std::cin >> maxPassengersPerTrip;
        std::cout << "Enter the simulation duration in minutes: ";
        std::cin >> simulationDurationMinutes;
        std::cout << "Enter the elevator movement time between floors in seconds: ";
        std::cin >> elevatorMovementTimeSeconds;
        std::cout << "Enter the passenger exit wait time in seconds: ";
        std::cin >> passengerExitWaitSeconds;

        std::cout << "Initializing elevator system...\n";
        std::cout << "Number of floors: " << numFloors << "\n";
        std::cout << "Maximum passengers per trip: " << maxPassengersPerTrip << "\n";
        std::cout << "Simulation duration: " << simulationDurationMinutes << " minutes\n";
        std::cout << "Elevator movement time between floors: " << elevatorMovementTimeSeconds << " seconds\n";
        std::cout << "Passenger exit wait time: " << passengerExitWaitSeconds << " seconds\n";
        std::cout << "Simulating passenger calls...\n";

        simulate_elevator_system(numFloors, simulationDurationMinutes, elevatorMovementTimeSeconds, passengerExitWaitSeconds);
        std::cout << "\nSimulation completed.\n\n";
        break;
      case 2:
        std::cout << "Exiting Elevator Simulation...\n";
        return 0;
      default:
        std::cout << "Invalid option. Please try again.\n";
    }
  } while(option != 2);

  return 0;
}
