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
  string inp;
  getline(cin,inp);
	while(testcases--) {
    getline(cin,inp);
    vector<lli> count(26,0);
    for(auto x:inp) {
      if(isalpha(x)) {
        x=tolower(x);
        count[x-'a']++;
      }
    }
    bool ans=true;
    for(lli i=0;i<26;i++) {
      if(!count[i]) {
        cout<<char('a'+i)<<endl;
        ans=false;
        break;
      }
    }
    if(ans)
      cout<<"~"<<endl;
  }
}

