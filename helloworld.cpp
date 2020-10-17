#include "std_lib_facilities.h"

using namespace std;

bool IsNumber(const string &s) {
    return all_of(s.cbegin(),s.cend(),[](const char &c) {
        return isdigit(c);
    });
}

int main()
try {
    int n, sum = 0;
    string s;
    vector<int> v;
    cout << "Enter the number of values to add: ";
    cin >> n;
    cout << "Enter multiple integers (| to end input): ";
    for (;;)
    {
        cin >> s;
        if (s=="|") break;
        if (!IsNumber(s)) error("It is not a number!");
        v.push_back(stoi(s));
    }
    //if (n > v.size()) error("n is bigger than the size of the vector");
    for (int i = 0; i < n; i++)
        sum+=v[i];
    cout << "The sum of the first " << n << " numbers is " << sum << ".\n";
} catch (out_of_range) {
    cerr << "Error of the range!\n";
    return 1;
}