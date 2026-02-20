// LEVELS:
// Motorcycles = 0,
// Cars = 1,
// Trucks = 2

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <fstream>

#define MAX_VEHICLES 105
#define LEVELS 3
#define MAX_SPOTS 35

using namespace std;

struct ParkingSpot {
    int level;
    int spotNumber;
    bool occupied = false;
};

struct Vehicle {
    string licensePlate;
    string vehicleType;
    int entryTime;
    int level;
    int spotNumber;
};

// Prototype the functions
void ReadFromFile(Vehicle vehicles[], ParkingSpot spots[LEVELS][MAX_SPOTS], int& count);
void DisplayVehicles(Vehicle vehicles[], int& count);
void FreeSpots(ParkingSpot spots[LEVELS][MAX_SPOTS]);
void ParkVehicle(Vehicle vehicles[], ParkingSpot spots[LEVELS][MAX_SPOTS], int& count);
void SearchVehicle(Vehicle vehicles[], int& count);
void SortVehicle(Vehicle vehicles[], int& count);
void VehicleFee(Vehicle vehicles[], ParkingSpot spots[LEVELS][MAX_SPOTS], int& count);
void SaveVehicles(Vehicle vehicles[], int& count);
int mapVehicleType(string type);
int mapFeeVehicle(string type);

int main()
{
    int count = 0; // Variable to keep track of the number of vehicles
    int option;

    // Declare an array of structures for both vehicles and spots
    Vehicle vehicles[MAX_VEHICLES];
    ParkingSpot spots[LEVELS][MAX_SPOTS];

    // Garage Menu
    cout << R"(
    === Parking Garage Management ===
    1. Load data from file
    2. Show all parked vehicles
    3. Show available spots
    4. Park a vehicle
    5. Search vehicle by plate
    6. Sort vehicles
    7. Remove a vehicle
    8. Save data to file (Exit)
    )";
    cout << "\n";

    // Call the functions based on the user input
    while (true)
    {
        cout << "Enter an option: ";
        cin >> option;

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
                FreeSpots(spots);
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
                VehicleFee(vehicles, spots, count);

            default:
                cout << "Invalid option\n";
        }
    }

    // Save the data back to the file if the user exits the program
    SaveVehicles(vehicles, count);
   
}

void ReadFromFile(Vehicle vehicles[], ParkingSpot spots[LEVELS][MAX_SPOTS], int& count)
{
    // This function reads the vehicles information from the text file and stores it in the arrays.
    ifstream read_file("vehicles.txt");

    while (read_file >> vehicles[count].licensePlate >> vehicles[count].vehicleType >> vehicles[count].entryTime >> vehicles[count].level >> vehicles[count].spotNumber)
    {
        // Mark the spot associated with this vehicle as true
        spots[vehicles[count].level][vehicles[count].spotNumber].occupied = true;

        // Add one vehicle
        count ++;

    }

    cout << "Vehicles loaded correctly" << endl;
    cout << "Spots marked as occupied" << endl;

    read_file.close();
}

void DisplayVehicles(Vehicle vehicles[], int& count)
{
    // This function displays all parked vehicles.
    if (count == 0)
    {
        cout << "The garage is empty. " << endl;
        return ;
    }

    cout << "license plate | type | entry time | level | spot number " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << vehicles[i].licensePlate << " " << vehicles[i].vehicleType << " " << vehicles[i].entryTime << " " << vehicles[i].level << " " << vehicles[i].spotNumber << endl;
    }
}

void FreeSpots(ParkingSpot spots[LEVELS][MAX_SPOTS])
{
    // This function displays all free spots per level (vehicle type).
    cout << "level | spot number" << endl;
    for (int i = 0; i < LEVELS; i++)
    {
        cout << "Free Spots per level " << i << endl;

        for (int j = 0; j < MAX_SPOTS; j++)
        {
            if (spots[i][j].occupied == false) // Free spots
            {
                cout << i << "-" << j << endl;
            }

            else
            {
                cout << "Full" << endl;
            }
        }
    }
}

void ParkVehicle(Vehicle vehicles[], ParkingSpot spots[LEVELS][MAX_SPOTS], int& count)
{
    // This function gets the license plate of a vehicle and parks it in the first compatible spot.
    if (count == MAX_VEHICLES)
    {
        cout << "Garage is full. " << endl; // edge case
        return ;
    }

    // Get the new vehicle info
    string plate, type;
    int time, level;

    cout << "Enter the plate and type of the vehicle: ";
    cin >> plate >> type;

    // Check for duplicates
    for (int i = 0; i < count; i++)
    {
        if (vehicles[i].licensePlate == plate)
        {
            cout << "Vehicle already exists. " << endl;
            return ;
        }
    }

    // Otherwise, add the vehicle to the array and mark spot as true
    cout << "Enter the entry time: ";
    cin >> time;

    level = mapVehicleType(type); // Get the level of the vehicle based on its type

    for (int i = 0; i < MAX_SPOTS; i++)
    {
        if (spots[level][i].occupied == false)
        {
            spots[level][i].occupied = true; // Park the vehicle here

            vehicles[count].licensePlate = plate;
            vehicles[count].vehicleType = type;
            vehicles[count].entryTime = time;
            vehicles[count].level = level;
            vehicles[count].spotNumber = i;

            count ++;

            break; // Stop when the spot is found
        }
    }
}

