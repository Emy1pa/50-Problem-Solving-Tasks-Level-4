#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

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

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {
    31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29
        : 28) : NumberOfDays[Month - 1];
}

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day ==
        NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}



string ReadDateString(){
    string Date;
    cout << "Please enter Date dd/mm/yyyy? ";
    cin >> Date;
    return Date;
}

vector <string> SplitString(string S1, string Delim){
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) !=
        std::string::npos){
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}

sDate ConvertDataToStructure(string Text, string Seperator = "/") {
    sDate Date;
    vector <string> vString;

    vString = SplitString(Text, Seperator);
    Date.Day = stoi(vString[0]);
    Date.Month = stoi(vString[1]);
    Date.Year = stoi(vString[2]);

    return Date;
}

string ConvertDateToString(sDate Date, string Seperator = "/") {
    string TextRecord = "";
    TextRecord += to_string(Date.Day) + Seperator;
    TextRecord += to_string(Date.Month) + Seperator;
    TextRecord += to_string(Date.Year) ;
    return TextRecord;
}

enum enDateFormat {
    enDMY,
    enYDM,
    enMDY,
    enDashDMY,
    enDashMDY,
    enTextDMY,
};

void PrintDayFormat(string S1, enDateFormat DateFormat){
    sDate Date = ConvertDataToStructure(S1);
    switch (DateFormat)
    {
    case enDateFormat::enDMY: 
        cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
        break;
    case enDateFormat::enYDM:
        cout << Date.Year << "/" << Date.Day << "/" << Date.Month << endl;
        break;
    case enDateFormat::enMDY:
        cout << Date.Month << "/" << Date.Day << "/" << Date.Year << endl;
        break;
    case enDateFormat::enDashDMY:
        cout << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
        break;
    case enDateFormat::enDashMDY:
        cout << Date.Month << "-" << Date.Day << "-" << Date.Year << endl;
        break;
    case enDateFormat::enTextDMY:
        cout << "Date: " << Date.Day << ", Month: " << Date.Month << ", Year: " << Date.Year << endl;
        break;
   
    }
}

int main()
{
    string Text = ReadDateString();
    
    PrintDayFormat(Text, enDateFormat::enDMY);
    PrintDayFormat(Text, enDateFormat::enMDY);
    PrintDayFormat(Text, enDateFormat::enYDM);
    PrintDayFormat(Text, enDateFormat::enDashMDY);
    PrintDayFormat(Text, enDateFormat::enDashDMY);
    PrintDayFormat(Text, enDateFormat::enTextDMY);
    system("pause>0");

}
