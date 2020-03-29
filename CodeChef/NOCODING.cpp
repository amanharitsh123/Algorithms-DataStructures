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
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    string inp;
    cin>>inp;
    lli inst=2;
    char buff=inp[0];
    for(lli i=1;i<inp.size();i++) {
        if(buff<=inp[i])
          inst+=inp[i]-buff+1;
        else
          inst+='z'-buff+1+inp[i]-'a'+1;
        buff=inp[i];
    }
    if(inst<=11*inp.size())
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
	}
}

