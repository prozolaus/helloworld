#include "std_lib_facilities.h"

class Name_value
{
public:
    string names;
    double scores;
    Name_value(string n, double s)
        : names(n), scores(s) {}
};

Name_value get()
{
    string str1;
    char ch;
    cin >> str1 >> ch;
    switch (ch)
    {
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        cin.putback(ch);
        double d;
        cin >> d;
        return Name_value{str1, d};
    default:
        error("Wrong score!");
    }
}

int main()
{
    vector<Name_value> n;
    while (true)
    {
        Name_value t = get();
        if (t.names == "NoName" && t.scores == 0)
            break;
        for (int i = 0; i < n.size(); i++)
            if (t.names == n[i].names)
                error("Error! You have already inputted this name!");
        n.push_back(t);
    }
    for (int i = 0; i < n.size(); i++)
        cout << n[i].names << " has " << n[i].scores << " scores." << endl;
}