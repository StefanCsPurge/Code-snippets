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
void numarare()
{
    int b[55],nr;
    for(int i=0; i<n; i++)
    {
        nr=0;
        for(int j=0; j<i; j++)
            if(a[j]<=a[i])
                nr++;
        for(int j=i+1; j<n; j++)
            if(a[j]<a[i])
                nr++;
        b[nr]=a[i];
    }
    for(int i=0; i<n; i++)
        a[i]=b[i];
}
void afish()
{
    ofstream fout("sort.out");
    for(int i=0; i<n; i++)
        fout<<a[i]<<' ';
}
int main()
{
    read();
    numarare();
    afish();
    return 0;
}
