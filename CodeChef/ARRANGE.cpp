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

lli reverse(lli x,lli k) {
  lli ans=0;
  for(lli i=0;i<k;i++) {
    if(x&1LL<<i) {
      ans=ans|(1LL<<(k-i-1));
    }
  }
  return ans;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,i;
    string inp;
    cin>>n>>inp;
    char ans[(1LL<<n) +1];
    for(i=0;i<(1LL<<n);i++) {
      lli r=reverse(i,n);
      ans[r]=inp[i];
    }
    ans[i]='\0';
    cout<<ans<<endl;
	}
}

