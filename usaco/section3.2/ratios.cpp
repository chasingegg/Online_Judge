/*
PROG: ratios
LANG: C++
*/

//2017.6.19

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("ratios.in");
ofstream fout("ratios.out");

int target[3];
int a[3][3];
int res[3];
int out[4];
int flag = 0;

int main()
{
    int min = 303;
    for(int i = 0; i < 3; ++i) fin >> target[i];
    for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j)fin >> a[i][j];
    for(int i = 0; i < 100; ++i)
    {
        for(int j = 0; j < 100; ++j)
        {
            if(i + j >= min) break;
            for(int k = 0; k < 100; ++k)
            {
                if(i == 0 && j == 0 && k == 0) continue;
                if(i + j + k >= min) break;
                res[0] = i * a[0][0] + j * a[1][0] + k * a[2][0];
                res[1] = i * a[0][1] + j * a[1][1] + k * a[2][1];
                res[2] = i * a[0][2] + j * a[1][2] + k * a[2][2];
                if(res[0] >= target[0] && res[0] % target[0] == 0 && res[0] * target[1] == res[1] * target[0] && res[0] * target[2] == res[2] * target[0])
                {
                    out[0] = i;
                    out[1] = j;
                    out[2] = k;
                    out[3] = res[0] / target[0];
                    //cout << i << j << k << endl;
                    min = i + j + k;
                    flag = 1;
                }
            }
        }
    }    
    if(!flag) fout << "NONE" << endl;
    else
        fout << out[0] << " " << out[1] << " " << out[2] << " " << out[3] << endl;
    return 0;
}