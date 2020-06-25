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

int N = 0;
int total = 0;
vector<int> prime;
vector<int> prime_list;

void sieve() {
  prime.resize(N, -1);
  for(int i=2; i<N; i++) {
    if(prime[i]!=-1)
      continue;
    prime_list.pb(i);
    for(int j=i; j<N; j+=i) {
      prime[j] = i;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> arr;
  input(arr, n);
  for(auto x:arr)
    N = max(N, x);

  ++N;
  sieve();
  vector<int> ans1(n), ans2(n);
  for(int i=0; i<n; i++) {
    int x = arr[i];
    int a, b;
    if(x%2==0)
      a=2, b=prime[x];
    else {
      a = prime[x];
      b = x;
      while(b%a)
        b /= a;

    }

    cout << a <<" "<<b << endl;
    if(__gcd(x,a+b)!=1)
      ans1[i] = ans2[i] = -1;
    else
      ans1[i] = a, ans2[i] = b;
  }

  output(ans1);
  output(ans2);
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

