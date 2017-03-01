/*
PROG: barn1
LANG: C++
*/

//2017.2.22

//这道题算是比较有印象的一道题，主要就是将数组排好序 然后将每相邻两个元素取差再进行排序 去掉那些比较大的间隔就行
//中途有一个小bug是可能给的板的数量比较大，大于牛的数量那就直接输出牛的数量即可

#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("barn1.in");
ofstream fout("barn1.out");

int a[1000];
int b[1000];
void quick_sort(int a[], int low, int high)
{
    if(low >= high)
        return;
    int first = low;
    int last = high;
    int key = a[first];
    while(first < last)
    {
        while(first < last && a[last] >= key)
            --last;
        a[first] = a[last];
        while(first < last && a[first] <= key)
            ++first;
        a[last] = a[first];
    }
    a[first] = key;
    quick_sort(a, low, first - 1);
    quick_sort(a, first + 1, high);
}
int main()
{
    int M, S, C;
    int res = 0;
    fin >> M >> S >> C;
    if(M >= C)
    {
        fout << C << endl;
        return 0;
    }
    for(int i = 0; i < C; ++i)
    {
        fin >> a[i];
    }
    quick_sort(a, 0, C - 1);
    for(int i = 1; i < C; ++i)
    {
        b[i - 1] = a[i] - a[i - 1];
    }
    quick_sort(b, 0, C - 2);
    for(int i = 0; i < M - 1; ++i)
    {
        res += b[C - 2 - i];
    }
    fout << a[C - 1] - a[0]  + M - res << endl;
    //cout << "hello" << endl;
    return 0;
}
