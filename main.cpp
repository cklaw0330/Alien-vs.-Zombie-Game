// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: T10L 
// Names: LAW CHIN KEAT | LO PEI QIN | HO TSI QI 
// IDs: 1211103427 | 1211101157 | 1211101875 
// Emails: 1211103427@student.mmu.edu.my | 1211101157@student.mmu.edu.my | 1211101875@student.mmu.edu.my
// Phones: 01115360330 | 01156679385 | 0162204285 
// ********************************************************* 

#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
#include<iomanip>
#include<time.h>
#include<fstream>
#include<filesystem>
#include "howtoplay.h"
#include<string>
#include<cmath>

using namespace std;

int row = 5 ;
int col = 9;
int zombieCount = 1;
int curr = 0;

class Zombie
{
    private:
        int life;
        int attack;
        int range;
        int rows;
        int cols;
    
    public:

        Zombie()
        {
            double rangeValue = sqrt(row*row + col*col)/2;
            life = 100 + (rand() % 16) * 10; //random 100-250, resolution 10
            attack = 5 * ((rand() % 4) + 1); //random 5-20, resolution 5
            range = (rand() % int(rangeValue) + 1); //random value based on the dimension of board
        }

        void display()
        {
            cout << "Life " << setw(3) << life << ", Attack " << setw(3) << attack << ", Range" << setw(3) << range;
        }

        void addAttack (int a)
        {
            attack += a;
        }

        void deductLife(int x)
        {
            life = (life - x <= 0) ? 0 : life - x;
        }

        bool isAlive()
        {
            return life > 0;
        }

        void setLocation(int r, int c)
        {
            rows = r;
            cols = c;
        }

        void printLocation()
        {
            cout << "Row: " << rows << ", Col: " << cols << endl;
        }

        int getRow()
        {
            return rows;
        }

        int getCol()
        {
            return cols;
        }

        int getRange()
        {
            return range;
        }

        void setRange(int ran)
        {
           range = ran;
        }

        int getAttack()
        {
            return attack;
        }

        void setAttack(int a)
        {
           attack = a;
        }

        int getLife()
        {
            return life;
        }

        void setLife(int l)
        {
           life = l;
        }
};

class Alien
{
    private:
        int life;
        int attack;
        int row;
        int col;

    public:

        Alien()
        {
            life = 100;
            attack = 0;
        }

        void display()
        {
            cout << "Life " << setw(3) << life << ", Attack " << setw(3) << attack;
        }

        void addAttack(int a)
        {
            attack += a;
        }

        int getAttack()
        {
            return attack;
        }

        void setAttack(int a)
        {
           attack = a;
        }

        void resetAttack()
        {
            attack = 0;
        }

        void addLife(int h)
        {
            life = (life + h > 100) ? 100 : life + h;
        }

        void deductLife(int l)
        {
            life = (life - l <= 0) ? 0 : life - l;
        }

        bool isAlive()
        {
            return life > 0;
        }

        void setLocation(int r, int c)
        {
            row = r;
            col = c;
        }

        void printLocation()
        {
            cout << "Row: " << row << ", Col: " << col << endl;
        }

        int getRow()
        {
            return row;
        }

        int getCol()
        {
            return col;
        }

        int getLife()
        {
            return life;
        }

        void setLife(int l)
        {
           life = l;
        }
};


typedef vector< vector<char> > Board;
typedef vector<Zombie> ZombieVector;

Board board;
Alien alien;
ZombieVector zombies;
string menuCommand;
string gameName = "";
bool readfilefail = false;

bool isGameEnd = false;
bool isPlayAgain = false;

char objects[] = {'<','^','v', '>', 'r', 'h', 'p', ' '};
char arrows[] = {'<','^','v', '>'};

void resizeBoard()
{
    board.resize(row);

    for (int i=0; i< row; i++)
    {
        board[i].resize(col,' ');
    }
}

