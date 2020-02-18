#include <iostream>
using namespace std;
int radical(int n)
{
    int st=1,dr=n;
    while(st<=dr)
    {
        int m=(st+dr)/2;
        if(m*m==n)
            return m;
        if(m*m<n)
            st=m+1;
        else
            dr=m-1;
    }
    return dr;
}
int main()
{
    cout<<radical(5);
    return 0;
}
