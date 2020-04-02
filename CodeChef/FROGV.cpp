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


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases=1;
	while(testcases--) {
    lli n,k,p;
    cin>>n>>k>>p;
    vector<lli> coords;
    input(coords,n);
    vector<lli> sorted(coords.begin(),coords.end());
    sort(all(sorted));
    vector<lli> sum(n,0);
    for(lli i=0;i<n;i++) {
      if(sorted[i]-sorted[i-1]>k)
        sum[i]++,sum[i]+=sum[i-1];
      else
        sum[i]=sum[i-1];
    }
    for(lli test=0;test<p;test++) {
      lli a,b;
      cin>>a>>b,--a,--b;
      a=coords[a];
      b=coords[b];
      lli i=lower_bound(all(sorted),a)-sorted.begin();
      lli j=lower_bound(all(sorted),b)-sorted.begin();
      j=min(j,n-1LL);
      if(sum[j]-sum[i]==0)
        cout<<"Yes"<<endl;
      else
        cout<<"No"<<endl;
    }
	}
}

