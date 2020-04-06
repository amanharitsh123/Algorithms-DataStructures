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

lli solve(lli n,lli a,lli b, lli c) {
  lli ans=0;
  for(lli i=0;i<=a;i++) {
    for(lli j=0;j<=b;j++) {
      for(lli k=0;k<=c;k++) {
        if(i+j+k<=n)
          ans++;
      }
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
    lli n,a,b,c;
    cin>>n>>a>>b>>c;
    
    if(c>b)
      c=c^b,b=c^b,c=c^b;

    lli fi=0;
    for(lli i=0;i<=a and n-i>=0;i++) {
      lli target=n-i;
      lli ans=0;
      if(b+c<=target) {
        ans+=(b+1)*(c+1);
      } else if(c>=target)
        ans+=(target+1)*(target+2)/2;
      else {
        lli lower=target-min(b,target);
        ans+=(target-c)*(c+1) + (c+1)*(c+2)/2 - (lower)*(lower+1)/2;;
      }
      fi+=ans;
    }
    cout<<fi<<endl;
	}
}