void saveGame()
{
    if(gameName != "")
        {
            cout << "This game was saved under name \"" << gameName << "\" before." << endl;
        }
    string filename;
    cout << "Enter the file name to save the current game: ";
    cin >> filename;
    ofstream MyFile("game/" + filename);
    MyFile << row << endl << col << endl << zombieCount << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            MyFile << board[i][j];
        }
    }
    MyFile << endl << alien.getLife() << endl << alien.getAttack() << endl;
    for (int i = 0; i < zombieCount; i++)
    {
        MyFile << zombies[i].getLife() << endl << zombies[i].getAttack() << endl << zombies[i].getRange() << endl;
    }
    MyFile.close();
    cout << "Game saved" << endl << endl;
    Pause();
    ClearScreen();
}

void loadGame()
{
// save game before loading (only show this when user are inside a game)
    string filename;
    char saveornot;
    string myText;
    if (menuCommand != "2")
    {
        cout << " Do you want to save current game? (y/n): ";
        cin >> saveornot;
        if (saveornot == 'y')
        {
            saveGame();
        }
    }    

// print all saved file
    cout << endl << ".: List of saved game :." << endl;
    int counter = 1;
    for(const auto & entry : std::filesystem::directory_iterator("./game"))
    {

        cout << counter++ << ". " << entry.path().filename().generic_string() << endl;
    }


// input load file name
    cout << endl << "Enter the file name to load: ";
    cin >> filename;
    ifstream MyReadFile("game/" + filename);
    if(MyReadFile.fail()){
        cout << "This file is not existing, please check your spelling." << endl << endl;
        readfilefail = true;
    }

    else
    {
        gameName = filename;
        int index = 0;
        while (getline (MyReadFile, myText)) {
            if (index == 0)
            {
                row = stoi(myText);
            }

            else if (index == 1)
            {
                col = stoi(myText);
            }

            else if (index == 2)
            {
                zombieCount = stoi(myText);
                zombies.resize(zombieCount);
            }

            else if (index == 3)
            {
                resizeBoard();
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        board[i][j] = myText[j+(i*col)];

                        if(myText[j+(i*col)] == 'A')
                        {
                            alien.setLocation(i,j);
                        }

                        else if(isdigit(myText[j+(i*col)]))
                        {
                            zombies[myText[j+(i*col)]-'1'].setLocation(i,j);
                        }
                    }
                }
            }

            else if (index == 4)
            {
                alien.setLife(stoi(myText));
            }

            else if (index == 5)
            {
                alien.setAttack(stoi(myText));
            }

            else if (index >= 6)
            {
                // 6: zombie1 life, 7: zombie1 attack, 8: zombie1 range
                if (index % 3 == 0)
                {
                    zombies[(index-6)/3].setLife(stoi(myText));
                }
                else if (index % 3 == 1)
                {
                    zombies[(index-6)/3].setAttack(stoi(myText));
                }
                else if(index % 3 == 2)
                {
                    zombies[(index-6)/3].setRange(stoi(myText));
                }
            }

            index++;
        }
        MyReadFile.close();
        cout << "Game Loaded" << endl << endl;
    }
    
    Pause();
    ClearScreen();
}

bool checkInArray(char c, char arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        if(arr[i] == c)
        {
            return true;
        }
    }

    return false;
}

bool checkAlienZombie(char c)
{
    return ! checkInArray(c,objects,8);
}

char getRandomObject()
{

    return objects[rand()% 8];
}

void placeRandomToMap()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            board[i][j] = getRandomObject();
        }
    }

    board[(row-1)/2][(col-1)/2] = 'A';
    alien.setLocation((row-1)/2,(col-1)/2);

    for(int z=0; z<zombieCount; z++)
    {
        int r,c;
        do
        {
            r = rand() % row;
            c = rand() % col;
        } while (checkAlienZombie(board[r][c]));
        
        board[r][c] = '1'+ z;
        zombies[z].setLocation(r,c);


    }
}

