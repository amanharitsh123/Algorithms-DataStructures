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
    lli n;
    cin>>n;
    vector<lli> dp(n+1,1);
    vector<string> mat;
    for(lli i=0;i<n;i++) {
      string temp;
      cin>>temp;
      mat.push_back(temp);
    }
    lli pos=0;
    lli turn=0;
    for(lli i=n-1;i>=0;i--) {
      bool hash=false;
      for(lli j=n-1;j>=0;j--) {
        if(mat[i][j]=='#') {
          hash=true;
          dp[j]=false;
        }
        if(!hash and dp[j])
          ++pos,cout<<i<<" "<<j<<endl;;
      }
	  }
    cout<<pos<<endl;
  }
}

