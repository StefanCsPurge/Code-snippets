#include <iostream>
#include <fstream>

using namespace std;
int n,a[55];
void read()
{
    ifstream fin("mult.in");
    fin>>n;
    for(int i=0;i<n;i++)
        fin>>a[i];
}
int verificare()
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        if(a[i]==a[j])
        return 0;
    return 1;
}
int main()
{
    read();
    if(verificare())
        cout<<"da";
    else cout<<"nu";
    return 0;
}
