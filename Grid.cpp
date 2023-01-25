#include "Grid.h"
#include <vector>

Grid::Grid(int n)
{
   size = n;
   finalPoint = 0;

   //Creating our board
   board = new int*[size];
   for(int i = 0; i < size; i++)
   {
       board[i] = new int[size];
   }

   //Initializing empty cells with "0".
   for(int i = 0; i<size; i++)
   {
       for(int j = 0; j<size; j++)
       {
           this->board[i][j] = 0;
       }
   }
}

Grid::~Grid()
{
    for(int i = 0; i < size; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

//A method to print the board
void Grid::printBoard()
{
    for(int i = 0; i<size; i++)
    {
        for(int j = 0; j<size; j++)
        {
            cout << this->board[i][j];
        }
        cout << endl;
    }
}

void Grid::place(int value, int row, int column)
{
    this->board[row][column] = value;
}

// A link can be created in 2 ways:
// "Mini-L" type and "straight" type
// A link's length must be equal or bigger than 3
// If we can identify at least a 3-length link, then a link must be created.
bool Grid::linkCheck1()
{
    // First, checking for Mini-l type links.
    // Think the board as : A____B
    //                      |    |
    //                      |    |
    //                      C____D
    for(int row = 0; row < this->size; row++)
    {
        for(int column = 0; column < this->size; column++)
        {
            if(row == 0 && column == 0) // A
            {
                if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row+1][column]
                && this->board[row+1][column] == this->board[row][column+1]
                && this->board[row][column] == this->board[row][column+1])
                {
                    return true;
                }
            }
            else if(row == 0 && 0 < column && column < this->size-1) // A____B
            {
                if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row][column-1]
                && this->board[row][column-1] == this->board[row+1][column]
                && this->board[row][column] == this->board[row+1][column])
                {
                    return true;
                }
                else if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row][column+1]
                && this->board[row][column+1] == this->board[row+1][column]
                && this->board[row][column] == this->board[row+1][column])
                {
                    return true;
                }
            }
            else if(row == 0 && column == this->size-1) // B
            {
                if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row][column-1]
                && this->board[row][column-1] == this->board[row+1][column]
                && this->board[row][column] == this->board[row+1][column])
                {
                    return true;
                }
            }
            else if(0 < row && row < this->size-1 && column == this->size-1) // B____C
            {
                if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row-1][column]
                && this->board[row-1][column] == this->board[row][column-1]
                && this->board[row][column] == this->board[row][column-1])
                {
                    return true;
                }
                else if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row][column-1]
                && this->board[row][column-1] == this->board[row+1][column]
                && this->board[row][column] == this->board[row+1][column])
                {
                    return true;
                }
            }
            else if(row == this->size-1 && column == this->size-1) // C
            {
                if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row-1][column]
                && this->board[row-1][column] == this->board[row][column-1]
                && this->board[row][column] == this->board[row][column-1])
                {
                    return true;
                }
            }
            else if(row == this->size-1 && 0 < column && column < this->size-1) // D____C
            {
                if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row][column-1]
                && this->board[row][column-1] == this->board[row-1][column]
                && this->board[row][column] == this->board[row-1][column])
                {
                    return true;
                }
                else if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row-1][column]
                && this->board[row-1][column] == this->board[row][column+1]
                && this->board[row][column] == this->board[row][column+1])
                {
                    return true;
                }
            }
            else if (row == this->size-1 && column == 0) // D
            {
                if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row-1][column]
                && this->board[row-1][column] == this->board[row][column+1]
                && this->board[row][column] == this->board[row][column+1])
                {
                    return true;
                }
            }
            else if (0 < row && row < this->size-1 && column == 0) // A____D
            {
                if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row-1][column]
                && this->board[row-1][column] == this->board[row][column+1]
                && this->board[row][column] == this->board[row][column+1])
                {
                    return true;
                }
                else if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row][column+1]
                && this->board[row][column+1] == this->board[row+1][column]
                && this->board[row][column] == this->board[row+1][column])
                {
                    return true;
                }
            }
            else if(0 < row && row < this->size-1 && 0 < column && column < this->size-1) // Middle-zone
            {
                if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row][column-1]
                && this->board[row][column-1] == this->board[row-1][column]
                && this->board[row][column] == this->board[row-1][column])
                {
                    return true;
                }
                else if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row-1][column]
                && this->board[row-1][column] == this->board[row][column+1]
                && this->board[row][column] == this->board[row][column+1])
                {
                    return true;
                }
                else if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row][column+1]
                && this->board[row][column+1] == this->board[row+1][column]
                && this->board[row][column] == this->board[row+1][column])
                {
                    return true;
                }
                else if(this->board[row][column] != 0
                && this->board[row][column] == this->board[row+1][column]
                && this->board[row+1][column] == this->board[row][column-1]
                && this->board[row][column] == this->board[row][column-1])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Grid::linkCheck2()
{
    //Checking the horizontal straight links
    for(int row = 0; row < this->size; row++)
    {
        for(int column = 0; column < this->size - 2; column++)
        {
            if(this->board[row][column] != 0
            && this->board[row][column] == this->board[row][column+1]
            && this->board[row][column+1] == this->board[row][column+2]
            && this->board[row][column] == this->board[row][column+2])
            {
                return true;
            }
        }
    }

    //Checking the vertical straight links
    for(int row = 0; row < this->size - 2; row++)
    {
        for(int column = 0; column < this->size; column++)
        {
            if(this->board[row][column] != 0
            && this->board[row][column] == this->board[row+1][column]
            && this->board[row+1][column] == this->board[row+2][column]
            && this->board[row][column] == this->board[row+2][column])
            {
                return true;
            }
        }
    }

    return false;
}

