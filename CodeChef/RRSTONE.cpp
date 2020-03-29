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

  lli n,k;
  cin>>n>>k;
  vector<lli> arr;
  input(arr,n);
  if(k==0) {
    output(arr);
    return 0;
  }
  if(k%2==0)
    k=2;
  else
    k=1;

  while(k--) {
    lli ma=0;
    for(auto x:arr)
      ma=max(ma,x);
    for(lli i=0;i<n;i++)
      arr[i]=ma-arr[i];
  }
	output(arr);
}

