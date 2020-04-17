#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<cmath>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
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

lli solve(vector<lli> &arr,lli k) {
  lli ans=0;
  for(auto x:arr) {
    ans+= ceil((x*1.0)/k);
  }
  return ans;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
  lli MAX=1000000000;
	while(testcases--) {
    lli n,h;
    cin>>n>>h;
    vector<lli> arr;
    input(arr,n);
    lli lo=1,hi=MAX;
    while(lo<hi) {
      lli mid=(lo+hi)/2;
      lli hcal=solve(arr,mid);
      if(hcal>h) {
        lo=mid+1;
      } else {
        hi=mid;
      }
    }
    cout<<lo<<endl;
	}
}

