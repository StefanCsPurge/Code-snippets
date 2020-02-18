#include <fstream>

using namespace std;
ifstream fin("mat.in");
ofstream fout("mat.out");
int a[55][55],n,m,l,c;
void read()
{
    fin>>n>>m>>l>>c;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            fin>>a[i][j];
}
void stergere(int l,int c)
{
    for(int i=0; i<l; i++)
        for(int j=c+1; j<m; j++)
            a[i][j-1]=a[i][j];
    for(int i=l+1; i<n; i++)
        for(int j=c+1; j<m; j++)
            a[i-1][j-1]=a[i][j];
    for(int i=l+1; i<n; i++)
        for(int j=0; j<c; j++)
            a[i-1][j]=a[i][j];
    n--;
    m--;
}
void afish()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            fout<<a[i][j]<<' ';
        fout<<"\n";
    }
}
int main()
{
    read();
    stergere(l-1,c-1);
    afish();
    return 0;
}
