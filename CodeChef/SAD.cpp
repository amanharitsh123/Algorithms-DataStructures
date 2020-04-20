#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<utility>
#include<limits.h>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
#define pi pair<lli,lli>

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

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases=1;
	while(testcases--) {
    lli r,c;
    cin>>r>>c;
    lli mat[r][c];
    set<pi> s;
    for(lli i=0;i<r;i++) {
      lli mi=LLONG_MAX;
      for(lli j=0;j<c;j++) {
        cin>>mat[i][j];
        mi=min(mi,mat[i][j]);
      }
      for(lli j=0;j<c;j++) {
        if(mat[i][j]==mi) {
          s.insert({i,j});
        }
      }
    }

    lli ans=0;
    for(lli j=0;j<c and !ans;j++) {
      lli ma=LLONG_MIN;
      for(lli i=0;i<r;i++)
        ma=max(ma,mat[i][j]);

      for(lli i=0;i<r;i++)
        if(mat[i][j]==ma)
          if(s.find({i,j})!=s.end()) {
            ans=mat[i][j];
            break;
          }
    }
    if(!ans)
      cout<<"GUESS"<<endl;
    else
      cout<<ans<<endl;
  }
}

