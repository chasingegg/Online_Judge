/*
PROG: range
LANG: C++
*/

//2017.6.29
//要是常规就是全部暴搜一通
//可以dp来做 
//对于(i, j) dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 if a[i][j] == 1

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
using namespace std;

ifstream fin("range.in");
ofstream fout("range.out");

int N;
int a[255][255];
int dp[255][255];
int res[255];

int main()
{
    fin >> N;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            char ch; fin >> ch;
            a[i][j] = ch - '0';
        }
    for(int i = 0; i < N; ++i)
        if(a[i][0]) dp[i][0] = 1;
    for(int i = 1; i < N; ++i)
        if(a[0][i]) dp[0][i] = 1;
    
    for(int i = 1; i < N; ++i)
        for(int j = 1; j < N; ++j)
        {
            if(a[i][j])
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            for(int k = 2; k <= dp[i][j]; ++k)
                res[k]++;
        }
    
    for(int i = 2; i <= N; ++i)
    {
        if(res[i])
            fout << i << " " << res[i] << endl;
    }
    return 0;
}