#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
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

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    cin>>n;
    if(n==0 or n==1) {
      cout<<n<<endl;
      continue;
    }
    lli lo=1,hi=100000;
    while(lo<hi) {
      lli mid=(lo+hi)/2;
      if((mid*(mid-1)/2)<n)
        lo=mid+1;
      else if((mid*(mid-1)/2)==n) {
        lo=mid;
        break;
      }
      else
        hi=mid-1;
    }
    
    lli an=lo*(lo-1)/2;
    if(an==n) {
      cout<<lo-1<<endl;
      continue;
    }
    else if(an>n)
      hi=lo,--lo;
    else
      hi=lo+1;
    
    lli ah=hi*(hi-1)/2;
    an=lo*(lo-1)/2;
    cout<<min(lo+n-an-1,hi+ah-n-1)<<endl;
	}
}