void gameSetup()
{
    
    while (true)
    {
        cout << "Default Game Settings" << endl;
        cout << "---------------------" << endl;
        cout << "Board Rows     : " << row << endl;
        cout << "Board Columns  : " << col << endl;
        cout << "Zombie Count   : " << zombieCount << endl;

        cout << endl << "Do you wish to change the game settings (y/n)? => ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            ClearScreen();
            cout << "Board Settings" << endl;
            cout << "-----------------" << endl;
            while(true)
            {
                cout << "Enter rows => ";
                cin >> row;

                if(row%2 == 0)
                {
                    cout << "Row must be an odd number, try again!" << endl;
                }
                else break;
            }
            
            while(true)
            {
                cout << "Enter columns => ";
                cin >> col;

                if(col%2 == 0)
                {
                    cout << "Row must be an odd number, try again!" << endl;
                }
                else break;
            }
            
            cout << endl << "Zombie Settings" << endl;
            while(true)
            {
                cout << "Enter number of zombies => ";
                cin >> zombieCount;

                if(zombieCount > 9)
                {
                    cout << "Maximum 9 zombies in this game. Try again." << endl;
                }

                else if(zombieCount >= row*col)
                {
                    cout << "Board cannot fit so many zombies. A board of " << row << " x " << col << " board can only have maximum " << row*col -1 << " zombies. Try again." << endl;

                }
                else break;
            }

            cout << "\nSettings Updated." << endl;
            Pause();
            ClearScreen();
            break;
        }

        else if(choice == 'n' || choice == 'N')
        {
            ClearScreen();
            break;
        }

        else
        {
            cout << "Invalid input, try again" << endl;
            Pause();
            ClearScreen();
        }
    }

    zombies.resize(zombieCount);

    for (int z=0; z<zombieCount; z++)
    {
        zombies[z] = Zombie();
    }

    gameName = "";

    resizeBoard();

    placeRandomToMap();

}

void drawMap()
{
    int MAX_HORIZONTAL = 2 + 2 * col;
    cout << "    " << setw((MAX_HORIZONTAL+21)/2) <<".: Alien vs Zombie :." << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(j==0)
                cout << "     +-+";
            else
                cout << "-+";
        }

        cout << endl;

        for(int j=0; j<col; j++)
        {
            if(j==0)
                cout << setw(4) << i+1 << " |" << board[i][j] << "|";
            else
                cout << board[i][j] << "|";
        }

        cout << endl;
    }

    for(int j=0; j<col; j++)
    {
        if(j==0)
            cout << "    " << " +-+";
        else
            cout << "-+";
    }

    cout << endl;

    if (col >= 10)
    {
        for(int j=0; j<col; j++)
        {
            if(j==0)
                cout << "    " <<  "    ";
            else if(j + 1 < 10)
            {
                cout << "  ";
            }
            else
                cout << (j+1)/10 << " ";
        }

        cout << endl;
    }

    

    for(int j=0; j<col; j++)
    {
        if(j==0)
            cout <<  "      " << (j+1)%10 << " ";
        else
            cout << (j+1)%10 << " ";
    }

    cout << endl;
}

void showStatus(int curr)
{
    cout << ((curr == 0) ? " -> " : "    ") << "Alien    : ";
    alien.display();
    // alien.printLocation();
    cout << endl;

    for(int i=0; i<zombieCount; i++)
    {
        cout << ((curr == i+1) ? " -> " : "    ") << "Zombie " << i+1 << " : " ;
        zombies[i].display();
        // zombies[i].printLocation();
        cout << endl;
    }
}

bool checkIsAllZombieDead()
{
    for(int i=0; i<zombieCount; i++)
    {
        if(zombies[i].isAlive())
        return false;
    }

    return true;
}

bool checkValidMoves(int r, int c)
{
    if (r >= 0 && r <= row-1 && c >=0 && c<= col -1)
    {
        return true;
    }

    else return false;
}

bool checkIsZombie(char c)
{
    char zombiesCode[] = {'1','2','3','4','5','6','7','8','9'};
    return checkInArray(c, zombiesCode,9);
}

void resetTrail()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(board[i][j] == '.')
            {
                board[i][j] = getRandomObject();
            }
        }
    }

}

