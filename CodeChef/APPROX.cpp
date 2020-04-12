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
    lli k=0;
    cin>>k;
    if(k!=0)
      cout<<"3.";
    else
      cout<<"3";
    lli a=103993,b=33102;
    a=a-3*b;
    while(k--) {
      a=a*10;
      if(a<b) {
        cout<<0;
      } else {
        cout<<a/b;
        a=a-(a/b)*b;
      }
    }
    cout<<endl;
	}
}

