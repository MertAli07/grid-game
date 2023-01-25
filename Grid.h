#include <iostream>
using namespace std;

class Grid
{
public:
    int size;
    int** board;
    int finalPoint;
    Grid(int size);
    ~Grid();
    void printBoard();
    void place(int value, int row, int column);
    bool linkCheck1();
    bool linkCheck2();
    void formLink(int value, int row, int column);
    void kaboom(int row, int column);
};
