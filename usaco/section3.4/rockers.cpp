/*
PROG: rockers
LANG: C++
*/

//2017.6.30
//dp问题

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int N,T,M;
int music[21];
int CD[21][21];//i－j区间内,每张CD最多装多少个
int dp[21][21];//i张CD前j首歌
void makeCD()
{
    for(int i=1;i<=N;++i)
        for(int j = i;j<=N;++j)
        {
            int tmp[21];
            memset(tmp, 0, sizeof(tmp));
            
            for(int k = i;k<=j;++k)
                for(int t = T;t>=music[k];--t)
                    tmp[t] = max(tmp[t],tmp[t-music[k]]+1);
            CD[i][j] = tmp[T];
        }
}
void DP()
{
    for(int j = 1;j<=N;++j) dp[1][j] = CD[1][j];
    for(int i = 2;i<=M;++i)
        for(int j = 1;j<=N;++j)
            for(int k = i-1;k<=j-1;++k)
                dp[i][j] = max(dp[i][j],dp[i-1][k]+CD[k+1][j]);
}
int main()
{
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
    cin >> N >> T >> M;
    M = min(N,M);
    for(int i = 1;i<=N;++i) cin >> music[i];
    makeCD();
    DP();
    cout << dp[M][N]<<endl;
    return 0;
}