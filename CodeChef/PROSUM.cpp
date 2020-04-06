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
    lli n;
    cin>>n;
    vector<lli> arr;
    input(arr,n);
    lli sum=n*(n-1)/2;
    lli valid=0;
    lli no_of_two=0;
    for(lli i=0;i<n;i++) {
        if(arr[i]==0 or arr[i]==1) {
          sum-=n-i-1+valid;
        } else if(arr[i]==2) {
          no_of_two++;
          valid++;
        } else {
          valid++;
        }
    }
    cout<<sum-(no_of_two*(no_of_two-1)/2)<<endl;
	}
}

