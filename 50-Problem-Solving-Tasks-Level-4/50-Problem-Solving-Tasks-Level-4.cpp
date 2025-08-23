#include <iostream>
using namespace std;



short ReadYear() {
    short Year = 0;
    cout << "Please enter a year to check ? ";
    cin >> Year;
    return Year;
}

short ReadMonth() {
    short Month = 0;
    cout << "Please enter a month to check ? ";
    cin >> Month;
    return Month;
}


short ReadDay() {
    short Day = 0;
    cout << "Please enter a day to check ? ";
    cin >> Day;
    return Day;
}

bool IsLeapYear(short Year){
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}






int CalculateNumberOfDaysFromBeginningOfTheYear(short Year, short Month, short Day){
    short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    short sum = 0;
    IsLeapYear(Year) ? NumberOfDays[1] = 29 : NumberOfDays[1] = 28;
    int Rest = 0;
    for (int i = 0; i < Month - 1; i++)
       
        sum += NumberOfDays[i];
    sum += Day;
    return sum;
}




int main()
{
    short Year = ReadYear();
    cout << endl;

    short Month = ReadMonth();
    cout << endl;

    short Day = ReadDay();
    cout << endl;
    
    cout << "Number of Days from the beginning of the year is " << CalculateNumberOfDaysFromBeginningOfTheYear(Year, Month, Day) << endl;

    system("pause>0");
}
