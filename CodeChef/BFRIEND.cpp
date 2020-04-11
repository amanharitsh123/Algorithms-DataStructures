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


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<lli> arr;
    input(arr,n);
    sort(all(arr));
    lli i=lower_bound(all(arr),b)-arr.begin();
    if(a<=b) {
      if(i==0)
        cout<<arr[i]-b+arr[i]-a+c<<endl;
      else
        cout<<b-a+c<<endl;
    } else {
      if(i==n) {
        cout<<b-arr[n-1]+a-arr[n-1]+c<<endl;
      } else {
        cout<<a-b+c<<endl;
      }
    }
	}
}

