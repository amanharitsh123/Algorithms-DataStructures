#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end();
using namespace std;
typedef long long int lli;

lli mod=10000009;

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
    string arr;
    cin>>arr;
    lli n=arr.size();
    lli ways=1;
    lli lim=n/2;
    if(n%2==0)
      lim=n/2-1;
    for(lli i=0;i<=lim;i++) {
      lli mirror=n-i-1;
      if(arr[i]==arr[mirror] and arr[i]=='?')
        ways*=26;
      else if(arr[i]=='?' or arr[mirror]=='?')
        ;
      else if(arr[i]!=arr[mirror]) {
        ways=0;
        break;
      }
      ways=ways%mod;
    }
    cout<<ways%mod<<endl;
	}
}

