#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;

void print_vector(vector<int> a) {
  for (int i = 0; i < a.size(); i++) 
    cout << a[i] << " ";
  cout << endl << endl;
}

int main()
{
  int n = 100;
  vector<int> numbers, primes;
  cout << "Input max number: ";
  cin >> n;
  cout << endl;
  for (int i = 0; i < n; i++)
    numbers.push_back(i);
  numbers[1] = 0;
  for (int i = 2; i < n; i++)
    if (numbers[i]!=0)
      for (int j = i*2; j < n; j+=i)
        numbers[j] = 0;
  for (int i = 0; i < n; i++)
    if (numbers[i]!=0) primes.push_back(i);
  print_vector(primes);
}