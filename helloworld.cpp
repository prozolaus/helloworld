#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <set>

using namespace std;

void print_vector(vector<string> a) {
  for (int i = 0; i < a.size(); i++) 
    cout << a[i] << " ";
  cout << endl << endl;
}

void print_vector(vector<int> a) {
  for (int i = 0; i < a.size(); i++) 
    cout << a[i] << " ";
  cout << endl << endl;
}

int main()
{
  vector<string> strings = {"you", "they", "we", "they", "me", "she", "you", "me", "you"}, maxs;
  vector<int> counts;
  int n = strings.size();
  int count, max = 0;
  print_vector(strings);
  for (int i = 0; i < n; i++)
  {
    count = 0;
    for (int j = 0; j < n; j++)
      if (strings[j]==strings[i]) 
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
        if (strings[i]==maxs[j]) flag = true;
      if (!flag) maxs.push_back(strings[i]);
    }
  cout << "Moda: " ;
  print_vector(maxs);
  //cout << endl;
}