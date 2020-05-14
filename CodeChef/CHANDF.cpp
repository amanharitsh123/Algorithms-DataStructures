#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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
using namespace std;
typedef long long int lli;

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

lli power(lli num,lli base) {
  if(base==0)
    return 1;

  if(base%2)
    return (num%MOD*power(num,base-1)%MOD)%MOD;
  else {
    lli x=power(num,base/2);
    x=(x*x)%MOD;
    return x;
  }
}

lli fun(lli x, lli y, lli z) {
  return (x&z)*(y&z);
}

void solve() {
  lli x, y, l, r;
  cin >> x >> y >> l >> r;
  lli z=max(x,y);
  z=x|y;
  lli ans = 0;
  for(lli i=0;i<=63 and x!=0 and y!=0;i++) {
    if(z & 1LL<<i)
      if((ans | ( 1LL<<i)) <=r)
        ans = ans | 1LL<<i;
  }
  
  lli ans2 = 0;
  for(lli i=62; i>=0 and x!=0 and y!=0;i--) {
    if(z & 1LL<<i)
      if((ans2 | ( 1LL<<i)) <=r)
        ans2 = ans2 | 1LL<<i;
  }

  if(fun(x,y,ans) < fun(x, y, ans2))
    ans = ans2;
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

