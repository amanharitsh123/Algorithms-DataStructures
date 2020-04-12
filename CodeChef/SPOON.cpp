#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<ctype.h>
#define all(arr) arr.begin(),arr.end()
using namespace std;
typedef long long int lli;

void lower(string &sl) {
transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
}

template <typename T>
lli input(vector<T> &arr,lli n) {
  T temp;
  lli ans=0;
 for(lli i=0;i<n;i++) {
  cin>>temp;
  lower(temp);
  if (temp.find("spoon") != std::string::npos) {
    ans=1;
  }
  arr.push_back(temp);
 }
 return ans;
}

template <typename T>
void output(vector<T> arr) {
  T temp;
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli r,c;
    cin>>r>>c;
    vector<string> arr;
    lli ans=0;
    if(input(arr,r))
      ans=1;
    else {
      string temp;
      for(lli j=0;j<c;j++) {
        temp="";
        for(lli i=0;i<r;i++) {
          temp.push_back(arr[i][j]);
        }
        if(temp.find("spoon") != string::npos) {
          ans=1;
          break;
        }
      }
    }
    if(ans)
      cout<<"There is a spoon!"<<endl;
    else
      cout<<"There is indeed no spoon!"<<endl;

	}
}

