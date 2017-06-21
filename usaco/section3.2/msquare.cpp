/*
PROG: msquare
LANG: C++
*/

//2017.6.18
//不会做。。。真的不会做。。抄一波答案 不得不说腿神好厉害 把每个状态用字符串来表示
//bfs 因为需要的是最少的操作数
#include<iostream>
#include<fstream>
#include<set>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

ifstream fin("msquare.in");
ofstream fout("msquare.out");

struct Node
{
    string s1, s2;
    int d;
    Node(string _s1, string _s2, int _d) {
        s1 = _s1;  //表示数字的字符串
        s2 = _s2;  //记录翻转操作序列的结果字符串
        d = _d;    //记录操作序列的长度
    }
};

string tmp = ""; 
set<string> ss; 
queue<Node> Q; //宽搜

Node bfs()
{
    //初始假设为12345678
    if(tmp == "12345678") return Node("", "", 0);
    Q.push(Node("12345678", "", 0));
    ss.insert("12345678");
    while(!Q.empty())
    {
        Node cur = Q.front(); Q.pop();
        string C = cur.s1;
        //A情况
        string A(C.rbegin(), C.rend());
        if(A == tmp)
            return Node(A, cur.s2 + "A", cur.d + 1);
        if(!ss.count(A))
        {
            ss.insert(A);
            Q.push(Node(A, cur.s2 + "A", cur.d + 1));
        }
        //B情况
        string B(C[3]+C.substr(0,3)+C.substr(5)+C[4]);
        if(B == tmp)
            return Node(B, cur.s2 + "B", cur.d + 1);
        if(!ss.count(B))
        {
            ss.insert(B);
            Q.push(Node(B, cur.s2 + "B", cur.d + 1));
        }
        //C情况
        swap(C[1],C[2]);swap(C[1],C[5]);swap(C[1],C[6]);
        if(C == tmp)
            return Node(C, cur.s2 + "C", cur.d + 1);
        if(!ss.count(C))
        {
            ss.insert(C);
            Q.push(Node(C, cur.s2 + "C", cur.d + 1));
        }
    }
}
int main()
{
    char in; 
    for(int i = 0; i < 8; ++i) 
    {
        fin >> in; tmp += in;
    }
    Node res = bfs();
    fout << res.d << endl << res.s2 << endl;
    return 0;
}