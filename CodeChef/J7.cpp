#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<math.h>
#include<iomanip>
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

int main() {
	lli testcases;
	cin>>testcases;
	while(testcases--) {
    float p,s,q,l1,l2,h1,h2;
    cin>>p>>s;
    p=p/4.0;
    q=s/2.0;
    l1=2.0*p+sqrt(4.0*p*p-12.0*q);
    l2=2.0*p-sqrt(4.0*p*p-12.0*q);
    l1=l1/6.0;
    l2=l2/6.0;
    h1=p-2.0*l1;
    h2=p-2.0*l2;
    //cout<<l1<<" "<<h1<<" "<<l2<<" "<<h2<<endl;
    float ma=max(l1*l1*h1,l2*l2*h2);
    if(l1*l1*h1==ma and l1>0 and h1>0)
      cout<<fixed << setprecision(2) <<l1*l1*h1<<endl;
    else
      cout<<fixed << setprecision(2) <<l2*l2*h2<<endl;
	}
}

