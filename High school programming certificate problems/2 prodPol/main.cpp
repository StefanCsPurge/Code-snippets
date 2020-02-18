#include <iostream>
#include <fstream>
using namespace std;
int a[100],b[100],n,m,p,q[100];
void read()
{
    ifstream fin("pol.in");
    fin>>n>>m;
    for(int i=0;i<=n;i++)
        fin>>a[i];
    for(int i=0;i<=m;i++)
        fin>>b[i];
}
void produs()
{
    p=n+m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        q[i+j]+=a[i]*b[j];
}
void afish()
{
    ofstream fout("pol.out");
    fout<<p<<"\n";
    for(int i=0;i<=p;i++)
        fout<<q[i]<<" ";
}
int main()
{
    read();
    produs();
    afish();
    return 0;
}
