#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    double a=0, min=0, max=0, sum=0;
    vector<double> v;
    int count = 0;
    string s="";
    while (cin>>a>>s)
    {
        if (a=='|') break;
        if (s=="cm") a/=100; // 1m = 100cm
        else if (s=="in") a=a*2.54/100; // 1ft = 12in
        else if (s=="ft") a=a*12*2.54/100; // 1 in = 2.54cm
        else if (s!="m") continue; 
        v.push_back(a);
        if (a < min) {
            min = a;
            cout<< min <<"m - the most smallest among inputted numbers."<<endl;
        }
        else if (a > max) {
            max = a;
            cout<< max <<"m - the most biggest among inputted numbers."<<endl;
        }
        count++;
        sum+=a;
    }
    sort(v.begin(),v.end());
    cout << "The all inputted and sorted numbers: " << endl;
    for (double x : v) cout << x << "m ";
    cout << "\nAmount of inputted numbers: "<< count << endl;
    cout << "The sum of inputted numbers: "<< sum << "m." << endl;
}