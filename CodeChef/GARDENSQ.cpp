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
  int n, m;
  cin >> n >> m;
  vector<string> mat;
  for(int i=0; i<n; i++) {
    string temp;
    cin >> temp;
    mat.push_back(temp);
  }

  lli ans = 0;
  map<char, vector<int> > mp;
  for(int i=0; i<n; i++) {
    mp.clear();
    for(int j=0; j<m; j++) {
      if(mp.find(mat[i][j])!=mp.end()) {
        for(auto k:mp[mat[i][j]]) {
          int base = i+j-k;
          if(base>=n)
            continue;
          
          if(mat[i][k]==mat[base][k] and mat[i][j]==mat[base][j])
            ++ans;
        }
      }
      mp[mat[i][j]].push_back(j);
    }
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

