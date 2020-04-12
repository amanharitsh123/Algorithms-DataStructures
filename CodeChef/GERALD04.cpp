#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<sstream>
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

int toint(string x) {
  stringstream temp(x);
  float t;
  temp>>t;
  return t;
}

float diff(string s1,string s2) {
  float minutes=0;
  float h1,h2,m1,m2;
  h1=toint(s1.substr(0,1));
  m1=toint(s1.substr(3,4));
  h2=toint(s2.substr(0,1));
  m2=toint(s2.substr(3,4));
  return (h2-h1)*60.0+(m2-m1);
}

int main() {
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    string time1,time2;
    float a1=0,a2=0;
    float dist;
    cin>>time1>>time2>>dist;
    float waiting=diff(time2,time1);
    a1=waiting+(float)dist;
    if(2*dist<=waiting) {
      a2=waiting;
    } else {
      a2=dist+waiting/2.0;
    }
    printf("%.1f %.1f\n",a1,a2);
	}
}

