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






bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year > Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            (Date1.Month > Date2.Month ? true :
                (Date1.Month == Date2.Month ?
                    Date1.Day > Date2.Day : false))
            : false);
}






int main()
{

    
    sDate Date1, Date2;
    cout << "Enter Date1: \n";
    Date1 = ReadFullDate();
    cout << endl;

    cout << "Enter Date2: \n";
    Date2 = ReadFullDate();

    if (IsDate1AfterDate2(Date1, Date2))
        cout << "\nYes, Date1 is After Date2.\n";
    else
        cout << "\nNon, Date1 is NOT After Date2.\n";



    system("pause>0");

}
