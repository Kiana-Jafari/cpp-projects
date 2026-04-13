#include <iostream>
#include <vector>
#include "File.h"
#include "Structures.h"
#include "ModifyData.h"
#include "Bookings.h"
#include "Display.h"

int main()
{

    std::vector<Train> trains;
    std::vector<Passenger> passengers;
    std::vector<Booking> bookings;

    int num;

    std::cout << R"(
    === Train Reservation Management System ===
    
    Welcome to this train booking management system!
    This program is able to read data from text files,
    display recommended trains,
    book tickets for travelers based on their source and destination
    and only if the train already has seats to book,
    cancel a ticket, and display reservations in addition to their current status (i.e. Booked or Canceled).

    To run the program enter:

    1. Read data from text files
    2. Add data to a table
    3. Remove a record from the train table 
    4. Display data
    5. Display recommended trains
    6. Find available seat efficiently and book a ticket
    7. Cancel a ticket
    8. Display reservations and their current status
    -1. Save data back to the files
    
    Enter -1 to exit the program and save data back to text files. 
    Feel free to test it by choosing a number!
    )";
    std::cout << "\n";

    while (true)
    {
        std::cout << "Enter a number: ";
        std::cin >> num;

        if (num == -1)
        break;

        switch (num)
        {
            case 1:
                readFromFile(trains, passengers, bookings);
                break;

            case 2:
                addData(trains, passengers);
                break;

            case 3:
                removeTrain(trains, bookings);
                break;

            case 4:
                displayData(trains, passengers);
                break;

            case 5:
                recommendedTrains(trains);
                break;

            case 6:
                bookTicket(bookings, trains, passengers);
                break;
            
            case 7:
                cancelTicket(trains, passengers, bookings);
                break;
                
            case 8:
                displayReservations(trains, passengers, bookings);
                break;
        }
    }

    saveToFile(trains, passengers, bookings); // Save data back to file if user enters 'exit'
}   