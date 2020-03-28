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
	string dict;
  for(char x='z';x>='a';x--)
       dict.push_back(x);

  while(testcases--) {
    lli n;
    cin>>n;
    lli mul=n/25;
    lli offset=n%25;
    for(auto x=dict.size()-offset-1;x!=dict.size() and offset!=0;++x)
      cout<<dict[x];
    while(mul--)
      cout<<dict;
   cout<<endl;
	}
}

