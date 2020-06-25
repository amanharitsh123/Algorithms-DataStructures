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
  vector<lli> arr;
  cin >> n;
  input(arr, n);
  vector<lli> ans(n, 0);
  vector<lli> assigned(100001, false);
  for(auto x:arr)
    assigned[x] = true;

  int num = 0;
  queue<int> q;
  for(int i=0; i<n; i++) {
    while(assigned[num])
      ++num;
    
    if(q.size()==0)
      ans[i] = num, ++num; 
    else
      ans[i] = q.front(), q.pop();

    if(i+1<n and arr[i]!=arr[i+1])
      q.push(arr[i]);
  }

  output(ans);
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  cin >> testcases;
  while(testcases--) {
    solve();
  }
}
