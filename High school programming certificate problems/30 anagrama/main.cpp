#include <iostream>
#include <cstring>
using namespace std;
int ap[26];
char a[22],b[22];
void aparitii()
{
    int n=strlen(a);
    for(int i=0;i<n;i++)
        ap[a[i]-'a']++;
    n=strlen(b);
    for(int i=0;i<n;i++)
        ap[b[i]-'a']--;
}
int verif()
{
    if(strlen(a)!=strlen(b))
        return 0;
    for(int i=0;i<26;i++)
        if(ap[i]!=0)
        return 0;
    return 1;
}
int main()
{
    cin.getline(a,22);
    cin.getline(b,22);
    aparitii();
    if(verif())
        cout<<"Da";
    else cout<<"Nu";
    return 0;
}
