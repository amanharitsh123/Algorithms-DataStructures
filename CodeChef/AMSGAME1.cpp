#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef long long int lli;

template <typename T>
void input_vector(vector<T> &arr,lli n) {
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


// Solution by subtracting min and max repeatedly: TC: O(sum(arr))
int main() {
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    set<lli> s;
    cin>>n;
    input_set(s,n);
    while((*s.begin())!=(*s.rbegin()))
    {
      lli t=*s.rbegin();
      s.erase(t);
      s.insert(t-*s.begin());
    }
    cout<<*s.begin()<<endl;
	}
}

