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
    lli progress=1,days=0;
    for(lli i=0;i<inp.size();) {
      if(inp[i]=='#') {
        ++i;
      } else {
        lli curlength=0;
        while(i<inp.size() and inp[i]=='.')
          ++curlength,++i;
        if(curlength>=progress)
          ++days,progress=curlength+1;
      }
    }
    cout<<days<<endl;
  }
}

