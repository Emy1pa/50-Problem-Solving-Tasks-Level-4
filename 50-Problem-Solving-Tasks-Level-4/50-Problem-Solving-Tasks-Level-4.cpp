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
    
    int Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (CheckIfLeapYear(Year) ? 29 : 28) :
        Days[Month - 1];
}






int main()
{
    short Year = ReadYear();
    cout << endl;

    short Month = ReadMonth();

    cout << "\nNumber of Days in Month [" << Month << "] is "
        << NumberOfDaysInAMonth(Year, Month);

   
    
    system("pause>0");
}
