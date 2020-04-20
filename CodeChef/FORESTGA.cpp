#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define pl pair<lli,lli>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
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


lli power(lli num,lli base) {
  if(base==0)
    return 1;

  if(base%2)
    return (num%MOD*power(num,base-1)%MOD)%MOD;
  else {
    lli x=power(num,base/2);
    x=(x*x)%MOD;
    return x;
  }
}

bool valid(vector<pl> &arr,lli m,lli l,lli w) {
  lli sum=0;
  for(auto x:arr) {
    if(x.first+x.second*m < l)
      continue;
    sum+=x.first+x.second*m;
    if(sum>=w) {
      //cout<<"True for "<<m<<endl;
      return true;
    }
  }
  return false;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases=1;
	while(testcases--) {
    lli n,w,l;
    cin>>n>>w>>l;
    vector<pl> arr;
    for(lli i=0;i<n;i++) {
      lli a,b;
      cin>>a>>b;
      arr.push_back({a,b});
    }

    lli lo=0,hi=1000000000LL,mid;
    hi=hi*hi;
    while(lo<hi) {
      mid=(lo+hi)/2;
      if(valid(arr,mid,l,w)) 
        hi=mid;
      else
        lo=mid+1;
    }
    cout<<min(hi,lo)<<endl;
	}
}

