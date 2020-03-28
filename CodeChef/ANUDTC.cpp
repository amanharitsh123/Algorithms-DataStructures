#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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


//Is it possible to make exactly N equal pieces from the whole cake?
//Is it possible to make exactly N pieces from the whole cake?
//Is it possible to make exactly N pieces from the whole cake, in such a way that no two of them are equal?

int main() {
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    cin>>n;
    if(360%n==0)
      cout<<"y ";
    else
      cout<<"n ";

    if(n<=360)
      cout<<"y ";
    else
      cout<<"n ";
    
    if(n*(n+1)/2 <=360)
      cout<<"y"<<endl;
    else
      cout<<"n"<<endl;
	}
}

