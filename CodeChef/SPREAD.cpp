#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
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
  T temp;
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

vector<lli> tree;

void update(int x, lli val) {
  for(;x<tree.size();x+=(x&-x))
    tree[x]+=val;
}

lli sum(int x) {
  lli ans=0;
  while(x>0) {
    ans+=tree[x];
    x-=(x&-x);
  }
  return ans;
}

void range_update(lli l,lli r,lli val) {
  lli n=r-l+1;
  update(l,val);
  update(r+1,-val);
}

//lli range_sum(lli l, lli r) {
//    return sum(r)-sum(l);
//}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli n,m,c;
  cin>>n>>m>>c;
  tree.resize(n+1,0);
  range_update(1,n,c);
  char s;
  lli u,v,k;

  while(m--) {
    cin>>s;
    if(s=='S') {
      cin>>u>>v>>k;
      range_update(u,v,k);
    } else {
      cin>>u;
      cout<<sum(u)<<endl;
    }

    //output(tree);
  }

}

