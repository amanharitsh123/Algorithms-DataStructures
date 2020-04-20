#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<limits.h>
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
  map<char,lli> count;
  for(char x='a';x<='z';x++)
    count[x]=LLONG_MAX;
  
  lli ans=(1<<27)-1;
	while(testcases--) {
    map<char,lli> mp;
    string inp;
    lli temp=0;
    cin>>inp;
    for(auto x:inp) {
        temp=temp|(1<<(x-'a'));
        if(mp.find(x)!=mp.end())
          mp[x]++;
        else
          mp[x]=1;
    }
    for(auto it=mp.begin();it!=mp.end();it++) {
      auto x=*it;
      count[x.first]=min(x.second,count[x.first]);
    }
    ans=ans&temp;
  }
  
  if(ans) {
    for(lli i=0;i<26;i++)
      if(ans&(1<<i))
        while(count['a'+i])
          cout<<(char)('a'+i),--count['a'+i];
    cout<<endl;
  } else
    cout<<"no such string"<<endl;

}

