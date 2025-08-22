#include <iostream>
using namespace std;


int ReadYear() {
    int Year = 0;
    cout << "Please enter a year to check ? ";
    cin >> Year;
    return Year;
}


bool CheckIfLeapYear(int Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
       
}

int main()
{
    int Year = ReadYear();
    if (CheckIfLeapYear(Year))
        cout << "\nYes, Year [" << Year << "] it is a leap year \n";
    else
        cout << "\nNo, Year [" << Year << "] it is not a leap year \n";

    system("pause>0");
}
