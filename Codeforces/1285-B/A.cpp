#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
int main() {
	lli t;
	cin>>t;
	string s;
  cin>>s;
  lli l=0,r=0;
  for(string::size_type i=0;i<s.size();i++)
  {
    if(s[i]=='L')
      ++l;
    else
      ++r;
  }
  cout<<l+r+1<<endl;
}

