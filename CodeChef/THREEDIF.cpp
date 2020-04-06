#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
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
    vector<lli> arr;
    input(arr,3);
    sort(all(arr));
    lli a=arr[0],b=arr[1],c=arr[2];
    --b,c-=2;
    lli MOD=1000000007;
    a=a%MOD;
    b=b%MOD;
    c=c%MOD;
    a=(a%MOD*b%MOD)%MOD;
    a=(a%MOD*c%MOD)%MOD;
    cout<<a<<endl;
	}
}

