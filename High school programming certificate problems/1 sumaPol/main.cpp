#include <iostream>
#include <fstream>
using namespace std;
int a[100],b[100],n,m,p,s[100];
void read()
{
    ifstream fin("pol.in");
    fin>>n>>m;
    for(int i=0;i<=n;i++)
        fin>>a[i];
    for(int i=0;i<=m;i++)
        fin>>b[i];
}
void suma()
{
    p=(n>m)?n:m;  //if (n>m) p=n else p=m;
    for(int i=0;i<=p;i++)
        s[i]=a[i]+b[i];
    while(p>0 && s[p]==0)
        p--;
}
void afish()
{
    ofstream fout("pol.out");
    fout<<p<<"\n";
    for(int i=0;i<=p;i++)
        fout<<s[i]<<" ";
}
int main()
{
    read();
    suma();
    afish();
    return 0;
}
