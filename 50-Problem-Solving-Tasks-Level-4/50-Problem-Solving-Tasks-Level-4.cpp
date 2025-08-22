#include <iostream>
using namespace std;

//enum enMonthOfYear {January = 1, February = 2, March = 3, April = 4,
//Mai = 5, June = 6, July = 7, August = 8,
//September = 9, October = 10, November = 11,
//December = 12};


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


bool CheckIfLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
       
}

int NumberOfDaysInAMonth(short Year, short Month) {
    if (Month < 1 || Month > 12)
        return 0;
    if (Month == 2)
        return CheckIfLeapYear(Year) ? 29 : 28;
    short arr31Days[12] = { 1, 3, 5, 7, 8, 10, 12 };
    for (short i = 1; i <= 12; i++)
    {
        if (arr31Days[i - 1] == Month)
            return 31;
    }
    return 30;
}

int NumberOfHoursInAMonth(short Year, short Month) {
    return NumberOfDaysInAMonth(Year, Month) * 24;
}

int NumberOfMinutesInAMonth(short Year, short Month) {
    return NumberOfHoursInAMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month) {
    return NumberOfMinutesInAMonth(Year, Month) * 60;
}




int main()
{
    short Year = ReadYear();
    cout << endl;

    short Month = ReadMonth();

    cout << "\nNumber of Days in Month [" << Month << "] is "
        << NumberOfDaysInAMonth(Year, Month);

    cout << "\nNumber of Hours in Month [" << Month << "] is "
        << NumberOfHoursInAMonth(Year, Month);

    cout << "\nNumber of Minutes in Month [" << Month << "] is "
        << NumberOfMinutesInAMonth(Year, Month);

    cout << "\nNumber of Seconds in Month [" << Month << "] is "
        << NumberOfSecondsInAMonth(Year, Month);
    
    system("pause>0");
}
