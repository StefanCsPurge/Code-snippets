#include <iostream>
#include <fstream>
using namespace std;
ifstream f("sir.in");
int a[100],n,b[100],m;
void read(int &n,int a[])
{
    f>>n;
    for(int i=0; i<n; i++)
        f>>a[i];
}
void afisare(int n,int a[])
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

///16.Suma elementelor dintr-un sir
int suma(int a[],int n)
{
    int s=0;
    for(int i=0; i<n; i++)
        s+=a[i];
    return s;
}

///17.Maxim/minim din sir
int maxim(int a[],int n)
{
    int m=INT_MIN;  //INT_MAX pt minim
    for(int i=0; i<n; i++)
        if(a[i]>m) // < pt minim
            m=a[i];
    return m;
}

///18.Verificare daca toate elementele sunt impare:
int verifTot(int a[],int n)
{
    for(int i=0; i<n; i++)
        if(a[i]%2==0)
            return 0;
    return 1;
}

///19.Sa se verifice daca exista macar un element egal cu 10 in sir
int verifE(int a[],int n)
{
    for(int i=0; i<n; i++)
        if(a[i]==10)
            return 1;
    return 0;
}

///20. Sortarea unui vector
void sortare(int a[],int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(a[i]>a[j])
            {
                int aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
}

///21. Interclasarea a doi vectori
void interclasare(int a[],int b[],int n,int m)
{
    int i=0,j=0,c[100],k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
            c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    for(; i<n; i++)
        c[k++]=a[i];
    for(; j<m; j++)
        c[k++]=b[j];
    for(i=0; i<k; i++)
        cout<<c[i]<<" ";
    cout<<"\n";
}

///22. Stergere elemente pare din sir
void stergere(int a[],int &n)
{
    int st=0;
    for(int i=0; i<n; i++)
        if(a[i]%2==0)
            st++;
        else a[i-st]=a[i];
    n-=st;
}

///23. Inserarea intre oricare 2 elemente (impare) a elementului -1
void inserare(int a[],int &n)
{
    int b[100],k=0;
    for(int i=0;i<n-1;i++)
    {
        b[k++]=a[i];
        if(a[i]%2==1 && a[i+1]%2==1)
        b[k++]=-1;
    }
    b[k++]=a[n-1];
    n=k;
    for(int i=0;i<n;i++)
        a[i]=b[i];
}

///24.
void max3(int n, int a[])
{
    ///The 3 biggest elements
    int max1=INT_MIN, max2 =INT_MIN, max3 = INT_MIN;
    for (int i = 0;i < n;i++)
    {
        if (a[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2)
        {
            max3 = max2;
            max2 = a[i];
        }
        else if (a[i] > max3)
            max3 = a[i];
    }
    cout << max1 << ' ' << max2 << " "<<max3<<"\n";
}

///25.
int sumA(int st,int dr)
{
    ///Sum of the even elements using divide & conquer
    if (st > dr)
        return 0;
    int m = (st + dr) / 2;
    if (st == dr)
    {
        if (!(a[m] % 2))
            return a[m];
        else return 0;
    }
    return sumA(st, m) + sumA(m + 1, dr);
}

int main()
{
    read(n,a);
    read(m,b);
    //cout<<"Suma elementelor din sirul a: "<<suma(a,n)<<"\n";
    cout<<"Maximul din sirul a: "<<maxim(a,n)<<"\n";
    cout<<"Verificare daca toate elementele din a sunt impare: "<<verifTot(a,n)<<"\n";
    cout<<"Verificare daca exista macar un element egal cu 10 in sirul a: "<<verifE(a,n)<<"\n";
    cout<<"Sortare + afisare sir a si b: "<<"\n";
    sortare(a,n);
    afisare(n,a);
    sortare(b,m);
    afisare(m,b);
    cout<<"Interclasare sir a si sir b: "<<"\n";
    interclasare(a,b,n,m);
    cout<<"Stergere elemente pare din a: "<<"\n";
    stergere(a,n);
    afisare(n,a);
    cout<<"Inserarea elementului -1 intre oricare 2 elemente impare in b: "<<"\n";
    inserare(b,m);
    afisare(m,b);
    return 0;
}
