#include "std_lib_facilities.h"

using namespace std;

bool IsNumber(const string &s) {
    return all_of(s.cbegin(),s.cend(),[](const char &c) {
        return isdigit(c);
    });
}

int main()
{
    vector<int> mon, tue, wed, thu, fri, sat, sun;
    string str;
    char i[256];
    int count = 0, mon_sum = 0, tue_sum = 0, wed_sum = 0, thu_sum = 0, fri_sum = 0, sat_sum = 0, sun_sum = 0;
    while (cin >> str)
    {
        if (str=="Monday"||str=="Mon"||str=="monday"||str=="mon") {
            cin >> i;
            if (IsNumber(i)) mon.push_back(atoi(i));
            else count++;
        }
        else if (str=="Tuesday"||str=="Tue"||str=="tuesday"||str=="tue") {
            cin >> i;
            if (IsNumber(i)) tue.push_back(atoi(i));
            else count++;
        }
        else if (str=="Wednesday"||str=="Wed"||str=="wednesday"||str=="wed") {
            cin >> i;
            if (IsNumber(i)) wed.push_back(atoi(i));
            else count++;
        }
        else if (str=="Thursday"||str=="Thu"||str=="thursday"||str=="thu") {
            cin >> i;
            if (IsNumber(i)) thu.push_back(atoi(i));
            else count++;
        }
        else if (str=="Friday"||str=="Fri"||str=="friday"||str=="fri") {
            cin >> i;
            if (IsNumber(i)) fri.push_back(atoi(i));
            else count++;
        }
        else if (str=="Saturday"||str=="Sat"||str=="saturday"||str=="sat") {
            cin >> i;
            if (IsNumber(i)) sat.push_back(atoi(i));
            else count++;
        }
        else if (str=="Sunday"||str=="Sun"||str=="sunday"||str=="sun") {
            cin >> i;
            if (IsNumber(i)) sun.push_back(atoi(i));
            else count++;
        }
        else cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int i = 0; i < mon.size(); i++) {cout << mon[i] << " "; mon_sum += mon[i];}
    if (mon.size() > 0) cout << "- Monday, sum: " << mon_sum << endl;

    for (int i = 0; i < tue.size(); i++) {cout << tue[i] << " "; tue_sum += tue[i];}
    if (tue.size() > 0) cout << "- Tuesday, sum: " << tue_sum << endl;

    for (int i = 0; i < wed.size(); i++) {cout << wed[i] << " "; wed_sum += wed[i];}
    if (wed.size() > 0) cout << "- Wednesday, sum: " << wed_sum << endl;

    for (int i = 0; i < thu.size(); i++) {cout << thu[i] << " "; thu_sum += thu[i];}
    if (thu.size() > 0) cout << "- Thursday, sum: " << thu_sum << endl;

    for (int i = 0; i < fri.size(); i++) {cout << fri[i] << " "; fri_sum += fri[i];}
    if (fri.size() > 0) cout << "- Friday, sum: " << fri_sum << endl;

    for (int i = 0; i < sat.size(); i++) {cout << sat[i] << " "; sat_sum += sat[i];}
    if (sat.size() > 0) cout << "- Saturday, sum: " << sat_sum << endl;

    for (int i = 0; i < sun.size(); i++) {cout << sun[i] << " "; sun_sum += sun[i];}
    if (sun.size() > 0) cout << "- Sunday, sum: " << sun_sum << endl;

    cout << "Counting incorrect entry of values: " << count << endl;
    cout << "Done!" << endl;
    
}