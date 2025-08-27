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

struct sDate {
    short Year;
    short Month;
    short Day;
};

sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) ||
        (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {
    31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29
        : 28) : NumberOfDays[Month - 1];
}

bool CheckIfLastMonthInYear(sDate Date){
    return Date.Month == 12;
}

bool CheckIfLastDayInMonth(sDate Date) {
    return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
}





int main()
{
   
    
    
    sDate Date1 = ReadFullDate();
    cout << endl;
    
    
    if (CheckIfLastDayInMonth(Date1))
        cout << "\nYes, Day is Last In Month\n";
    else
        cout << "\No, Day is not Last In Month\n";
    
    
    if (CheckIfLastMonthInYear(Date1))
        cout << "\nYes, Month is Last In Year\n";
    else
        cout << "\nNo, Month is NOT Last In Year\n";
    
    system("pause>0");
}
