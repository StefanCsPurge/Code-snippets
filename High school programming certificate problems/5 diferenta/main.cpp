#include <fstream>

using namespace std;
int n,m,a[55],b[55],c[110],p;
void read()
{
    ifstream fin("mult.in");
    fin>>n>>m;
    for(int i=0;i<n;i++)
        fin>>a[i];
    for(int i=0;i<m;i++)
        fin>>b[i];
}
int caut(int x,int a[],int n)
{
    for(int i=0;i<n;i++)
        if(a[i]==x)
        return 1;
    return 0;
}
void diferenta()
{
    p=0;
    for(int i=0;i<n;i++)
        if(!caut(a[i],b,m))
        c[p++]=a[i];
}
void afish()
{
    ofstream fout("mult.out");
    for(int i=0;i<p;i++)
        fout<<c[i]<<" ";
}
int main()
{
    read();
    diferenta();
    afish();
    return 0;
}
