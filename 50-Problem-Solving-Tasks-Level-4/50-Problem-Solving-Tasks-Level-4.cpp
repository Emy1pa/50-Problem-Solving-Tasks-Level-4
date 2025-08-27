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

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}


sDate IncreaseDateByOne(sDate Date){
    if (IsLastDayInMonth(Date)) {
         Date.Day = 1;
         if (IsLastMonthInYear(Date.Month)) {
             Date.Month = 1;
             Date.Year++;
         }
         else 
             Date.Month++;
    }
    else
        Date.Day++;


    return Date;
}





int main()
{
   
    
    
    sDate Date1 = ReadFullDate();
    cout << endl;
    
    Date1 = IncreaseDateByOne(Date1);

    cout << "Date after adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    
    
    system("pause>0");
}
