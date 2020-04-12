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

void get_count(unordered_map<char,lli> &mp, string &a){
  for(auto x:a)
    if(mp.find(x)!=mp.end())
      ++mp[x];
    else
      mp[x]=1;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    string a,b;
    cin>>a>>b;
    unordered_map<char,lli> mp1,mp2;
    get_count(mp1,a);
    get_count(mp2,b);
    bool ans1=true,ans2=true;
    for(char x='a';x<='z';++x) {
      if((mp1.find(x)==mp1.end()) and (mp2.find(x)==mp2.end()))
        continue;

      if((mp1.find(x)!=mp1.end()) and (mp2.find(x)!=mp2.end())) {
        ans1=ans1 and (mp1[x]==mp2[x]);
      } else {
        ans2=false;
        ans1=false;
      }
    }
    if((ans1 and ans2) or (!ans1 and !ans2))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
	}
}

