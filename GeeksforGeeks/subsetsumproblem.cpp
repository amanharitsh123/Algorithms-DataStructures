#include <iostream>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

bool solve(int* arr,int sum,int index,int size,int target,unordered_map< pair<int,int> ,int,hash_pair> &dp)
{
    if(target==sum)
        return true;
    if( dp.find( make_pair(index,sum) ) != dp.end() )
        return dp[make_pair(index,sum)];
    
    if(index >= size or sum > target)
        return false;
    return dp[make_pair(index,sum)]=solve(arr,sum+arr[index],index+1,size,target,dp) or solve(arr,sum,index+1,size,target,dp);
}

bool possible(int* arr,int size,int target)
{
    // O(N^2) Solution Top Down
    // return solve(arr,0,0,size,target,dp);
    // O(N^2) Bottom Up
    unordered_map< pair<int,int> ,int,hash_pair> dp;
    vector< vector<int> > v(target+1 ,vector<int> (size+1,0));
    
    // sum 0 with any number of elements
    for(int i=0;i<=size;i++)
        v[0][i]=true;
    
    // any sum with zero elements other than one
    for(int i=1;i<=target;i++)
        v[i][0]=false;
    
    for(int sum=1;sum<=target;sum++)
        for(int i=1;i<=size;i++)
        {
            v[sum][i]=v[sum][i-1];
            if(sum-arr[i-1] >=0)
                v[sum][i] = v[sum][i] or v[sum-arr[i-1]][i-1];
        }
    return v[target][size];


    

}

int main() {
	int t,n,sum;
    bool ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int * arr = new int[n];
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum%2==0 and possible(arr,n,sum/2))
        {
            cout<<"YES"<<endl;
        } else
        {
            cout<<"NO"<<endl;
        }

    }
	return 0;
}

// 2
// 4
// 1 5 11 5
// 3
// 1 3 5 