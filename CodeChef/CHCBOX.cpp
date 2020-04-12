#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<limits.h>
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


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    cin>>n;
    vector<lli> arr;
    input(arr,n);
    lli ma=LLONG_MIN;
    for(auto x:arr)
      ma=max(x,ma);

    lli first=-1,end=n-1,last=-1;
    lli ans=0;
    for(lli i=0;i<n;i++) {
      if(arr[i]==ma) {
        if(first==-1)
          first=i;
        else {
          if((i-end-1)>=(n/2)) {
            ans+=(i-end-n/2);
          }
        }
        end=i;
      }
    }
    last=end;
    if(first==last) {
      ans=n/2;
    } else {
      if((first+n-1-last)>=(n/2)) {
        ans+=(first+n-last-n/2);
      }
    }
    cout<<ans<<endl;
	}
}

