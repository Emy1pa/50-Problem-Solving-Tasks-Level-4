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

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {
    31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short CalculateNumberOfDaysFromBeginningOfTheYear(short Year, short Month, short Day){
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++)
        TotalDays += NumberOfDaysInAMonth(i, Year);
    TotalDays += Day;
    return TotalDays;
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

short DaysToAdd() {
    short DaysToAdd = 0;
    cout << "How many days to add ? ";
    cin >> DaysToAdd;
    return DaysToAdd;
}

sDate DateAddDays(short Days, sDate Date)
{
    short RemainingDays = Days +
        CalculateNumberOfDaysFromBeginningOfTheYear(Date.Year, Date.Month,
            Date.Day);
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}





int main()
{
   
    
    
    sDate Date = ReadFullDate();
    short Days = DaysToAdd();

    Date = DateAddDays(Days, Date);
    

    cout << "\nDate after adding [" << Days << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    
    system("pause>0");
}
