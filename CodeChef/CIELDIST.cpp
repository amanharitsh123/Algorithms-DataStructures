#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
#include<math.h>
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
  
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli ds,dt,d;
    cin>>ds>>dt>>d;
    if(ds>d+dt or dt>d+ds) {
      // One cirlce inside another
      if(ds>d+dt) {
        cout<<ds-d-dt<<endl;
      } else {
        cout<<dt-d-ds<<endl;
      }
    }
    else if(ds+dt>=d) {
      // Circles cross each other
      printf("0\n");
    } else {
      // circles are not co-centric
      printf("%.6f\n",sqrt((d-dt-ds)*(d-ds-dt)));
    }
	}
}

