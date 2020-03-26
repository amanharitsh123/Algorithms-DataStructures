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

int main() {
	lli n,d;
  cin>>n>>d;
  vector<lli> arr;
  input(arr,n);
  sort(all(arr));
  lli count=0;
  for(lli i=0;i<n-1;)
    if(arr[i+1]-arr[i]<=d)
      ++count,i+=2;
    else
      ++i;
  cout<<count<<endl;
}

