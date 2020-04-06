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

bool valid(string inp) {
  bool ans=true;
  
  if(inp.size()!=5)
    ans=false;

  if(inp[2]!='-')
    ans=false;

  if( inp[0] > 'h' or inp[0] < 'a' or inp[3] > 'h' or inp[3] < 'a')
      ans=false;
  
  if( inp[1] < '1' or inp[1] > '8' or inp[4] < '1' or inp[4] > '8')
      ans=false;

  return ans;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
  string t;
  getline(cin,t);
	while(testcases--) {
    string inp;
    getline(cin,inp);
   // cout<<"inp is "<<inp<<endl;
    if(!valid(inp)) {
      cout<<"Error"<<endl;
    } else {
      lli temp=abs(inp[3]-inp[0])*abs(inp[4]-inp[1]);
      if(temp==2)
        cout<<"Yes"<<endl;
      else
        cout<<"No"<<endl;
    }
	}
}

