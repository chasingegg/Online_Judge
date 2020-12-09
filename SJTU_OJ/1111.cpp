#include<iostream>
#include<cstring>
using namespace std;
 
char s1[30];
char s2[30];
char res[10000];
 
int len;
 
void put(int root_s1, int start, int last, int index) {
    if(start > last) return;
    int i;
    for(i = start;i <= last; ++i) 
    {
        if(s2[i] == s1[root_s1]) {
            break;
        }
    }
    int left_len = i - 1;
    int right_len = len - i;
    res[index] = s2[i];
   
    put(root_s1 + 1, start, i-1, index * 2);
 
    put(root_s1 + i - start + 1, i+1, last, index * 2 + 1);
}
 
int main() {
    cin >> s1 >> s2;
    int len = strlen(s1);
    //cout << len << endl;
    for(int i = 0; i < 1007; ++i)
        res[i] = ' ';
    put(0, 0, len - 1, 1);
    int x = 0;
    for(int i = 1; i < 1002; ++i) {
        if(res[i] == ' ')
            cout << "NULL ";
        else {
            cout << res[i] << " ";
            if(++x == len) {
                 cout << endl;
                 break;
            } 
        }
    }
 
}