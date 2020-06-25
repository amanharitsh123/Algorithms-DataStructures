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

void reduce(vector<int> &value, int index) {
   int n = value.size();
   for(int j=0; j<n; j++) {
    value[j] -= abs(index - j);
   } 
}

void find_zeros(vector<int> &values, queue<int> &q) {
  for(int i=0; i<values.size(); i++)
    if(values[i]==0)
      q.push(i);
}

void solve() {
  string inp;
  cin >> inp;
  int t = 0, n = inp.size();
  cin >> t;
  vector<int> values;
  input(values, t);
  map<char, int> mp;
  for(auto x:inp)
    mp[x] += 1;

  queue<int> q;
  for(int i=0; i<t; i++)
    if(values[i]==0)
      q.push(i);

  int i = 0;
  string ans;
  ans.resize(t);
  char cur = 'z';
  while(q.size()) {
    int count = q.size();
    while(count>mp[cur] and cur>='a')
      --cur;

    while(q.size()) {
      ans[q.front()] = cur;
      values[q.front()] = -1;
      reduce(values, q.front());
      q.pop();
    }

    --cur;
    find_zeros(values, q);
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
