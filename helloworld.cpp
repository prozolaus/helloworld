#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
  const int number = 100;
  vector<int> primes;
  bool flag;
  for (int i = 2; i < number; i++)
  {
    flag = false;
    for (int j = 2; j < i; j++)
      if (i%j==0) flag = true;
    if (!flag) primes.push_back(i);
  }
  for (int x : primes)
    cout << x << " ";
  cout << endl;
  
}