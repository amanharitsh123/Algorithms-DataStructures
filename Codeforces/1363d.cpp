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

void print(int x,int n) {
  for(int i=x; i<=n; i++) {
    cout << i << " ";
    cout.flush();
  }
  cout << endl;
  cout.flush();
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> mat[k];
  for(int i=0; i<k; i++) {
    int size;
    cin >> size;
    input(mat[i], size);
  }

  // Find index of max element
  int lo=1, hi=n;
  cout << "? " << n << " "; // 11 query remianing
  cout.flush();
  print(1, n);
  int max_value, value;
  cin >> max_value;
  while(lo<hi) {
    int mid = (lo+hi)/2;
    cout << "? " << mid-lo+1 << " ";
    cout.flush();
    print(lo, mid);
    cin >> value;
    if(value == max_value)
      hi = mid;
    else
      lo = mid + 1;
  }

  vector<int> ans;
  for(int i=0; i<k; i++) {
    bool present = false;
    for(auto x: mat[i])
      if(x==lo)
        present = true;

    if(!present) {
      ans.push_back(max_value);
    } else {
      cout << "? " << n-mat[i].size() << " ";
      cout.flush();
      vector<bool> visited(n+1, true);
      for(auto x:mat[i])
        visited[x] = false;
      
      for(int ii=1; ii<=n; ii++) {
          if(visited[ii])
            cout << ii << " ";
          cout.flush();
      }

      cout << endl;
      cout.flush();
      int temp;
      cin >> temp;
      ans.push_back(temp);
    }
  }

  cout << "! ";
  output(ans);
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

