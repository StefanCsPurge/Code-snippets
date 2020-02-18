#include <iostream>

using namespace std;
int n, a[111],x, length;
void insert_element(int x,int pos)
{
   n++;
   for(int i=n;i>pos;i--)
    a[i]=a[i-1];
   a[pos]=x;
}
int find_pos(int x)
{
    int lt=0,rt=n-1,mid;
    while(lt<=rt)
    {
        mid=(lt+rt)/2;
        if(x==a[mid]) return mid;
        if(x<a[mid])
            rt=mid-1;
        else lt=mid+1;
    }
    return lt;
}
int main()
{
    cin>>length;
    while(n<length)
    {
        cin>>x;
        int p=find_pos(x);
        insert_element(x,p);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    return 0;
}
