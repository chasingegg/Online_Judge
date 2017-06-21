/*
PROG: fact4
LANG: C++
*/

//2017.5.30
//我都觉得是水题。。。

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("fact4.in");
ofstream fout("fact4.out");

#define MASK 100000  //约定N<=4220 而5^5=3125 所以只需要关注最后5位即可
int temp;
int pow(int x)
{
    int res = 1;
    for(int i = 0; i < x; ++i)
    {
        res *= 2;
    }
    return res;
}
int num_five(int x)
{
    int i = 0;
    while(x % 5 == 0)
    {
        x /= 5;
        ++i;
    }
    temp = x;
    return i;
}
int main()
{
    int N; fin >> N;
    int res = 1;
    int tmp;
    for(int i = 1; i <= N; ++i)
    {
        if(i % 5 == 0)
        {
            tmp = num_five(i);
            res = res * temp / pow(tmp);
            res = res % 100000;
        }
        else
        {
            res = res * i;
            res = res % 100000;
        }
    }    
    fout << res % 10 << endl;
    return 0;
}