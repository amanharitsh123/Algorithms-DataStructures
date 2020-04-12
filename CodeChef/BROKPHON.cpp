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
    lli n;
    vector<lli> arr;
    cin>>n;
    input(arr,n);
    lli ans=0;
    for(lli i=0;i<n;) {
      lli val=arr[i];
      int length=0;
      while(i<n and arr[i]==val)
        ++length,++i;
      int temp=0;
      if(i-length!=0)
        ++temp;
      if(i<n)
        ++temp;
      ans+=min(temp,length);
    }
    cout<<ans<<endl;
	}
}

