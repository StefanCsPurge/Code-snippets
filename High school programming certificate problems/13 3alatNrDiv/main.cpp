#include <iostream>
#include <fstream>
using namespace std;
int n,a[55];
void read()
{
    ifstream fin("exista.in");
    fin>>n;
    for(int i=0; i<n; i++)
        fin>>a[i];
}
int nrDiv(int x)
{
    int d,nr=0;
    for(d=1;d*d<x;d++)
        if(x%d==0)
        nr+=2;
    if(d*d==x)
        nr++;
    return nr;
}
int verificare()
{
    if(n<3)
        return 0;
    int x1=nrDiv(a[0]),x2=nrDiv(a[1]),x3;
    for(int i=2;i<n;i++)
    {
        x3=nrDiv(a[i]);
        if(x1==x2 && x2==x3)
            return 1;
        x1=x2;
        x2=x3;
    }
    return 0;
}
int main()
{
    read();
    if(verificare())
        cout<<"da";
    else cout<<"nu";
    return 0;
}
