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

string solve() {
  lli r, c;
  cin >> r >> c;
  string rt = "";
  string mat[r];
  char temp[r][c];
  memset(temp, ' ', sizeof(temp));
  vector<bool> processed(false, 26);
  for(lli i=0; i<r; i++)
    cin >> mat[i];

  for(lli i=r-1;i>=1;i++) {
    // Left to right
    lli ans = true;
    vector<bool> ;
    for(lli j=0; j<c and ans; j++) {
      ans = ans and possible(i, j, mat, processed);
      tset.insert(mat[i][j]);
    }

    if(ans) {
      for(auto x:tset)
        s.insert(x);
      continue;
    }
    ans = true;
    // right to left
    tset.clear();
    for(lli j=0; j<c and ans; j++) {
      ans = ans and possible(i, j, mat, processed);
      tset.insert(mat[i][j]);
    }

    if(!ans)
      return "-1";
    else {
      for(auto x:tset)
        s.insert(x);
    }
  }
  return rt;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases, t=0;
  cin>>testcases;
  while(testcases--) {
    ++t;
    cout << "Case #" << t << ": "<<solve()<<endl;;
  }
}

