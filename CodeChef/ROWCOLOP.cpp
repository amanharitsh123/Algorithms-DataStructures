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
	
  lli n,testcases;
	cin>>n>>testcases;
  lli row_max=0;
  lli col_max=0;
  vector<lli> row(n,0);
  vector<lli> col(n,0);
	while(testcases--) {
    string inp;
    lli ind,val;
    cin>>inp>>ind>>val,--ind;
    if(inp=="RowAdd") {
      row[ind]+=val;
    } else {
      col[ind]+=val;
    }
	}
  for(auto x:row)
    row_max=max(row_max,x);
  for(auto x:col)
    col_max=max(col_max,x);
  cout<<row_max+col_max<<endl;
}

