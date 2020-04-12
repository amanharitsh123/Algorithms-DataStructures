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

vector<lli> prime_list;
lli N=1000000;
vector<lli> prime(N + 1,1);

void sieve() {
  for(lli i=2;i<=N;i++) {
    if(prime[i]) {
      prime_list.push_back(i);
      for(lli j=i+i;j<=N;j+=i)
        prime[j]=0;
    }
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    cin>>n;
    cout<<(n/2)<<endl;
    vector<lli> temp[2];
    int turn=0;
    auto it=lower_bound(all(prime_list),n);
    for(auto x=prime_list.begin();x<=it and *x<=n;x++) {
      temp[turn].push_back(*x);
    }
    cout<<temp[turn].size()+1<<" "<<1<<" ";
    vector<lli> save(all(temp[turn]));
    output(temp[turn]);
    while(temp[turn].size()) {
      //cout<<"one arraay done "<<endl;
      //string c;
      //cin>>c;
      turn=turn^1;
      lli i=0;
      for(auto x:temp[turn^1]) {
        if(i==0) {
          if(x+2<=n)
            temp[turn].push_back(x+2);
          else
            break;
        } else if(x*save[i]<=n){
          temp[turn].push_back(x*save[i]);
        } else {
          break;
        }
        ++i;
      }
      temp[turn^1].clear();
      if(temp[turn].size())
        cout<<temp[turn].size()<<" ",output(temp[turn]);
    }
	} 
}

