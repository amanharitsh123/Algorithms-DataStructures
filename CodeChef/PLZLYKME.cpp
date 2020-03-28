#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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
    float l,d,s,c;
    cin>>l>>d>>s>>c;
    if(d==1) {
      if(s>=l)
        cout<<"ALIVE AND KICKING"<<endl;
      else
        cout<<"DEAD AND ROTTING"<<endl;
      continue;
    }
    float a=log(c+1);
    float b=log(l)-log(s);
    b=b/(d-1.0);
    if(a>=b)
      cout<<"ALIVE AND KICKING"<<endl;
    else
      cout<<"DEAD AND ROTTING"<<endl;
	}
}

