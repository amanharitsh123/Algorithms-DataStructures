#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<numeric>
using namespace std;
typedef unsigned long long int lli;

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

int main() {
	lli n;
	cin>>n;
  vector<lli> arr;
  input(arr,n);
  lli sum=accumulate(arr.begin(),arr.end(),0ULL);
  if(sum==(n*(n+1ULL)/2ULL)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

