#include <iostream>
#include <fstream>
using namespace std;
int prim(int x)
{
    if(x<2||(x>2 && x%2==0))
        return 0;
    for(int d=3;d*d<=x;d+=2)
        if(x%d==0)
        return 0;
    return 1;
}
void afish(int n)
{
    ofstream fout("prietene.out");
    if(n<4)
    {
        fout<<"nu exista perechi";
        return;
    }
    fout<<"(2 3)"<<',';
    int v1=1,v2;
    for(int i=5;i<n;i+=2)
    {
        v2=prim(i);
        if(v1&&v2)
            fout<<"("<<i-2<<' '<<i<<")"<<',';
        v1=v2;
    }
}
int main()
{
    int n;
    cin>>n;
    afish(n);
    return 0;
}
