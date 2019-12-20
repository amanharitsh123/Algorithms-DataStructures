#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    lli t;
    cin>>t;
    while(t--)
    {       
        lli n,m;
        cin>>n>>m;
        std::vector<std::vector<int>> inp(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
        std::vector<std::vector<int>> ans(n+1, std::vector<int>(m+1, 0));
        for(lli i=1;i<=n;i++)
            for(lli j=1;j<=m;j++)
            {
                cin>>inp[i-1][j-1];
                dp[i][j] = dp[i-1][j];
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
                if(j+1<=m)
                    dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
                if(inp[i-1][j-1]<=dp[i][j])
                    ans[i][j]=0;
                else
                    ans[i][j]=1;
                dp[i][j] = max(dp[i][j],inp[i-1][j-1]);

            }
        for(lli i=1;i<=n;i++)
        {
            for(lli j=1;j<=m;j++)
            {
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }    
}