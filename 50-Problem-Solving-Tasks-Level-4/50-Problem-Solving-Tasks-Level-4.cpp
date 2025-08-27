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


bool CheckIfDate1IsEqualToDate2(sDate Date1, sDate Date2){
    bool Result = ((Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true: false): false):false);
    return Result;
}


int main()
{
   
    
    
    sDate Date1 = ReadFullDate();
    cout << endl;
    sDate Date2 = ReadFullDate();
    

    if (CheckIfDate1IsEqualToDate2(Date1, Date2))
        cout << "\nYes, Date1 is equal to Date2.";
    else
        cout << "\nNo, Date1 is not equal to Date2";
    
    
    
    system("pause>0");
}
