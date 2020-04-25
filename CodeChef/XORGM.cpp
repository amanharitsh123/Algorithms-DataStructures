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
void output(vector<T> &arr) {
  T temp;
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(map<T,T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) {
    cin>>temp;
    if(arr.find(temp)==arr.end())
      arr[temp]=1;
    else
      arr[temp]++;
  }
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
    vector<lli> a,ans;
    map<lli,lli> mp;
    cin>>n;
    input(a,n);
    input_set(mp,n);
    lli val=0;
    for(auto x:a)
      val^=x;

    for(auto x:mp) {
      if(x.second%2)
        val^=x.first;
    }

    bool possible=true;
    for(auto x:a) {
      if((mp.find(x^val)!=mp.end()) and mp[x^val]!=0)
        ans.push_back(x^val),--mp[x^val];
      else
        possible=false;
    }

    if(possible)
      output(ans);
    else
      cout<<-1<<endl;
	}
}

