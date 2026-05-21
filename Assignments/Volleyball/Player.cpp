#include "Player.hpp"

Player::Player(
    const std::string& firstName,
    const std::string& lastName,
    const std::string& fatherName,
    const std::string& phoneNumber,
    const std::string& address,
    const std::string& nationalID,
    int playerID

) : Person(firstName, lastName, fatherName, phoneNumber, address, nationalID)

{
    this->playerID = playerID;
}

// setter
void Player::setPlayerID(int playerID) { this->playerID = playerID; }

// getter
const int Player::getPlayerID() const { return playerID; }
