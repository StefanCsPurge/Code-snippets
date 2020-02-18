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
int verifDDS()
{
    int p=a[0][0]%2;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
        if(a[i][j]%2!=p)
        return 0;
    return 1;
}
int main()
{
    read();
    if(verifDDS())
        cout<<"Da";
    else cout<<"Nu";
    return 0;
}
