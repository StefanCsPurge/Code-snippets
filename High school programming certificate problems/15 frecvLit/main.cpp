#include <fstream>
using namespace std;
int ap[26];
void read()
{
    ifstream fin("text.in");
    char c;
    while(fin>>c)
    {
        if(c>='a' && c<='z')
            ap[c-32-'A']++;
        else if(c>='A' && c<='Z')
            ap[c-'A']++;
    }
}
void afish()
{
    int ok=0;
    ofstream fout("text.out");
    for(int i=0;i<26;i++)
        if(ap[i]!=0)
    {
        fout<<(char)(i+'A')<<'-'<<ap[i]<<"\n";
        ok=1;
    }
    if(!ok)
        fout<<"nu exista litere";
}
int main()
{
    read();
    afish();
    return 0;
}
