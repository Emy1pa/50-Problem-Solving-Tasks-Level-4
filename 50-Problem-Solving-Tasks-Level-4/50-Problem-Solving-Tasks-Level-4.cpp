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

sDate IncreaseDateByXDays(sDate Date, short xDays){
    for (int i = 1; i <= xDays; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date; 
}

sDate IncreaseDateByOneWeek(sDate Date){
    for (int i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByXWeeks(sDate Date, short xWeeks){
    for (short i = 1; i <= xWeeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate IncreaseDateByOneMonth(sDate Date) {
    if (Date.Month == 12) {
        Date.Month = 1;
        Date.Year++;
    }
    else {
        Date.Month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

sDate IncreaseDateByXMonths(sDate Date, short xMonths) {
    for (int i = 1; i <= xMonths; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}



sDate IncreaseDateByOneYear(sDate Date){
    Date.Year += 1;
    return Date;
}

sDate IncreaseDateByXYears(sDate Date, short xYears) {
    for (int i = 1; i <= xYears; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
sDate IncreaseDateByXYearsFaster(sDate Date, short xYears) {
    Date.Year += xYears;
    return Date;
}

sDate IncreaseDateByOneDecade(sDate Date){
    Date.Year += 10;
    return Date;
}

sDate IncreaseDateByXDecades(sDate Date, short xDecades) {
    for (int i = 1; i <= xDecades; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}

sDate IncreaseDateByXDecacesFaster(sDate Date, short xDecades){
    Date.Year += (xDecades * 10);
    return Date;
}

sDate IncreaseDateByOneCentury(sDate Date) {
    Date.Year += 100;
    return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date) {
    Date.Year += 1000;
    return Date;
}



int main()
{



    sDate Date = ReadFullDate();
    cout << endl;

    cout << "Date After: " << endl;

    Date = IncreaseDateByOneDay(Date);

    cout << "\n01- Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDays(Date, 10);

    cout << "02- Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneWeek(Date);
    cout << "03- Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXWeeks(Date, 10);
    cout << "04- Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMonth(Date);
    cout << "05- Adding 1 month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXMonths(Date, 5);
    cout << "06- Adding 5 month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneYear(Date);
    cout << "07- Adding 1 year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYears(Date, 10);
    cout << "08- Adding 10 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYearsFaster(Date, 10);
    cout << "09- Adding 10 years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneDecade(Date);
    cout << "10- Adding one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecades(Date, 10);
    cout << "11- Adding 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecacesFaster(Date, 10);
    cout << "12- Adding 10 Decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneCentury(Date);
    cout << "13- Adding One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "14- Adding One Millenium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    system("pause>0");
}
