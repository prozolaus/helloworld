#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
   int x = 51, m = 1, n = 101, i = 1, count = 0;
    bool flag = false;
    double d = 0;
    char a = ' ';
    cout << "Загадайте число від 1 до 100.\n\n";
    while ((n - m) > 3 && count < 5)
    {
        cout << "Чи Ваше число менше, ніж " << x << "?\n";
        cin >> a;
        if (a == 'y') n = x;
        else if (a == 'n') m = x;
        else continue;
        d = (m + n) / 2.0;
        if ((m + n) % 2 == 1) {
            if (!flag) { x = (int)d; flag = true; }
            else { x = (int)d + 1; flag = false; }
        }
        else x = (int)d;
        count++;
    }
    for (a = 'n'; a == 'n'; i++)
    {
        if (i == 3) break;
        cout << "Ваше число " << m + i << "?\n";
        cin >> a;
        if (a == 'y') x = m + i;
    }
    if (a == 'n') x = m;
    cout << "Чудово! Значить, Ви задумали число " << x << ".\n";
}