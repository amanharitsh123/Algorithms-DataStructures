#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<queue>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
#define kick(t,a) cout<<"Case #"<<t<<": "<<a<<endl;
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
	
  lli testcases,ttt=0;
	cin>>testcases;
	while(testcases--) {
    ++ttt;
    lli n, k;
    cin >> n >> k;
    vector<lli> arr;
    input(arr,n);
    priority_queue<lli> q;
    for(lli i=1;i<n;i++) {
      q.push(arr[i]-arr[i-1]);
    }

    while(k--) {
      lli x=q.top();
      q.pop();
      q.push(ceil(x/2.0));
      q.push(x/2);
    }

    kick(ttt,q.top());
	}
}

