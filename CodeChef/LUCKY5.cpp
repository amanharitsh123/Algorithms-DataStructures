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

char foo(lli &a,lli &b) {
  if(a>b) {
    ++b;
    return '7';
  } else {
    ++a;
    return '4';
  }
}

int main() {
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli moves=0;
    string num;
    cin>>num;
    lli n4=count(num.begin(), num.end(), '4');
    lli n7=count(num.begin(),num.end(),'7');
    for(lli i=0;i<num.size();i++) {
      if(num[i]!='7' and num[i]!='4') {
        char x=foo(n4,n7);
        num[i]=x;
        ++moves;
      }
    }
    if(!n4 or !n7)
      ++moves;
    cout<<moves<<endl;
	}
}

