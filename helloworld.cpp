#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int cent1 = 0, cent5 = 0, cent10 = 0, cent25 = 0, cent50 = 0, sum = 0;
    cout << "How many one-cent coins do you have? ";
    cin >> cent1;
    cout << "How many five-cent coins do you have? ";
    cin >> cent5;
    cout << "How many ten-cent coins do you have? ";
    cin >> cent10;
    cout << "How many twenty five-cent coins do you have? ";
    cin >> cent25;
    cout << "How many fifty-cent coins do you have? ";
    cin >> cent50;
    cout << endl;
    if (cent1 > 0) {
        cout << "You have " << cent1 << " one-cent coin";
        if (cent1 > 1) cout << "s."; else cout << "."; cout << endl;
    }
    if (cent5 > 0) {
        cout << "You have " << cent5 << " five-cent coin";
        if (cent5 > 1) cout << "s."; else cout << "."; cout << endl;
    }
    if (cent10 > 0) {
        cout << "You have " << cent10 << " ten-cent coin";
        if (cent10 > 1) cout << "s."; else cout << "."; cout << endl;   
    }
    if (cent25 > 0) {
        cout << "You have " << cent25 << " twenty five-cent coin";
        if (cent25 > 1) cout << "s."; else cout << "."; cout << endl;
    }
    if (cent50 > 0) {
        cout << "You have " << cent50 << " fifty-cent coin";
        if (cent50 > 1) cout << "s."; else cout << "."; cout << endl;
    }
    sum = cent1 + cent5 * 5 + cent10 * 10 + cent25 * 25 + cent50 * 50;
    cout << "\nTotal value of your coins is " << sum/100 << " dollar";
    if ((sum/100)!=1) cout << "s "; else cout << " ";
    cout << sum%100 << " cents.\n\n";

}