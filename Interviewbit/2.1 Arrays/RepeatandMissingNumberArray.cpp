vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int sum=0;
    long long int count=1;
    long long int xor_factor=0,sumofsquares=0,tsum=0;
     int a,b;
     int ma=-1;
     
    for(int i=0;i<A.size();i++)
    {
        tsum=A[i];
        sum+=(count-tsum);
        // ma=max(ma,A[i]);
        // xor_factor^=A[i]^count;
        sumofsquares+=(count*count-tsum*tsum);
        count+=1;
        
    }
    // cout<<sumofsquares<<" "<<sum<<endl;
    
    long long int temp=sumofsquares/sum;
    b=(temp+sum)/2;
    a=b-sum;
    vector<int> ans={a,b};
    return ans;
    
}
