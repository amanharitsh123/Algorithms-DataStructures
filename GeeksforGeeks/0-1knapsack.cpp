#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n,W;
    cin>>t;
    while(t--)
    {
        cin>>n>>W;
        int * weight = new int[n];
        int * value = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>value[i];
        }
        int weight_total=0;
        for(int i=0;i<n;i++)
        {
            cin>>weight[i];
            // weight_total+=weight[i];
        }
        // Recursion solutuion
        // F(n,v)=max(value[n]+F[n-1,v-weight[n]],F[n-1,v])
        // Base Case: F(0,v) = 0 and F(n,0)=0
        
        // dp matrix
        // vector< vector<int> > dp(n+1,vector<int>(W+1,0));
        int dp[n+1][W+1];
        
        for(int w=0;w<=W;w++)
        {
            for(int i=0;i<=n;++i)
            {
                if(i==0 or w==0)
                {
                    dp[i][w]=0;
                    continue;
                }
                dp[i][w]=dp[i-1][w];
                if(w-weight[i-1]>=0)
                dp[i][w]=max(dp[i][w],value[i-1]+dp[i-1][w-weight[i-1]]);
            }
        }
        cout<<dp[n][W]<<endl;
    }

}


// 2
// 3
// 4
// 1 2 3
// 4 5 1
// 2
// 3
// 1 2 3
// 4 5 6