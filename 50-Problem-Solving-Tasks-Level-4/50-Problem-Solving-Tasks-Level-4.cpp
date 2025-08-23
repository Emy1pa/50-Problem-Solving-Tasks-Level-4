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

string DayShortName(short
    DayOfWeekOrder)
{
    string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
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

string MonthShortName(short MonthNumber){
    string Months[12] = { "Jan", "Feb", "Mar",
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec" };

    return (Months[MonthNumber - 1]);
}

void DisplayMonth(short Month, short Year){

    int NumberOfDays;

    int Current = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = CalculateDaysOfMonth(Month, Year);

    printf("\n _______________%s__________________\n\n",
        MonthShortName(Month).c_str());

    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    int i;
    for (i = 0; i < Current; i++)
        printf("    ");
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%4d", j);
        if (++i == 7) {
            i = 0;
            printf("\n");
        }
    }
    printf("\n ____________________________________\n");


}

void DisplayYearCalendar(short Year){
    printf("\n ____________________________________\n\n");
    printf("            Calendar - %d       ", Year);
    printf("\n ____________________________________\n");

    for (int i = 1; i <= 12; i++)
    {
        DisplayMonth(i, Year);
    }

}




int main()
{
    short Year = ReadYear();
    cout << endl;
    
    
    DisplayYearCalendar(Year);

    system("pause>0");
}
