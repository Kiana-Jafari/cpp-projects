#include "Team.hpp"
#include <iostream>

// constructor (similar to setTeam() method)
Team::Team(
    const Coach& coach,
    const std::string& teamName,
    const std::string& firstColor,
    const std::string& secondColor,
    const Person& gymOwner
)

{
    this->coach = coach;
    this->teamName = teamName;
    this->firstColor = firstColor;
    this->secondColor = secondColor;
    this->gymOwner = gymOwner;
}
    
// setters
void Team::setCoach(const Coach& coach) { this->coach = coach; }
void Team::setTeamName(const std::string& teamName) { this->teamName = teamName;}
void Team::setGymOwner(const Person& gymOwner) { this->gymOwner = gymOwner; }
void Team::setShirtsColor(const std::string& firstColor, const std::string& secondColor)
{
    // a single method to set/modify the color of shirts
    this->firstColor = firstColor;
    this->secondColor = secondColor;
}

// getters
const Coach& Team::getCoach() const { return coach; }
const std::string& Team::getTeamName() const { return teamName; }
const std::pair<std::string, std::string> Team::getShirtsColor() const { return std::make_pair(firstColor, secondColor); }
const Person& Team::getGymOwner() const { return gymOwner; }

bool Team::isPlayerPresent(const Player& player) const
{
    // check if the player is already present in the team
    for (size_t i{0}; i < nPlayer; ++i)
    {
        if (players.at(i).getPlayerID() == player.getPlayerID())
        {
            return true;
            break;
        }
    }

    return false;
}

void Team::insertPlayer(const Player& player)
{
    // insert the player to the team if they're not already a member of and the team has not reached its capacity.
    if (!isFull())
    {
        if (!isPlayerPresent(player))
        {
            players.at(nPlayer) = player;
            ++nPlayer;
        }
    }
}

void Team::deletePlayer(const Player& player)
{
    // if the player is present, remove them.
    if (isPlayerPresent(player))
    {
        removePlayer(player);
    }
}

void Team::getInput()
{
    // read all team information from the input
    std::string input, c1, c2;

    // Team name
    std::cout << "Enter the team name: ";
    std::getline(std::cin, input);
    this->setTeamName(input);
    
    // Coach
    std::cout << "Enter the coach info:";
    std::cout << "\n\nEnter the coach's nationalID: ";
    std::getline(std::cin, input);
    coach.setNationalID(input);
    std::cout << "\nEnter the CoachID: ";
    std::getline(std::cin, input);
    coach.setCoachID(std::stoi(input));
    std::cout << "\nEnter the coach's first name: ";
    std::getline(std::cin, input);
    coach.setFirstName(input);
    std::cout << "\nEnter the coach's last name: ";
    std::getline(std::cin, input);
    coach.setLastName(input);
    std::cout << "\nEnter the coach's father name: ";
    std::getline(std::cin, input);
    coach.setFatherName(input);
    std::cout << "\nEnter the coach's phone number: ";
    std::getline(std::cin, input);
    coach.setPhoneNumber(input);
    std::cout << "\nEnter the coach's address: ";
    std::getline(std::cin, input);
    coach.setAddress(input);

    // Shirts color
    std::cout << "Enter the first shirt's color: ";
    std::getline(std::cin, c1);
    std::cout << "Enter the second shirt's color: ";
    std::getline(std::cin, c2);
    this->setShirtsColor(c1, c2);

    // Gym owner
    std::cout << "\n\nEnter the gym owner's info:";
    std::cout << "\n\nEnter the nationalID: ";
    std::getline(std::cin, input);
    gymOwner.setNationalID(input);
    std::cout << "\nEnter the first name: ";
    std::getline(std::cin, input);
    gymOwner.setFirstName(input);
    std::cout << "\nEnter the last name: ";
    std::getline(std::cin, input);
    gymOwner.setLastName(input);
    std::cout << "\nEnter the father's name: ";
    std::getline(std::cin, input);
    gymOwner.setFatherName(input);
    std::cout << "\nEnter the phone number: ";
    std::getline(std::cin, input);
    gymOwner.setPhoneNumber(input);
    std::cout << "\nEnter the address: ";
    std::getline(std::cin, input);
    gymOwner.setAddress(input);

    // Players
    size_t remainingCapacity{capacity - nPlayer};

    std::cout << "Remaining capacity of players: " << remainingCapacity;
    std::cout << "\nEnter the number of players you wanna add to the team (must be between 0 and " << remainingCapacity << "): ";
    std::getline(std::cin, input);

    int n = std::stoi(input);

    if (isValid(n, remainingCapacity))
    {
        for (size_t i{0}; i < n; ++i)
        {
            Player p;

            std::cout << "Enter the player " << i+1 << " info:";

            std::cout << "\n\nEnter the player's nationalID: ";
            std::getline(std::cin, input);
            p.setNationalID(input);
            std::cout << "\nPlayerID: ";
            std::getline(std::cin, input);
            p.setPlayerID(std::stoi(input));
            std::cout << "first name: ";
            std::getline(std::cin, input);
            p.setFirstName(input);
            std::cout << "\nlast name: ";
            std::getline(std::cin, input);
            p.setLastName(input);
            std::cout << "\nfather's name: ";
            std::getline(std::cin, input);
            p.setFatherName(input);
            std::cout << "phone number: ";
            std::getline(std::cin, input);
            p.setPhoneNumber(input);
            std::cout << "address: ";
            std::getline(std::cin, input);
            p.setAddress(input);

            insertPlayer(p); // insert player if they're not already present in the team
        }
    }
}

