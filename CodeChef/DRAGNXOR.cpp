#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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
    lli n,a,b,count=0,ans=0;
    cin>>n>>a>>b;
    for(lli i=0;i<n;i++) {
      if(a&1<<i)
        ++count;
      if(b&1<<i)
        ++count;
    }
    if(count>n) {
      count=2*n-count;
    }
    for(lli i=n-1;i>=0 and count>0;i--,count--) {
      ans=ans|1<<i;
    }
    cout<<ans<<endl;
	}
}

