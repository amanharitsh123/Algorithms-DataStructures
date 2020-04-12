#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define MAX 100000
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
    lli n;
    cin>>n;
    vector<lli> houses;
    vector<lli> fuels;
    input(houses,n);
    input(fuels,n);
    sort(all(fuels));
    lli term=0;
    vector< vector<lli> > dp(2,vector<lli> (1001, MAX));
    for(lli i=0;i<=1;i++)
      dp[i][0]=0;
    
    for(lli j=0;j<=1000;j++) {
      for(lli i=1;i<=n;i++) {
        if(fuels[i-1]<=j)
          dp[term][j]=min(dp[term][j-fuels[i-1]]+1,dp[term^1][j]);
        else
          dp[term][j]=dp[term^1][j];
        term=term^1;
      }
    }
    lli ans=0;
    for(auto x:houses) {
      ans+=dp[term][2*x];
    }
    cout<<ans<<endl;
	}
}

