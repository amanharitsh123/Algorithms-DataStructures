#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<cmath>
#include<limits.h>
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

struct point {
  lli x,y;
};


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
  lli max_ind=-1,min_ind=-1,ma=LLONG_MIN,mi=LLONG_MAX;
	for(lli ind=0;ind<testcases;ind++) {
    
    lli x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    lli area=(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
    area=abs(area);

    if(area>=ma)
      ma=area,max_ind=ind;
    if(area<=mi)
      mi=area,min_ind=ind;
	}
  cout<<min_ind+1<<" "<<max_ind+1<<endl;
}

