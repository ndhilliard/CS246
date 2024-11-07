#include "StaticSet.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    // set size to 128
    StaticSet<char> charSet(128);

    // Opens a file and reads the characters of the file
    ifstream inputFile("input.txt");
    // if input file is invalid
    if (!inputFile)
    {
        cout << "Error: Unable to open file." << endl;
        return 0;
    }

    char ch;
    while (inputFile.get(ch))
    {
        charSet.Insert(ch);
    }

    inputFile.close();

    // Displays the size and content of the object
    cout << "Size of StaticSet: " << charSet.Size() << endl;
    cout << "Contents of StaticSet: " << charSet.ToString() << endl;

    return 0;
}
