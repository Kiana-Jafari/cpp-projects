#include <fstream>
#include "Structures.h"

void ReadFromFile(std::array<Vehicle, MAX_VEHICLES>& vehicles, std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS>& spots, int& count)
{
    // This function reads data from the text file and stores it in the array.
    std::ifstream read_file("vehicles.txt");

    while (
        read_file 
        >> vehicles.at(count).licensePlate 
        >> vehicles.at(count).vehicleType 
        >> vehicles.at(count).entryTime 
        >> vehicles.at(count).level 
        >> vehicles.at(count).spotNumber
    )

    {
        spots
        .at(vehicles.at(count).level)
        .at(vehicles.at(count).spotNumber)
        .occupied = true;
        
        count ++;
    }

    read_file.close();
}

void SaveVehicles(const std::array<Vehicle, MAX_VEHICLES>& vehicles, int& count)
{
    // This function saves the vehicles information back to the text file.
    std::ofstream write_file("vehicles.txt");

    for (size_t i{0}; i < count; ++i)
    
    write_file 
    << vehicles.at(i).licensePlate << " " 
    << vehicles.at(i).vehicleType << " "
    << vehicles.at(i).entryTime << " "
    << vehicles.at(i).level << " "
    << vehicles.at(i).spotNumber << "\n";

    write_file.close(); // Close the file
}