#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string a, b, c, min1, min2, min3;
    cout << "Enter three words through space: ";
    cin >> a >> b >> c;
    min1 = (a < b) ? a : b;
    if (min1 > c) min1 = c;
    if (min1 == a) {
        if (b < c) {
            min2 = b;
            min3 = c;
        }
        else {
            min2 = c;
            min3 = b;
        }
    }
    else if (min1 == b) {
        if (a < c) {
            min2 = a;
            min3 = c;
        }
        else {
            min2 = c;
            min3 = a;
        }
    }
    else if (min1 == c) {
        if (a < b) {
            min2 = a;
            min3 = b;
        }
        else {
            min2 = b;
            min3 = a;
        }
    }
    cout << "The words are sorted: " << min1 << ' ' << min2 << ' ' << min3 << endl;
}