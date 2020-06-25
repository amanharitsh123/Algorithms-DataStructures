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

map<char, int> mp;
int possible(string &inp, int k) {
  int ans = 0;
  if(inp.size()<k)
    return 0;

  ans = k;
  int target = k;
  for(int div=2;;div++) {
    target = k;
    for(char x='a'; x<='z'; x++) {
      int f = mp[x]/div;
      target -= f;
    }

    if(target>0)
      return ans;
    ans = max(ans, div*k);
  }
}

void solve() {
  int n, k;
  string inp;
  cin >> n >> k;
  vector<int> factors;
  cin >> inp;
  mp.clear();
  for(auto x:inp)
    mp[x]+=1;

  int max_same_count = 0;
  for(char x='a'; x<='z'; x++)
    max_same_count = max(max_same_count, mp[x]);

  for(int i=1; i*i<=k; i++) {
    if(k%i)
      continue;

    factors.pb(i);
    if(i != k/i)
      factors.pb(k/i);
  }

  int ans = max_same_count;
  for(auto x:factors)
    ans = max(ans, possible(inp, x));

  cout << ans << endl;
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
