// Author: CrunchiesJL

using namespace std;
#include <array>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

void PrintList(vector<double> list)
{
    int count = 0;
    for (double i : list)
    {
        cout << setprecision(10) << i << " ";
        count++;
    }
    cout << endl;
    cout << "Size of list: " << count << endl;
}

void format(vector<double> list)
{
    int count = 0;
    for (double i : list)
    {
        cout << setprecision(10) << i << ", ";
        count++;
    }
    cout << endl;
}

void meanMedian(vector<double> list)
{
    double mean = 0;
    double median = 0;
    double sum = 0;
    
    for (double i : list)
        {
            sum += i;
        }
    mean = sum / list.size();

    if (list.size() % 2 == 0)
    {
        median = (list.at((list.size()/2) - 1) + list.at(list.size()/2)) / 2;
    }
    else
    {
        median = list.at((list.size()/2));
    }

    cout << "mean: " << mean << endl;

    cout << "median: " << median << endl;

}

double calcMean(vector<double> list)
{
    double mean = 0;
    double sum = 0;
    
    for (double i : list)
        {
            //cout << "currValue: " << i << endl; 
            sum += i;
            //cout << "currSum: " << sum << endl;
        }
    mean = sum / list.size();

    return mean;
}

void calcVariance(vector<double> list)
{
    vector<double> varList;
    double variance = 0;
    string input;

    double mean = calcMean(list);
    cout << "mean: " << mean << endl;

    cout << "Values: "; PrintList(list);

    double temp2;
    for (double i : list)
    {
        double temp = 0;
        if (mean > i) { temp = (mean - i) * -1; }
        if (mean < i) { temp = i - mean; }

        temp *= temp;
        temp2 += temp;
    }

    variance = (temp2 / (list.size()-1));

    cout << "Variance: " << variance << endl;

    cout << "Standard Deviation: " << sqrt(variance) << endl;

}

void interRange(vector<double> list)
{
    double median;
    int medianIndex1;
    int medianIndex2;
    double inter;

    double q1;
    double q3;

    if (list.size() % 2 != 0)
    {
        //median = (list.at(list.size()/2) + list.at(list.size()/2 + 1)) / 2;
        median = list.at(list.size()/2 + 1);
        medianIndex1 = list.size()/2 + 1;

        //cout << "test " << (list.at(medianIndex/2) - 1) << " " << (list.at(medianIndex/2)) << endl;
        //cout << "test " << list.at(medianIndex + ((medianIndex/2) - 1)) << " " << list.at(medianIndex + (medianIndex/2)) << endl;

        q1 = (list.at((medianIndex1/2) - 1) + list.at(medianIndex1/2)) / 2;

        q3 = (list.at(medianIndex1 + ((medianIndex1/2) - 2)) + list.at(medianIndex1 + (medianIndex1/2) - 1)) / 2;

        inter = q3 - q1;

        //list.at(medianIndex/2);
        //(list.size() / 2) + 1 + (list.size() / 4);

        cout << "First and third quartiles:f " << endl;
        cout << q1 << " " << q3 << endl << endl;
        cout << "Range between quartiles:" << endl;
        cout << inter << endl << endl;
        cout << "Outliers: " << endl;
        cout << "Below: " << q1 - (1.5 * inter) << " Above: " << q3 + (1.5 * inter) << endl << endl;
        cout << "Extreme outliers: " << endl;
        cout << "Below: " << q1 - (3 * inter) << " Above: " << q3 + (3 * inter) << endl << endl;

    }
    else
    {
        //median = list.at(list.size()/2);
        median = (list.at((list.size()/2) - 1) + list.at(list.size()/2)) / 2;
        medianIndex1 = list.size()/2;
        medianIndex2 = list.size()/2 + 1;

        q1 = (list.at((medianIndex1/2) - 1) + list.at(medianIndex1/2)) / 2;

        q3 = (list.at(medianIndex2 + ((medianIndex1/2) - 2)) + list.at(medianIndex2 + (medianIndex1/2) - 1)) / 2;

        inter = q3 - q1;

        cout << "First and third quartiles: " << endl;
        cout << q1 << " " << q3 << endl << endl;
        cout << "Range between quartiles:" << endl;
        cout << inter << endl << endl;
        cout << "Outliers: " << endl;
        cout << "Below: " << q1 - (1.5 * inter) << " Above: " << q3 + (1.5 * inter) << endl << endl;
        cout << "Extreme outliers: " << endl;
        cout << "Below: " << q1 - (3 * inter) << " Above: " << q3 + (3 * inter) << endl << endl;

    }
}

int main()
{
    string input;
    vector<double> list;
    cout << "input data: ";
    getline(cin, input);
    istringstream iss(input);

    double temp;
    while (iss >> temp)
    {
        list.push_back(temp);
    }

    sort(list.begin(), list.end());

    cout << endl << "Here's the list you provided sorted from least to greatest:" << endl;

    PrintList(list);

    cout << endl<< "hi" << endl;
    cout << "1 for mean and median, respectively" << endl;
    cout << "2 for variance" << endl;
    cout << "3 to format for R" << endl;
    cout << "4 for quartiles" << endl;
    cout << "9 to enter a new set of data" << endl;
    cout << "0 to exit" << endl;
    
    int choice;
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
            case 1:
                meanMedian(list);
                break;
            case 2:
                calcVariance(list);
                break;
            case 3:
                format(list);
                cout << endl;
                break;
            case 4:
                interRange(list);
                break;
            case 9:
                list.clear();
                cout << "Elements left in the list: ";
                PrintList(list);
                cout << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "input new data: ";
                getline(cin, input);
                istringstream tempiss(input);
                while (tempiss >> temp)
                {
                    list.push_back(temp);
                }

                sort(list.begin(), list.end());

                cout << endl << "Here's the list you provided sorted from least to greatest:" << endl;

                PrintList(list);
                break;
        }

        cout << "wassup" << endl;
        cout << "1 for mean and median, respectively" << endl;
        cout << "2 for variance" << endl;
        cout << "3 to format for R" << endl;
        cout << "4 for quartiles" << endl;
        cout << "9 to enter a new set of data" << endl;
        cout << "0 to exit" << endl;
        cin >> choice;
    }

    cout << "exiting . . . " << endl;
    //PrintList(list, length);
}