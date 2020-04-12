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


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    cin>>n;

    // Edge case of 0
    if(!n) {
      cout<<-1<<endl;
      continue;
    } else if(n==1) {
      cout<<2<<endl;
      continue;
    }

    bool ans=true;
    lli bits=log(n)/log(2);
    for(lli i=0;i<=bits;i++) {
      if(!(n & (1<<i))) {
        ans=false;
        break;
      }
    }
    if(ans)
      cout<<(1<<bits) - 1<<endl;
    else
      cout<<-1<<endl;

	}
}

