bool convert(char x){
    if(x=='T')
        return true;
    if(x=='F')
        return false;
    return  false;
}

int Solution::cnttrue(string A) {

    // mod factor
    int mod = 1003;
    
    
    int f[A.size()][A.size()];
    int t[A.size()][A.size()];
    
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++){
            t[i][j]=0;
            f[i][j]=0;
        }
    }
    
    for(int i=0;i<A.size();i++)
    {
        if(convert(A[i]))
        {
            
            t[i][i]=1;
            f[i][i]=0;
        } else
        {
            
            t[i][i]=0;
            f[i][i]=1;
        }
    }

    for(int sa=3;sa<=A.size();sa+=2)
    {
        for(int i=0;i<A.size();i+=2)
        {
            int lo=i;
            int hi=i+sa-1;
            hi=min(hi,int(A.size())-1);
            int ans_true=0;
            int ans_false=0;
            
            if(lo==hi)
                continue;

            for(int j=lo;j<=hi;j++)
            {
                if(A[j]=='|')
                {
                    ans_true += (t[lo][j-1]*t[j+1][hi]) + (t[lo][j-1]*f[j+1][hi]) + (f[lo][j-1]*t[j+1][hi]);
                    ans_false += (f[lo][j-1]*f[j+1][hi]);
                }
                else if(A[j]=='&')
                {
                    ans_true += (t[lo][j-1]*t[j+1][hi]);
                    ans_false += (f[lo][j-1]*f[j+1][hi]) + (t[lo][j-1]*f[j+1][hi]) + (f[lo][j-1]*t[j+1][hi]);
                } 
                else if(A[j]=='^')
                {
                    ans_true +=  (t[lo][j-1]*f[j+1][hi]) + (f[lo][j-1]*t[j+1][hi]);
                    ans_false += (t[lo][j-1]*t[j+1][hi]) + (f[lo][j-1]*f[j+1][hi]);
                }
            }
            
            t[lo][hi] = ans_true%mod;
            f[lo][hi] = ans_false%mod;

        }
    }
    
    
    
    return t[0][A.size()-1];
}