void Grid::formLink(int value, int row, int column)
{
    vector<int> link;
    if(row-1 >= 0 && this->board[row-1][column] == value) // UP
    {
        link.push_back(row-1);
        link.push_back(column);
        if(column-1 >= 0 && this->board[row-1][column-1] == value) // UP-LEFT
        {
            link.push_back(row-1);
            link.push_back(column-1);
        }
        if(row-2 >= 0 && this->board[row-2][column] == value) // UP-UP
        {
            link.push_back(row-2);
            link.push_back(column);
        }
        if(column+1 <= this->size-1 && this->board[row-1][column+1] == value) // UP-RIGHT
        {
            link.push_back(row-1);
            link.push_back(column+1);
        }
    }
    if(column+1 <= this->size-1 && this->board[row][column+1] == value) // RIGHT
    {
        link.push_back(row);
        link.push_back(column+1);
        if(row-1 >= 0 && this->board[row-1][column+1] == value) // RIGHT-UP
        {
            link.push_back(row-1);
            link.push_back(column+1);
        }
        if(column+2 <= this->size-1 && this->board[row][column+2] == value) // RIGHT-RIGHT
        {
            link.push_back(row);
            link.push_back(column+2);
        }
        if(row+1 <= this->size-1 && this->board[row+1][column+1] == value) // RIGHT-DOWN
        {
            link.push_back(row+1);
            link.push_back(column+1);
        }
    }
    if(row+1 <= this->size-1 && this->board[row+1][column] == value) // DOWN
    {
        link.push_back(row+1);
        link.push_back(column);
        if(column-1 >= 0 && this->board[row+1][column-1] == value) // DOWN-LEFT
        {
            link.push_back(row+1);
            link.push_back(column-1);
        }
        if(row+2 <= this->size-1 && this->board[row+2][column] == value) // DOWN-DOWN
        {
            link.push_back(row+2);
            link.push_back(column);
        }
        if(column+1 <= this->size-1 && this->board[row+1][column+1] == value) // DOWN-RIGHT
        {
            link.push_back(row+1);
            link.push_back(column+1);
        }
    }
    if(column-1 >= 0 && this->board[row][column-1] == value) // LEFT
    {
        link.push_back(row);
        link.push_back(column-1);
        if(row-1 >= 0 && this->board[row-1][column-1] == value) //LEFT-UP
        {
            link.push_back(row-1);
            link.push_back(column-1);
        }
        if(column-2 >= 0 && this->board[row][column-2] == value) // LEFT-LEFT
        {
            link.push_back(row);
            link.push_back(column-2);
        }
        if(row+1 <= this->size && this->board[row+1][column-1] == value) // LEFT-DOWN
        {
            link.push_back(row+1);
            link.push_back(column-1);
        }

    }
    for(int i = 0; i<link.size(); i = i+2)
    {
        this->board[link.at(i)][link.at(i+1)] = 0;
    }
    this->board[row][column]++;
}

void Grid::kaboom(int row, int column)
{
    int victim = this->board[row][column];

    //Checking the row
    for(int i = 0; i < this->size; i++)
    {
        if(this->board[row][i] == victim)
        {
            this->board[row][i] = 0;
            this->finalPoint = this->finalPoint + victim;
        }
    }

    //Checking the column
    for(int i = 0; i < this->size; i++)
    {
        if(this->board[i][column] == victim)
        {
            this->board[i][column] = 0;
            this->finalPoint = this->finalPoint + victim;
        }
    }

    //Checking the diagonal "\"
    for(int i = 0; i < this->size; i++)
    {
        for(int j = 0; j < this->size; j++)
        {
            if(i==j && row+i < this->size && column+j < this->size && this->board[row+i][column+j] == victim)
            {
                this->board[row+i][column+j] = 0;
                this->finalPoint = this->finalPoint + victim;
            }
        }
    }

    for(int i = this->size-1; i >= 0; i--)
    {
        for(int j = this->size-1; j >= 0; j--)
        {
            if(i==j && row-i >= 0 && column-j >= 0 && this->board[row-i][column-j] == victim)
            {
                this->board[row-i][column-j] = 0;
                this->finalPoint = this->finalPoint + victim;
            }
        }
    }

    //Checking the diagonal "/"
    for(int i = 0; i < this->size; i++)
    {
        if(row-i >= 0 && column+i < this->size && this->board[row-i][column+i] == victim)
        {
            this->board[row-i][column+i] = 0;
            this->finalPoint = this->finalPoint + victim;
        }
    }

    for(int i = 0; i < this->size; i++)
    {
        if(row+i < this->size && column-i >= 0 && this->board[row+i][column-i] == victim)
        {
            this->board[row+i][column-i] = 0;
            this->finalPoint = this->finalPoint + victim;
        }
    }
}