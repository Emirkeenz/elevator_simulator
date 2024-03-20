#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <random>

int simulate_elevator_system(
    int numFloors,
    float simulationDurationMinutes,
    int elevatorMovementTimeSeconds,
    int passengerExitWaitSeconds);

void print_menu();

short get_menu_option();

#endif