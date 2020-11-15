#include "std_lib_facilities.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    constexpr int size = 4;
    vector<char> comp(size);
    for (int i = 0; i < size; i++)
    {
        comp[i] = rand() % 26 + 97;
        for (int j = 0; j < i; j++)
        {
            if (comp[i] == comp[j])
            {
                i--;
                break;
            }
        }
    }
    int bulls, cows;
    vector<char> user(size);
    char k;
    do
    {
        bulls = 0, cows = 0;
        for (int i = 0; i < size; i++)
        {
            cin >> k;
            if (k < 'a' || k > 'z') {
                error("Wrong input!");
            }
            else user[i] = k;
        }
        for (int i = 0; i < size; i++)
        {
            if (user[i] == comp[i])
                bulls++;
            else
            {
                for (int j = 0; j < size; j++)
                {
                    if (j == i)
                        continue;
                    if (user[j] == comp[i])
                        cows++;
                }
            }
        }
        cout << "bulls: " << bulls << ", cows: " << cows << endl << endl;
    } while (bulls != size);
    for (char x : comp)
        cout << x;
    cout << endl;
}