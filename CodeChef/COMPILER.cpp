#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<utility>
#include<stack>
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
	lli testcases;
	cin>>testcases;
  lli ans=0;
	while(testcases--) {
    ans=0;
    string inp;
    cin>>inp;
    stack< pair<char,lli>  > st;
    st.push({'a',-1});
    for(int i=0;i<inp.size();i++) {
      if(inp[i]=='<') {
        st.push({inp[i],i});
        continue;
      }
      if(st.top().first=='<') {
          st.pop();
          if(st.top().second==-1) ans=max(ans,i-st.top().second);
      } else {
        st.push({inp[i],i});
      }
    }
    cout<<ans<<endl;
  }
}

