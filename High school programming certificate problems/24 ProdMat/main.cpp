#include <fstream>
using namespace std;
ofstream fout("mat.out");
int a[55][55],b[55][55],p[55][55],n1,n2,m1,m2;
void read(int a[55][55],int &n,int &m,char nume[10])
{
    ifstream fin(nume);
    fin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            fin>>a[i][j];
}
void produs()
{
    for(int i=0; i<n1; i++)
        for(int j=0; j<m2; j++)
            for(int k=0; k<m1; k++)
                p[i][j]+=a[i][k]*b[k][j];
}
void afish()
{
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<m2; j++)
            fout<<p[i][j]<<' ';
        fout<<"\n";
    }
}
int main()
{
    read(a,n1,m1,"mat1.in");
    read(b,n2,m2,"mat2.in");
    if(m1!=n2)
        fout<<"imposibil";
    else
    {
        produs();
        afish();
    }
    return 0;
}
