#include <iostream>
#include <fstream>
using namespace std;
ifstream f("matrice.in");
int a[100][100],n,m;
void read(int i,int j)
{
    if(i==n) return;
    if(j==m)
    {
        read(i+1,0);
        return;
    }
    f>>a[i][j];
    read(i,j+1);
}
void afish(int i,int j)
{
    if(i==n) return;
    if(j==m)
    {
        cout<<endl;
        afish(i+1,0);
        return;
    }
    cout<<a[i][j]<<" ";
    afish(i,j+1);
}

///Suma elementelor din matrice:
int sumamat(int i,int j)
{
    if(i==n) return 0;
    if(j==m)
        return sumamat(i+1,0);
    return a[i][j]+sumamat(i,j+1);
}

///Produsul elementelor din matrice divizibile cu 5
int produsulmat(int i,int j, int &ok)
{
    if(i==n) return 1;
    if(j==m) return produsulmat(i+1,0,ok);
    if(a[i][j]%5==0)
    {
        ok=1;
        return a[i][j]*produsulmat(i,j+1,ok);
    }
    return produsulmat(i,j+1,ok);
}

///Maximul din matrice
int maxMat(int i,int j,int maxi)
{
    if(i==n) return maxi;
    if(j==m) return maxMat(i+1,0,maxi);
    if(a[i][j]>maxi)
        return maxMat(i,j+1,a[i][j]);
    return maxMat(i,j+1,maxi);
}

///Inlocuire diagonala secundara cu 0
void diag_sec(int i)
{
    if(i==n) return;
    a[i][n-1-i]=0;
    diag_sec(i+1);
}

///Suma elementelor din triunghiul din N
int StriunghiN(int i,int j)
{
    if(i==(n-1)/2) return 0;
    if(j==n-i-1) return StriunghiN(i+1,i+2);
    return a[i][j]+StriunghiN(i,j+1);
}

int main()
{
    f>>n>>m;
    read(0,0);
    afish(0,0);
    cout<<sumamat(0,0)<<endl;
    int ok=0,p=produsulmat(0,0,ok);
    if(ok) cout<<p<<endl;
    else cout<<"nu exista elemente div cu 5 in matrice"<<endl;
    cout<<maxMat(0,0,-100000000)<<endl<<endl;
    afish(0,0);
    cout<<endl;
    ///Transformare in matrice patratica:
    m=n;
    diag_sec(0);
    afish(0,0);
    cout<<StriunghiN(0,1);
    return 0;
}
