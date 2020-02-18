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
int prim(int x)
{
    if(x<2||x>2 && x%2==0)
        return 0;
    for(int d=3; d*d<=x; d+=2)
        if(x%d==0)
            return 0;
    return 1;
}
int sumaDDP()
{
    int s=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        if(prim(a[i][j]))
        s+=a[i][j];
    return s;
}
int main()
{
    read();
    cout<<sumaDDP();
    return 0;
}
