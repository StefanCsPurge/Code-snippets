#include <iostream>

using namespace std;
///a la puterea n:
int a_la_n(int a,int n)
{
    if(!n) return 1;
    return a*a_la_n(a,n-1);
}

///n factorial
int nFactorial(int n)
{
    if(!n) return 1;
    return n*nFactorial(n-1);
}

///Suma Gaus
int gaus(int n)
{
    if(n==1) return 1;
    return n+gaus(n-1);
}

///Nr cif unui numar
int nrcif(int x)
{
    if(x<10) return 1;
    return 1+nrcif(x/10);
}

///Suma cifrelor unui numar
int sumacif(int x)
{
    if(x<10) return x;
    return x%10+sumacif(x/10);
}

///Produsul cifrelor unui nr
int prodcif(int x)
{
    if(!x) return 1;
    return x%10*prodcif(x/10);
}

///Cifra maxima din nr
int cifmax(int x,int c)
{
    if(!x) return c;
    if(x%10>c)
        return cifmax(x/10,x%10);
    return cifmax(x/10,c);
}

///Verificare daca un numar este palindrom:
int palindrom(int x,int og)
{
    if(!x) return og;
    return palindrom(x/10,og*10+x%10);
}

///Eliminare cifre pare dintr-un numar:
int elimcif2(int x)
{
    if(!x) return 0;
    if(x%2==0)
        return elimcif2(x/10);
    else return elimcif2(x/10)*10+x%10;
}
///Sa se elimine cifrele divizibile cu 3:
int elimcif3(int x)
{
    if(!x) return 0;
    if(x%10%3==0)
        return elimcif2(x/10);
    else return elimcif2(x/10)*10+x%10;
}

///Sa se introduca 0 dupa fiecare cifra impara in nr
int baga0(int x)
{
    if(!x) return 0;
    if(x%2) return baga0(x/10)*100+x%10*10;
    else return baga0(x/10)*10+x%10;
}

///Sa se introduca intre oricare 2 cifre media lor aritmetica
int bagaMA(int x)
{
    if(x<10) return x;
    int m=(bagaMA(x/10)%10+x%10)/2;
    return bagaMA(x/10)*100+m*10+x%10;
}

///Sa se verifice daca cifrele unui numar sunt in ordine strict descrescatoare
int verifdesc(int x)
{
    if(x<10) return 1;
    if(x/10%10<=x%10)
        return 0;
    return verifdesc(x/10);
}
///Sa se verifice daca un nr are toate cifrele prime:
int cifprime(int x)
{
    if(x<10 && (x==2 || x==3 || x==5 || x==7))
        return 1;
    if(x%10!=2 && x%10!=3 && x%10!=5 && x%10!=7)
        return 0;
    return cifprime(x/10);
}

///Cifra de control a unui numar:
int cifcontrol(int x)
{
    if(x<10) return x;
    int s=sumacif(x);
    if(s<10) return s;
    return cifcontrol(s);
}

///Verificare daca un numar este prim:
int verif_imp(int x,int d)
{
    if(d*d>x) return 1;
    if(x%d==0) return 0;
    return verif_imp(x,d+2);
}
int prim(int x)
{
    if(x<2 || (x>2 && x%2==0))
        return 0;
    return verif_imp(x,3);
}

///Numarul de divizori ai unui numar:
int nrdiv_rec(int x,int d)
{
    if(d*d>x)
        return 0;
    if(d*d==x)
        return 1;
    if(x%d==0)
        return 2+nrdiv_rec(x,d+1);
    return nrdiv_rec(x,d+1);
}

///Suma divizorilor unui numar
int sumadiv(int x,int d)
{
    if(d*d>x)
        return 0;
    if(d*d==x)
        return d;
    if(x%d==0)
        return d+x/d+sumadiv(x,d+1);
    return sumadiv(x,d+1);
}
///CMMDC si CMMMC:
int cmmdc(int x, int y)
{
    if(!y) return x;
    return cmmdc(y,x%y);
}
int cmmmc(int x,int y)
{
    return x*y/cmmdc(x,y);
}

///Descompunerea in factori primi:
int putere(int &x,int d)
{
    if(x%d!=0) return 0;
        x/=d;
    return 1+putere(x,d);
}
void desc(int d,int &x)
{
    if(d*d>x)
    {
        if(x!=1)
        cout<<x<<"^"<<1;
        return;
    }
    int p=putere(x,d);
    if(p>0) cout<<d<<"^"<<p<<" ";
    desc(d+2,x);
}
void descFactoriPrimi(int x)
{
    int p=putere(x,2);
    if(p>0) cout<<"2^"<<p<<" ";
    desc(3,x);
    cout<<endl;
}
int main()
{
    cout<<"Aici sunt toate functiile recursive de baza"<<endl<<endl;
    cout<<a_la_n(2,10)<<endl;
    cout<<nFactorial(5)<<endl;
    cout<<gaus(10)<<endl;
    cout<<nrcif(0)<<endl;
    cout<<sumacif(121)<<" "<<"Cifra de control pt "<<1287361<<"="<<1287361%9<<endl;
    cout<<cifcontrol(12346)<<endl;
    cout<<prodcif(1231)<<endl;
    cout<<cifmax(1287361,0)<<endl; //cif min cu param cifmin(x,9);
    cout<<cifprime(72322)<<endl;
   // cout<<elimcif(12345,0,1)<<endl;
    cout<<palindrom(131,0)<<endl;
    cout<<prim(69)<<endl;
    cout<<nrdiv_rec(4,1)<<endl;
    cout<<sumadiv(4,1)<<endl;
    cout<<cmmdc(12,28)<<" "<<cmmmc(12,28)<<endl;
    descFactoriPrimi(990);
    cout<<elimcif2(92356)<<endl;
    cout<<baga0(23499)<<endl;
    cout<<bagaMA(123)<<endl;
    cout<<verifdesc(911)<<endl;
    return 0;
}
