#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<queue>
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
void input_set(multiset<T, greater<T> > &arr,lli n) {
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
    lli n,q;
    cin>>n>>q;
    lli last=0;
    queue<lli> queue[2];
    vector<lli> arr;
    input(arr,n);
    sort(all(arr),greater<lli> ());
    //output(arr);
    for(auto x:arr)
      queue[0].push(x);
    
    int turn=0;
    lli ma;
    while(q--) {
      lli val;
      cin>>val;
      while(last<val-1) {
        if(queue[turn].size()==0)
          ma=queue[turn^1].front(),queue[turn^1].pop(),turn=turn^1;
        else {
          ma=queue[turn].front();
          if(queue[turn^1].size()!=0)
            ma=max(ma,queue[turn^1].front());
          if(ma==queue[turn].front())
            queue[turn].pop();
          else
            queue[turn^1].pop();
        }
        queue[turn^1].push(ma/2);
        ++last;
      }
      cout<<max(queue[0].front(),queue[1].front())<<endl;
    }
	}
}

