#include <iostream>
using namespace std;

struct stYearInfo {
    short Days = 0;
    short Hours = 0;
    int Minutes = 0;
    int Seconds = 0;
};



int ReadYear() {
    int Year = 0;
    cout << "Please enter a year to check ? ";
    cin >> Year;
    return Year;
}


bool CheckIfLeapYear(int Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
       
}

stYearInfo YearInfo(int Year) {
    stYearInfo YearInfo;
    YearInfo.Days = CheckIfLeapYear(Year) ? 366 : 365;
    YearInfo.Hours = YearInfo.Days * 24;
    YearInfo.Minutes = YearInfo.Hours * 60;
    YearInfo.Seconds = YearInfo.Minutes * 60;
    return YearInfo;
}

void PrintResult(stYearInfo YearInfo, int Year){
    
    cout << "Number of Days in Year [" << Year << "] is " << YearInfo.Days << endl;
    cout << "Number of Hours in Year [" << Year << "] is " << YearInfo.Hours << endl;
    cout << "Number of Minutes in Year [" << Year << "] is " << YearInfo.Minutes << endl;
    cout << "Number of Seconds in Year [" << Year << "] is " << YearInfo.Seconds << endl;
}

int main()
{
    int Year = ReadYear();
    PrintResult(YearInfo(Year), Year);
    
    system("pause>0");
}
