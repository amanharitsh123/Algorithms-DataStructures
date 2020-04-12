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

struct data {
  float m,r,c;
};

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    float d,u,n,cost=0;
    lli ind=0;
    cin>>d>>u>>n;
    cost=d*u;
    vector<data> arr;
    lli gcd=0;
    for(lli t=1;t<=n;t++) {
      float m,r,c;
      cin>>m>>r>>c;
      if(cost > c/m + r*u) {
        cost = c/m +r*u;
        ind = t;
      }
    }
    cout<<ind<<endl;
	}
}
