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
int sCif(int x)
{
    int s=0;
    while(x)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}
int verifSDS()
{
    for(int i=1;i<n;i++)
        for(int j=n-i;j<n;j++)
        if(sCif(a[i][j])%2==0)
        return 1;
    return 0;
}
int main()
{
    read();
    if(verifSDS())
        cout<<"Da";
    else cout<<"Nu";
    return 0;
}
