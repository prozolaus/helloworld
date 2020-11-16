#include "std_lib_facilities.h"

using namespace std;

void check(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            error("It is not a number!");
    }
    if (s.size() > 4)
        error("The number of digits is more than 4.");
}

void units(string s)
{
    cout << s[0] << " - units.";
}

void tens(string s)
{
    cout << s[0] << " - tens, ";
    string temp_s(s.begin()+1, s.end());
    units(temp_s);
}

void hundreds(string s)
{
    cout << s[0] << " - hundreds, ";
    string temp_s(s.begin()+1, s.end());
    tens(temp_s);
}

void thousands(string s)
{
    cout << s[0] << " - thousands, ";
    string temp_s(s.begin()+1, s.end());
    hundreds(temp_s);
}

int main()
{
    int num;
    while (cin)
    {
        string s, s2;
        cin >> s;
        check(s);
        num = stoi(s);
        s2 = to_string(num);
        if (s2.size() == 4)
            thousands(s2);
        else if (s2.size() == 3)
            hundreds(s2);
        else if (s2.size() == 2)
            tens(s2);
        else
            units(s2);
        cout << endl;
    }
}
