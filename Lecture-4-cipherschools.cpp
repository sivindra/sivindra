#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter integers"<<endl;
    int a,b,c,d;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cout<<(a>b && c>d)<<endl;
    cout<<(a>b || c>d);
}
