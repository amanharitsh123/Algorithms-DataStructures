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

lli bs(lli n, lli s) {
  lli lo = 0, hi = n-1;
  while(lo<hi) {
    lli mid = (lo+hi)/2;
    lli count = n-mid;
    lli sum = count*n - count*(count+1LL)/2LL;
    if(sum >=s)
      lo = mid+1;
    else
      hi = mid-1;
  }

  lli count = n-lo;
  lli sum  = count*n - count*(count + 1LL)/2LL;
  if(sum >= s)
    return n-lo;
  else
    return n-lo+1;
  //return n-hi;
}

void solve() {
  /*
   T = n*(n+1)/2
   s = given sum
   1) T == s (0 ops)
   2) T > s (Binary search)
   3) T < s (Not possible)
  */

  lli n, s, t;
  cin >> n >> s;
  t = n*(n+1)/2LL;
  if(t==s)
    cout << 0 << endl;
  else 
    cout << bs(n, t-s) << endl;
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

