#include <fstream>
using namespace std;
struct elemP
{
 int x,prim;
}a[55];
int n;
int prim(int x)
{
    if(x<2||(x>2 && x%2==0))
        return 0;
    for(int d=3; d*d<=x; d+=2)
        if(x%d==0)
            return 0;
    return 1;
}
void read()
{
    ifstream fin("sort.in");
    fin>>n;
    for(int i=0; i<n; i++)
        {
            fin>>a[i].x;
            a[i].prim=prim(a[i].x);
        }
}
void sort_prime()
{
    for(int i=0; i<n-1; i++)
        if(a[i].prim)
        for(int j=i+1; j<n; j++)
            if(a[j].prim && a[i].x>a[j].x)
            {
                elemP aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
}
void afish()
{
    ofstream fout("sort.out");
    for(int i=0; i<n; i++)
        fout<<a[i].x<<" ";
}
int main()
{
    read();
    sort_prime();
    afish();
    return 0;
}
