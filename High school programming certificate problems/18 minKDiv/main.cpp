#include <iostream>

using namespace std;
int nrDiv(int x)
{
    int d,nr=0;
    for(d=1; d*d<x; d++)
        if(x%d==0)
            nr+=2;
    if(d*d==x)
        nr++;
    return nr;
}
int main()
{
    int k;
    cin>>k;
    for(int i=1;;i++)
        if(nrDiv(i)==k)
    {
        cout<<i;
        return 0;
    }
    return 0;
}
