#include "std_lib_facilities.h"

vector<string> articles = {"a", "an", "the", "A", "An", "The"};
vector<string> nouns = {"C++", "birds", "bird"};
vector<string> verbs = {"fly", "flies", "rule", "rules"};
vector<string> unions = {"but", "and", "or"};

bool articles_check()
{
    string s;
    cin >> s;
    for (int i = 0; i < articles.size(); i++)
        if (s == articles[i])
            return true;
    return false;
}

bool nouns_check()
{
    string s;
    cin >> s;
    for (int i = 0; i < nouns.size(); i++)
        if (s == nouns[i])
            return true;
    return false;
}

bool verbs_check()
{
    string s;
    cin >> s;
    for (int i = 0; i < verbs.size(); i++)
        if (s == verbs[i])
            return true;
    return false;
}

bool unions_check()
{
    string s;
    cin >> s;
    for (int i = 0; i < unions.size(); i++)
        if (s == unions[i])
            return true;
    return false;
}

bool dot_check()
{
    if (cin.get() == '\n')
        return false;
    char s;
    cin >> s;
    if (s == '.')
        return true;
    return false;
}

int main()
{
    bool a = true, b = true, c = true, u = false, dot = false;
    while (cin)
    {
        for (int i = 0; i < 2; i++)
        {
            a = articles_check();
            if (a)
            {
                b = nouns_check();
                if (b)
                {
                    c = verbs_check();
                    if (c)
                    {
                        if (i == 0)
                        {
                            u = unions_check();
                            if (!u)
                                break;
                        }
                        else
                            dot = dot_check();
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else
                break;
        }
        if (!a || !b || !c || !u || !dot)
            cout << "No!" << endl;
        else
            cout << "Yes!" << endl;
        cin.ignore(cin.rdbuf()->in_avail());
    }
}