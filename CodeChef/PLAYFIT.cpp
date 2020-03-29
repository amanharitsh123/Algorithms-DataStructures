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
    cin>>n;
    vector<lli> arr(n);
    vector<lli> min_arr;
    lli temp=1000000000;
    for(lli i=0;i<n;i++) {
      cin>>arr[i];
      temp=min(temp,arr[i]);
      min_arr.push_back(temp);
    }
    lli diff=-1;
    temp=arr[n-1];
    for(lli i=n-1;i>=0;i--) {
      if(temp>min_arr[i])
        diff=max(diff,temp-min_arr[i]);
      temp=max(temp,arr[i]);
    }
	
  if(diff!=-1)
    cout<<diff<<endl;
  else
    cout<<"UNFIT"<<endl;
  }
}

