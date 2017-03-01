/*
PROG:gift1
LANG:C++
*/
//
//  main.cpp
//  test

// 这道题毕竟也只是第二题，一遍就过了，虽然debug还是花了不少时间
// 感觉写的很暴力，其中一个重点是由输入的字符串得到它在数组的index，写了一个search函数
// 然后就是题目意思要理解，是把得到的钱减去送出的钱，并不是最终每个人的钱，因为每个人是
//有本钱的

//  Created by Dimon on 16/10/26.
//  Copyright © 2016年 Dimon. All rights reserved.
//

#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

ifstream fin("gift1.in");
ofstream fout("gift1.out");

int search(string a[], string b, int NP)
{
    for(int i = 0; i < NP; ++i)
    {
        if(a[i] == b)
            return i;
    }
    return -1;
}

int main()
{
    int NP, index;
    int num_all, num_per;
    string ch;
    string a[15];
    int m[15];
    string tmp[15];
    fin >> NP;
    //cin >> NP;
    for(int i = 0; i < NP; ++i)
    {
        fin >> a[i];
        m[i] = 0;
    }
    for(int i = 0; i < NP; ++i)
    {
        fin >> ch;
        fin >> num_all >> num_per;
        int master = search(a, ch, NP);
        m[master] -= num_all;
        if(num_per != 0)
        {
            int money = num_all / num_per;
            int remain = num_all - (num_all / num_per) * num_per;
            for(int j = 0; j < num_per; ++j)
            {
                fin >> tmp[j];
                index = search(a, tmp[j], NP);
                m[index] += money;
            }
            m[master] += remain;
        }
    }
    for(int i = 0; i < NP; ++i)
    {
        fout << a[i] << ' ' << m[i] << endl;
    }
    // insert code here...
    //cout << "Hello, World!\n";
    return 0;
}
