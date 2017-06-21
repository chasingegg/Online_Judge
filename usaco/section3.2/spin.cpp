/*
PROG: spin
LANG: C++
*/

//2017.6.18

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("spin.in");
ofstream fout("spin.out");

int speed[6];  
int wheel[5][360];  
int pos[5];  
int main() {  

    for (int i = 0; i < 5; i++) {  
        int n;  
        fin >> speed[i] >> n;
        int a, b;  
        for (int k = 0; k < n; k++) {  
            fin >> a >> b;
            for (int j = a; j <= a + b; j++) {  
                wheel[i][j % 360] = 1;  
            }  
        }  
    }  
    for (int i = 0; i < 360; i++) {  
        for (int j = 0; j < 360; j++) {  
            if (wheel[0][(j + pos[0]) % 360] && wheel[1][(j + pos[1]) % 360] && wheel[2][(j + pos[2]) % 360] && wheel[3][(j + pos[3]) % 360] && wheel[4][(j + pos[4]) % 360]) {  
                fout << i << endl;  
                return 0;  
            }  
        }  
        for (int j = 0; j < 5; j++) {  
            pos[j] -= speed[j];  
            pos[j] += 360;  
            pos[j] %= 360;  
        }  
    }  
    fout << "none" << endl; 
  
    return 0;  
}  