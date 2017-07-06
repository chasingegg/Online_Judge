/*
PROG: heritage
LANG: C++
*/

//2017.6.30
//关于二叉树的三种遍历方式 
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

ifstream fin("heritage.in");
ofstream fout("heritage.out");

char pre[30], in[30];
char pos[50];
int size;
int sindex = -1;

void post(int first, int last)
{
    if(first > last)
        return;
    int i;
    ++sindex;
    for(i = 0; i < size; ++i)
        if(in[i] == pre[sindex]) break;

    post(first, i - 1);
    post(i + 1, last);
    fout << in[i];
}
int main()
{
    fin >> in >> pre;
    size = strlen(in) - 1;
    post(0, strlen(in) -1);
    
    fout << endl;

    return 0;
}