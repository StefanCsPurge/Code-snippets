#include <fstream>
using namespace std;
int a[100],b[100],c[200],n,m,p;
void read()
{
    ifstream fin("sort.in");
    fin>>n>>m;
    for(int i=0;i<n;i++)
        fin>>a[i];
    for(int i=0;i<m;i++)
        fin>>b[i];
}
void interclasare()
{
    int i,j; 
    p=0;
    for(i=0,j=0;i<n && j<m;)
        if(a[i]<b[j])
        c[p++]=a[i++];
    else
        c[p++]=b[j++];
    for(;i<n;i++)
        c[p++]=a[i];
    for(;j<m;j++)
        c[p++]=b[j];
}
void afish()
{
    ofstream fout("sort.out");
    for(int i=0;i<p;i++)
        fout<<c[i]<<" ";
}
int main()
{
    read();
    interclasare();
    afish();
    return 0;
}
