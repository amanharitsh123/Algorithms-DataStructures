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
    lli n,inp,ans=0,g=0;
    cin>>n;
    cin>>g;
    cin>>inp;
    g=__gcd(g,inp);
    if(g==1)
      ans=2;
    for(lli i=2;i<n;i++) {
      cin>>inp;
      g=__gcd(g,inp);
      if(g==1)
        ans=i+1;
    }
    if(ans!=0)
      cout<<ans<<endl;
    else
      cout<<-1<<endl;
	}
}

