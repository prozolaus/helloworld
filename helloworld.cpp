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
  bool flag, flag2;
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
  str1 = "";
  while (true)
  {
    flag2 = true;
    cout << "Input name of person (NoName for exit): ";
    cin >> str1;
    if (str1 == "NoName")
      break;
    for (int i = 0; i < names.size(); i++) {
      if (str1 == names[i]) {
        cout << names[i] << " has " << scores[i] << " scores" << endl;
        flag2 = false;
        break;
      }
    }
    if (flag2) cout << "Error! Our base doesn't consist this name!" << endl;
  }
}