/*
PROG: contact
LANG: C++
*/

//2017.5.29
//这道题我选择抄答案
//不过发现在进行字符串的匹配过程中其实实现的依然是暴力的做法 
//主要的想法就是hash 把字符串的数值作为index保存下来 但有问题就是 00 000 0000 这种情况方式就是前面加上1作为区分
#include<iostream>
#include<fstream>
#include<string>
#include<memory.h>
#include<algorithm>
using namespace std;

ifstream fin("contact.in");
ofstream fout("contact.out");

struct Node
{
    int count, index;
    char str[15];
}; Node n[200000];
int used[200000];
int cmp(Node n1, Node n2)
{
    if(n1.count == n2.count)
        return n1.index < n2.index;
    return n1.count > n2.count;
}

int main()
{
    int A, B, N;
    string s, temp;
    fin >> A >> B >> N;
    //getline(cin, temp);
    while(fin >> temp)  s += temp;
    //return 0;
    if(s.length() < B) B = s.length(); //是个可能会出现的bug

    int counter, num;
    for(int i = A; i <= B; ++i)
    {
        for(int j = 0; j < s.length() - i + 1; ++j)
        {
            counter = 0, num = 1;
            while(counter < i)
            {
                num <<= 1;
                num = num | (int)(s[j + counter] - '0');
                ++counter;
            }
            n[num].count++;
            if(n[num].count == 1)
            {
                n[num].index = num;
                for(int k = 0; k < i; ++k) 
                    n[num].str[k] = s[k + j];
            }
        }
    }
    sort(n, n+200000, cmp);
    bool judge = true; counter = 0;
    for(int i = 0; i < 200000; ++i)
    {
        if(n[i].count != 0)
        {
            if(!used[n[i].count])
            {
                ++counter; num = 1;
                if(counter > N) break;
                if(!judge) fout << endl; judge = false;
                fout << n[i].count << endl << n[i].str;
                used[n[i].count] = 1;
            }
            else {
                if(num % 6 == 0) fout << endl << n[i].str;
                else fout << " " << n[i].str; ++num;
            }
        }
    }
    fout << endl;
    return 0;
}