/*
Sean Warnock
CSCI 14 Summer 2018
Assignment 4 due 7/12/2018
https://github.com/seanwarnock/CSCI14-Assignment4.git

1) The logic should allow the user to enter as many
records as they wish, computer Gross Payu and Net Pay.
Write the data to the data file, Personel.dat.  Put a single
 blank between each data field to as as a default delimiter.

2) Retrieve each record.  Read a record and check for the EOF.  Since you really don't
know how many records are in the data file, use a while loop.
The loop will read the record at the end of the loop

3) Paginate the output information.

Be sure to format appropriate values as currency.  See if you can
format the hours as decimal with 1 decimal position (i.e. 40 hours
as 40.0 hours).  Use a While loop around the main logic to let the
user keep adding or reading instead of one pass through the entire
program logic.

*/
#include <time.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#ifdef _WIN32
  #include <winsock2.h>
  #include <windows.h>
#endif
#ifdef __linux__

#endif

using namespace std;

void WriteDataFile (string);

void ReadDataFile (string);

int main ()
{
  bool boolExitProgram = false;

  do
  {
    char charMenuChoice;

    system("cls");
    cout << "[1] Enter payroll information." << endl;
    cout << "[2] Display payroll information" << endl;
    cout << "[9] End program" << endl;

    cin >> charMenuChoice;

    switch  (charMenuChoice)
    {
      case '1' :
        cout << "Payroll";
        WriteDataFile("Personnl.Dat");
      break;

      case '2' :
        //cout << "Display";
        ReadDataFile("Personnl.Dat");
      break;

      case '9' :
        cout << "Exit time!";
        boolExitProgram = true;
      break;
    }
  } while (boolExitProgram != true);
  return 0;
}


void WriteDataFile (string FileName)
{
  string WriteFirstName;
  string WriteLastName;
  string WriteWorkerID;
  float WriteHours;
  float WritePayRate;
  float WriteTaxRate;

  ofstream outFile;
  outFile.open(FileName, ofstream::out | ofstream::app);

  if (!outFile)
  {
    cout << "File not found!";
    exit(666);
  }

  cout << "First Name : ";
  cin >> WriteFirstName;
  cout << endl << "Last Name : ";
  cin >> WriteLastName;
  cout << endl << "Worker ID : ";
  cin >> WriteWorkerID;
  cout << endl << "Hours : ";
  cin >> WriteHours;
  cout << endl << "Pay Rate : ";
  cin >> WritePayRate;
  cout << endl << "Tax Rate : ";
  cin >> WriteTaxRate;

  outFile << endl << WriteFirstName << " " << WriteLastName << " " << WriteWorkerID << " " << WriteHours << " " << WritePayRate << " " << WriteTaxRate;


  outFile.close();
  system("pause");
}

void ReadDataFile (string FileName)
{
//This function reads the text file and outputs the "records" in the requested format.

  string ReadFirstName;
  string ReadLastName;
  string ReadWorkerID;
  float ReadHours;
  float ReadPayRate;
  float ReadTaxRate;
  float GrossPay;
  float TotalTax;
  float NetPay;

  int counter = 0;

  ifstream inFile;

  inFile.open(FileName);

  system("cls");
  if (!inFile)
  {
    cout << "File not found!";
    exit(666);
  }

  while (!inFile.eof())
  {
  //Read each line.  Perform raw calculation on data read.  Finally output information to the screen.

    inFile >> ReadFirstName >> ReadLastName >> ReadWorkerID >> ReadHours >> ReadPayRate >> ReadTaxRate;

    GrossPay = (ReadHours * ReadPayRate);
    TotalTax = GrossPay * ReadTaxRate;
    NetPay = GrossPay - TotalTax;

    cout.unsetf(ios::floatfield);
    cout.precision(1);
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);

    cout << "\tRecord #" <<counter << endl;
    cout << "Employee ID: " << ReadWorkerID << endl;
    cout << "Last Name: " << ReadLastName << " First Name:" << ReadFirstName << endl;
    cout << "Hours Worked: " << ReadHours;
    cout.precision(2);
    cout << " Pay Per Hour: $" << ReadPayRate << " Gross Pay: $" << GrossPay << endl;
    cout << "Taxes: $" << TotalTax << " Net Pay: $" << NetPay << endl;
    cout << "Employee Tax Rate: " << ReadTaxRate << "%" << endl << endl;

    counter++;

    if ((counter % 4) == 0)
    {
      system("pause");
      system("cls");
    }
  }

  inFile.close();
  system("pause");
}
