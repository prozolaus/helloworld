#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <set>

using namespace std;

void print_vector(vector<int> a) {
  for (int i = 0; i < a.size(); i++) 
    cout << a[i] << " ";
  cout << endl << endl;
}

int main()
{
  srand(static_cast<unsigned int>(time(0)));
  vector<int> numbers, counts, maxs;
  const int n = 10;
  int count, max = 0;
  for (int i = 0; i < n; i++) numbers.push_back(rand()%10);
  print_vector(numbers);
  for (int i = 0; i < n; i++)
  {
    count = 0;
    for (int j = 0; j < n; j++)
      if (numbers[j]==numbers[i]) 
        count++;
    counts.push_back(count);
    if (count > max) 
      max = count;
  }
  //print_vector(counts);
  for (int i = 0; i < n; i++)
    if (max==counts[i]) {
      bool flag = false;
      for (int j = 0; j < maxs.size(); j++)
      {
        if (numbers[i]==maxs[j]) flag = true;
      }
      if (!flag) maxs.push_back(numbers[i]);
    }
  cout << "Moda: " ;
  print_vector(maxs);
  //cout << endl;
}