#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define MAX 10000000000 
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

lli valid(lli x) {
  lli ans=true;
  while(x and ans) {
    int dig=x%10;
    if(!(dig==0 or dig==1 or dig==4 or dig==9))
      ans=false;
    x=x/10;
  }

  return ans;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
  vector<lli> squares;
  for(lli i=0;i*i<=MAX;i++) {
    if(valid(i*i))
      squares.push_back(i*i);
  }

	while(testcases--) {
    lli a,b;
    cin>>a>>b;
    lli count=upper_bound(all(squares),b) - lower_bound(all(squares),a);
    cout<<count<<endl;
	}
}

