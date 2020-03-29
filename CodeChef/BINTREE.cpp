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
    unordered_map<lli,lli> steps;
    lli i,j;
    cin>>i>>j;
    lli dist=0;
    lli temp=i;
    // go up from i
    do {
      steps[i]=dist;
      dist++;
      i=i/2;
    } while(i>=1);
    // go up from j
    i=j;
    dist=0;
    do {
      if(steps.find(i)!=steps.end())
      {
        cout<<dist+steps[i]<<endl;
        break;
      }
      i=i/2;
      ++dist;
    } while(i>=1);
	}
}

