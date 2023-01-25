#include "Grid.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

    //A function to split strings
    vector<string> string_split(const string& str){
    vector<string> result;
    istringstream iss(str);
    for (string s; iss >> s; )
        result.push_back(s);
    return result;
}

int main(int argc, char** argv)
{
    //First, I am getting the number of lines in "input1.txt"
    fstream new_file;
    new_file.open(argv[1], ios::in);
    string line;
    int count;
    while (getline (new_file, line))
    {
        count++;
    }
    new_file.close();

    //Then, I create an array according to the line size and store my data in it.
    string inputData1[count];
    fstream file1;
    file1.open(argv[1], ios::in);
    string data;
    int index = 0;
    while (getline (file1, data))
    {
        inputData1[index] = data;
        index++;
    }
    file1.close();

    //PART1
    Grid* grid1 = new Grid(stoi(inputData1[0]));

    for(int i = 1; i<count; i++)
    {
        vector<string>temp;
        int step[3]; // value, row, int
        temp = string_split(inputData1[i]);
        step[0] = stoi(temp[0]);
        step[1] = stoi(temp[1]);
        step[2] = stoi(temp[2]);

        grid1->place(step[0], step[1], step[2]);
        while(grid1->linkCheck1() || grid1->linkCheck2())
        {
            grid1->formLink(step[0]++, step[1], step[2]);
        }
    }
    // PART 1 IS DONE

    // Getting the data from input2.txt
    vector<string> data2;
    fstream new_file2;
    new_file2.open(argv[2], ios::in);
    string line2;
    while (getline (new_file2, line2))
    {
        data2.push_back(line2);
    }
    new_file2.close();

    //Initializing our grid2 for PART 2
    Grid* grid2 = new Grid(stoi(data2[0]));
    for(int i = 1; i < stoi(data2[0])+1; i++)
    {
        vector<string> temp;
        temp = string_split(data2[i]);
        for(int j = 0; j < stoi(data2[0]); j++)
        {
            grid2->board[i-1][j] = stoi(temp[j]);
        }
    }

    //Putting the bombs
    for(int i = stoi(data2[0])+1; i < data2.size(); i++)
    {
        vector<string> temp;
        temp = string_split(data2[i]);
        grid2->kaboom(stoi(temp[0]), stoi(temp[1]));
    }
    //PART 2 IS DONE

    //Writing our boards to output.txt file
    ofstream outputFile(argv[3]);

    if(outputFile.is_open())
    {
        outputFile << "PART 1:" << "\n";
        for(int i = 0; i < grid1->size; i++)
        {
            for(int j  = 0; j < grid1->size; j++)
            {
                outputFile << grid1->board[i][j] << " ";
            }
            outputFile << "\n";
        }
        outputFile << "\n";
        outputFile << "PART 2:" << "\n";
        for(int i = 0; i < grid2->size; i++)
        {
            for(int j = 0; j < grid2->size; j++)
            {
                outputFile << grid2->board[i][j] << " ";
            }
            outputFile << "\n";
        }
        outputFile << "Final Point: " << grid2->finalPoint << "p";
        outputFile.close();
    }
    return 0;
}