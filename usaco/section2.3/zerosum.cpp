/*
PROG: zerosum
LANG: C++
*/

//2017.4.29
//在1，2...N数字中添加 ‘+’ ‘-’ ‘ ’使得最终结果为0
//使用dfs 每一层三种情况 由于按照ASCII码的顺序 所以顺序是空格 + - 
//记录现有的和 记录现在由于空格的状况保存下来的书left 记录现在的数字step 记录现在要输出的string

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int N;
void dfs(int sum, int left, int step, string res)
{
    if(step == N)
    {
        if(sum + left == 0) {
            fout << res << endl;
            return;
        }
        else 
            return;
    }
    //' '空格
    if(left < 0) 
        dfs(sum, left * 10 - step - 1, step + 1, res + " " + char(step + 1 + '0'));
    else
        dfs(sum, left * 10 + step + 1, step + 1, res + " " + char(step + 1 + '0'));
    //'+'
    dfs(sum + left, step + 1, step + 1, res + "+" + char(step + 1 + '0'));

    //'-'
    dfs(sum + left, -step-1, step + 1, res + "-" + char(step + 1 + '0'));
}
int main()
{
    fin >> N;
    dfs(0, 1, 1, "1");
    //cout << int(' ') << ' ' << int('+') << " " << int('-') << " ";
    //cout << "hello" << endl;
    return 0;
}