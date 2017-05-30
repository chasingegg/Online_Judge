/*
PROG: stamps
LANG: C++
*/

//2017.5.29
//dp问题 f[i]表示i的面值需要邮票的最少数 f[i] = min(f[i - val[j]]) + 1
//话说dp问题一直都是我的痛点。。。真心难想。。

#include<iostream>
#include<fstream>
using namespace std;

#define MAX 2147400000

ifstream fin("stamps.in");
ofstream fout("stamps.out");

int s[205];
int f[2000000];

int main()
{
    int K, N; fin >> K >> N;
    int res;
    for(int i = 0; i < N; ++i) fin >> s[i];
    int num;
    for(num = 1; ; ++num)
    {
        res = MAX;
        for(int i = 0; i < N; ++i)
        {
            if(num - s[i] >= 0)
            {
                if(f[num - s[i]] < res) 
                    res = f[num - s[i]] + 1;
            }

        }
        if(res > K) break;
        f[num] = res;
    }
    fout << num - 1 << endl;
    return 0;
}