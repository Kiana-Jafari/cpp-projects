#include <iostream>
#include "Team.hpp"

using namespace std;

int main()
{

    // 1. Create a Coach and a Person (gym owner)
    Coach coach1{"John", "Doe", "Robert", "555-1234", "123 Main St", "ID123", 101};
    Person owner1{"Alice", "Smith", "Paul", "555-5678", "456 Oak Ave", "ID456"};

    // 2. Create a Team
    Team teamA{coach1, "Thunderbolts", "Blue", "White", owner1};

    // 3. Create some players
    Player p1{"Mike", "Jordan", "James", "555-1111", "10 Sports Rd", "ID101", 1};
    Player p2{"Steve", "Curry", "Dell", "555-2222", "22 Hoops Ln", "ID102", 2};
    Player p3{"LeBron", "James", "Joe", "555-3333", "33 Champion Dr", "ID103", 3};
    Player p4{"Kevin", "Durant", "Wayne", "555-4444", "44 Scorer Blvd", "ID104", 4};

    // Test insertPlayer
    teamA.insertPlayer(p1);
    teamA.insertPlayer(p2);
    teamA.insertPlayer(p3);
    teamA.insertPlayer(p4);

    std::cout << "--- After inserting 3 players ---\n";
    teamA.showTeamInfo();

    // Test duplicate insertion (should be ignored)
    teamA.insertPlayer(p2);  // duplicate
    std::cout << "--- After duplicate insertion of player ID 2 ---\n";
    teamA.showTeamInfo();

    // Test isPlayerPresent
    std::cout << "--- Presence check ---\n";
    std::cout << "Player ID 1 present? " << (teamA.isPlayerPresent(p1) ? "Yes" : "No") << "\n";
    std::cout << "Player ID 99 present? " << (teamA.isPlayerPresent(Player{"", "", "", "", "", "", 99}) ? "Yes" : "No") << "\n\n";

    // Test deletePlayer (remove player ID 2)
    teamA.deletePlayer(p2);
    std::cout << "--- After deleting player ID 2 ---\n";
    std::cout << "\n--- Team 1 info ---\n";
    teamA.showTeamInfo();

    Team teamB;
    teamB.setTeamName("AllStars");
    teamB.setShirtsColor("Red", "Black");
    teamB.setCoach(Coach{"Greg", "Popovich", "Mike", "555-9999", "5 Courtside", "ID999", 202});
    teamB.setGymOwner(Person{"Mark", "Cuban", "Stanley", "555-7777", "77 Arena Dr", "ID777"});
    
    // Insert players into teamB
    teamB.insertPlayer(p4);     // player ID 4
    teamB.insertPlayer(p1);     // player ID 1 (already in teamA)
    teamB.insertPlayer(Player{"James", "Harden", "James Sr.", "555-5555", "55 Beard St", "ID105", 5});

    std::cout << "\n--- Team B before adding from Team A ---\n";
    teamB.showTeamInfo();

    // Add all players from teamA to teamB
    teamB.add(teamA);
    std::cout << "\n--- Team B after adding players from Team A ---\n";
    teamB.showTeamInfo();

    // Test getInput() method
    // Team teamB;
    // teamB.getInput();
}
