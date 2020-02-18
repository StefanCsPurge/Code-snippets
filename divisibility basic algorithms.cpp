#include <iostream>

using namespace std;

///1.Primalitate
int prim(int x)
{
    if(x<2||(x>2 && x%2==0))
        return 0;
    for(int d=3; d*d<=x; d+=2)
        if(x%d==0)
            return 0;
    return 1;
}

///2.Cmmdc + cmmmc
int cmmdc(int x, int y)
{
    while(y)
    {
        int r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int cmmmc(int x,int y)
{
    return x*y/cmmdc(x,y);
}

///3.Numarul de divizori
int nrDiv(int x)
{
    int d,nr=0;
    for(d=1;d*d<x;d++)
        if(x%d==0)
        nr+=2;
    if(d*d==x)
        nr++;
    return nr;
}

int nrDivFaster(int x)
{
    int nr,pr=1,d;
    for(nr=0;x%2==0;x/=2,nr++);
    if(nr>0)
        pr*=(nr+1);
    for(d=3;d*d<=x;d+=2)
    {
        for(nr=0;x%d==0;x/=d,nr++);
        if(nr>0)
            pr*=(nr+1);
    }
    if(x!=1)
      pr*=2;
    return pr;
}

///4.Suma divizorilor
int sDiv(int x)
{
    int s=0,d;
    for(d=1; d*d<x; d++)
        if(x%d==0)
            s+=d+x/d;
    if(d*d==x)
        s+=d;
    return s;
}

///5.Descompunerea in factori primi
void descFactPr(int x)
{
    int nr;
    for(nr=0;x%2==0; x/=2,nr++);
    if(nr>0)
        cout<<"2^"<<nr<<' ';
    for(int d=3;d*d<=x;d+=2)
    {
        for(nr=0;x%d==0; x/=d,nr++);
        if(nr>0)
            cout<<d<<'^'<<nr<<' ';
    }
    if(x!=1)
        cout<<x<<"^1";
}
int main()
{
    int x;
    cin>>x;
    if(prim(x))
        cout<<"Este prim"<<"\n";
    else
        cout<<"Nu este prim"<<"\n";
    cout<<"CMMDC: "<<cmmdc(x,0)<<"\n"<<"CMMMC: "<<cmmmc(x,0)<<"\n";
    cout<<"Numarul de divizori: "<<nrDiv(x)<<"\n";
    cout<<"Suma divizorilor: "<<sDiv(x)<<"\n";
    cout<<"Descompunerea in factori primi: ";
    descFactPr(x);
    return 0;
}
