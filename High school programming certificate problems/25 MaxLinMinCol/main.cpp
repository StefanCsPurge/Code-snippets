#include <fstream>
using namespace std;
ifstream fin("mat.in");
ofstream fout("mat.out");
int n,m,a[55][55],maxi[55],mini[55],ok;
void read()
{
    fin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        fin>>a[i][j];
}
void calcule()
{
    for(int i=0;i<n;i++)
        maxi[i]=-1000000000;
    for(int j=0;j<m;j++)
        mini[j]=1000000000;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if(a[i][j]>maxi[i])
            maxi[i]=a[i][j];
        if(a[i][j]<mini[j])
            mini[j]=a[i][j];
    }
}
void afish()
{
    ok=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if(a[i][j]==maxi[i] && a[i][j]==mini[j])
        {
            ok=1;
            fout<<a[i][j]<<"\n";
        }
    }
    if(!ok)
        fout<<"Nu exista.";
}
int main()
{
    read();
    calcule();
    afish();
    return 0;
}
