#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<queue>
#define all(arr) arr.begin(),arr.end()
#define pi pair<lli,lli>
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
	
  string inp;
  cin>>inp;
  lli n=inp.size();
  queue<pi> q;
  unordered_map<lli,lli> visited;
  unordered_map<char, vector<lli> > adj;
  for(lli i=0;i<n;i++) {
    char c=inp[i];
    if(adj.find(c)!=adj.end())
      adj[c].push_back(i);
    else {
      vector<lli> arr(1,i);
      adj[c]=arr;
    }
  }
  visited[0]=1;
  q.push({0,0});
  while(q.size()) {
    auto top=q.front();
    lli i=top.first,depth=top.second;
    q.pop();
    if(i==n-1) {
      cout<<depth<<endl;
      break;
    }
    char c=inp[i];
    
    for(auto e:adj[c]) 
      if(visited.find(e)==visited.end())
        visited[e]=1,q.push({e,depth+1});
    
    adj[c].clear();
    
    if(i+1<n and visited.find(i+1)==visited.end())
      visited[i+1]=1,q.push({i+1,depth+1});
    
    if(i-1>=0 and visited.find(i-1)==visited.end())
      visited[i-1]=1,q.push({i-1,depth+1});
  }

}

