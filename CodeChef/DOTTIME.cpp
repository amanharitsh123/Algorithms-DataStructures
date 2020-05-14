#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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
#define kick(t,a) cout<<"Case #"<<t<<": "<<a<<endl;

using namespace std;
typedef unsigned long long int lli;

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

#define N 500002
#define MOD 998244353 
vector<lli> tree;

void update(lli target, lli new_val, lli old_val) {
  while(target<tree.size()) {
    tree[target] = (tree[target]%MOD-old_val%MOD)%MOD;
    tree[target] = (tree[target]%MOD+new_val%MOD)%MOD;
    target += target & -target;
  }
}

lli sum(lli target) {
  lli ans = 0;
  while(target > 0) {
    ans = (ans%MOD + tree[target]%MOD)%MOD;
    target -= target & -target;
  }
  return ans;
}

lli sum_range(lli l, lli r) {
  return (sum(r)%MOD - sum(l-1)%MOD)%MOD;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin >> testcases;
  while(testcases--) {
    lli n, m, q;
    cin >> n >> m >> q;
    tree.resize(n+1, 0);
    for(lli i=0; i<n; i++) {
      lli temp;
      cin >> temp;
      update(i+1, temp, 0);
    }

    for(lli i=0; i<q; i++) {
      lli pos, val;
      cin >> pos >> val;
      update(pos, val, sum_range(pos,pos));
      lli ans = 0;
      for(lli i=0; i<m; i++) {
        lli temp = sum_range(i+1, i+n-m+1) %MOD;
        temp = (temp%MOD*temp%MOD)%MOD;
        ans = (ans%MOD + temp%MOD)%MOD;
      }

      cout << ans << endl;
    }
  }
}

