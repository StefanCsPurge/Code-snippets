#include <fstream>
using namespace std;
int n,a[55];
void read()
{
    ifstream fin("sort.in");
    fin>>n;
    for(int i=0;i<n;i++)
        fin>>a[i];
}
void insertie_sort()
{
    for(int i=1;i<n;i++)
    {
        int j=i-1,aux=a[i];
        for(j=i-1;j>=0 && aux<a[j];j--)
            a[j+1]=a[j];
        a[j+1]=aux;
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
    insertie_sort();
    afish();
    return 0;
}
