#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
   double a = 0, b = 0, res = 0;
  char oper;
  string act;
  cin >> a;
  cin >> oper;
  cin >> b;
  switch (oper)
  {
  case '+':
    res = a + b;
    act = "Sum";
    break;
  case '-':
    res = a - b;
    act = "Difference";
    break;
  case '*':
    res = a * b;
    act = "Multiplication";
    break;
  case '/':
    res = a / b;
    act = "Division";
    break;
  default:
    cout << "Incorrect operation!\n";
    break;
  }
  cout << act << " of " << a << " and " << b << " is " << res << endl;
}