Compilation and Usage Instruction

Purpose of this Assignment:

The main purpose of this group project is to build a “King of New York Game”. This assignment is broken down into 4 sections. Our objectives for this assignment was to get a general set up of the game. 
It consisted of 5 parts 1) Setting up the Map 2) Setting up a Map loader 3) Rolling a Dice 4) Setting up the players and lastly setting up the cards deck/Monster Cards/Tokens/cubes/unit tiles.

Environment

We used Microsoft Visual Studio 2017 as our IDE in order to create C++ classes and to compile it. Some of the external libraries that we used throughout our code are:

* #include <vector>: this is used in order to store values into container. It was especially used in the Map classes, as well other classes throughout the assignment.

* #include <string>: String were used throughout our application in order to represent a sequence of characters (ex: words).

* #include <iostream>: Allows the program to get input from users as well output values for users to view. This was also used throughout our classes in the assignment.

* #include <cstdlib>: we used the srand() and rand() methods in order to create a random generator. This was used for the dice roll and tiles.

* #include <ctime>: knowing the time was needed in the dice class, tiles class and card class

* #include <fstream>: used in the map classes, to read text files.

* #include <sstream>: used in the map classes, in order to read text files.

* #include <algorithm>: was used in order to shuffle the cards and tiles.

Design

A driver was implemented for each of the 5 sections in order to illustrate that the code is working as intended. Below represents a breakdown of each of the drivers.

1) playerDriver: will call many player functions within its driver. It begins, by calling the function allowing the users to choose the amount of players that wishes 
to play the game (between 2-6 players). Each player will then be asked to select a monster that he/she wishes to be as well which region they wish to occupy. The functions to create

tokens will be called and assigned to each player. The dice class acts a friend class to player, which work hand in hand with another.

Classes/Header Files that are called within the driver: Player.cpp, Player.h

2) MapDriver: is used to create the five regions (Manhattan, Staten Island, Queens, Bronx, Brooklyn). The 6 zones within Manhattan will also be created. 
Once all the regions and zones are created, edges will be made in order to connect its neighbouring regions/zones.

Classes/Header Files that are called within the driver: Vertex.cpp, Vertex.h, Map.cpp, Map.h, Edge.cpp, Edge.h, Graph.cpp, Graph.h

3) DeckDriver: Consists of creating a few of the tokens, energy cubes, monsters, tiles and cards.

Classes/Header Files that are called within the driver: Tiles.cpp, Tiles.h, Tokens.cpp, Tokens.h, Monsters.cpp, Monsters.h, Cards.cpp, Cards.h, EnenmeyCubes.cpp, EnemeyCubes.h

4) DiceDriver: will create 2 dice and output the results once it has completed its roll.

Classes/Header Files that are called within the driver: Dice.cpp, Dice.h

5) FileIODriver: will read a text file consisting of the New York Map. If the file is not found or can’t be read it will exit the system.

Classes/Header Files that are called within the driver: FileIO.cpp, FileIO.h 