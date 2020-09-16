#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
  double number = 1, cells = 1;
  cout << setprecision(16);
  cout << cells << " cell, " << number << " grain of rice \n";
  while(cells<64) {
    number*=2;
    cells++;
    cout << cells << " cells, " << number << " grains of rice \n";
  }
}