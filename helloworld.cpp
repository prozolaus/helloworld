#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    double a,b,c=1.0/100;
    while (cin>>a>>b)
    {
        if (a=='|') break;
        cout<<"a = "<<a<<"; b = "<<b<<".\n";
        if (a==b) cout<<"The numbers are equal.\n";
        else if (a+c==b||a-c==b) cout<<"The numbers are almost equal.\n";
        else {
            cout<<"The smallest number: "<<((a<b)?a:b)<<"."<<endl;
            cout<<"The biggest number: "<<((a>b)?a:b)<<"."<<endl;
        }
    }
}