#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define MOD 998244353

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

lli mul(lli a, lli b) {
  return (a%MOD*b%MOD)%MOD;
}

lli power(lli a,lli b) {
  lli ans = 1;
  while(b > 0) {
    if(b&1)
      ans = mul(ans, a);
    a = mul(a,a);;
    b >>= 1;
  }
  return ans;
}

lli dp[3001][3001];

void solve() {
  lli n, sum;
  cin >> n >> sum;
  vector<lli> arr;
  input(arr, n);
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for(lli i=1; i<=n; i++) {
    dp[i][0] = mul(2, dp[i-1][0]);
  }

  for(lli s=1; s<=sum; s++) {
    for(lli i=1; i<=n; i++) {
      if(arr[i-1]<=s) {
        dp[i][s] = (dp[i-1][s-arr[i-1]]%MOD + mul(dp[i-1][s], 2)%MOD)%MOD;
      } else {
        dp[i][s] = mul(dp[i-1][s], 2);
      }
    }
  }

  cout << dp[n][sum] << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

