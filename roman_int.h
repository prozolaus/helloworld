#include "std_lib_facilities.h"

const int roman_size = 4000;

class Roman_int
{
public:
    Roman_int();
    Roman_int(string s);
    string as_roman() { return roman; }
    int as_int() { return number; }
    istream &operator>>(istream &is);

private:
    int number;
    string roman;
    vector<string> units{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    vector<string> dozens{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> hundreds{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> thousands{"", "M", "MM", "MMM"};
    vector<string> romans{roman_size};
    void fill_romans();
    void fill_units(string doz, int a);
    void str_to_int(string s);
};