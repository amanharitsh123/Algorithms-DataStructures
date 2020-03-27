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
	lli n;
  string dict;
  unordered_map<char,char> mp;
  char offset='a';
  cin>>n>>dict;
  for(char x:dict) {
    x=tolower(x);
    mp[offset]=x;
    ++offset;
  }
  for(lli i=0;i<n;i++) {
    string inp;
    cin>>inp;
    for(char x:inp) {
      if(isalpha(x)) {
        if(isupper(x)) {
          x=tolower(x);
          x=mp[x];
          x=toupper(x);
          cout<<x;
        } else {
          x=mp[x];
          cout<<x;
        }
      } else if(x=='_') {
        cout<<" ";
      } else {
        cout<<x;
      }
    }
    cout<<endl;
  }
}

