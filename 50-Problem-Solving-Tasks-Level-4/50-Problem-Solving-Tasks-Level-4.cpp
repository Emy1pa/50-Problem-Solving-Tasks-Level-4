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

short ReadDay() {
    short Day = 0;
    cout << "Please enter a day to check ? ";
    cin >> Day;
    return Day;
}


short DayOrder(short Year, short Month, short Day){
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + 12 * a - 2;
    short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return d;
}

string PrintDayOfWeek(short Day){
    switch (Day)
    {
    case 0:
        return "Sunday";
        break;
    case 1:
        return "Monday";
        break;
    case 2:
        return "Tuesday";
        break;
    case 3:
        return "Wednesday";
        break;
    case 4:
        return "Thursday";
        break;
    case 5:
        return "Friday";
        break;
    case 6:
        return "Saturday";
        break;
    }
}






int main()
{
    short Year = ReadYear();
    cout << endl;
    short Month = ReadMonth();
    cout << endl;
    short Day = ReadDay();

    short OrderDay = DayOrder(Year, Month, Day);
    cout << endl;
    cout << "Date          : " << Day << "/" << Month << "/" << Year << endl;
    
    cout << "Day Order     : " << OrderDay << endl;
    
    cout << "Day Name      : " << PrintDayOfWeek(OrderDay) << endl;

    system("pause>0");
}
