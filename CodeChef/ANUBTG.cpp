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
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    vector<lli> arr;
    cin>>n;
    input(arr,n);
    sort(all(arr));
    lli cost=0;
    for(lli i=arr.size()-1;i>=0;i--) {
      cost+=arr[i];
      --i;
      if(i>=0)
        cost+=arr[i];
      i-=2;
    }
    cout<<cost<<endl;
	}
}

