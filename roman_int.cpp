#include "roman_int.h"

Roman_int::Roman_int()
{
    fill_romans();
    number = 0;
}

Roman_int::Roman_int(string s)
{
    fill_romans();
    if (s.empty())
        error("Empty string");
    str_to_int(s);
}

void Roman_int::fill_units(string str, int a)
{
    for (int j = a, i = 0; i < units.size(); j++, i++)
        romans[j] = str + units[i];
}

void Roman_int::fill_romans()
{
    for (int i = 0; i < roman_size; i += 9)
    {
        int temp = i / 10;
        int temp2 = i / 100;
        int temp3 = i / 1000;
        string str;
        romans[i] = thousands[temp3];
        romans[i] += hundreds[temp2 % 10];
        romans[i] += dozens[temp % 10];
        str = romans[i];
        ++i;
        fill_units(str, i);
    }
}

void Roman_int::str_to_int(string s)
{
    for (int i = 1; i < roman_size; i++)
        if (s == romans[i])
        {
            number = i;
            roman = s;
            return;
        }
    error("Wrong input of roman number!");
}

istream &Roman_int::operator>>(istream &is)
{
    string s;
    is >> s;
    is.exceptions(is.exceptions() | ios_base::badbit);
    if (is.eof())
        error("No input!");
    str_to_int(s);
    return is;
}

ostream &operator<<(ostream &os, Roman_int &r)
{
    if (r.as_int() == 0)
        error("Roman number wasn't inputed!");
    return os << r.as_roman();
}
/*
int main()
{
    //Roman_int r, 
    //cout << "Enter a roman number: ";
    //r.operator>>(cin);
    //cout << "Roman " << r << " is " << r.as_int() << endl;
    Roman_int rom{"MMMCMXCIX"};
    cout << "Roman " << rom << " is " << rom.as_int() << endl;
}
*/