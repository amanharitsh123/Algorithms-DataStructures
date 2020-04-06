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


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli x,k;
    cin>>x>>k;
    lli primes=0;

    //Counting itself as a factor
    if(x>=3)
      ++primes;

    while(!(x%2))
      x=x/2,++primes;

    // Finding prime divisors
    
    for(lli i=3;i<=x;i+=2) {
      while(!(x%i))
        x=x/i,++primes;
    }

    cout<<int(k<=primes)<<endl;
	}
}

