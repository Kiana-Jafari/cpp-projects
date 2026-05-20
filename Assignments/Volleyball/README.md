# Volleyball Team Management System
In C++ create a class named `Person` that stores the information of an individual. This information includes: `first name`, `last name`, `father's name`, `phone number`, `address`, and `national ID`.

Then create another class named `Player` that inherits from the `Person` class and additionally has an integer field `player ID` which serves as an identifier for a volleyball player.

Create a third class named `Coach` that inherits from the Person class and additionally has an integer field `coach ID` which serves as an identifier for a volleyball coach.

Create suitable member functions (including constructors) for these classes.

Define a fourth class named `Team` that stores the information of a volleyball team. Its members are:

- A list of the team's players (maximum length 20) of type `Player`
- An integer `nPlayer` representing the number of players currently in the team
- Information of the head coach (type `Coach`)
- Team name (`String`)
- First shirt color (`String`)
- Second shirt color (`String`)
- Name of the gym owner (type `Person`)

In addition to the constructor, define the following functions for the `Team` class:

|Function Name|Argument(s)|Return Type|Description|
|-------------|-----------|-----------|-----------|
|setCoach|A Coach object|void|Sets the team's coach information.|
|setTeam|(parameters of your choice)|void|Assigns the team's information.|
insertPlayer|A Player object p|void|If player p is not already a member of the team, adds them to the team.|
|isPlayerPresent|A Player object p|boolean|Returns true if player p is a member of the team, otherwise false.|
|deletePlayer|A Player object p|void|If player p is a member of the team, removes them from the team.|
|show|None|void|Prints all team information.|
|getInput|None|void|Reads all team information from input.|
|add|A Team object T|void|Adds all players who are members of team T to this team.|
