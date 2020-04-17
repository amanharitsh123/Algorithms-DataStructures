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

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,m;
    cin>>n>>m;
    vector<lli> seq;
    input(seq,m);
    vector<lli> mat[n];
    vector<lli> itr(n,0);
    for(lli i=0;i<n;i++) {
      lli ci;
      cin>>ci;
      input(mat[i],ci);
      sort(all(mat[i]));
      itr[i]=ci-1;
    }
    lli ans=0;
    for(auto x:seq) {
      if(itr[x]==-1)
        continue;
      ans+=mat[x][itr[x]];
      --itr[x];
    }
    cout<<ans<<endl;
	}
}

