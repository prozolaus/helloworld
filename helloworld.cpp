#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp (int a,int b) { return (a>b); }

int main()
{
    vector<int> v = {1,2,5,66,54,3,21};
    //cout << v.size() << endl;
    for (int x : v) cout << x << " ";
    cout << endl;
    sort(v.begin(), v.end(), comp);
    for (int x : v) cout << x << " ";
    cout << endl;
    
    

    

}