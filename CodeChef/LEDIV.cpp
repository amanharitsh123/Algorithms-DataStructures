#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<math.h>
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

lli smallest_factor(lli x) {
    for(lli i=2;i<=sqrt(x);i++)
      if(x%i==0)
        return i;
    return x;
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
    lli x=arr[0];
    for(lli i=1;i<n;i++)
      x=__gcd(arr[i],x);
    
    if(x!=1)
      cout<<smallest_factor(x)<<endl;
    else
      cout<<-1<<endl;
	}
}

