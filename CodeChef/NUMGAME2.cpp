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

int main() {
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    cin>>n;
    if((n-1)%4==0)
      cout<<"ALICE"<<endl;
    else
      cout<<"BOB"<<endl;
	}
}

