/*
PROG: shopping
LANG: C++
*/

//2017.6.27
//dp问题 dp[][][][][] 最多五种商品 把表填满

#include<iostream>
#include<fstream>

using namespace std;



int dp[6][6][6][6][6];
int s, b;

struct youhui
{
    int index;
    int num;
};
youhui pai[100][6];
int yPrice[100];
int num_wu[100];
int buy[6][3];
int nyouhui[100][6];

int min(int a, int b)
{
    return a < b ? a : b;
}
void buyListSort()
{
    bool flag = false;
    for(int i = 0; i < b; ++i) {
        for(int j = 0; j <= b - 2; ++j)
            if(buy[j][0] > buy[j+1][0])
            {
                flag = true;
                int a,b,c;
                a = buy[j][0]; b = buy[j][1]; c = buy[j][2];
                buy[j][0] = buy[j+1][0]; buy[j][1] = buy[j+1][1]; buy[j][2] = buy[j+1][2];
                buy[j+1][0] = a; buy[j+1][1] = b; buy[j+1][2] = c;
            }
        if(!flag)break;
    }
}
void buildYH()
{
    for(int i=0; i < s; ++i){
        for(int j = 0; j < num_wu[i]; ++j)
        {
            int p = pai[i][j].index;
            for(int k =0; k < 5; ++k)
                if(p == buy[k][0]) { nyouhui[i][k] = pai[i][j].num; break;}
        }
        nyouhui[i][5] = yPrice[i];
    }
}

int main()
{
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    cin >> s;
    int n;
    for(int i = 0; i < s; ++i)
    {
        cin >> num_wu[i]; 
        for(int j = 0; j < num_wu[i]; ++j)
        {   
            int a, b;
            cin >> a >> b;
            pai[i][j].index = a; pai[i][j].num = b;
        }
        cin >> yPrice[i];
    }
    cin >> b;
    for(int i = 0; i < b; ++i)
    {   
        cin >> buy[i][0] >> buy[i][1] >> buy[i][2];
    }

    buyListSort();
    buildYH();

    dp[0][0][0][0][0] = 0;
    for(int x1 = 0;x1 < 6;++x1)
        for(int x2 = 0;x2 < 6;++x2)
            for(int x3 = 0;x3 < 6;++x3)
                for(int x4 = 0;x4 < 6;++x4)
                    for(int x5 = 0;x5 < 6;++x5)
                    {
                        dp[x1][x2][x3][x4][x5] = x1 * buy[0][2] + x2 * buy[1][2] + x3 * buy[2][2] + x4 * buy[3][2] + x5 * buy[4][2];
                        for(int i = 0; i < s; ++i)
                        {
                            if(x1 - nyouhui[i][0] >=0 && x2 - nyouhui[i][1] >=0 && x3 - nyouhui[i][2] >=0 && x4 - nyouhui[i][3] >=0 && x5 - nyouhui[i][4] >=0)
                                dp[x1][x2][x3][x4][x5] = min(dp[x1][x2][x3][x4][x5],(dp[x1 - nyouhui[i][0]][x2 - nyouhui[i][1]][x3 - nyouhui[i][2]][x4 - nyouhui[i][3]][x5 - nyouhui[i][4]] + nyouhui[i][5]));
                        }
                    }
    cout << dp[buy[0][1]][buy[1][1]][buy[2][1]][buy[3][1]][buy[4][1]] << endl;


    return 0;
}