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

const int N = 1e4 + 1;
vector<int> prime_list;
vector<bool> prime(N, true);
vector<int> ans(N, 0);
void sieve() {
  for(int i=2; i<N;i++){
    if(prime[i]==false)
      continue;
    prime_list.push_back(i);
    for(int j=2*i; j<N; j+=i) {
      prime[j] = false;
    }
  }

  for(auto x:prime_list)
    for(auto y:prime_list) {
      if((x+2*y)>=N)
        break;
      ans[x+2*y]++;
    }
}

void solve() {
  int n;
  cin >> n;
  cout << ans[n] << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();
  lli testcases;
  cin>>testcases;
  while(testcases--) {
    solve();
  }
}

