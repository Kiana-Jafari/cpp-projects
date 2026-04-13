#include <iostream>
#include "Structures.h"
#include "File.h"
#include "Preprocess.h"
#include "Display.h"

int main()
{
    int count{0}; // Variable to keep track of the number of the vehicles
    int option;

    // Declare an array of structures for both vehicles and spots
    std::array<Vehicle, MAX_VEHICLES> vehicles;
    std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS> spots;

    // Garage Menu
    std::cout << R"(
    === Parking Garage Management ===

    Welcome to this parking garage management system.
    What this program is able to do:

    1. Load data from file
    2. Show all parked vehicles
    3. Show available spots
    4. Park a vehicle
    5. Search vehicle by plate
    6. Sort vehicles
    7. Remove a vehicle
    8. Save data to file (Exit)
    
    Feel free to run the program 
    using the test cases in the `test.txt` file!
    )";
    std::cout << "\n";

    // Call the functions based on the user input

    while (true)
    {
        std::cout << "Enter an option: ";
        std::cin >> option;

        if (option == 8)
        break;

        switch (option) 
        {
            case 1:
                ReadFromFile(vehicles, spots, count);
                break;

            case 2:
                DisplayVehicles(vehicles, count);
                break;

            case 3:
                DisplayFreeSpots(spots);
                break;
            
            case 4:
                ParkVehicle(vehicles, spots, count);
                break;

            case 5:
                SearchVehicle(vehicles, count);
                break;

            case 6:
                SortVehicle(vehicles, count);
                break;
            
            case 7:
                ExitVehicle(vehicles, spots, count);
        }
    }

    // Save the data back to the file if the user exits the program
    SaveVehicles(vehicles, count);
}