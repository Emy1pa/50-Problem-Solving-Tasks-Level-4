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


bool CheckIfDate1IsLessThanDate2(sDate Date1, sDate Date2){
    bool Result = (Date1.Year < Date2.Year) ? true : (Date1.Year > Date2.Year) ? false :
        (Date1.Month < Date2.Month) ? true : (Date1.Month > Date2.Month) ? false :
        (Date1.Day < Date2.Day) ? true : false;
    return Result;
}


int main()
{
   
    
    
    sDate Date1 = ReadFullDate();
    cout << endl;
    sDate Date2 = ReadFullDate();
    

    if (CheckIfDate1IsLessThanDate2(Date1, Date2))
        cout << "\nYes, Date1 is less than Date2.";
    else
        cout << "\nNo, Date1 is not less than Date2";
    
    
    
    system("pause>0");
}
