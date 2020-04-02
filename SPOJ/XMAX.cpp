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


void gaussian(vector<lli> &arr) {
  sort(all(arr),greater<int>());
  lli ind=0;
  lli n=arr.size();
  for(lli bit=60;bit>=0;bit--) {
    if(arr[ind] & (1LL<<bit)) {
        // traverse whole array and find numbers with this set bit.
      for(lli i=0;i<n;i++) {
          if((i!=ind) and (arr[i]& (1LL<<bit)))
            arr[i]=arr[i]^arr[ind];
        }
      ++ind;
    } else {
      for(lli i=ind;i<n;i++) {
        if(arr[i] & 1LL<<bit) {
          swap(arr[i],arr[ind]);
          ++bit;
          break;
        }
      }
    }
  }
}


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli n;
  cin>>n;
  vector<lli> arr;
  input(arr,n);
  gaussian(arr);
  lli ans=0;
  for(auto x:arr)
    ans=ans^x;
  cout<<ans<<endl;
}

