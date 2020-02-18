#include <iostream>

using namespace std;
int a[100],n;
int cautBp(int x)
{
    int st=0,dr=n-1;
    while(st<=dr)
    {
        int mij=(st+dr)/2;
        //if(a[mij]==x) return mij;
        if(a[mij]>x)
            dr=mij-1;
        else if(a[mij]<=x) //cea mai din dreapta poz in caz ca se repeta
            st=mij+1;
    }
    return st;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<cautBp(5)+1;
    return 0;
}
