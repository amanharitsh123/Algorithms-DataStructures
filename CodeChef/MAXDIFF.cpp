#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<numeric>
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
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,k;
    vector<lli> arr;
    cin>>n>>k;
    input(arr,n);
    sort(arr.begin(),arr.end());
    lli first_k=abs(accumulate(arr.begin(),arr.end(),0)-2*accumulate(arr.begin(),arr.begin()+k,0));
    lli last_k=abs(accumulate(arr.rbegin(),arr.rend(),0)-2*accumulate(arr.rbegin(),arr.rbegin()+k,0));
    cout<<max(first_k,last_k)<<endl;
	}
}

