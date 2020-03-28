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
  
  lli N=100001;
  lli prefix[N];
	prefix[0]=0;
  for(lli i=1;i<N;i++)
    if(i%10==2 || i%10==3 || i%10==9)
      prefix[i]=1+prefix[i-1];
    else
      prefix[i]=prefix[i-1];

  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli l,r;
    cin>>l>>r;
    cout<<prefix[r]-prefix[l-1]<<endl;
	}
}

