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
	
  lli testcases=1;
	while(testcases--) {
    vector<lli> arr;
    input(arr,4);
    lli pro=1;
    for(auto x:arr)
      pro*=x;
    
    bool ans=false;
    for(auto it=arr.begin()+1;it!=arr.end();it++) {
      if(arr[0]*(*it)==(pro/(arr[0]*(*it))))
        ans=true;
    }
    
    if(ans)
      cout<<"Possible"<<endl;
    else
      cout<<"Impossible"<<endl;
	}
}

