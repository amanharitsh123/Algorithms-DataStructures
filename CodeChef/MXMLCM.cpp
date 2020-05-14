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
#define N 10001

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) {cout<<x<<" ";};
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

lli power(lli num,lli base) {
  lli ans = 1;
  while(base>0) {
    if(base&1)
      ans = mul(ans, num);

    num = mul(num, num);
    base >>= 1;
  }

  return ans;
}

bool prime[10001];
vector<lli> prime_list[10001];
void sieve() {
  memset(prime, true, sizeof(prime));
  for(lli i=2; i<N; i++) {
    if(!prime[i])
      continue;
    prime_list[i].push_back(i);
    for(lli j=2*i; j<N; j+=i) {
      prime_list[j].push_back(i);
      prime[j]=false;
    }
  }
}


void solve() {
  lli n, m;
  cin >> n >> m;
  vector<lli> arr;
  input(arr, n);
  lli lcm = 1;
  lli number = 1;
  map<lli, lli> mp;
  for(auto x:arr) {
    for(auto y:prime_list[x]) {
      lli count = 0, t=x;
      while(t%y==0)
        t/=y, ++count;
      mp[y] += 0;
      mp[y] = max(mp[y], count);
    }
  }

  for(lli i=2;i<=m;i++) {
    lli new_lcm = 1;
    for(auto x:prime_list[i]) {
      lli count = 0, t=i;
      while(t%x==0)
        t/=x, ++count;
      
      if(count > mp[x]) {
        count -= mp[x];
        while(count--)
          new_lcm *= x;
      }
    }

    if(new_lcm > lcm) {
      lcm = new_lcm;
      number = i;
    }
  }

  cout << number << endl;
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

