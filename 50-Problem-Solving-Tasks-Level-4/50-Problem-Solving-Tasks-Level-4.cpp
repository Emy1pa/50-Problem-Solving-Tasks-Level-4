#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>

using namespace std;

enum enDateComparison {
    enBefore = -1,
    enEqual = 0,
    enAfter = 1
};

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

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(sDate Date1, sDate
    Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    return enDateCompare::After;
}
bool checkForOverlapPeriod(stPeriod Period1, stPeriod Period2){
    if (
        CompareDates(Period2.EndDate,
            Period1.StartDate) == enDateCompare::Before
        ||
        CompareDates(Period2.StartDate,
            Period1.EndDate) == enDateCompare::After
        )
        return false;
    else
        return true;
}





int main()
{

    
    stPeriod Period1, Period2;
   

    cout << "Enter Period 1: \n";
    cout << "Enter Start Date: \n\n";

    Period1.StartDate = ReadFullDate();

    cout << "\nEnter End Date: \n\n";

    Period1.EndDate = ReadFullDate();

    cout << "\nEnter Period 2: \n";
    cout << "Enter Start Date: \n\n";

    Period2.StartDate = ReadFullDate();

    cout << "\nEnter End Date: \n\n";

    Period2.EndDate = ReadFullDate();

    if (checkForOverlapPeriod(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods do not Overlap\n";
    system("pause>0");

}
