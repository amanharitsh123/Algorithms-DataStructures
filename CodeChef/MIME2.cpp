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
	
  lli n,q;
	cin>>n>>q;
  unordered_map<string,string> mp;
	while(n--) {
   string ext,type;
   cin>>ext>>type;
   mp[ext]=type;
	}
  
  while(q--) {
    string data;
    cin>>data;
    lli i=data.size()-1;
    string ans="unknown";
    
    while(i>=0 and data[i]!='.')
      --i;

    if(i<0)
      cout<<ans<<endl;
    else {
      ans="";
      ++i;
      while(i<data.size())
        ans.push_back(data[i]),++i;

      if(mp.find(ans)!=mp.end())
        cout<<mp[ans]<<endl;
      else
        cout<<"unknown"<<endl;
    }

  }
}

