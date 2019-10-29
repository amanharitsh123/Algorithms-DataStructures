int dp[2][1000][1000];
int solve(int turn,int l,int r ,vector<int> &A) {
    
    if(l>r)
        {return 0;}
    if(l==r)
        {
            
            if(turn==0)
                return A[l];
            return 0;
        }
        
    if(dp[turn][l][r]!=-1)
        return dp[turn][l][r];
    
    if(turn==0)
        return dp[turn][l][r]=max(A[l]+solve(!turn,l+1,r,A),A[r]+solve(!turn,l,r-1,A));
    else
    {
        return dp[turn][l][r]=min(solve(!turn,l+1,r,A),solve(!turn,l,r-1,A));
        
    }

}

int Solution::maxcoin(vector<int> &A) {

    for(int i=0;i<2;i++)
        for(int j=0;j<A.size();j++)
            for(int k=0;k<A.size();k++)
                {
                    dp[i][j][k]=-1;
                }
    return solve(0,0,A.size()-1,A);
}
