#include <iostream>
///Prelucrarea numarului
using namespace std;
///6.Numarul cifrelor unui numar
int nrCif(int x)
{
    int nr=0;
    do
    {
        nr++;
        x/=10;
    }
    while(x);
    return nr;
}

///7.Suma cifrelor (pare)
int sCif(int x)
{
    int s=0;
    while(x)
    {
        if(x%2==0)
            s+=x%10;
        x/=10;
    }
    return s;
}

///8.Produsul cifrelor (pare)
int prodCif(int x)
{
    int p=1;
    do
    {
        if(x%2==0)
            p*=x%10;
        x/=10;
    }
    while(x);
    return p;
}

///9.Cifra maxima
int cifMax(int x)
{
    int M=INT_MIN; //m=x%10;
    do
    {
        if(x%10>M)
            M=x%10;
        x/=10;
    }
    while(x);
    return M;
}

///10.Cifra minima para
int cifMin(int x)
{
    int m=INT_MAX,ok=0;
    do
    {
        if(x%10<m && x%2==0)
        {
            ok=1;
            m=x%10;
        }
        x/=10;
    }
    while(x);
    if(ok)
    return m;
    return -1;
}

///11.Sa se verifice daca toate cifrele sunt impare
int verifCif(int x)
{
    do
    {
        if(x%2==0)
            return 0;
        x/=10;
    }
    while(x);
    return 1;
}

///12.Sa se verifice daca exista macar o cifra de 0 in numar
int verifNr(int x)
{
    do
    {
        if(x%10==0)
            return 1;
        x/=10;
    }
    while(x);
    return 0;
}

///13.Oglinditul unui numar / palindromul
int oglindit(int x)
{
    int nou=0;
    while(x)
    {
        nou=nou*10+x%10;
        x/=10;
    }
    return nou;
}

///14.Stergerea cifrelor impare
int stergere(int x)
{
    if(x==0) return 0;
    int nou=0,p=1;
    while(x)
    {
        if(x%2==0)
        {
            nou=x%10*p+nou;
            p*=10;
        }
        x/=10;
    }
    if(nou!=0)
        return nou;
    else return -1;
}

///15. Sa se introduca intre oricare 2 cifre (pare) cate un 1
int inserare(int x)
{
    int nou=0,p=1;
    while(x>9)
    {
        nou=x%10*p+nou;
        p*=10;
        if(x%2==0 && x/10%2==0)
        {
            nou=1*p+nou;
            p*=10;
        }
        x/=10;
    }
    nou=x*p+nou;
    return nou;
}
int main()
{
    int x;
    cout<<"Introdu numarul: "; cin>>x;
    cout<<"Numar cifre: "<<nrCif(x)<<"\n";
    cout<<"Suma cifre pare: "<<sCif(x)<<"\n";
    cout<<"Produsul cifrelor pare: "<<prodCif(x)<<"\n";
    cout<<"Cifra maxima: "<<cifMax(x)<<"\n";
    cout<<"Cifra minima para: "<<cifMin(x)<<"\n";
    cout<<"Verif daca toate cifrele sunt impare: "<<verifCif(x)<<"\n";
    cout<<"Verif daca exista o cifra de 0: "<<verifNr(x)<<"\n";
    cout<<"Palindromul: "<<oglindit(x)<<"\n";
    cout<<"Stergere cifre impare: "<<stergere(x)<<"\n";
    cout<<"Inserare 1 intre oricare 2 cifre pare: "<<inserare(x)<<"\n";
    return 0;
}
