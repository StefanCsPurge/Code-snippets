#include <iostream>
#include <fstream>
using namespace std;
int n,a[55][55];
void read()
{
    ifstream f("mat.in");
    f>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        f>>a[i][j];
}
int nrCif(int x)
{
    int nr=0;
    do
    {
        nr++;
        x/=10;
    }while(x);
    return nr;
}
int numarareSDP()
{
    int nr=0;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
        if(nrCif(a[i][j])%2==0)
        nr++;
    return nr;
}
int main()
{
    read();
    cout<<numarareSDP();
    return 0;
}
