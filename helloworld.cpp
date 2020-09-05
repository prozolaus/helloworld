#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  vector<string> str = { "one","two","three","four","five","six","seven","eight","nine" };
  int number;
  string s;
  cin >> number;
  cout << str[number - 1] << endl;
  cin >> s;
  for (int i = 0; i < str.size(); i++)
  {
    if (s == str[i]) cout << i+1 << endl;
  }
}