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

bool IsEndOfWeek(sDate Date){
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(sDate Date){
    return DayOfWeekOrder(Date) == 5 || DayOfWeekOrder(Date) == 6;
}
bool IsBuisnessDay(sDate Date){
    return !(IsWeekEnd(Date));
}

short DaysUntilTheEndOfWeek(sDate Date){
    return 6 - DayOfWeekOrder(Date);
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

//short DaysUntilTheEndOfMonth(sDate Date, bool IncludeEndDay = false) {
//    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Day);
//    short Days = NumberOfDaysInCurrentMonth - Date.Day;
//    return IncludeEndDay ? ++Days : Days;
//}

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
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

short DaysUntilTheEndOfMonth(sDate Date){
    sDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(sDate Date) {
    short DaysUntilEndOfMonth = DaysUntilTheEndOfMonth(Date);
    short Days = 0;
    for (short Month = 12; Month > Date.Month; Month--)
    {
        Days += NumberOfDaysInAMonth(Month, Date.Year);
    }
    Days += DaysUntilEndOfMonth;
    return Days;
}




int main()
{

    sDate Date = ReadFullDate();
    cout << endl;

    short OrderOfDayInWeek = DayOfWeekOrder(Date);

    cout << "Today is " << DayShortName(OrderOfDayInWeek) << " , " << Date.Day  << "/" << Date.Month << "/" << Date.Year << endl;
    
    cout << "\nIs it End of Week ?\n";
    if (IsEndOfWeek(Date))
        cout << "Yes, it is the end of week \n";
    else
        cout << "No, it is not the end of the week \n";

    cout << "\nIs it Weekend ?\n";
    if (IsWeekEnd(Date))
        cout << "Yes, it is a week end.\n";
    else
        cout << "No, it is not a week end.\n";

    cout << "\n Is it Business Day ?\n";
    if (IsBuisnessDay(Date))
        cout << "Yes, it is a buisness day.\n";
    else
        cout << "No, it is NOT a buisness day.\n";

    cout << "\nDays until end of week: " << DaysUntilTheEndOfWeek(Date) << " Day(s).\n";
    cout << "Days until end of month: " << DaysUntilTheEndOfMonth(Date) << " Day(s).\n";
    cout << "Days until end of year: " << DaysUntilTheEndOfYear(Date) << " Day(s).\n";
    system("pause>0");

}
