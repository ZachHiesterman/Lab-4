#include <iostream>
#include <fstream>
#include <iomanip>

/*
    Zach Hiesterman
    Computer Science Fall 2024
    Due: October 15th
    Lab 4: Tempature Output
    
*/

using namespace std;

const int maxTemp = 120;
const int minTemp = -30;
const int starDegree = 3;

void TempChart(int tempatures[], int count, ofstream& outFile)
{
    cout << "Tempature Bar chart\n";
    cout << "Each " << "*" << " is equal to 3 degrees.\n";
    cout << "Tempatures:";

    outFile << "Tempature Bar chart\n";
    outFile << "Each " << "*" << " is equal to 3 degrees.\n";
    outFile << "Tempatures:";

    for (int i = 0; i < count; i++)
        {
            int temp = tempatures[i];

            if (temp < minTemp || temp > maxTemp)
                {
                cout << "Error: Tempature" << temp << "is out of range.";
                outFile << "Error: Tempature" << temp << "is out of range.";
                continue;
                }
            
            int degreeCount = (temp >= 0) ? (temp / starDegree) : 0;
            
            cout << setw(3) << temp << " | ";

            for (int j = 0; j < degreeCount; j++)
                cout << "*";

            cout << "\n";

            outFile << setw(3) << temp << " | ";

            for (int j = 0; j < degreeCount; j++)
                {
                outFile << "*";
                }
            outFile << "\n";
        }
}

int main()
{
    ifstream inFile("inTemp.dat");
    ofstream outFile("tempOut.dat");
    int tempatures[100];
    int count = 0;

    if (!inFile)
        cout << "Error: Unable to open input file address.\n";
        return 1;

    if (!outFile)
        cout << "Error: Unable to open output file address.\n";
        return 1;
    
    while (count < maxTemp && (inFile >> tempatures[count]))
        {
            count++;
        }
    inFile.close();

    TempChart(tempatures, count, outFile);

    outFile.close();

    return 0;
}