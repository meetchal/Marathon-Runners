//Mitchell Harrington

//This program uses data from a text file to output a table, using 1D and 2D arrays, with miles run for each day, mile averages for each day, and total miles run. 
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//constants to use for the array columns/elements.
const int columns = 7;
const int rows = 5;

//Function initialization
void getNamesMiles(string nameArray[], int rows, int milesArray[][columns], int columns);

void getSumAverage(string nameArray[], int rows, int milesArray[][7], int columns);

void printResult(string nameArray[], int rows, int milesArray[][7], int columns, double miles_avg[], int total_miles[]);


int main() 
{
  //String array for the names, and integer array for the miles.
  string nameArray[rows];
  int milesArray[rows][columns];
  getNamesMiles(nameArray, rows, milesArray, columns);
  getSumAverage(nameArray, rows, milesArray, columns);
}


//reads and inputs the text file's names into nameArray, and then inputs the number of miles into the milesArray.
void getNamesMiles(string nameArray[], int rows, int milesArray[][7], int columns)
{
  ifstream runnersTxt;
  
  //Counter for the index.
  int index = 0;
  runnersTxt.open("runners.txt");
  while (!runnersTxt.eof())
  {
    //Name into the array.
    runnersTxt >> nameArray[index];
    for (int i = 0; i < columns; i++)
    {
      //Inserts the mile elements into the milesArray one by one.
      runnersTxt >> milesArray[index][i];
    }
    index++;
  }
  runnersTxt.close();
}


//Function for calculating the sum and average of the miles.
void getSumAverage(string nameArray[], int rows, int milesArray[][7], int columns)
{
  //Another 1D array for the average miles.
  double miles_avg[columns];
  int total_miles[columns];

  //Reads the first element in the column, then it iterates through the rows in the same column, adding to the sum for each row. Continues until finished with all of the columns.
  for (int i = 0; i < columns; i++)
  {
    double sum = 0;
    for (int j = 0; j < rows; j++)
    {
      sum += milesArray[j][i];
    }
    //Total added.
    total_miles[i] = sum;
    //Divides sum by columns (7) to get the average for the days.
    miles_avg[i] = sum / columns;
  }
  printResult(nameArray, rows, milesArray, columns, miles_avg, total_miles);
}




//Function for printing out the table. 
void printResult(string nameArray[], int rows, int milesArray[][7], int columns, double miles_avg[], int total_miles[])
{
  cout << setw(18) << "Mon   " << "Tue   " << "Wed   " << "Thu   " << "Fri   " << "Sat   " << "Sun  " << endl;
  
  //Iterates and prints the names, then corresponding miles for each day next to the names.
  for (int i = 0; i < rows; i++)
  {
    cout << setw(11) << left << nameArray[i] << ' ';
    for (int j = 0; j < columns; j++)
    {
      cout << setw(3) << milesArray[i][j] << " | ";
    }
  cout << endl;
  } 
  
  //Averages.
  cout << "Averages    ";
  for (int i = 0; i < columns; i++)
  {
    cout << setw(3) << left << fixed << setprecision(0) << miles_avg[i] << " | ";
  }
  cout << endl << "Totals      ";
  //Total miles.
  for (int i = 0; i < columns; i++)
  {
    cout << setw(3) << left << fixed << setprecision(0) << total_miles[i] << " | ";
  }
  cout << endl;
}