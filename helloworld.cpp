#include "std_lib_facilities.h"

using namespace std;

double fact(double x)
{
    if (!x) return 1;
    double sum = x;
    for (double i = x-1; i > 1; i--)
        sum *= i;
    return sum;
}

int main() 
{
    double a, b, p, c;
    int i, j;
    cout << "Input two integers separated by a space: ";
    cin >> a >> b;
    j = (int)b;
    i = (int)a;
    if (a-i || b-j) error("The first and second numbers must be integers!");
    if (a<1 || b<1) error("The integers must be more than zero!");
    if (a>100) error("The range must be from 1 to 100!");
    if (a<b) error("The second integer mustn't be more than first!");
    p = fact(a) / fact(a-b);
    c = p / fact(b);
    cout << "P(" << a << "," << b << ") = " << p << endl;
    cout << "C(" << a << "," << b << ") = " << c << endl;
}