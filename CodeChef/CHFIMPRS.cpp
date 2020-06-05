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
  int n, m, ele;
  cin >> n >> m;
  map<int, int> mp;
  set<pi> odd;
  set<pi> even;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> ele;
      mp[ele] += 1;
    }
  }

  for(auto x:mp) {
    if(x.second & 1)
      odd.insert({-x.second, x.first});
    else
      even.insert({-x.second, x.first});
  }

  
  vector< vector<int> > arr;
  for(int i=0; i<n; i++) {
    vector<int> temp(m);
    int eeee = m/2;
    if(m%2==0)
      --eeee;
    for(int j=0; j<=eeee; j++) {
      int k = m-j-1;
      if(k==j) {
        pi e;

        if(odd.size()==0) {
          e = *even.begin();
          even.erase(even.begin());
        } else {
          e = *odd.begin();
          odd.erase(odd.begin());
        }

        temp[j] = e.second;
        e.first++;
        if(e.first%2!=0)
          odd.insert(e);
        else if(e.first!=0)
          even.insert(e);
      } else {
        if(even.size()==0 and -1*(*odd.begin()).first==1) {
          cout << -1 << endl;
          return;
        }

        pi e;
        if(even.size()==0) {
          e = *odd.begin();
          odd.erase(odd.begin());
        } else {
          e = *even.begin();
          even.erase(even.begin());
        }

        temp[j] = temp[k] = e.second;
        e.first+=2;
        if(e.first%2!=0)
          odd.insert(e);
        else if(e.first!=0)
          even.insert(e);
      }
    }
    arr.push_back(temp);
  }

  for(int i=0; i<n; i++)
    output(arr[i]);
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

