#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<limits.h>
#include<map>
#define all(arr) arr.begin(),arr.end()
using namespace std;
typedef long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  T in;
  for(lli i=0;i<n;i++) cin>>in.first>>in.second, arr.push_back(in);
}

template <typename T>
void output(vector<T> arr) {
  T temp;
  for(auto x:arr) cout<<"{"<<x.first<<" "<<x.second<<"}, ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

struct interval {
  lli x,y;
  bool operator<(const interval &o) const {
    if(x==o.x)
      return y<o.y;
    return x<o.x;
  }
};

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,m;
    vector< pair<lli,lli> > arr;
    cin>>n>>m;
    input(arr,n);
    //output(arr);
    arr.push_back({0LL,0LL});
    sort(all(arr));
    //output(arr);
    
    while(m--) {
      lli p;
      cin>>p;
      lli wait=0;
      lli i=lower_bound(all(arr),make_pair(p,LLONG_MIN))-arr.begin();
      i=min(i,n);
      if(arr[i].first>p)
        --i;
      //cout<<"p: "<<p<<" "<<i<<endl;
      if(i<=n and arr[i].second>p)
        cout<<0<<endl;
      else
        if(i+1<=n)
          cout<<arr[i+1].first-p<<endl;
        else
          cout<<-1<<endl;
    }
	}
}

