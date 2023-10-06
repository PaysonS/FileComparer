// Author : Payson Story
#include "fileFunctions.cpp"

int main()
{
    ifstream inFile1;
    ifstream inFile2;
    ofstream outFile1;
    ofstream outFile2;
    string file1;
    string file2;

    bool noSpace = false;
    int fileCounter = 1;

    cout << "Enter the name of the first file you would like to open: ";
    cin >> file1;
    inFile1 = fileInput(file1);

    cout << "Enter the name of the second file you would like to open: ";
    cin >> file2;
    inFile2 = fileInput(file2);

    firstPass(inFile1, fileCounter);
    fileCounter++;
    firstPass(inFile2, fileCounter);
    cout << "Files have been created with comments removed. Would you like to remove spaces?(y)(n)" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        fileCounter = 1;
        inFile1.close();
        inFile2.close();
        inFile1.open("file" + to_string(fileCounter) + ".txt");
        fileCounter++;
        inFile2.open("file" + to_string(fileCounter) + ".txt");
        fileCounter = 1;
        spaceRemover(inFile1, fileCounter);
        fileCounter++;
        spaceRemover(inFile2, fileCounter);
        cout << "Spaces have been removed from the files." << endl;
        noSpace = true;
    }
    else
    {
        cout << "Spaces have not been removed from the files." << endl;
        cout << "Would you like to exit the program?(y)(n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'y')
        {
            return 0;
        }
        else
        {
            main();
        }
    }
    inFile1.close();
    inFile2.close();
    if (noSpace)
    {
        fileCounter = 1;
        inFile1.open("file" + to_string(fileCounter) + "NoSpace.txt");
        fileCounter++;
        inFile2.open("file" + to_string(fileCounter) + "NoSpace.txt");
    }
    else
    {
        fileCounter = 1;
        inFile1.open("file" + to_string(fileCounter) + ".txt");
        fileCounter++;
        inFile2.open("file" + to_string(fileCounter) + ".txt");
    }
    fileCompare(inFile1, inFile2);

    return 0;
}
