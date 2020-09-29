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
  cout << endl;
}

int main()
{
  srand(static_cast<unsigned int>(time(0)));
  set<int> st;
  vector<int> numbers, counts;
  const int n = 35;
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
    if (max==counts[i]) st.insert(numbers[i]);
  set<int> :: iterator it = st.begin();
  cout << "Moda: " ;
  for (; it != st.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}