void moveAlien(string direction)
{
    int currRow = alien.getRow();
    int currCol = alien.getCol();
    int newRow;
    int newCol;

    while(true)
    {
        ClearScreen();
        drawMap();
        cout << endl;
        showStatus(0);
        cout << endl;

        if(direction == "up")
        {
            newRow = currRow -1;
            newCol = currCol;
        }

        else if(direction == "down")
        {
            newRow = currRow + 1;
            newCol = currCol;
        }

        else if(direction == "left")
        {
            newRow = currRow;
            newCol = currCol-1;
        }

        else if(direction == "right")
        {
            newRow = currRow;
            newCol = currCol+1;
        }

        if (!checkValidMoves(newRow,newCol))
        {
            cout <<"Alien hits a border.\n";
            Pause();
            break;
        }


        if (board[newRow][newCol] == '>' || board[newRow][newCol] == '<' || board[newRow][newCol] == '^' || board[newRow][newCol] == 'v')
        {
            char dirSymbol = board[newRow][newCol];
            switch (dirSymbol)
            {
            case '^':
                direction = "up";
                break;

            case 'v':
                direction = "down";
                break;

            case '<':
                direction = "left";
                break;

            case '>':
                direction = "right";
                break;
            
            default:
                break;
            }

            cout << "Alien finds an arrow.\n";
            cout << "Alien's attack is increased by 20.\n";

            alien.addAttack(20);
            board[currRow][currCol] = '.';
            alien.setLocation(newRow,newCol);
            board[newRow][newCol] = 'A';
            currRow = newRow;
            currCol = newCol;

        }

        else if(board[newRow][newCol] == 'h')
        {
            cout << "Alien finds a health pack\nAlien's life increased by 20." << endl;
            alien.addLife(20);
            board[currRow][currCol] = '.';
            alien.setLocation(newRow,newCol);
            board[newRow][newCol] = 'A';
            currRow = newRow;
            currCol = newCol;
        }

        else if(board[newRow][newCol] == 'p')
        {
            int nearestZombie = -1;
            int nearestDistance = INT_MAX;

            for (int z=0; z<zombieCount; z++)
            {
                int distance = abs(zombies[z].getCol() - alien.getCol()) + abs(zombies[z].getRow()-alien.getRow());

                if(distance < nearestDistance)
                {
                    nearestDistance = distance;
                    nearestZombie = z;
                } 
            }
            zombies[nearestZombie].deductLife(10);
            cout << "Alien finds a pod." << endl;
            cout << "Zombie " << nearestZombie + 1 << " receives a damage of 10." << endl;
            if (zombies[nearestZombie].isAlive())
            {
                cout << "Zombie is still alive" << endl;
            }
            else
            {
                cout << "Zombie " << nearestZombie + 1 << " defeated" << endl;
                board[zombies[nearestZombie].getRow()][zombies[nearestZombie].getCol()] = ' ';
                
            }

            board[currRow][currCol] = '.';
            alien.setLocation(newRow,newCol);
            board[newRow][newCol] = 'A';
            currRow = newRow;
            currCol = newCol;
        }

        else if(checkIsZombie(board[newRow][newCol]))
        {
            int zombieIndex = int(board[newRow][newCol]) - '0' - 1;

            zombies[zombieIndex].deductLife(alien.getAttack());

            cout << "Alien attacks Zombie " << zombieIndex+1 << endl;
            cout << "Zombie " << zombieIndex + 1 << " receives a damage of " << alien.getAttack() << ".\n";

            if(zombies[zombieIndex].isAlive())
            {
                cout << "Zombie " << zombieIndex + 1 << " still alive.\n";
                currRow = newRow;
                currCol = newCol;
                Pause();
                break;
            }

            else
            {

                cout << "Zombie " << zombieIndex + 1 << " is dead.\n";

                board[currRow][currCol] = '.';
                alien.setLocation(newRow,newCol);
                board[newRow][newCol] = 'A';
                currRow = newRow;
                currCol = newCol;
            }
            
        }

        else if (board[newRow][newCol] == ' ' || board[newRow][newCol] == '.')
        {
            cout << "Alien finds an empty space. \n";
            board[currRow][currCol] = '.';
            alien.setLocation(newRow,newCol);
            board[newRow][newCol] = 'A';
            currRow = newRow;
            currCol = newCol;
        }

        else if (board[newRow][newCol] == 'r')
        {
            string objectString;
            cout << "Alien stumbles upon a rock.\n";
            while(board[newRow][newCol] == 'r')
            {
                board[newRow][newCol] = getRandomObject();
            }
            
            switch (board[newRow][newCol])
            {
            case 'h':
                objectString = "a health";
                break;
            case 'p':
                objectString = "a pod";
                break;
            case ' ':
                objectString = "an empty space";
                break;
            default:
                objectString = "an arrow";
                break;
            }
            cout << "Alien discover " << objectString << " beneath the rock.\n";
            Pause();
            break;
        }

        
        Pause();
    }

    ClearScreen();
    drawMap();
    cout << endl;
    showStatus(0);
    cout << endl;
    cout << "Alien turn ends. The trail is reset.\n";
    alien.resetAttack();
    resetTrail();
    Pause();
    if(checkIsAllZombieDead())
    {
        isGameEnd = true;

        cout << "Alien wins." << endl;
        while(true)
        {
            cout << "Play again? (y/n)> " ;
            char input;
            cin >> input;

            if (input == 'y' || input == 'Y')
            {
                isPlayAgain = true;
                break;
            }

            else if (input == 'n' || input == 'N')
            {
                isPlayAgain = false;
                break;
            }

            else
            {
                cout << "Invalid input, try again.\n";
            }
        }

    }
    
}

