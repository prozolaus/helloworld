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
  int n, p;
  vector<int> numbers, primes;
  cout << "Input number of prime numbers: ";
  cin >> p;
  n = p*10;
  cout << endl;
  for (int i = 0; i < n; i++)
    numbers.push_back(i);
  numbers[1] = 0;
  for (int i = 2; i < n; i++)
    if (numbers[i]!=0)
      for (int j = i*2; j < n; j+=i)
        numbers[j] = 0;
  for (int i = 0, j = 0; i < n && j < p; i++)
    if (numbers[i]!=0) {
      primes.push_back(i);
      j++;
    }
  cout << p << " prime numbers from 2 to " << primes[p-1] << ": \n";
  print_vector(primes);
}