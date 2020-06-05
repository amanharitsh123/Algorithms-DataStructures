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
#define MOD 9

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

lli foo(lli n) {
  while(true) {
    lli sum = 0;
    while(n) {
      sum += n%10;
      n /= 10;
    }

   if(sum < 10)
     return sum;
   n = sum;
  }
}
lli power(lli a,lli b) {
  lli ans = 1;
  while(b > 0) {
    if(b&1) {
      ans = ans*foo(a);
      ans = foo(ans);
    }
    a = foo(foo(a)*foo(a));
    b >>= 1;
  }
  return ans;
}

void solve() {
  lli a, n;
  cin >> a >> n;
  if(a%9==0) {
    cout << 9 << endl;
    return;
  }
  cout << power(a, n) << endl;
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

