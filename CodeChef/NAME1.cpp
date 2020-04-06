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
    string a,b;
    vector<lli> pcount(26,0);
    vector<lli> count(26,0);
    lli n;
    cin>>a>>b>>n;
    
    for(char x:a)
      pcount[x-'a']++;
    
    for(char x:b)
      pcount[x-'a']++;
    
    for(lli i=0;i<n;i++) {
      string temp;
      cin>>temp;
      for(char x:temp)
        count[x-'a']++;
    }

    bool ans=true;

    for(char x=0;x<26;x++)
      if(count[x]>pcount[x]) {
        ans=false;
        break;
      }
    
    if(ans)
      cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	}
}

