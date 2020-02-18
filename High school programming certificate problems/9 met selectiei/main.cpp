#include <fstream>
using namespace std;
int a[55],n;
void read()
{
    ifstream fin("sort.in");
    fin>>n;
    for(int i=0; i<n; i++)
        fin>>a[i];
}
int pozMin(int p)
{
    int pmin=p;
    for(int i=p+1; i<n; i++)
        if(a[i]<a[pmin])
            pmin=i;
    return pmin;
}
void selectie()
{
    for(int i=0;i<n-1;i++)
    {
        int v=pozMin(i);
        int aux=a[i];
        a[i]=a[v];
        a[v]=aux;
    }
}
void afish()
{
    ofstream fout("sort.out");
    for(int i=0;i<n;i++)
        fout<<a[i]<<' ';
}
int main()
{
    read();
    selectie();
    afish();
    return 0;
}
