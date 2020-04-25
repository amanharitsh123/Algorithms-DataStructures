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

struct cust {
  lli d,f,b;
  bool operator<(const cust &o) const {
    return f>o.f;
  }
};

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,m;
    cin>>n>>m;
    vector<lli> count;
    input(count,m);
    map<lli,vector<cust> > mp;
    vector<lli> ans(n,-1);
    vector<pair<lli,cust>> unassigned;
    lli profit=0;
    for(lli i=0;i<n;i++) {
      cust x;
      cin>>x.d>>x.f>>x.b;
      x.d--;
      if(count[x.d]) {
        profit+=x.f;
        ans[i]=x.d+1;
        --count[x.d];
      } else {
        unassigned.push_back({i,x});
      }
    }

    lli i=0;
    for(auto x:unassigned) {
      while(count[i]==0)
        ++i;
      ans[x.first]=i+1;
      count[i]--;
      profit+=x.second.b;
    }

    cout<<profit<<endl;
    output(ans);
  }
}

