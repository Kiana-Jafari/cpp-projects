#pragma once

#include "Structures.h"

void readFromFile(std::vector<Train>& trains, std::vector<Passenger>& passengers, std::vector<Booking>& bookings);
void saveToFile(std::vector<Train>& trains, std::vector<Passenger>& passengers, std::vector<Booking>& bookings);