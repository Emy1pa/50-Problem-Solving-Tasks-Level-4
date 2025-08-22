#include <iostream>
using namespace std;


int ReadYear() {
    int Year = 0;
    cout << "Please enter a year to check ? ";
    cin >> Year;
    return Year;
}

bool CheckIfLeapYear(int Year){
    if (Year % 400 == 0)
        return true;
    else if (Year % 4 == 0 && Year % 100 != 0)
        return true;
    else
        return false;
}

int main()
{
    int Year = ReadYear();
    if (CheckIfLeapYear(Year))
        cout << "Yes, it is a leap year \n";
    else
        cout << "No, it is not a leap year \n";
    
    system("pause>0");
}
