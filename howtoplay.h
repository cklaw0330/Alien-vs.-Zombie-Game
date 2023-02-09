#include<iostream>

using namespace std;

int ClearScreen()
{
    #if defined(_WIN32)
        return std::system("cls");
    #elif defined(__linux__) || defined(__APPLE__)
        return std::system("clear");
    #endif
}

int Pause()
{
    #if defined(_WIN32)
        return std::system("pause");
    #elif defined(__linux__) || defined(__APPLE__)
        return std::system(R"(read -p "Press any key to continue . . . " dummy)");
    #endif
}

void howToPlay()
{
    ClearScreen();
    cout << "Alien vs Zombie is a turn-based combat game in which the player" << endl << "controls Alien to defeat a group of Zombies." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|A|p|h|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << "You can set the dimension of the board by yourself." << endl;
    cout << "By default, the board is in dimension 5 x 9." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|A|p|h|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << "You can also set the number of Zombies by yourself." << endl;
    cout << "As more Zombies in a game, as more challenge and harder for you to win that game." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|A|p|h|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << "Alphabet A in the middle is representing Alien." << endl;
    cout << "Number is representing Zombie." << endl;
    cout << "All the other elements inside the board called objects." << endl << endl;
    Pause();
    ClearScreen();

    cout << "Object: " << endl;
    cout << "+---------+-----------------------------------------------------------------------+" << endl;
    cout << "|Name     |Appearance        |Description                                         |" << endl;
    cout << "+---------+-----------------------------------------------------------------------+" << endl;
    cout << "|Arrow    |^(up), v(down)    |- Changes Alien's direction of movement.            |" << endl;
    cout << "|         |<(left), >(right) |- Adds 20 attack to Alien.                          |" << endl;
    cout << "+---------+-----------------------------------------------------------------------+" << endl;
    cout << "|Health   |h                 |- Adds 20 life to Alien.                            |" << endl;
    cout << "+---------+-----------------------------------------------------------------------+" << endl;
    cout << "|Pod      |p                 |- Instantly inflicts 10 damage to Zombie when hit by|" << endl;
    cout << "|         |                  |  Alien.                                            |" << endl;
    cout << "+---------+-----------------------------------------------------------------------+" << endl;
    cout << "|Rock     |r                 |- Hides a game object (except Rock and Trail)       |" << endl;
    cout << "|         |                  |  beneath it.                                       |" << endl;
    cout << "|         |                  |- Reveals the hidden game object when hit by Alien. |" << endl;
    cout << "|         |                  |- Stops the Alien from moving.                      |" << endl;
    cout << "+---------+-----------------------------------------------------------------------+" << endl;
    cout << "|Empty    |Space             |- Just an empty space on the board.                 |" << endl;
    cout << "+---------+-----------------------------------------------------------------------+" << endl;
    cout << "|Trail    |.                 |- Left by Alien when it moves.                      |" << endl;
    cout << "|         |                  |- Reset to a random game object (except the Trail   |" << endl;
    cout << "|         |                  |  after Alien's turn ends.                          |" << endl;
    cout << "+---------+-----------------------------------------------------------------------+" << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|A|p|h|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << "    Alien    : Life 100, Attack   0" << endl;
    cout << "    Zombie 1 : Life 200, Attack  15, Range  4" << endl << endl;

    cout << "The lines after the board are showing all the attributes of Alien and Zombies." << endl;

    cout << "There are 2 attributes of Alien:" << endl;
    cout << "- life (fixed with initial value 100)" << endl;
    cout << "- attack (always be 0 after Alien turns end)." << endl << endl;
    cout << "There are 3 attributes of Zombies:" << endl;
    cout << "- life & attack (random value)" << endl;
    cout << "- range (random value based on the dimension of board)" << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|A|p|h|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 100, Attack   0" << endl;
    cout << "    Zombie 1 : Life 200, Attack  15, Range  4" << endl << endl;

    cout << "command>" << endl << endl;

    cout << "The arrow in front of Alien is indicating the turn of Alien in this moment." << endl;
    cout << "'command>' is the line that let user to give command to the Alien." << endl << endl;
    Pause();
    ClearScreen();

    cout << "Command: " << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|Command            |Description                                                  |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|up                 |- Alien to move up.                                          |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|down               |- Alien to move down.                                        |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|left               |- Alien to move left.                                        |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|right              |- Alien to move right.                                       |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|arrow              |- Switch the direction of an arrow object in the game board  |" << endl;
    cout << "|                   |  (The player will be asked to enter the row and column of   |" << endl;
    cout << "|                   |  the arrow object to switch, followed by the direction of   |" << endl;
    cout << "|                   |  the arrow object to switch to.)                            |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|help               |- List and describe the commands that the player can use in  |" << endl;
    cout << "|                   |  the game.                                                  |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|save               |- Save the current game to a file.                           |" << endl;
    cout << "|                   |  (The player will be asked to enter the name of the file to |" << endl;
    cout << "|                   |  save to.)                                                  |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|load               |- Load a saved game from a file.                             |" << endl;
    cout << "|                   |  (The player will be asked to enter the name of the file to |" << endl;
    cout << "|                   |  load from.)                                                |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl;
    cout << "|quit               |- Quit the game while still in play.                         |" << endl;
    cout << "|                   |  (The player will be asked to confirm his/her decision.)    |" << endl;
    cout << "+-------------------+-------------------------------------------------------------+" << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|A|p|h|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 100, Attack   0" << endl;
    cout << "    Zombie 1 : Life 200, Attack  15, Range  4" << endl << endl;

    cout << "command>" << endl << endl;

    cout << "There are 3 cases where the Alien will stop to move:" << endl ;
    cout << "- hit the border" << endl;
    cout << "- hit the rock" << endl;
    cout << "- hit the Zombie (zombie does not dead)" << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|A|p|h|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 100, Attack   0" << endl;
    cout << "    Zombie 1 : Life 200, Attack  15, Range  4" << endl << endl;

    cout << "command> right" << endl << endl;

    cout << "Let say user input right, the Alien will move to the right continuously afterwards." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|A|p|h|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 100, Attack   0" << endl;
    cout << "    Zombie 1 : Life 200, Attack  15, Range  4" << endl << endl;

    cout << "Alien finds a pod." << endl;
    cout << "Zombie 1 receives a damage of 10." << endl;
    cout << "Zombie 1 is still alive." << endl << endl;

    cout << "The screen will output what object the Alien found and what will be" << endl;
    cout << "happening before the position of Alien changes in the board." << endl;
    cout << "In this situation, Alien found a pod and the nearest zombie will receive a damage of 10." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|.|A|h|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 100, Attack   0" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "Alien finds a health pack." << endl;
    cout << "Alien's life increased by 20." << endl << endl;

    cout << "The initial position of Alien become a dot which is indicating the Trail." << endl;
    cout << "Now Alien found a health pack and Alien's life increased by 20," << endl;
    cout << "since Alien life is full, Alien's life remain the same." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|.|.|A|^|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 100, Attack   0" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "Alien finds an arrow." << endl;
    cout << "Alien's attack is increased by 20." << endl << endl;

    cout << "Alien's initial attack is always 0 unless it found an arrow. The more arrow it found, the more attack it got." << endl;
    cout << "Alien direction will also be changed." << endl;
    cout << "Note!!! The Alien's attack will become 0 once its turn over" << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|.|.|.|A|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 100, Attack  20" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "Alien finds an empty space." << endl << endl;

    cout << "Alien is moving up now" << endl;
    cout << "Alien found an empty space, nothing happen." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|r|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|.|.|.|.|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 100, Attack  20" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "Alien stumbles upon a rock." << endl;
    cout << "Alien discover a pod beneath the rock." << endl << endl;

    cout << "Alien found a rock, and force it stop moving." << endl;
    cout << "The rock will reveals any other random object." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>|.|.|.|.|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 100, Attack  20" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "Alien turn end. The trail is reset." << endl << endl;

    cout << "Alien turn end. Zombie 1 turn." << endl;
    cout << "Zombie will move to any 1 of 4 direction." << endl;
    cout << "After moving, if the distance between Alien and Zombie is within the Zombie's Range," << endl;
    cout << "Zombie will attack Alien, else Zombie turn end." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>|1|^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|<| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>| |h|>| |<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << "    Alien    : Life 100, Attack  20" << endl;
    cout << " -> Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "Zombie 1 moves down." << endl << endl;

    cout << "Zombie 1 randomly assigned to move down." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>| |^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|1| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>| |h|>| |<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << "    Alien    : Life 100, Attack  20" << endl;
    cout << " -> Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "Zombie 1 attacks Alien." << endl;
    cout << "Alien receives a damage of 15." << endl;
    cout << "Alien is still alive." << endl << endl;

    cout << "Since the distance between Alien and Zombie 1 is only 1 which is within 4," << endl;
    cout << "Zombie 1 will attack Alien with attack of 15." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>| |^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|1| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>| |h|>| |<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << "    Alien    : Life 85 , Attack  20" << endl;
    cout << " -> Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "Zombie 1's turn ends." << endl << endl;

    cout << "Zombie 1's turn ends, now back to Alien's turn" << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>| |^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|1| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>| |h|>| |<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 85 , Attack  20" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "command>" << endl << endl;

    cout << "You can also change the direction of the arrow." << endl;
    cout << "To do that, you need to input arrow." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>| |^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|1| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>| |h|>| |<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 85 , Attack  20" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "command> arrow" << endl << endl;

    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>| |^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|1| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>| |h|>| |<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 85 , Attack  20" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "command> arrow" << endl;
    cout << "Enter row, column, direction:" << endl << endl;

    cout << "Enter the row, column and direction that you want." << endl;
    cout << "Let say you want to change the arrow at (1,1) to down." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>| |^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|1| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>| |h|>| |<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 85 , Attack  20" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "command> arrow" << endl;
    cout << "Enter row, column, direction: 1 1 down" << endl << endl;

    cout << "The format you need to type is as shown above." << endl << endl;
    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |>| |v|v|>| |^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|1| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>| |h|>| |<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 85 , Attack  20" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "command> arrow" << endl;
    cout << "Enter row, column, direction: 1 1 down" << endl;
    cout << "Arrow > is switch to v." << endl << endl;

    Pause();
    ClearScreen();

    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   1 |v| |v|v|>| |^|p|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   2 |r| |v|^|h|1| |A|h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   3 |^|<|^|>| |h|>| |<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   4 |p|>|p|p|r|<| | |h| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   5 |h| |>|<|h| |h|r|<| " << endl;
    cout << "     +-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "      1 2 3 4 5 6 7 8 9  " << endl << endl;

    cout << " -> Alien    : Life 85 , Attack  20" << endl;
    cout << "    Zombie 1 : Life 190, Attack  15, Range  4" << endl << endl;

    cout << "command>" << endl << endl;

    cout << "In short, you need to change the arrow, so you can collect the arrow as many as possible and hits" << endl;
    cout << "the zombie until all the zombie is defeated." << endl << endl;
    Pause();
    ClearScreen();

    cout << "That's the end of this guideline, let's defeat the Zombie now!!!" << endl << endl;
    Pause();
    ClearScreen();

}