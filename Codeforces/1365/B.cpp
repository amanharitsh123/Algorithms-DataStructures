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

int find_max(vector<int> &arr) {
  int ans = 0;
  for(auto x:arr)
    ans = max(ans, x);
  
  return ans;
}

int find_min(vector<int> &arr) {
  int ans = 2;
  for(auto x:arr)
    ans = min(x, ans);
  return ans;
}

void solve() {
  int n;
  vector<int> arr;
  vector<int> type;
  cin >> n;
  input(arr, n);
  input(type, n);
  bool both = false;
  int ma=find_max(type), mi = find_min(type);
  both = ma==1 and mi==0;
  vector<pi> temp;
  vector<int> target(n, -1);
  for(int i=0; i<n; i++) 
    temp.push_back({arr[i], i});

  sort(all(temp));
  for(int i=0; i<n; i++)
    target[temp[i].second]=i;

  vector<bool> processed(n, false);
  bool possible = true;
  for(int i=0; i<n; i++) {
    int t = type[i];
    bool same_type = true;
    // Already at correct position
    if(target[i]==i or processed[i])
      continue;

    int x = target[i];
    while(x != i) {
      if(type[x]!=t)
        same_type = false;

      processed[x] = true;
      x = target[x];
    }

    if(same_type and !both) {
      possible = false;
    }
  }

  if(possible)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
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

