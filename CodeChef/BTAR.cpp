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
    vector<lli> arr;
    input(arr,n);
    vector<lli> count(4,0);
    for(auto x:arr) {
      count[x%4]++;
    }

    lli ans=0;
    // 1+1+1+1, 3+1, 3+3+3+3, 2+1+1
    
    // 1+3 pair
    ans=min(count[1],count[3]);
    
    count[1]-=ans;
    count[3]-=ans;

    // 2+1+1 pair
    while(count[1]>=2 and count[2]>=1) {
      ans+=2;
      count[1]-=2;
      count[2]-=1;
    }

    if(count[1])
      ans+=count[1]-1;
    else if(count[3])
      ans+=count[3]-1;

    if(count[2]%2==0 and count[1]%4==0 and count[3]%4==0) {
      ans+=count[2]/2;
      cout<<ans<<endl;
    } else 
      cout<<-1<<endl;
	}
}

