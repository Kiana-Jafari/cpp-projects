#pragma once
#include "Structures.h"

void ReadFromFile(std::array<Vehicle, MAX_VEHICLES>&, std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS>&, int&);
void SaveVehicles(const std::array<Vehicle, MAX_VEHICLES>&, int&);