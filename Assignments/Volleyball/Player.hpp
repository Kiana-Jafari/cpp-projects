#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Person.hpp"

class Player : public Person {

public:

    // constructors
    Player() = default;
    Player(
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&,
        int
    );

    // setter
    void setPlayerID(int);

    // getter
    const int getPlayerID() const;

private:

    int playerID;

};

#endif
