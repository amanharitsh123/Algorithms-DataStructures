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
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}

int main() {
	lli n;
	cin>>n;
  vector<lli> arr;
  input(arr,n);
  int* visited=new int[n+1]();
  vector< vector<lli> > ans;
  vector<lli> temp;
  for(lli i=1;i<=n;i++) {
    if(visited[i]) {
      continue;
    } else {
      temp.clear();
      lli ele=i;
      while(!visited[ele]) {
        visited[ele]=1;
        temp.push_back(ele);
        ele=arr[ele-1];
      }
      temp.push_back(ele);
      ans.push_back(temp);
    }
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
    output(x);
}

