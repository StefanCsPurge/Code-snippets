#include <fstream>
using namespace std;
int n,a[55];
void read()
{
    ifstream fin("cmmdc.in");
    fin>>n;
    for(int i=0; i<n; i++)
        fin>>a[i];
}
int cmmdc(int x,int y)
{
    while(y)
    {
        int r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int cmmmdc_sir()
{
    int c=0;
    for(int i=0;i<n;i++)
        c=cmmdc(c,a[i]);
    return c;
}
int main()
{
    read();
    ofstream fout("cmmdc.out");
    fout<<cmmmdc_sir();
    return 0;
}
