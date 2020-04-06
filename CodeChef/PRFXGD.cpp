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
    lli k,x;
    cin>>k>>x;
    vector<lli> arr(26,0);
    lli count=0;
    lli ans=-1;
    for(lli i=0;i<inp.size();i++) {
      ++arr[inp[i]-'a'];
      if(arr[inp[i]-'a']>x)
        ++count;
      if(count<=k)
        ans=i;
    }
    cout<<ans+1-min(count,k)<<endl;
	}
}

