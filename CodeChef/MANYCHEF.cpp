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

bool possible(string &inp,lli i) {
  string ref="CHEF";
  lli t=0;
  lli ans=true;
  vector<char> backup;
  lli x;
  for(x=i-3;x>=0 and x<=i;x++) {
    if(inp[x]!='?' and inp[x]!=ref[t]) {
      ans=false;
      break;
    } else {
      backup.push_back(inp[x]);
      inp[x]=ref[t];
    }
    ++t;
  }
  if(!ans)
    for(lli j=i-3;j<x;j++)
      inp[j]=backup[j-i+3];
  return ans and x>=0;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    string inp;
    cin>>inp;
    lli n=inp.size();
    for(lli i=n-1;i>=0;) {
      if(possible(inp,i))
        i-=4;
      else if(inp[i]=='?')
        inp[i]='A',i-=1;
      else
        --i;
    }
    cout<<inp<<endl;
	}
}

