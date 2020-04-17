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

vector<lli> prime_list;
vector<lli> prime(900,1);

void sieve() {
  for(lli i=2;i<=900;i++) {
    if(prime[i]) {
      prime_list.push_back(i);
      for(lli j=2*i;j<=900;j+=i)
        prime[j]=0;
    }
  }
}

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
	while(testcases--) {
    lli n,k;
    cin>>n>>k;
    if(k==n and n==1) {
      cout<<1<<endl;
      continue;
    }
    if(k>(n/2))
      cout<<-1<<endl;
    else {
      for(lli i=2,count=0;count<k;i+=2)
        cout<<i<<" ",++count;
      cout<<endl;
    }
	}
}

