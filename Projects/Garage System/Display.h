#pragma once

#include "Structures.h"

void DisplayVehicles(const std::array<Vehicle, MAX_VEHICLES>&, int&);
void DisplayFreeSpots(const std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS>&);
void SearchVehicle(const std::array<Vehicle, MAX_VEHICLES>&, int&);