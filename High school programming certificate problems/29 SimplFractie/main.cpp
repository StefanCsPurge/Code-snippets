#include <iostream>

using namespace std;
struct fractie
{
    int x,y;
}f1,f2,s;
int cmmdc(int x,int y)
{
    while(y)
    {
        int r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    cin>>f1.x>>f1.y>>f2.x>>f2.y;
    s.x=f1.x*f2.y+f2.x*f1.y;
    s.y=f1.y*f2.y;
    int c=cmmdc(s.x,s.y);
    cout<<s.x/c<<" "<<s.y/c;
    return 0;
}
