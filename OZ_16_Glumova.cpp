#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date {
    int day;
    string month;
    int year;
};

string ConvertDay(const int& day) {
    string ansDay;
    if (day < 10) {
       ansDay = "0" + to_string(day);
    }
    else {
        ansDay = to_string(day);
    }
    return ansDay;
}
string NumMonth(const string& month) {
    vector<string> months = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    string ansMonth;
    for (int i = 0; i < 12; ++i) {
        
        if (months[i] == month) {
            if (i + 1 < 10) {
                ansMonth = "0" + to_string(i+1);
            }
            else {
                ansMonth = to_string(i+1);
            }
            return ansMonth;
        }
    }
    return "00";
}

int main() {
    string dateStr = "1 January 2024";
    int day;
    string month;
    int year;
    int spaceCount = 0;
    string temp = "";
    for (char ch : dateStr) {
        if (ch == ' ') {
            if (spaceCount == 0) {
                day = stoi(temp);
            }
            else if (spaceCount == 1) {
                month = temp;
            }
            temp = "";
            spaceCount++;
        }
        else {
            temp += ch;
        }
    }
    year = stoi(temp);
    Date DATA = { day, month, year };
    
    string ansDay = ConvertDay(DATA.day);
    string ansMoth =NumMonth(DATA.month);
    string ansYear = to_string(DATA.year);

    string result = ansYear + ":" + ansMoth + ":" + ansDay;
    cout << result << endl;

    return 0;
}