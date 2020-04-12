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

lli solve(string &inp,lli i,lli j) {
  string sub;
  lli n=inp.size();
  lli count=0;
  for(lli x=i;x<=j and x<n;x++) {
    sub.push_back(inp[x]);
    if(inp[x]=='+')
      ++count;
  }
  if(sub.size()==4)
    return abs(2-count);
  else if(sub.size()==3) {
    if(sub=="---" or sub=="+++" or sub=="--+" or sub=="++-")
      return 1;
    return 0;
  } else {
    if(sub=="++" or sub=="--")
      return 1;
    return 0;
  }
  return 0;
}

char opp(char x) {
  if(x=='+')
    return '-';
  else
    return '+';
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
    lli ans=n;
    // Forward pass and backward pass
    string org=inp;
    lli temp=0;
    char target='-';
    for(lli i=0;i<n;i++) {
      if(inp[i]!=target)
        ++temp;
      target=opp(target);
    }
    
    ans=min(ans,temp);
    temp=0;
    target='+';
    for(lli j=0;j<n;j++) {
      if(inp[j]!=target)
        ++temp;
      target=opp(target);
    }

    ans=min(ans,temp);
    
    cout<<ans<<endl;
	}
}

