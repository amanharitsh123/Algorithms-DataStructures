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
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,temp,gcd;
    cin>>n;
    for(lli i=0;i<n;i++) {
      cin>>temp;
      if(!i) gcd=temp;
      else gcd=__gcd(gcd,temp);

    }
    cout<<gcd<<endl;
	}
}

