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

struct event {
  int x;
  int y;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n);
  for(auto &x: mat)
    input(x, m);
  event startpt = {0,0};
  int ans = 0;
  int max_level = (n+m-1)/2;
  for(int i=0; i<max_level; i++) {
    //cout  << "level " << i << endl;
    lli czero = 0, cone = 0;
    lli x = startpt.x;
    lli y = startpt.y;
    lli totalpts = 0;
    while(x<n and y>=0) {
      totalpts += 2;
      lli mx = n-1-x, my = m-1-y;
      //cout << i << " " << x << " " << y << " " << mx << " " << my << endl;
      if(mat[x][y]==1)
        cone++;
      else
        czero++;
      
      if(mat[mx][my]==1)
        cone++;
      else
        czero++;
      x+=1, --y;
    }
    
    startpt.y+=1;
    if(startpt.y>=m) {
      startpt.y=m-1;
      startpt.x+=1;
    }

    ans += min(totalpts-czero , totalpts-cone);
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

