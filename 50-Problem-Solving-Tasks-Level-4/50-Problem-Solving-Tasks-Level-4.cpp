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

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc.
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(sDate Date){
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder){
    string arrDayNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return arrDayNames[DayOfWeekOrder];
}

bool IsWeekEnd(sDate Date){
    return DayOfWeekOrder(Date) == 5 || DayOfWeekOrder(Date) == 6;
}


short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {
    31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 :
        28) : NumberOfDays[Month - 1];
}

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            (Date1.Month < Date2.Month ? true :
                (Date1.Month == Date2.Month ?
                    Date1.Day < Date2.Day : false))
            : false);
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        if (!IsWeekEnd(Date1)) {
                Days++;
        }
                Date1 = IncreaseDateByOneDay(Date1);
    }
        
    return IncludeEndDay ? ++Days : Days;
}





int main()
{

    cout << "Vacation Starts: \n";
    sDate Date1 = ReadFullDate();
    cout << endl;

    cout << "Vacation Ends: \n";
    sDate Date2 = ReadFullDate();
    cout << endl;

    short OrderOfDay1InWeek = DayOfWeekOrder(Date1);
    short OrderOfDay2InWeek = DayOfWeekOrder(Date2);

    cout << "Vacation From: " << DayShortName(OrderOfDay1InWeek) << " , " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    cout << "Vacation To: " << DayShortName(OrderOfDay2InWeek) << " , " << Date2.Day << "/" << Date2.Month << "/" << Date2.Year << endl;

    cout << "Actual Vacation Days is: " << GetDifferenceInDays(Date1, Date2) << endl;
    

    system("pause>0");

}
