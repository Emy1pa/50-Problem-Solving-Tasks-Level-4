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

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {
    31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29
        : 28) : NumberOfDays[Month - 1];
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

bool IsFirstDayInMonth(sDate Date)
{
    return (Date.Day == 1);
}

bool IsFirstMonthInYear(short Month)
{
    return (Month == 1);
}

sDate DecreaseDateByOneDay(sDate Date)
{
    if (IsFirstDayInMonth(Date))
    {
        if (IsFirstMonthInYear(Date.Month))
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else
        {
            Date.Month -= 1;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

sDate DecraseDateByXDays(sDate Date, short xDays){
    for (int i = 1; i <= xDays; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date){
    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDayByXWeeks(sDate Date, short xWeeks){
    for (int i = 0; i < xWeeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}
sDate DecreaseDayByOneMonth(sDate Date){
    if (Date.Month == 1) {
        Date.Month = 12;
        Date.Year--;
    }
    else {
        Date.Month--;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

sDate DecreaseDayByXMonths(sDate Date, short xMonths){
    for (int i = 1; i <= xMonths; i++)
    {
        Date = DecreaseDayByOneMonth(Date);
    }
    return Date;
}
sDate DecreasingDateByOneYear(sDate Date){
    Date.Year--;
    return Date;
}
sDate DecreaseDateByXYears(sDate Date, short xYears) {
    for (int i = 1; i <= xYears; i++)
    {
        Date = DecreasingDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXYearsFaster(sDate Date, short xYears) {
    Date.Year -= xYears;
    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date) {
    Date.Year -= 10;
    return Date;
}

sDate DecreaseDateByXDecades(sDate Date, short xDecades) {
    for (int i = 1; i <= xDecades; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}

sDate DecreaseDateByXDecadesFaster(sDate Date, short xDecades) {
    Date.Year -= xDecades * 10;
    return Date;
}

sDate DecreaseDateByOneCentury(sDate Date) {
    Date.Year -= 100;
    return Date;
}
sDate DecreaseDateByOneMillennium(sDate Date) {
    Date.Year -= 1000;
    return Date;
}




int main()
{

    sDate Date = ReadFullDate();
    cout << endl;

    cout << "Date After: " << endl;

    Date = DecreaseDateByOneDay(Date);
    cout << "\n01- Substracting one Day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecraseDateByXDays(Date, 10);
    cout << "\n02- Substracting 10 Days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneWeek(Date);
    cout << "\n03- Substracting one Week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDayByXWeeks(Date, 10);
    cout << "\n04- Substracting 10 Weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDayByOneMonth(Date);
    cout << "\n05- Substracting one Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDayByXMonths(Date, 5);
    cout << "\n06- Substracting 5 Months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreasingDateByOneYear(Date);
    cout << "\n07- Substracting one Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXYears(Date, 10);
    cout << "\n08- Substracting 10 Years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "\n09- Substracting 10 Years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneDecade(Date);
    cout << "\n10- Substracting one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "\n11- Substracting 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "\n12- Substracting 10 Decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneCentury(Date);
    cout << "\n13- Substracting one Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneMillennium(Date);
    cout << "\n14- Substracting one Millenium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0");
}
