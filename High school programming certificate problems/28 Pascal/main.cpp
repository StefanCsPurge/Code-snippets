#include <iostream>
#include <fstream>
using namespace std;

int n,a[20][20];
void pascal(int x)
{
    for(int i=0;i<=x;i++)
        a[i][0]=a[i][i]=1;
    for(int i=2;i<=x;i++)
        for(int j=1;j<i;j++)
        a[i][j]=a[i-1][j-1]+a[i-1][j];
}
void afish()
{
    ofstream fout("pascal.out");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
            fout<<a[i][j]<<" ";
        fout<<"\n";
    }
}
int main()
{
    cin>>n;
    pascal(n);
    afish();
    return 0;
}