void Team::add(const Team& team)
{
    // add all players who are members of team T to this team.
    for (size_t i{0}; i < team.nPlayer; ++i)
    {
        insertPlayer(team.players.at(i));
    }
}

void Team::showTeamInfo() const
{
    // display all team's info
    std::cout
        << "Gym owner info:\n\n"
        << "\nFull name: " << gymOwner.getFirstName() << " " << gymOwner.getLastName()
        << "\nnationalID: " << gymOwner.getNationalID()
        << "\n\nTeam \'" << teamName << "\' info:"
        << "\n\nCoach info:\n"
        << "\nFull name: " << coach.getFirstName() << " " << coach.getLastName()
        << "\nCoachID: " << coach.getCoachID()
        << "\nnationalID: " << coach.getNationalID()
        << "\n\nShirts colors: " << this->getShirtsColor().first << " - " << this->getShirtsColor().second
        << "\n\nNumber of current players: " << nPlayer
        << "\n\n Current players:\n";

    for (size_t i{0}; i < nPlayer; ++i)
    
    std::cout 
        << "\nPlayer " << i+1 << " info:"
        << "\nFull name: " << players.at(i).getFirstName() << " " << players.at(i).getLastName()
        << "\nPlayerID: " << players.at(i).getPlayerID()
        << "\nnationalID: " << players.at(i).getNationalID() << '\n';
}

// utility
void Team::removePlayer(const Player& player)
{
    // utility fucntion to remove the player and shift elements in the array
    for (size_t i{0}; i < nPlayer; ++i)
    {
        if (players.at(i).getPlayerID() == player.getPlayerID())
        {
            --nPlayer;

            for (size_t j{i}; j < nPlayer; ++j)
            {
                players.at(j) = players.at(j + 1);
            }

            break; // once the player is found and shifting is done
        }
    }
}

bool Team::isFull() const
{
    // utility to check whether the team reached its capacity (the array)
    if (nPlayer == capacity)
    return true;

    else
    return false;
}

bool Team::isValid(int input, int remainingCapacity) const
{
    // check whether the input is valid
    if (input >=0 && input <= remainingCapacity)
    return true;

    else
    return false;
}
