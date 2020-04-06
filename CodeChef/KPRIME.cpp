#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define N 100000
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

vector<lli> pfactor(N+1,0);
vector< vector<lli> > dp(N+1, vector<lli> (6,0));
void sieve() {
  for(lli i=2;i<=N;i++) {
    if(pfactor[i])
      continue;
    
    for(lli j=i;j<=N;j+=i)
      pfactor[j]+=1;
  }

  for(lli i=1;i<=N;i++) {
    for(lli k=1;k<=5;k++) {
      if(pfactor[i]==k)
        dp[i][k]=1+dp[i-1][k];
      else
        dp[i][k]=dp[i-1][k];
    }
  }
}


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
  sieve();
	while(testcases--) {
    lli a,b,k;
    cin>>a>>b>>k;
    cout<<dp[b][k]-dp[a-1][k]<<endl;
	}
}

