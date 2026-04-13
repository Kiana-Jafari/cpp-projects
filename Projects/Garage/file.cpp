#include "Structures.h"
#include <fstream>

void ReadFromFile(std::array<Vehicle, MAX_VEHICLES>&, std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS>&, int&)
{
    // This function reads data from the text file and stores it in the array.
    std::ifstream file("vehicles.txt");

    while (file >> )
}

void SaveVehicles(const std::array<Vehicle, MAX_VEHICLES>&, int&)
{

}