void SearchVehicle(Vehicle vehicles[], int& count)
{
    // This function gets the license plate of a vehicle and prints its information.
    string plate;
    bool isFound = false;

    cout << "Enter the vehicle plate: ";
    cin >> plate;

    for (int i = 0; i < count; i++)
    {
        if (vehicles[i].licensePlate == plate)
        {
            isFound = true;
            cout << "type | entry time | level | spot number " << endl;
            cout << vehicles[i].vehicleType << " " << vehicles[i].entryTime << " " << vehicles[i].level << " " << vehicles[i].spotNumber << endl;
            break;
        }
    }

    // Vehicle not found
    if (!isFound)
    cout << "Vehicle not found. " << endl;
}

void SortVehicle(Vehicle vehicles[], int& count)
{
    // This function sorts the vehicles using Bubble Sort and based on the entry time (earliest first).
    bool swapped;

    for (int i = 0; i < (count - 1); i++)
    {
        swapped = false;

        for (int j = 0; j < (count - 1 - i); j++)
        {
            if (vehicles[j].entryTime > vehicles[j + 1].entryTime)
            {
                swapped = true;

                swap(vehicles[j].licensePlate, vehicles[j + 1].licensePlate);
                swap(vehicles[j].vehicleType, vehicles[j + 1].vehicleType);
                swap(vehicles[j].entryTime, vehicles[j + 1].entryTime);
                swap(vehicles[j].level, vehicles[j + 1].level);
                swap(vehicles[j].spotNumber, vehicles[j + 1].spotNumber);
            }
        }

        if (!swapped)
        break;
    }
}

void VehicleFee(Vehicle vehicles[], ParkingSpot spots[LEVELS][MAX_SPOTS], int& count)
{
    // This function gets the license plate of a vehicle and the exit time and calculates the fee (exits).
    string plate;
    int exitTime;
    float fee = 0.0;

    cout << "Enter the license plate: ";
    cin >> plate;

    cout << "Enter the exit time: ";
    cin >> exitTime;

    for (int i = 0; i < count; i++)
    {
        if (vehicles[i].licensePlate == plate)
        {
            // Calculate the fee based on the time duration and type of the vehicle
            string type = vehicles[i].vehicleType;
            int spotNumber = vehicles[i].spotNumber;
            int level = vehicles[i].level;

            int rate = mapFeeVehicle(type); // Get the rate based on the vehicle type

            spots[level][spotNumber].occupied = false; // Free the spot

            int duration = exitTime - vehicles[i].entryTime;
            int hours = ceil(duration / 60.0);
            fee = hours * rate;

            // Shift the elements to the left
            count --;

            for (int j = i; j < count; j++)
            {
                vehicles[j].licensePlate = vehicles[j + 1].licensePlate;
                vehicles[j].vehicleType = vehicles[j + 1].vehicleType;
                vehicles[j].entryTime = vehicles[j + 1].entryTime;
                vehicles[j].level = vehicles[j + 1].level;
                vehicles[j].spotNumber = vehicles[j + 1].spotNumber;
            }

            break; // Stop once the vehicle has been removed
        }
    }

    cout << "Spot freed" << endl;
    cout << "Fee: $" << fee << endl;
}

void SaveVehicles(Vehicle vehicles[], int& count)
{
    // This function writes and saves the data back to the text file.
    ofstream write_file("vehicles.txt");

    for (int i = 0; i < count; i++)
    {
        write_file << vehicles[i].licensePlate << " " << vehicles[i].vehicleType << " " << vehicles[i].entryTime << " " << vehicles[i].level << " " << vehicles[i].spotNumber << endl;
    }

    write_file.close();
}

// HELPER FUNCTIONS

int mapVehicleType(string type)
{
    // This function gets the type of the vehicle and returns the associated level.
    map<string, int> VehicleType = {
        {"Motorcycle", 0}, {"Car", 1}, {"Truck", 2}
    };

    int level = VehicleType[type];

    return level;
}

int mapFeeVehicle(string type)
{
    // This function gets the type of the vehicle and returns the fee based on the type.
    map<string, int> Fee = {
        {"Motorcycle", 3}, {"Car", 5}, {"Truck", 8}
    };

    int rate = Fee[type];

    return rate;
}
