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

lli mod(string a,lli b) {
  lli temp=0;
  for(auto x:a) {
    temp=temp*10+x-'0';
    temp=temp%b;
  }
  return temp%b;
}

int main() {
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    string b;
    lli a;
    cin>>a>>b;
    if(b=="0") {
      cout<<a<<endl;
      continue;
    }
    if(a==0) {
      cout<<b<<endl;
      continue;
    }
    lli bb=mod(b,a);
    cout<<__gcd(a,bb)<<endl;
	}
}

