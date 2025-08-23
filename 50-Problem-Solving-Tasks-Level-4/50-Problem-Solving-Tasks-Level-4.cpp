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

bool IsLeapYear(short Year){
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short CalculateDaysOfMonth(short Month, short Year){
    if (Month < 1 || Month > 12)
        return 0;
    short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short DayOfWeekOrder(short Day, short Month, short Year) {
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}


void DisplayMonth(short Month, short Year){
    string arrMonthNames[12] = { "Jan","Feb","Mar","Apr","Mai","Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    cout << "\n\t\t------------------------ " << arrMonthNames[Month - 1] << " ------------------------\n\n";

    short DaysOfMonth = CalculateDaysOfMonth(Month, Year);
    string arrDayNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    cout << "\t\t";

    for (int i = 0; i < 7; i++)
    {
        cout << arrDayNames[i] << "\t";
    }
    cout << "\n\t\t";

    short FirstDay = DayOfWeekOrder(1, Month, Year);

    for (int i = 0; i < FirstDay; i++)
        cout << "\t";
    
    for (int Day = 1; Day <= DaysOfMonth; Day++)
    {
        cout << Day << "\t";

        if ((FirstDay + Day) % 7 == 0) 
            cout << "\n\t\t";
    }
    cout << "\n\t\t-----------------------------------------------------\n";
    
}




int main()
{
    short Year = ReadYear();
    cout << endl;
    short Month = ReadMonth();
    cout << endl;
    
    DisplayMonth(Month, Year);
   

    system("pause>0");
}
