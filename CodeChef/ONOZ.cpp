#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<utility>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
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


lli power(lli num,lli base) {
  if(base==0)
    return 1;

  if(base%2)
    return (num%MOD*power(num,base-1)%MOD)%MOD;
  else {
    lli x=power(num,base/2);
    x=(x*x)%MOD;
    return x;
  }
}

bool valid(pair<lli,lli> x, lli h, lli m) {
  return x.first<h and x.second<m;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli count=0;
    lli h,m;
    cin>>h>>m;
    for(lli i=1;i<=9;i++) {
      queue<pair<lli,lli>> q;
      q.push({i,i});
      set<pair<lli,lli>>s;
      while(q.size()) {
        auto x=q.front();
        q.pop();
        if(valid(x,h,m)) {
          if(s.find(x)==s.end()) {
            ++count,s.insert(x);
          }
          q.push({x.first*10+i,x.second});
          q.push({x.first,x.second*10+i});
          q.push({x.first*10+i,x.second*10+i});
        }
      }
    }
    cout<<count+1<<endl;;
	}
}

