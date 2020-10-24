#include "std_lib_facilities.h"

using namespace std;

int main() 
{
    int i = 0, c = 0;
    const int max_i = 44;
    double a = 1, b = 1;
    cout << a << " " << b << " ";
    while (i < max_i)
    {
        c = narrow_cast<int>(b + a);
        cout << c << " ";
        a = b;
        b = c;
        i++;
    }
    cout << "\nMax int that may contain this sequence is " << c << endl;
    
}