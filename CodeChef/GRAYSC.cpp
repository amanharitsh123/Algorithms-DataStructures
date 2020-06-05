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
  lli n, x;
  cin >> n;
  vector<int> arr;
  input(arr, n);
  bool ans = n>=130;
  vector< set<int> > s;
  set<int> t;
  for(int i=n-1; i>=0 and !ans; i--) {
    t.insert(arr[i]);
    s.push_back(t);
  }

  for(int i=0; i<n and !ans; i++) {
    for(int j=i+1; j<n and !ans; j++) {
      for(int k=j+1; k<n-1 and !ans; k++) {
        x = arr[i]^arr[k]^arr[j];
        ans = s[k+1].find(x)!=s[k+1].end();
      }
    }
  }

  if(ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

