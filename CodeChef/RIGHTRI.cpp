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

lli dist(lli x1,lli y1,lli x2,lli y2) {
  return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int main() {
	lli testcases;
	cin>>testcases;
  lli count=0;
	while(testcases--) {
    lli  x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    // Multiplication of slopes of two perpendicular lines is -1.
    lli  s1,s2,s3;
    s1=dist(x1,y1,x2,y2);
    s2=dist(x2,y2,x3,y3);
    s3=dist(x3,y3,x1,y1);
    lli ma=s1;
    ma=max(ma,s2);
    ma=max(ma,s3);
    if(2*ma==s1+s2+s3)
      ++count;
	}
  cout<<count<<endl;
}

