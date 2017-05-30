/*
PROG: humble
LANG: C++
*/

//2017.5.28
//总体思路是模拟产生所有的丑数 
//已知前i个丑数 求第i+1个丑数时 对于每个prime 检查最小的丑数并与prime相乘 去最小的便是第i+1个丑数

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
#define MIN 2147400000

ifstream fin("humble.in");
ofstream fout("humble.out");

long hum[100005];
long prime[105];
int p_index[105];

int K, N;
int main()
{
    fin >> K >> N;
    hum[0] = 1;
    for(int i = 0; i < K; ++i) fin >> prime[i];
    
    for(int i = 1; i <= N; ++i)
    {
        long min = MIN;
        for(int j = 0; j < K; ++j)
        {
            while(prime[j] * hum[p_index[j]] <= hum[i - 1])
                ++p_index[j];
            if(prime[j] * hum[p_index[j]] < min)
            {
                min = prime[j] * hum[p_index[j]];
            }
        }
        hum[i] = min;
    }
    fout << hum[N] << endl;
    return 0;
}