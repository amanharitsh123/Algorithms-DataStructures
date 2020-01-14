#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
lli k;
// Failed due to memory limit exceeded due to value of p : 2*10**9
lli solve(vector<lli> &arr,lli i,lli m,vector< vector<lli> > &dp) {
  if(i<0)
    return 0;
  if(dp[i][m]!=-1)
    return dp[i][m];
  dp[i][m] = solve(arr,i-1,m,dp);
  if(i+1>=k and m-arr[i]>=0)
    dp[i][m]=max(dp[i][m],k+solve(arr,i-k,m-arr[i],dp));
  else if(m-arr[i]>=0)
    dp[i][m] = max(dp[i][m],1+solve(arr,i-1,m-arr[i],dp));
  return dp[i][m];
}

int main() {
	lli t;
	cin>>t;
	while(t--) {
    lli n,p;
    cin>>n>>p>>k;
    vector<lli> arr(n);
    For(0,n)
      cin>>arr[I];
    sort(arr.begin(),arr.end());
    // DP states are F(M,i) = max(F(M,i-1),k+F(M-ai,i-k))
    //vector< vector<lli> > dp( n , vector<lli> (p+1, -1));
    //cout<<solve(arr,n-1,p,dp)<<endl;
    lli ans = 0;
    lli pref = 0;
    for(lli i=0;i<k and pref<=p;i++)
    {
      lli budget=pref;
      lli cnt = 0;
      for(lli j=i+k-1;j<n and budget+arr[j]<=p;j+=k)
      {
        budget += arr[j];
        cnt+=k;
      }
      ans = max(ans,i+cnt);
      pref += arr[i];
    }
    cout<<ans<<endl;
	}
}
