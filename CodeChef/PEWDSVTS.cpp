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
void input_set(priority_queue<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push(temp);
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
  double a, b, x, y, z;
  cin >> n >> a >> b >> x >> y >> z;
  priority_queue<lli> s;
  input_set(s, n);
  lli d1 = ceil((z-a)/x);
  lli d2 = ceil((z-b)/y);
  if(d2>d1) {
    cout << 0 << endl;
    return;
  }

  lli additional = z-x*(d2-1)-a, c = 0;
  while(additional > 0 and s.size()!=0) {
    ++c;
    lli t = s.top();
    s.pop();
    additional -= t;
    t /= 2;

    if(t!=0)
      s.push(t);
  }

  if(additional <= 0)
    cout << c << endl;
  else
    cout << "RIP" << endl;

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

