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

typedef vector< vector<char> > Board;

Board board;
int row = 5 ;
int col = 9;
int zombieCount = 1;

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

    resizeBoard();

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

int main()
{
    ClearScreen();
    gameSetup();

    ClearScreen();
    drawMap();

    return 0;
}
