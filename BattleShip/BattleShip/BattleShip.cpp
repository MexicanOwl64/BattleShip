
#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 10;
int maxships = 5;
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
    while (s < maxships)
    {
        int x = rand() % rows;
        int y = rand() % elements;
        if (matrix[x][y] != 1 )
        {
            if (matrix[x + 3][y + 3] == 0 && matrix [x-3][y-3] == 0 )
            {          
                if (x < 10 && y < 10)
                {
                    s++;
                    matrix[x][y] = 1;
                }
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    Clear();
    Show();
    cout << "=====================================" << endl;
    SettingShips();
    Show();
    system("pause");
    return 0;
}

