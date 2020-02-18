#include <fstream>

using namespace std;
ifstream fin("mat.in");
ofstream fout("mat.out");
struct element
{
    int x,nrd;
}a[55][55];
int n,m;
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
void read()
{
    fin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        fin>>a[i][j].x;
        a[i][j].nrd=nrDiv(a[i][j].x);
    }
}
void afish()
{
    int maxi=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(a[i][j].nrd>maxi)
        maxi=a[i][j].nrd;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(maxi==a[i][j].nrd)
        fout<<a[i][j].x<<"\n";
}
int main()
{
    read();
    afish();
    return 0;
}
