#include <iostream>
using namespace std;
int v[1000],n;

void citire()
{ int i;
  cin>>n;
  for(i=1;i<=n;i++)
      cin>>v[i];
}
void afis()
{ int i;
  for(i=1;i<=n;i++)
     cout<<v[i]<<" ";
  cin>>i;
}

///Insertion
void insertie_sort()
{
    for(int i=1;i<n;i++)
    {
        int j=i-1,aux=a[i];
        for(j=i-1;j>=0 && aux<a[j];j--)
            a[j+1]=a[j];
        a[j+1]=aux;
    }
}

///Counting
void numarare()
{
    int b[55],nr;
    for(int i=0; i<n; i++)
    {
        nr=0;
        for(int j=0; j<i; j++)
            if(a[j]<=a[i])
                nr++;
        for(int j=i+1; j<n; j++)
            if(a[j]<a[i])
                nr++;
        b[nr]=a[i];
    }
    for(int i=0; i<n; i++)
        a[i]=b[i];
}

///Selection
int pozMin(int p)
{
    int pmin=p;
    for(int i=p+1; i<n; i++)
        if(a[i]<a[pmin])
            pmin=i;
    return pmin;
}
void selectie()
{
    for(int i=0;i<n-1;i++)
    {
        int v=pozMin(i);
        int aux=a[i];
        a[i]=a[v];
        a[v]=aux;
    }
}

///Bubble sort
void bubbleSort(int a[],int n)
{
    int p=n,ok;
    do
    {
       p--; ok=0;
       for(int i=0;i<p;i++)
       { 
           if(a[i]>a[i+1]) 
           {
              swap(a[i],a[i+1]);
              ok=1;
           }
       }
     }while(ok);
}

//////////////////////// QUICK SORT VARIANTS ////////////////////////

///V1:
void pozitie(int p,int u,int &k)
{  int i,j,di,dj,aux;
   i=p; j=u; di=0; dj=-1;
   while(i<j)
      {  if(v[i]>v[j])
            {aux=v[i]; v[i]=v[j]; v[j]=aux;
             aux=di; di=-dj; dj=-aux;
            }
          i+=di;
          j+=dj;
      }
    k=i;
}
void quick(int p,int u)
{   int k;
    if(p<u)
     {  pozitie(p,u,k);
        quick(p,k-1);
        quick(k+1,u);
     }
}

///V2:
int partitioning(int x[],int st,int dr)
{

    int aux,i,j,di,dj;

    di=0;
    dj=1;
    i=st;
    j=dr;

    while(i<j)
    {

        if (x[i]>x[j])
        {
            aux=x[i];
            x[i]=x[j];
            x[j]=aux;

            aux=di;
            di=dj;
            dj=aux;
        }

        i=i+di;
        j=j-dj;
    }
    return j;

}

void quick(int x[],int st,int dr)
{

    int p;
    if (st<dr)
    {
        p=partitioning(x,st,dr);
        quick(x,st,p-1);
        quick(x,p+1,dr);
    }

}

///V3:
void quickS(int a[],int st, int dr)
{
    if(st<dr)
    {   int i=st,j=dr,d=0;
        while(i<j)
        { if(a[i]>a[j]) 
           {   swap(a[i],a[j]);
               d=1-d;
            }
          i+=d; j-=1-d;
        }
     quickS(a,st,i-1);
     quickS(a,i+1,dr);
    }
}

int main ()
{
  citire();
  quick(1,n);
  afis();
  return 0;
}
