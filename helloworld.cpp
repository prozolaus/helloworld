#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int val1 = 0;
    int val2 = 0;
    int min = 0;
    int max = 0;
    cout << "Enter first number: ";
    cin >> val1;
    cout << "Enter second number: ";
    cin >> val2;
    max = (val1 > val2) ? val1 : val2;
    min = (val1 < val2) ? val1 : val2;
    cout << "The largest number is " << max << endl;
    cout << "The smallest number is " << min << endl;
    cout << "The sum of these numbers is " << val1 + val2 << endl;
    cout << "The difference of these numbers is " << max - min << endl;
    cout << "The product of these numbers is " << val1 * val2 << endl;
    cout << "The division of these numbers is " << (double)max / min << endl;

    


}