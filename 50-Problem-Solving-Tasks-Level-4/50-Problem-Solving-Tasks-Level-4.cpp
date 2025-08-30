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

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((
        Date1.Month == Date2.Month) ?
        ((Date1.Day == Date2.Day) ? true :
            false) : false) : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2)
        && !IsDate1EqualDate2(Date1, Date2));
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

//short CalculatePeriodLength(stPeriod Period, bool IncludeEndDay= false){
//    int Days = 0;
//
//    while (IsDate1BeforeDate2(Period.StartDate, Period.EndDate)) {
//        Days++;
//        Period.StartDate = IncreaseDateByOneDay(Period.StartDate);
//    }
//    return IncludeEndDay ? ++Days : Days;
//}

void SwapDates(sDate& Date1, sDate& Date2)
{
    sDate TempDate;
    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;
    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;
    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short SwapFlagValue = 1;
    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

int CalculatePeriodLength(stPeriod Period, bool IncludeEndDate = false){
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}

bool CheckIfDateWithinPeriod(stPeriod Period, sDate Date){
    return (!IsDate1BeforeDate2(Date, Period.StartDate)&& !IsDate1AfterDate2(Date, Period.EndDate));
}

int main()
{

    
    stPeriod Period1;

    sDate Date;
   
    cout << "Enter Period 1: \n";
    cout << "Enter Start Date: \n\n";

    Period1.StartDate = ReadFullDate();

    cout << "\nEnter End Date: \n\n";

    Period1.EndDate = ReadFullDate();

    cout << "\n\nEnter Date to check: \n\n";

    Date = ReadFullDate();

    if (CheckIfDateWithinPeriod(Period1, Date))
        cout << "\nYes, Date is within period\n";
    else
        cout << "\nNon, Date is not within period \n";

    system("pause>0");

}