void switchArrow()
{
    cout << "Enter row, column, direction: ";
    int r,c;
    string direction;
    cin >> r >> c >> direction;

    r--;
    c--;

    if(checkInArray(board[r][c],arrows,4))
    {
        if(direction == "up" || direction == "down" || direction == "left" || direction == "right")
        {
            if (direction == "up")
            {
                cout << "Arrow " << board[r][c] << " is switch to ^." << endl;
                board[r][c] = '^';
            }

            else if (direction == "down")
            {
                cout << "Arrow " << board[r][c] << " is switch to v." << endl;
                board[r][c] = 'v';
            }

            else if (direction == "left")
            {
                cout << "Arrow " << board[r][c] << " is switch to <." << endl;
                board[r][c] = '<';
            }

            else
            {
                cout << "Arrow " << board[r][c] << " is switch to >." << endl;
                board[r][c] = '>';
            }
        }
        else
        {
            cout << "Invalid direction input. " << endl;
        }
    }
    else
    {
        cout << "The object located in row and column given is not an arrow. Try again." << endl;
    }
}

void moveZombie(int zombieIndex)
{

    int currRow = zombies[zombieIndex].getRow();
    int currCol = zombies[zombieIndex].getCol();
    int newRow, newCol;
    string direction;

    string moves[] = {"up","down","left","right"};
    
    ClearScreen();
    drawMap();
    cout << endl;
    showStatus(zombieIndex+1);
    cout << endl;

    while(true)
    {
        direction = moves[rand()%4];

        if(direction == "up")
        {
            newRow = currRow -1;
            newCol = currCol;
        }

        else if(direction == "down")
        {
            newRow = currRow + 1;
            newCol = currCol;
        }

        else if(direction == "left")
        {
            newRow = currRow;
            newCol = currCol-1;
        }

        else if(direction == "right")
        {
            newRow = currRow;
            newCol = currCol+1;
        }

        if (!checkValidMoves(newRow,newCol))
        {
            continue;
        }

        if (checkIsZombie(board[newRow][newCol]))
        {
            continue;
        }

        if (board[newRow][newCol] == 'A')
        {
            continue;
        }

        break;
    }

    zombies[zombieIndex].setLocation(newRow,newCol);
    board[currRow][currCol] = ' ';
    board[newRow][newCol] = '1' + zombieIndex;

    cout << "Zombie " << zombieIndex + 1 << " moves " << direction << endl;

    Pause();
    ClearScreen();
    drawMap();
    cout << endl;
    showStatus(zombieIndex+1);
    cout << endl;

    int distance = abs(zombies[zombieIndex].getCol() - alien.getCol()) + abs(zombies[zombieIndex].getRow()-alien.getRow());

    if (distance <= zombies[zombieIndex].getRange())
    {
        alien.deductLife(zombies[zombieIndex].getAttack());

        cout << "Zombie " << zombieIndex + 1 << " attacks Alien.\n";
        cout << "Alien receives a damage of " << zombies[zombieIndex].getAttack() << ".\n";

        if(alien.isAlive())
        {
            cout << "Alien is still alive.\n";
        }
        else
        {
            cout << "Alien is dead.\n";
        }
    }
    else
    {
        cout << "Zombie " << zombieIndex + 1 << " is unable to attack Alien.\n";
        cout << "Alien is too far.\n";
    }

    Pause();

    ClearScreen();
    drawMap();
    cout << endl;
    showStatus(zombieIndex+1);
    cout << endl;

    cout << "Zombie " << zombieIndex +1 << "'s turn ends.\n";

    Pause();

    ClearScreen();
    drawMap();
    cout << endl;
    showStatus(zombieIndex+1);
    cout << endl;

    if(! alien.isAlive())
    {
        isGameEnd = true;
        cout << "Alien lose the game.\n";
        while(true)
        {
            cout << "Play again? (y/n)> " ;
            char input;
            cin >> input;

            if (input == 'y' || input == 'Y')
            {
                isPlayAgain = true;
                break;
            }

            else if (input == 'n' || input == 'N')
            {
                isPlayAgain = false;
                break;
            }

            else
            {
                cout << "Invalid input, try again.\n";
            }
        }
    }

}

