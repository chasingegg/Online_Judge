#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size() ;
        int p_indx[m]; 
        for(int i=0; i<m;i++) p_indx[i]=0;
        int dp[n+1]; dp[0]=1;
        
        for(int i=1 ; i<n; i++)
        {
            dp[i]=INT_MAX;
            for(int j=0; j<m; j++) 
            {
                if(dp[p_indx[j]]*primes[j] < dp[i]) dp[i]=dp[p_indx[j]]*primes[j];
            }
            for(int j=0; j<m;j++)
            {
                if(dp[i]==dp[p_indx[j]]*primes[j]) p_indx[j]++;
            }
        }
        
        return dp[n-1];   
    }
};