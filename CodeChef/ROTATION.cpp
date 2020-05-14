#include<bits/stdc++.h>
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

void solve() {
  lli n, m;
  cin >> n >> m;
  vector<lli> arr;
  input(arr, n);

  lli i, offset = 0, d = 0;
  while(m--) {
    string type;
    cin >> type >> d;
    if(abs(offset)>=n) {
      bool neg = offset < 0;
      offset = abs(offset)%n;
      if(neg)
        offset = -offset;

    }

    if(type=="A") {
      offset += d;
    } else if(type=="C") {
      offset -= d;
    } else {
      --d;
      d -= offset;
      if(d<0)
        d = (n+d)%n;
      else
        d = d%n;
      cout << arr[d] << endl;
    }
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases = 1;
  while(testcases--) {
    solve();
  }
}

