#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<climits>
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
    return (num*power(num,base-1));
  else {
    lli x=power(num,base/2);
    x=(x*x);
    return x;
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli a;
    cin>>a;
    lli last=0,max=INT_MIN,max_ind=0;
    for(lli i=0;i<=34;i++) {
      if(power(2,i+1)<=(a*(i+1)+1)) {
        last=i+1;
        lli val=-1LL*power(2,i+1)+(a*(i+1)-1); 
        if(val>max)
          max=val,max_ind=i+1;
      }
    }

    cout<<last<<" "<<max_ind<<endl;
	}
}

