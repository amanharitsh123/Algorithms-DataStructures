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
lli prime = 31;
vector<lli> h;
vector<lli> powprime;

lli gethash(lli i, lli j) {
  lli x = (h[j+1]-h[i]+MOD)%MOD;
  x = mul(x, powprime[powprime.size()-1-i]);
  return x;
}

void solve() {
  string inp;
  cin >> inp;
  lli n = inp.size();
  h.resize(n+1, 0);
  powprime.resize(n, 0);
  lli p = 1;

  // hash compute
  lli hash_value = 0;
  for(int i=0; i<n; i++) {
    powprime[i] = p;
    p = mul(p, prime); 
    hash_value = (hash_value + mul(inp[i]-'a'+1LL, powprime[i]))%MOD;
    h[i+1] = hash_value;
  }

  lli ans = 0;
  for(int i=1; i<=n-3; i+=2) {
    lli s1 = gethash(0, i/2);
    lli s2 = gethash(i/2 + 1, i);
    lli s3 = gethash(i+1, (n+i)/2);
    lli s4 = gethash((n+i)/2+1, n-1);

    if(s1==s2 and s3==s4)
      ++ans;
  }

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

