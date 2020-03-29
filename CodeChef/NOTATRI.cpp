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

lli bs(vector<lli> &arr,lli i,lli j) {
  lli lo=j+1;
  lli hi=arr.size()-1;
  lli target=arr[i]+arr[j];
  while(lo<=hi) {
    lli mid=(lo+hi)/2;
    if(arr[mid]<=target) {
      lo=mid+1;
    } else
    {
      hi=mid-1;
    }
  }
  return lo;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli n,ans;
  vector<lli> arr;
  while(true) {
    cin>>n;
    ans=0;
    
    if(!n)
      break;
    arr.clear();
    input(arr,n);
    sort(all(arr));
    for(lli i=0;i<n;i++)
      for(lli j=i+1;j<n;j++) {
        ans+=n-bs(arr,i,j);
      }
    cout<<ans<<endl;
  }
}

