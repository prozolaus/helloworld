#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

double num () {
  string s;
  vector<string> str = { "one","two","three","four","five","six","seven","eight","nine" };
  bool flag = false;
  double d = 0;
  cin >> s;
  for (int i = 0; i < str.size(); i++) {
    if (s==str[i]) {d = i+1; flag = true; break;}
  }
  if (!flag) d = stof(s);
  return d;
}

int main()
{
  double a = 0, b = 0, res = 0;
  char oper;
  string act;
  a = num();
  cin >> oper;
  b = num();
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