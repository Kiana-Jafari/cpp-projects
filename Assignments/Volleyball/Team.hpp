#ifndef TEAM_HPP
#define TEAM_HPP

#include "Person.hpp"
#include "Player.hpp"
#include "Coach.hpp"

#include <array>
#include <string>

class Team {

public:

    const static size_t capacity{20};

    // constructors
    Team() = default;
    Team(
        const Coach&,
        const std::string&,
        const std::string&,
        const std::string&,
        const Person&
    );

    // setters
    void setCoach(const Coach&);
    void setTeamName(const std::string&);
    void setShirtsColor(const std::string&, const std::string&);
    void setGymOwner(const Person&);

    // getters
    const Coach& getCoach() const;
    const std::string& getTeamName() const;
    const std::pair<std::string, std::string>getShirtsColor() const;
    const Person& getGymOwner() const;

    void insertPlayer(const Player&);
    bool isPlayerPresent(const Player&) const;
    void deletePlayer(const Player&);
    void showTeamInfo() const;
    void getInput();
    void add(const Team&);

private:

    std::array<Player, capacity> players;
    int nPlayer{0};
    Coach coach;
    std::string teamName;
    std::string firstColor;
    std::string secondColor;
    Person gymOwner;

    // utility functions
    void removePlayer(const Player&);
    bool isFull() const;
    bool isValid(int, int) const;

};

#endif
