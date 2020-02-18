#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("vector.in");
int a[100],n,b[100],m,c[200],k;
void read(int i,int l,int x[])
{
    if(i==l) return;
    fin>>x[i];
    read(i+1,l,x);
}
void afish(int i,int l,int x[])
{
    if(i==l) return;
    cout<<x[i]<<" ";
    afish(i+1,l,x);
}

///Suma elementelor unui vector:
int sumaelem(int i)
{
    if(i==n) return 0;
    return a[i]+sumaelem(i+1);
}

///Elementul maxim din vector:
int maxim(int i, int maxi)
{
    if(i==n) return maxi;
    if(a[i]>maxi)
        return maxim(i+1,a[i]);
    return maxim(i+1,maxi);
}

///Sortare vector:
void sortare(int i,int j)
{
    if(i==n-1)
        return;
    if(j==n)
    {
        sortare(i+1,i+2);
        return;
    }
    if(a[i]>a[j])
    {
        int aux=a[i];
        a[i]=a[j];
        a[j]=aux;
    }
    sortare(i,j+1);
}

///Sa se verifice daca exista 3 numere pitagoreice in vector:
int pitagoreice_rec(int i,int j,int k)
{
    if(i==n-2) return 0;
    if(j==n-1)
        return pitagoreice_rec(i+1,i+2,i+3);
    if(k==n)
        return pitagoreice_rec(i,j+1,j+2);
    if(a[i]*a[i]+a[j]*a[j]==a[k]*a[k] || a[k]*a[k]+a[j]*a[j]==a[i]*a[i] || a[k]*a[k]+a[i]*a[i]==a[j]*a[j])
        return 1;
    return pitagoreice_rec(i,j,k+1);
}

///Stergere elemente divizibile cu 3 din vector
void stergere(int i,int &s)
{
    if(i==n) return;
    if(a[i]%3==0) s++;
    else
        a[i-s]=a[i];
    stergere(i+1,s);
}

///Sa se formeze al treilea vector(c) din a si b prin interclasare
void interclasare_nerecursiv(int a[],int b[],int c[],int n,int m,int &k)
{
    int i,j;
    for(i=0,j=0; i<n && j<m;)
        if(a[i]<b[j])
            c[k++]=a[i++];
        else c[k++]=b[j++];
    for(; i<n; i++) c[k++]=a[i];
    for(; j<m; j++) c[k++]=b[j];
}
void interclasare_rec(int i,int j,int &k)
{
    if(k==m+n) return;

    if(a[i]<b[j])
    {
        c[k++]=a[i];
        interclasare_rec(i+1,j,k);
    }
    else
    {
        c[k++]=b[j];
        interclasare_rec(i,j+1,k);
    }
    /*
    if(i<n)
    {
        c[k++]=a[i];
        interclasare_rec(i+1,j,k);
    }
    if(j<m)
    {
        c[k++]=b[j];
        interclasare_rec(i,j+1,k);
    }
    */
}
int main()
{
    fin>>n;
    read(0,n,a);
    fin>>m;
    read(0,m,b);
    sortare(0,1);
    afish(0,n,a);
    cout<<endl;
    interclasare_nerecursiv(a,b,c,n,m,k);
    afish(0,k,c);
    cout<<endl;
    //k=0;
    //interclasare_rec(0,0,k);
    afish(0,k,c);

    cout<<endl<<endl;
    cout<<sumaelem(0)<<endl;
    cout<<maxim(0,-1000000000)<<endl;
    cout<<endl;
    cout<<pitagoreice_rec(0,1,2)<<endl;

    int sterse=0;
    stergere(0,sterse);
    n-=sterse;
    afish(0,n,a);
    cout<<endl;
    return 0;
}
