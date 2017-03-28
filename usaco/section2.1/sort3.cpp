/*
PROG: sort3
LANG: C++
*/

//2017.3.22

//仿佛好多题都不会啊,,,就这样还咋去依图啊
//主要就是将数排序 然后观察现在与原始的数组有什么区别,(1,2)这种表示应该是1实际上是2
//(1,2) (2,1)就可以直接交换1次 这种情况处理完以后 其余的情况都是交换2次解决

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("sort3.in");
ofstream fout("sort3.out");

int a[1200];
int f[4][4];
int tr[1200];
int res = 0;

void quick_sort(int low, int high)
{
    if(low >= high) return;
    int first = low;
    int last = high;
    int key = tr[first];
    while(first < last)
    {
        while(first < last && tr[last] >= key) --last;
        tr[first] = tr[last];
        while(first < last && tr[first] <= key) ++first;
        tr[last] = tr[first];
    }
    tr[first] = key;
    quick_sort(low, first - 1);
    quick_sort(first + 1, high);
}

void cal(int i , int j)
{
    if(f[i][j] > f[j][i])
    {
        res += f[j][i];
        f[i][j] -= f[j][i]; f[j][i] = 0;
    } else {
        res += f[i][j];
        f[j][i] -= f[i][j]; f[i][j] = 0;
    }
}
int main()
{
    int N; fin >> N;
    for(int i = 0; i < N; ++i) fin >> a[i];
    for(int i = 0; i < N; ++i) tr[i] = a[i];
    quick_sort(0, N - 1);
    //for(int i = 0; i < N; ++i) cout << tr[i] << " ";
    for(int i = 0; i < N; ++i)
        ++f[tr[i]][a[i]];
    cal(1, 2);  //cout << res << endl;
    cal(1, 3);  //cout << res << endl;
    cal(2, 3);  //cout << res << endl;
    for(int j = 2; j <= 3; ++j)
        {
            if(f[1][j] != 0)
            {
             res += 2 * f[1][j];
             break;
            }
        }
    fout << res << endl;
    return 0;
}