/*
PROG: nocows
LANG: C++
*/

//2017.4.13

//dp问题 
//f[i][j] 含义是i个节点 深度小于等于j 
//一棵树有左子树和右子树 以及根节点 可设节点数为k 和 m - k - 1 各种组合方式用乘法公式
//f[i][j] += loop(f[k][j-1] * f[m-k-1][j-1]) 
#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("nocows.in");
ofstream fout("nocows.out");

int f[250][150];

int main()
{
    int N, K;
    fin >> N >> K;
    for(int i = 1; i <= K; ++i)
    {
        f[1][i] = 1;
    }
    for(int i = 3; i <= N; i = i + 2) {
        for(int j = 2; j <= K; ++j) {
            for(int k = 1; k < i; ++k) 
                f[i][j] = (f[i][j] + f[k][j-1] * f[i-k-1][j-1]) % 9901;
        }
    }
    fout << (f[N][K] - f[N][K-1] + 9901) % 9901 << endl;
    return 0;
}