#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>

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

struct stPeriod {
    sDate StartDate;
    sDate EndDate;
};

sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            (Date1.Month < Date2.Month ? true :
                (Date1.Month == Date2.Month ?
                    Date1.Day < Date2.Day : false))
            : false);
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
    return (Date.Day ==
        NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

short CalculatePeriodLength(stPeriod Period, bool IncludeEndDay= false){
    int Days = 0;

    while (IsDate1BeforeDate2(Period.StartDate, Period.EndDate)) {
        Days++;
        Period.StartDate = IncreaseDateByOneDay(Period.StartDate);
    }
    return IncludeEndDay ? ++Days : Days;
}



int main()
{

    
    stPeriod Period1;
   

    cout << "Enter Period 1: \n";
    cout << "Enter Start Date: \n\n";

    Period1.StartDate = ReadFullDate();

    cout << "\nEnter End Date: \n\n";

    Period1.EndDate = ReadFullDate();

    cout << "\n\nPeriod Length is: " << CalculatePeriodLength(Period1) << endl;
    cout << "Period Length (Including End Date) is: " << CalculatePeriodLength(Period1, true) << endl;

    
    system("pause>0");

}
