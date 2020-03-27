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

bool check(string a,string b) {
    lli i,j;
    for(i=0,j=0;i<(lli)a.size() and j<(lli)b.size();j++) {
      if(a[i]==b[j]) {
        ++i;
      }
    }
    return i==(lli)a.size();
}

int main() {
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    string a,b;
    cin>>a>>b;
    lli i,j;
    for(i=0,j=0;i<(lli)a.size() and j<(lli)b.size();j++) {
      if(a[i]==b[j]) {
        ++i;
      }
    }
    if(check(a,b) or check(b,a))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
	}
}

