#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
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



lli N=1000000;
vector<lli> prime(N + 1,1);
vector<lli> level[500001];

void sieve() {
  level[1].push_back(1);
  
  for(lli i=2;i<=N;i++) {
    if(prime[i]) {
      lli cc=1;
      level[cc++].push_back(i);
      for(lli j=i+i;j<=N;j+=i) {
        if(prime[j]) {
          prime[j]=0;
          level[cc++].push_back(j);
        }
      }
    }
  }
}



int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
  sieve();
	while(testcases--) {
    lli n;
    cin>>n;
    cout<<(n/2)<<endl;
    for(lli i=1;i<=(n/2);i++) {
      auto it=upper_bound(all(level[i]),n);
      if(it!=level[i].end() and *it <=n)
        cout<<it-level[i].begin()+1<<" ";
      else
        cout<<it-level[i].begin()<<" ";
      for(auto x=level[i].begin();*x<=n;x++)
        cout<<*x<<" ";
      cout<<endl;
    }
	}
}

