/*
PROG: agrinet
LANG: C++
*/

//2017.5.20
//这是一道纯正的最小生成树的题
//用Prim算法
#include <iostream>
#include <fstream>
using namespace std;

#define INF 1000000

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

int m[101][101];
bool f[101]; //0表示加进来了 1表示没加进来
int lowCost[101];
//int startNode[101];

int main()
{
    int n; fin >> n;
    int start;
    int res = 0;
    for(int i = 0; i < n; ++i) {

        for(int j = 0; j < n; ++j)
            fin >> m[i][j];
        
        lowCost[i] = INF;
    }

    start = 0;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!f[j] && lowCost[j] > m[start][j] && start != j) {
                lowCost[j] = m[start][j];
                //startNode[j] = start;
            }
        }
        f[start] = 1;
        int min = INF;
        for(int j = 0; j < n; ++j) {
            if(lowCost[j] < min) {
                min = lowCost[j];
                start = j;
            }
        }
        res += min;
        lowCost[start] = INF;
    }   
    fout << res << endl;
    return 0;
}