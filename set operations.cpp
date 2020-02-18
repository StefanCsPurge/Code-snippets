#include <iostream>
#include <fstream>
using namespace std;
int a[100],b[100],r[100],na,nb,nr,r2[100],nr2,r3[100],nr3;
ofstream fout("multimi.out");
///1. Sa se verifice daca un vector este o multime
bool verificare(int n,int v[])
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(v[i]==v[j])
                return 0;
    return 1;
}
///Citirea din mai multe fisiere
void citire(int v[],int &n, char nume[])
{
    ifstream fin(nume);
    fin>>n;
    for(int i=0; i<n; i++)
        fin>>v[i];
}
///Cautare element in vector
bool cautare(int x,int v[],int n)
{
    for(int i=0; i<n; i++)
        if(v[i]==x)
            return 1;
    return 0;
}
///2. Intersectia a doua multimi
void intersectie(int a[],int na,int b[],int nb,int r[],int &nr)
{
    for(int i=0; i<na; i++)
        if(cautare(a[i],b,nb)==1)
            r[nr++]=a[i];
}
///3. Reuniunea a doua multimi
void reuniune(int a[],int na, int b[],int nb, int r2[],int &nr2)
{
        for(int i=0; i<na; i++)
            r2[nr2++]=a[i];
        for(int i=0; i<nb; i++)
            if(cautare(b[i],r2,nr2)==0)
                r2[nr2++]=b[i];
}
///4. Diferenta a doua multimi
void diferenta(int a[],int na, int b[], int nb, int r3[],int &nr3)
{
   for(int i=0;i<na;i++)
       if(cautare(a[i],b,nb)==0)
        r3[nr3++]=a[i];
}
void afisare(int a[],int n)
{
    for(int i=0; i<n; i++)
        fout<<a[i]<< " ";
    fout<<endl;
}
int main()
{
    citire(a,na,"multime1.in");
    citire(b,nb,"multime2.in");
    if(verificare(na,a)==0 || verificare(nb,b)==0)
    {
        fout<<"multime incorecta";
        return 0;
    }
    intersectie(a,na,b,nb,r,nr);
    afisare(r,nr);
    reuniune(a,na,b,nb,r2,nr2);
    afisare(r2,nr2);
    diferenta(a,na,b,nb,r3,nr3);
    afisare(r3,nr3);
    return 0;
}
