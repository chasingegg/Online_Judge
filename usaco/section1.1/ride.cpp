/*
 PROG: ride
 LANG: C++
 */

//  main.cpp
//  usaco的开篇居然这么难以过掉，对自己的实力感到绝望

// 希望能持续地开始做题，并且能够写点类似于解题过程的东西藏在注释中
// 本题让我有了学习一下C++ STL的欲望，希望能够开始看起来

//  Created by Dimon on 16/10/22.
//  Copyright © 2016年 Dimon. All rights reserved.
//

#include <iostream>
#include<fstream>
using namespace std;

ifstream fin("ride.in");
ofstream fout("ride.out");


int main()
{
    char a[10], b[10];
    int res1 = 1, res2 = 1;
    int index1 = 0, index2 = 0;
    fin >> a >> b;
    while(a[index1] != '\0' && a[index1] != '\n' )
    {
        res1 *= a[index1] - 'A' + 1;
        ++index1;
    }
    while(b[index2] != '\0' && b[index2] != '\n' )
    {
        res2 *= b[index2] - 'A' + 1;
        ++index2;
    }
    if((res1 % 47) == (res2 % 47))
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}




















