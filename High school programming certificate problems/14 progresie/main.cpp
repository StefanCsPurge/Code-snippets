#include <fstream>
using namespace std;
int a[100],n;
void read()
{
    ifstream fin("progresie.in");
    fin>>n;
    for(int i=0; i<n; i++)
        fin>>a[i];
}
int pAritm()
{
    if(n<3)
        return 0;
    for(int i=1; i<n-1; i++)
        if(2*a[i]!=a[i-1]+a[i+1])
            return 0;
    return (a[1]-a[0]);
}
float pGeom()
{
    if(n<3 || a[0]==0)
        return 1;
    for(int i=1; i<n-1; i++)
        if(a[i]*a[i]!=a[i-1]*a[i+1])
            return 1;
    return (float)a[1]/a[0];
}
int main()
{
    read();
    ofstream fout("progresie.out");
    int v=pAritm();
    if(v)
        fout<<"elementele sirului formeaza o progresie aritmetica cu ratia "<<v<<"\n";
    else
    {
        float q=pGeom();
        if(q!=1)
            fout<<"elementele sirului formeaza o progresie geometrica cu ratia "<<q<<"\n";
        else fout<<"Nu este progresie"<<"\n";
    }
    return 0;
}
