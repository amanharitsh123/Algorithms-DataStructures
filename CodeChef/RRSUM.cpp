#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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
	lli n,q;
	cin>>n>>q;
	while(q--) {
    lli num;
    cin>>num;
    if(num<=n)
      cout<<0<<endl;
    else {
      if(num-n-1<=n)
        cout<<num-n-1<<endl;
      else
        cout<<3*n-num+1<<endl;
    }

	}
}

