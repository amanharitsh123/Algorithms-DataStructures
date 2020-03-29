#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<limits.h>
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
    vector<lli> arr;
    vector<lli>suffix(n);
    lli temp=0;
    input(arr,n);
    for(lli i=n-1;i>=0;i--) {
      temp+=arr[i];
      suffix[i]=temp;
    }
    temp=0;
    lli ans=LLONG_MAX;
    lli ind=-1;
    for(lli i=0;i<n;i++) {
      temp+=arr[i];
      if(temp+suffix[i]<ans)
        ans=temp+suffix[i],ind=i;
    }
    cout<<ind+1<<endl;
	}
}

