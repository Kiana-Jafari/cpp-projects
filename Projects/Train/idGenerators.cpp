#include "Structures.h"

// HELPER FUNCTIONS
int getPassengerID(const std::vector<Passenger>& passengers)
{
    // This helper function gets the next ID for passenger table.
    unsigned int maxID{0};

    for (const auto& passenger : passengers)
    {
        if (passenger.id > maxID)
        maxID = passenger.id;
    }

    return maxID + 1;
}

int getTrainID(const std::vector<Train>& trains)
{
    // Helper function to get the next autoincrement ID for train table.
    unsigned int maxID{0};

    for (const auto& train : trains)
    {
        if (train.id > maxID)
        maxID = train.id;
    }

    return maxID + 1;
}

int getBookingID(const std::vector<Booking>& bookings)
{
    unsigned int maxID{0};

    for (const auto& booking : bookings)
    {
        if (booking.bookingID > maxID)
        maxID = booking.bookingID;
    }

    return maxID + 1;
}