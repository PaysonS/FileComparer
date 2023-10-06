#include <iostream>
#include <fstream>
using namespace std;

// first pass of the file that remooves all comments and stores into a new file
auto firstPass(ifstream &inFile1, int counter)
{
    // creates a new file without the comments
    ofstream outFile;
    outFile.open("file" + to_string(counter) + ".txt");
    while (!inFile1.eof())
    {
        string line;
        getline(inFile1, line);
        line = line.substr(0, line.find("//"));
        outFile << line << endl;
    }
    inFile1.close();
}

// function that parses and replaces the files
auto spaceRemover(ifstream &inFile, int counter)
{
    ofstream outFile;
    outFile.open("file" + to_string(counter) + "NoSpace.txt");
    while (!inFile.eof())
    {
        string line;
        getline(inFile, line);

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ')
            {
                line.erase(i, 1);
            }
        }
        outFile << line << endl;
    }
    outFile.close();
    inFile.close();
}

auto fileInput(string file1)
{

    ifstream inFile1;

    inFile1.open(file1);
    if (inFile1.fail())
    {
        cout << "Error opening file " << file1 << endl;
        exit(1);
    }
    return inFile1;
}

auto fileCompare(ifstream &inFile1, ifstream &inFile2)
{

    string line1;
    string line2;
    int lineCounter = 1;
    while (!inFile1.eof() && !inFile2.eof())
    {
        getline(inFile1, line1);
        getline(inFile2, line2);
        if (line1 != line2)
        {
            cout << "Files are not the same." << endl;
            cout << "Line " << lineCounter << " is the first different line." << endl;
            cout << "File 1 line " << lineCounter << " is: " << line1 << endl;
            cout << "File 2 line " << lineCounter << " is: " << line2 << endl;
            cout << "Would you like to see the different letter?(y)(n)" << endl;
            char choice;
            cin >> choice;
            if (choice == 'y')
            {
                for (int i = 0; i < line1.length(); i++)
                {
                    if (line1[i] != line2[i])
                    {
                        cout << "File 1 letter: \'" << line1[i]
                             << "\' while file 2's letter is \'" << line2[i] << "\'" << endl;
                        return 0;
                    }
                }
            }
            return 0;
        }
        lineCounter++;
    }
    cout << "Files are the same." << endl;
    return 0;
}