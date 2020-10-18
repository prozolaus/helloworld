#include "std_lib_facilities.h"

using namespace std;

bool is_double(const std::string& s)
{
    std::istringstream iss(s);
    double d;
    return iss >> d >> std::ws && iss.eof();
}

class isnt_double {};

int main()
try {
    int n;
    double sum = 0;
    string s;
    vector<double> v, dif;
    cout << "Enter the number of values to add: ";
    cin >> n;
    cout << "Enter multiple real numbers (| to end input): ";
    for (;;)
    {
        cin >> s;
        if (s=="|") break;
        if (!is_double(s)) throw isnt_double();
        v.push_back(stod(s));
    }
    for (int i = 0; i < n; i++)
        sum+=v[i];
    cout << "The sum of the first " << n << " numbers is " << sum << ".\n";
    for (int i = 0; i < n-1; i++)
        dif.push_back(v[i+1]-v[i]);
    if (n>1) cout << "The difference between elements of the vector: ";
    for (double x : dif)
        cout << x << " ";
    cout << endl;
} catch (out_of_range) {
    cerr << "Error of the range!\n";
    return 1;
} catch (isnt_double) {
    cerr << "Input was wrong!\n";
    return 2;
} catch (...) {
    cerr << "Something went wrong!\n";
    return 3;
}