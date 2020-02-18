#include <iostream>
#include <fstream>
using namespace std;
int a[55][55],n;
void read()
{
    ifstream f("mat.in");
    f>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            f>>a[i][j];
}
int verif_magic()
{
    long long s=0,v=0;
    for(int i=0; i<n; i++)
    {
        s+=a[i][i];
        v+=a[i][n-1-i];
    }
    if(s!=v) return 0;
    v=0;
    long long v2=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            v+=a[i][j];
            v2+=a[j][i];
        }
        if(v!=s || v2!=s)
            return 0;
        v=0;
        v2=0;
    }
    return 1;
}
int main()
{
    read();
    if(verif_magic())
        cout<<"da";
    else cout<<"nu";
    return 0;
}
