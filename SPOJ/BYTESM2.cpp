#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,r,c;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        vector< vector<int> > mat(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>mat[i][j];
        vector<int> dp;
        dp=mat[r-1];
        for(int i=r-2;i>=0;i--)
        {
            vector<int> ans(c,0);
            for(int j=0;j<c;j++)
            {
                ans[j]=mat[i][j]+dp[j];
                if(j-1>=0)
                    ans[j]=max(ans[j],mat[i][j]+dp[j-1]);
                if(j+1<c)
                    ans[j]=max(ans[j],mat[i][j]+dp[j+1]);

            }
            dp=ans;
        }
        cout<<*max_element(dp.begin(),dp.end())<<endl; 

    }
}

// 1
// 6 5
// 3 1 7 4 2
// 2 1 3 1 1
// 1 2 2 1 8
// 2 2 1 5 3
// 2 1 4 4 4
// 5 2 7 5 1