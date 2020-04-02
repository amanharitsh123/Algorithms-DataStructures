#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
using namespace std;
typedef long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  T temp;
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,k;
    cin>>n>>k;
    vector<lli> arr;
    input(arr,n);
    lli ans=k;
    vector< vector<lli> > dp(n+1,vector<lli> (1024,0));
    dp[0][0]=1;
    for(lli i=1;i<=n;i++) {
      for(lli j=0;j<1024;j++) {
        dp[i][j]=dp[i-1][j] | dp[i-1][j^arr[i-1]];
        if(dp[i][j]) ans=max(ans,j^k);
      }
    }
    cout<<ans<<endl;
	}
}

