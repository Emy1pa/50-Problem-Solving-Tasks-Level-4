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
    short sum = 0;
    for (int i = 1; i <= Month - 1; i++)
       
        sum += NumberOfDaysInAMonth(i, Year);
    sum += Day;
    return sum;
}

void ConvertTotalDaysToDate(short TotalDays, short Year){
    short Rest = TotalDays;
    int CurrentMonth = 1;
    
    while (true) {
        short DaysInMonth = NumberOfDaysInAMonth(CurrentMonth, Year);

        if (Rest <= DaysInMonth) {
            cout << Rest << "/" << CurrentMonth << "/" << Year << endl;
            break;
        }
        else {
            Rest -= DaysInMonth;
            CurrentMonth++;
        }
    }
}




int main()
{
    short Year = ReadYear();
    cout << endl;

    short Month = ReadMonth();
    cout << endl;

    short Day = ReadDay();
    cout << endl;
    

    short TotalDays = CalculateNumberOfDaysFromBeginningOfTheYear(Year, Month, Day);
    cout << "Number of Days from the beginning of the year is " << TotalDays << endl;

    cout << "\nDate for [" << TotalDays << "] is: ";
    ConvertTotalDaysToDate(TotalDays, Year);

    system("pause>0");
}
