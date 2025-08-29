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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2){
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            (Date1.Month < Date2.Month ? true :
                (Date1.Month == Date2.Month ?
                    Date1.Day < Date2.Day : false))
            : false);
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2){
    return (Date1.Year == Date2.Year) ? ((
        Date1.Month == Date2.Month) ?
        ((Date1.Day == Date2.Day) ? true :
            false) : false) : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2) {
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enDateComparison DateComparison(sDate Date1, sDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateComparison::enBefore;
    else if (IsDate1AfterDate2(Date1, Date2))
        return enDateComparison::enAfter;
    else
        return enDateComparison::enEqual;
}

int main()
{

    
    sDate Date1, Date2;
    cout << "Enter Date1: \n";
    Date1 = ReadFullDate();
    cout << endl;

    cout << "Enter Date2: \n";
    Date2 = ReadFullDate();

    

    cout << "\nCompare Result = " << DateComparison(Date1, Date2) << endl;

    system("pause>0");

}
