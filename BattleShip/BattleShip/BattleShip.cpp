
#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 10;
int maxShips = 5;
int matrix[rows][elements];


void Clear()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < elements; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Show()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < elements; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void SettingShips()
{
    int s = 0;
    matrix[1][1] = 1;
    while (s < maxShips)
    {
        int x = rand() % rows;
        int y = rand() % elements;
        if (matrix[x][y] != 1 )
        {    
             s++;
             matrix[x][y] = 1;      
        }
    }
}

int NumberOfShips()
{
    int shipsLeft = 0;
   
    for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < elements; j++)
            {
                if (matrix[i][j] == 1)
                
                    shipsLeft++;
                
            }
        }
    
    return shipsLeft;
}
  void Attacking()

{
      int x = rand() % rows;
      int y = rand() % elements;

        if (matrix[x][y] == 1 )
        {     
            matrix[x][y] = 2;
            
            cout << "You hit a ship at: (" << x << "," << y << ") " << endl;
        }

        else {  
           
            cout <<"You have missed a ship at: (" << x << "," << y << ") " << endl;
        }
    
    
}

int main()
{
    char prompt;

    srand(time(NULL));
    Clear();
    Show();
    cout << "=====================================" << endl;
    SettingShips();
    Show();
    cout << "=====================================" << endl;
    while (1)
    {
        
        Attacking();
        cout << "Number of Ships Left: " << NumberOfShips() << endl;
        cout << "Do you want to keep going (y/n)?"; cin >> prompt;
        if (prompt == 'n')
        {
            break;
        }

            if (NumberOfShips() == 0)
            {
                break;
            }
    }

    cout << "Game Over" << endl;
    Show();
    system("pause");
    return 0;
}

