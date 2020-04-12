#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<limits.h>
#include<numeric>
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
    vector<lli> arr;
    cin>>n;
    input(arr,n);
    // At every index i, choose max abs diff b/w min(1..i)-max(i+1..n) and max(1..i)-min(i+1..n)
    
    // precomputer max and min from back
    vector<lli> max_back(n+1,LLONG_MIN);
    vector<lli> min_back(n+1,LLONG_MAX);
    lli ma=LLONG_MIN;
    lli mi=LLONG_MAX;
    lli residue_min=0;
    lli residue_max=0;
    
    for(lli i=n-1;i>=0;i--) {
      max_back[i]=max(max_back[i+1],arr[i]+residue_max);
      min_back[i]=min(min_back[i],arr[i]+residue_min);
      residue_max+=arr[i];
      residue_min+=arr[i];
      residue_max=max(residue_max,0LL);
      residue_min=min(residue_min,0LL);
    }

    residue_max=0;
    residue_min=0;
    ma=LLONG_MIN;
    mi=LLONG_MAX;
    lli ans=LLONG_MIN;
    
    for(lli i=0;i<n-1;i++) {
      ma=max(ma,arr[i]+residue_max);
      mi=min(mi,arr[i]+residue_min);
      residue_max+=arr[i];
      residue_min+=arr[i];
      residue_max=max(residue_max,0LL);
      residue_min=min(residue_min,0LL);
      lli t=max(abs(ma-min_back[i+1]),abs(mi-max_back[i+1]));
      ans=max(ans,t);
    }
    
    cout<<ans<<endl;
	}
}

