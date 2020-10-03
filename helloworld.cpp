#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <set>
#include <cmath>

using namespace std;

int main()
{
  double a = 1, b = -2, c = -3, d, x1, x2;
  if (a==-1) cout << "-";
  else if (a!=1) cout << a;
  cout << "x2";
  if (b==-1) cout << "-";
  else if (b<-1) cout << b;
  else if (b!=1) cout << "+" << b;
  else if (b==1) cout << "+";
  cout << "x";
  if (c >= 0) cout << "+" << c;
  else cout << c;
  cout << " = 0" << endl;
  d = pow(b,2) - 4*a*c;
  cout << "D = " << d << endl;
  if (d < 0) cout << "No roots!" << endl;
  else if (d==0) {
    x1 = (-b - sqrt(d))/(2*a);
    cout << "The root of equation is " << x1 << endl;
  }
  else {
    x1 = (-b - sqrt(d))/(2*a);
    x2 = (-b + sqrt(d))/(2*a);
    cout << "The roots of equation are " << x1 << " and " << x2 << endl;
  }

}