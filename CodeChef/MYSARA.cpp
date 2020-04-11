#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
using namespace std;
typedef unsigned long long int lli;

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

lli count(lli num) {
  lli c=0;
  for(lli i=0;i<64;i++)
    if(num&1LL<<i)
      ++c;
  return c;
}

lli subsets(lli num) {
  lli c=count(num);
  return power(2,c);
}

bool possible(lli a,lli b) {
  for(lli i=0;i<64;i++) {
      if((a&1LL<<i) and (!(b&1LL<<i)))
        return false;
  }
  return true;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli ans=1,num;
    lli n;
    cin>>n;
    cin>>num;
    bool pp=true;
    for(lli i=1;i<n;i++) {
      lli temp=0;
      cin>>temp;
      if(possible(num,temp)==false) {
        pp=false;
      }
      ans=(ans%MOD*subsets(num)%MOD)%MOD;
      num=temp;
    }
    if(pp)
      cout<<ans<<endl;
    else
      cout<<0<<endl;
	}
}

