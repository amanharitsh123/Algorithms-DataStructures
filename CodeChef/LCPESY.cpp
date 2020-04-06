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
    string a,b;
    cin>>a>>b;
    unordered_map<char,lli> mx,my;

    for(auto x:a) {
      if(mx.find(x)==mx.end()) mx[x]=1;
      else ++mx[x];
    }

    for(auto y:b) {
      if(my.find(y)==my.end()) my[y]=1;
      else ++my[y];
    }
    lli ans=0;
    for(auto it=mx.begin();it!=mx.end();it++) {
        char c=(*it).first;
        if(my.find(c)!=my.end())
          ans+=min(my[c],mx[c]);
    }
    cout<<ans<<endl;
	}
}