int main()
{
    srand(time(0));

    while (true)
    {
        alien = Alien();
        ClearScreen();
        // gameSetup();

        cout << "   .: Alien vs Zombie :.   " << endl;
        cout << "       1. New game         " << endl;
        cout << "       2. Load game        " << endl;
        cout << "       3. How to play      " << endl;
        cout << "       4. Quit             " << endl
             << endl;

        cout << "command> ";
        cin >> menuCommand;

        if (menuCommand == "1" || menuCommand == "2")
        {
            isGameEnd = false;
            isPlayAgain = false;
            while(true){
            ClearScreen();
            if (menuCommand == "1")
            {
                gameSetup();
            }
            
            else
            {
                loadGame();
                if (readfilefail == true)
                {
                    readfilefail = false;
                    continue;
                }
                
            }
            menuCommand = "";
            string input;

            while (true)
            {
                ClearScreen();
                drawMap();
                cout << endl;
                showStatus(0);
                cout << endl
                     << "command> ";
                cin >> input;

                if (input == "up" || input == "down" || input == "left" || input == "right")
                {
                    moveAlien(input);
                    if (isGameEnd)
                        break;
                    for (int z = 0; z < zombieCount; z++)
                    {
                        ClearScreen();
                        drawMap();
                        cout << endl;
                        showStatus(z + 1);
                        moveZombie(z);
                        if (isGameEnd)
                            break;
                    }
                    if (isGameEnd)
                        break;
                }

                else if (input == "arrow")
                {
                    switchArrow();
                    Pause();
                }

                else if (input == "help")
                {
                    cout << "Commands\n";
                    cout << "1. up      - Move up.\n";
                    cout << "2. down    - Move down.\n";
                    cout << "3. left    - Move left.\n";
                    cout << "4. right   - Move right.\n";
                    cout << "5. arrow   - Change the direction of an arrow.\n";
                    cout << "6. help    - Display these user commands.\n";
                    cout << "7. save    - Save the game.\n";
                    cout << "8. load    - Load a game.\n";
                    cout << "9. quit    - Quit the game.\n";
                    Pause();
                }

                else if (input == "save")
                {
                    saveGame();
                }

                else if (input == "load")
                {
                    loadGame();
                }

                else if (input == "quit")
                {
                    cout << "Save your game before quitting." << endl;
                    Pause();
                    cout << "Are you sure you want to quit the game? (y/n): ";
                    string confirm;
                    cin >> confirm;
                    if (confirm == "y" || confirm == "Y")
                    {
                        cout << "Game quit. " << endl;
                        isGameEnd = false;
                        isPlayAgain = false;
                        break;
                    }
                }

                else
                {
                    cout << "Invalid input. Use 'help' command to know about available commands.\n";
                    Pause();
                }
            }

            if (!isPlayAgain)
            {
                break;
            }
            else
            {
                menuCommand = "1";
            }
        }
        }

        else if (menuCommand == "3")
        {
            howToPlay();
        }

        else if (menuCommand == "4")
        {
            cout << "Quitting..." << endl;
            gameName = "";
            break;
        }

        else
        {
            cout << "Invalid input, try again" << endl;
            Pause();
            ClearScreen();
        }
    }
    return 0;
}
