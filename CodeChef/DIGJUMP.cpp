#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<queue>
#define all(arr) arr.begin(),arr.end()
#define pi pair<lli,lli>
#include<limits.h>
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

void bfs(string inp) {

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

void dynamic_pro(string inp) {
  lli n=inp.size();
  lli max_possible_jumps=20; // 00112233445566778899
  
  vector<lli> dp(n+2,1000000);
  
  vector<lli> chars(10,1000000);
  
  dp[1]=0;

  for(lli j=0;j<max_possible_jumps;j++) {
    // Using data from previous iteration reduce char distance array
    
    // for each char 0..9 maintain smallest value from 1st position.
    for(lli i=1;i<=n;i++) {
      lli num=inp[i-1]-'0';
      chars[num]=min(chars[num],dp[i]);
    }

    for(lli i=1;i<=n;i++) {
      lli num=inp[i-1]-'0';
      dp[i]=min(dp[i],dp[i-1]+1);
      dp[i]=min(dp[i],dp[i+1]+1);
      dp[i]=min(dp[i],chars[num]+1);
    }

  }
  cout<<dp[n]<<endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  string inp;
  cin>>inp;
  // bfs(inp);
  dynamic_pro(inp);
}

