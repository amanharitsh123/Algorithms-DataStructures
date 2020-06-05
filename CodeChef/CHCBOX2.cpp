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
  lli n;
  vector<int> arr;
  cin >> n;
  input(arr, n);
  int lo = 0;
  int hi = n-1;
  int ma = 0;
  lli ans = 0;
  for(int i=0; i<n; i++)
    ma = max(ma, arr[i]);

  while(arr[lo] != ma or arr[hi] != ma) {
    if(arr[lo] != ma)
      ++lo;

    if(arr[hi] != ma)
      --hi;
  }

  ans += max(lo + n-hi-1 - n/2+1LL, 0LL);
  lli prev = lo;
  while(lo<=hi) {
    if(arr[lo]==ma)
      ans += max(((lo-prev - (n/2) + 1LL)), 0LL);
    prev = lo;
    ++lo;
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

