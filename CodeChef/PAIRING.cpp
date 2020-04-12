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
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    vector< pair<lli,lli> > arr;
    lli n,m;
    cin>>n>>m;
    for(lli i=0;i<m;i++) {
      lli p,q;
      cin>>p>>q;
      arr.push_back({p,q});
    }

    vector<lli> visited(n,0);
    vector<lli> ans;
    for(lli i=m-1;i>=0;i--) {
      lli u,v;
      u=arr[i].first;
      v=arr[i].second;
      if(!visited[u] and !visited[v]) {
        ans.push_back(i);
        visited[u]=1;
        visited[v]=1;
      }
    }
    reverse(all(ans));
    output(ans);
	}
}

