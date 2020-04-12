#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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

lli dig(lli num) {
  lli temp=0;
  while(num) {
    temp+=num%10;
    num=num/10;
  }
  return temp;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases=1;
	while(testcases--) {
    lli n,count=0;
    cin>>n;
    for(lli i=n-97;i<=n;i++) {
      lli x=i+dig(i)+dig(dig(i));
      if(x==n) {
        ++count;
      }
    }
    cout<<count<<endl;
  }
}

