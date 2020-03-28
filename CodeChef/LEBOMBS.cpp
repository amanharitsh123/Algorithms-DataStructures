#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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
	while(testcases--) {
    lli n,count=0;
    string arr;
    string inp;
    cin>>n;
    cin>>inp;
    arr=inp;
    for(lli i=0;i<n;) {
      if(inp[i]=='1') {
        if(i-1>=0) arr[i-1]='1';
        if(i+1<n) arr[i+1]='1';
        ++i;
      } else {
        ++i;
      }
    }
    
    for(auto x:arr)
      if(x=='0') ++count;
    
    cout<<count<<endl;
	}
}

