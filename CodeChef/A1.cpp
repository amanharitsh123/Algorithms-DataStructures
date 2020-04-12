#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<math.h>
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
    lli n,m;
    cin>>n>>m;
    vector<lli> arr;
    input(arr,n);
    bool pay=false;
    for(lli i=0;i<pow(2,n) and !pay;i++) {
      lli sum=0;
      for(lli j=0;j<n;j++) {
        if(i&1<<j)
          sum+=arr[j];
      }
      if(sum==m)
        pay=true;
    }
    if(pay) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	}
}

