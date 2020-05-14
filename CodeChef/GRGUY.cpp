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
#define MOD 1000000007

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

void solve() {
  string mat[2];
  cin >> mat[0] >> mat[1];
  lli n = mat[0].size();
  bool dp[2][2];
  int count[2][2];
  memset(dp, false, sizeof(dp));
  memset(count, inf, sizeof(count));
  dp[0][0]=true;
  count[0][0]=0;
  count[1][0]=0;
  dp[1][0]=true;
  int prev = 1;
  for(int i=1; i<=n; i++) {
    dp[0][prev] = dp[1][prev] = false;
    count[0][prev] = count[1][prev] = inf;

    for(int turn=0; turn<2; turn++) {
      if(mat[turn][i-1]=='#') {
        dp[turn][prev]=false;
      } else {
        dp[turn][prev] = dp[turn][prev^1] or dp[turn^1][prev^1];
          
        if(dp[turn^1][prev^1]==true) {
          count[turn][prev]=1+count[turn^1][prev^1];
        } 

        if(dp[turn][prev^1]==true) {
          count[turn][prev]=min(count[turn][prev], count[turn][prev^1]);
        }

      }
    }
    // jumping from turn x to turn^1 x
    int a = count[0][prev]+1;
    int b = count[1][prev]+1;
    if(a<b)
      count[1][prev]= min(count[1][prev], a);
    else 
      count[0][prev] = min(count[0][prev], b);

    prev = prev^1;
  }

  //for(int i=1;i<=n;i++)
    //cout << count[0][i] << " " << count[1][i] << endl;
  prev = prev^1;
  lli ans = min(count[0][prev], count[1][prev]);
  if(dp[0][prev] or dp[1][prev]) {
    cout << "Yes" << endl;
    cout << ans << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin>>testcases;
  while(testcases--) {
    solve();
  }
}

