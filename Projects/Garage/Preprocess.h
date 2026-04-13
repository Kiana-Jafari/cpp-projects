#pragma once

#include "Structures.h"

void ParkVehicle(std::array<Vehicle, MAX_VEHICLES>&, std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS>&, int&);
void SortVehicle(std::array<Vehicle, MAX_VEHICLES>&, int&);
void ExitVehicle(std::array<Vehicle, MAX_VEHICLES>& vehicles, std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS>& spots, int& count);