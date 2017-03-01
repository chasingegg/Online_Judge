/*
 PROG: namenum
 LANG: C++
 */

//2017.2.20
//这道题似乎可以写一写
//题目的意思就是字母和数字是相对应的，只要将dict中的字母都转换成数字与输入的数字进行匹配即可

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

ifstream fin1("dict.txt");
ifstream fin("namenum.in");
ofstream fout("namenum.out");

string dict[5005];

string change(string name)
{
    string num = name;
    int i;
    for(i = 0; i < name.size(); ++i)
    {
        if(name[i] > 'Q')
            num[i] =  (name[i] - 1 - 'A') / 3 + 2 + '0';
        else
            num[i] = (name[i] - 'A') / 3 + 2 + '0';
    }
    return num;
}
int main()
{
    string val;
    string num, name;
    int flag = 0;
    fin >> val;
    while(fin1 >> name)
    {
        num = change(name);
        if(val == num)
        {
            fout << name << endl;
            flag = 1;
        }
    }
    if(flag == 0)
        fout << "NONE" << endl;
    return 0;
}