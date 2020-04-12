#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<cmath>
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

lli count_odd(lli l,lli r) {
  if((l%2) and (r%2)) {
    return 1+(r-l)/2; 
  } else if(!(l%2) and !(r%2)) {
    return (r-l)/2;
  } else {
    return (r-l+1)/2;
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    float l,r,g;
    cin>>l>>r>>g;
    int ll=ceil(l/g)*g;
    int rr=floor(r/g)*g;
    int ans=0;
    cout<<ll<<" "<<rr<<endl;
    if(rr<ll) {
      ans=0;
    } else if(ll==rr) {
      ans=(rr==g);
    } else
      ans=(rr-ll)/g+1;
    cout<<ans<<endl;
	}
}

