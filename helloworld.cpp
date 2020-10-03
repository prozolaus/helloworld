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
  string str1, str2;
  vector<string> names, scores;
  bool flag;
  while (str1 != "NoName" && str2 != "0")
  {
    flag = false;
    cin >> str1;
    cin >> str2;
    for (int i = 0; i < names.size(); i++)
      if (str1 == names[i])
      {
        cout << "Error! You have already inputted this name!" << endl;
        flag = true;
        break;
      }
    if (!flag && str1 != "NoName" && str2 != "0")
    {
      names.push_back(str1);
      scores.push_back(str2);
    }
  }
  for (int i = 0; i < names.size(); i++)
    cout << names[i] << ": " << scores[i] << " scores" << endl;
}