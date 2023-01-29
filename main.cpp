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

using namespace std;

class Zombie
{
    private:
        int life;
        int attack;
        int range;
        int row;
        int col;
    
    public:

        Zombie()
        {
            life = 100 + (rand() % 16) * 10; //random 100-250, resolution 10
            attack = 5 * ((rand() % 4) + 1); //random 5-20, resolution 5
            range = (rand() % 5) + 1; //random 1-5, resolution 1
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

        int getRange()
        {
            return range;
        }

        int getAttack()
        {
            return attack;
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
};


typedef vector< vector<char> > Board;
typedef vector<Zombie> ZombieVector;

Board board;
int row = 5 ;
int col = 9;
int zombieCount = 1;
int curr = 0;
Alien alien;
ZombieVector zombies;

char objects[] = {'<','^','v', '>', 'r', 'h', 'p', ' '};

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

void resizeBoard()
{
    board.resize(row);

    for (int i=0; i< row; i++)
    {
        board[i].resize(col,' ');
    }
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

        cout << endl << "Do you wish to change the game settings (y/n)? =>";
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

int main()
{
    srand(time(0));

    ClearScreen();
    gameSetup();

    ClearScreen();
    drawMap();
    showStatus(curr);

    return 0;
}
