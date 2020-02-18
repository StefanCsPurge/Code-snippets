#include <iostream>
#include <cstring>
using namespace std;

///Citire pe mai multe randuri
void read()
{
    ifstream f("text.in");
    char s[100];
    while(f.getline(s,100))
    {
        char *t=strtok(s," ");
        while(t)
        {
            int l=strlen(t);
            //prelucrare cuvant
            t=strtok(0," ");
        }
    }
}
///Sa se afiseze (numarul) de aparitii a unui caracter intr-un sir
void afish(char *s,char c)
{
    char *p=strchr(s,c);
    while(p)
    {
        cout<<p-s<<" ";
        p=strchr(p+1,c);
    }
}
///Sa se afiseze toate aparitiile unui sir in alt sir
void afish2(char *s1,char *s2)
{
    char *p=strstr(s1,s2);
    int l=strlen(s2);
    while(p)
    {
        cout<<p-s1<<" ";
        p=strstr(p+l,s2);
    }
}
bool litera(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return true;
    return false;
}
bool consoana(char c)
{
    if((c>='a' && c<='z' && !strchr("AEIOUaeiou",c)) || (c>='A' && c<='Z' && !strchr("AEIOUaeiou",c)))
        return true;
    return false;
}
///1) Se citeşte un text. Să se facă o statistică care să conţină : numărul de litere, numărul de cuvinte şi numărul de rânduri din text;
void statistica(int &lin,int &cuv,int &lit)
{
    ifstream f("text.in");
    char s[201];
    while(f.getline(s,201))
    {
        lin++;
        char *t=strtok(s," ,.!?;");
        while(t)
        {
            cuv++;
            int l=strlen(t);  //lit+=l; sau mai exact:
            for(int i=0;i<l;i++)
             if(litera(*(t+i)))    ///incearca *(t+i) // t[i];
                lit++;
             t=strtok(0," ,.!?;");
        }
    }
}
///Sa se stearga ultima consoana din sir
void stergereC(char *s)
{
    int ok=0;
    for(int i=strlen(s)-1;i>=0;i--)
        if(consoana(s[i]))
        {
            char aux[101]; ok=1;
            strcpy(aux,s+i+1);
            strcpy(s+i,aux);
            break;
        }
    if(!ok)
        cout<<"Nu avem consoane";
    else
    cout<<s;
}
///Sa se stearga toate vocalele dintr-un string.
void stergere(char *s)
{
    int l=strlen(s),sterse=0;
    for(int i=0;i<l;i++)
        if(strchr("AEIOUaeiou",s[i]))
        sterse++;
    else s[i-sterse]=s[i];
    s[l-sterse]=0;
}
///Sa se verifice daca toate vocalele sunt la inceput
bool verif(char *s)
{
    int n=strlen(s);
    for(int i=1;i<n;i++)
        if(strchr("AEIOUaeiou",s[i]) && consoana(s[i-1]))
            return 0;
    return 1;
    //+cond daca nu exista vocale
}
char d[100][30];
int n;
bool cautare(char d[][30],int n,char *s)
{
    for(int i=0;i<n;i++)
        if(strstr(d[i],s))
        return 1;
    return 0;
}
void sortare(char d[][30],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        if(strcmp(d[i],d[j])>0)
        swap(d[i],d[j]);
}
int main()
{

    return 0;
}
