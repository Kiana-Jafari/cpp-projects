#pragma once

/*  
    LEVELS:

    Motorcycles = 0,
    Cars = 1,
    Trucks = 2
*/

#include <string>
#include <array>
#include <cstddef>

const size_t MAX_VEHICLES{105};
const size_t LEVELS{3};
const size_t MAX_SPOTS{35};

struct ParkingSpot {
    int level;
    int spotNumber;
    bool occupied{false};
};

struct Vehicle {
    std::string licensePlate;
    std::string vehicleType;
    int entryTime;
    int level;
    int spotNumber;
};