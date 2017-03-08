/*
PROG: sprime
LANG: C++
*/

//2017.3.3

//作为第一章倒没觉得有多难，居然算比较顺畅地做出来了
//感觉是可以用猥琐的打表解决
//算了还是不猥琐了，主要用递归，因为每次N的情况都是在N-1的情况再追加一位
//感觉写的还是不好。。用数组存 然后返回个数

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

int N;
int a[10000] = {3, 5, 7};
int b[10000];


bool check(int num)
{
    for(int i = 2; i <= sqrt(num); ++i)
    {
        if(num % i == 0) return false;
    }
    return true;
}
int find_sprime(int n)
{
    if(n == 1)
    {
        a[0] = 2; a[1] = 3; a[2] = 5; a[3] = 7;
        return 4;
    }
    int len = find_sprime(n - 1);
    int l = 0;
    for(int i = 0; i < len; ++i)
    {
        int x = a[i] * 10;
        if(check(x + 1)) {b[l++] = x + 1;}
        if(check(x + 3)) {b[l++] = x + 3;}
        if(check(x + 7)) {b[l++] = x + 7;} 
        if(check(x + 9)) {b[l++] = x + 9;}
    }
    for(int i = 0; i < l; ++i)
    {
        a[i] = b[i];
    }
    return l;
}
int main()
{
    fin >> N;
    if(N == 1)
        cout << 3 << endl << 5 << endl << 7 << endl;
    //if(N == 2)
      //  cout << 31 << endl << 37 << endl << 53 << endl << 59 << endl << 71 << endl << 73 << endl << 79 << endl;
    int l = find_sprime(N);
    for(int i = 0; i < l; ++i)
        fout << a[i] << endl;
    return 0;
}