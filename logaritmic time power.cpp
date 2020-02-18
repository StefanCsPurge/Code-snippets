#include <iostream>

using namespace std;
int RidicareLogaritmica(int N, int P)
{
    int r = 1;
    while(P)
    {
        if(P % 2 == 1)
            r =  r * N;
        N =  N * N;
        P = P / 2;
    }
    return r;
}
int main()
{
    cout<<RidicareLogaritmica(5,10);
    return 0;
}
