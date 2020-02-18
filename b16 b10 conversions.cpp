#include <iostream>
#include <cstring>
using namespace std;

int conversie(char *s, int n)
{
    int nr=0;
    for(int i=0; i<n; i++)
        if(s[i]>='A')
            nr=nr*16+s[i]-'A'+10;
        else nr=nr*16+s[i]-'0';
    return nr;
}
int convRec(char *s, int n)
{
    if(n==0)
    {
        if(s[0]>='A')
            return s[0]-'A'+10;
        else return s[0]-'0';
    }
    if(s[n]>='A')
        return s[n]-'A'+10 + 16*convRec(s,n-1);
    else return s[n]-'0' + 16*convRec(s,n-1);
}
int main()
{
    char s[11];
    int n;
    cin>>s;
    n=strlen(s);
    cout<<conversie(s,n)<<"\n";
    cout<<convRec(s,n-1);
    return 0;
}
