#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<cstdio>
#define all(arr) arr.begin(),arr.end()
using namespace std;
typedef long long int lli;

struct inst {
  string type;
  string road;
};

template <typename T>
void input(vector<T> &arr,lli n) {
for(lli i=0;i<n;i++) {
    inst temp;
    string inps[3];
    char c;
    lli ind=0;
    while((c=getchar())!='\n') {
      if(c==' ') {
        if(ind!=2) {
          ++ind;
        } else {
          inps[ind].push_back(c);
        }
      } else {
        inps[ind].push_back(c);
      }
    }
    temp.type=inps[0], temp.road=inps[2], arr.push_back(temp);
  } 
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

void print_inst(string type,string road) {
  cout<<type<<" on "<<road<<endl;
}

string opp(string x) {
  if(x=="Right")
    return "Left";
  else 
    return "Right";
}

int main() {
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    scanf("%lld",&n);
    getchar();
    vector<inst> arr;
    input(arr,n);
    string type=(*arr.rbegin()).type;
    string road=(*arr.rbegin()).road;
    print_inst("Begin",road);
    for(auto it=arr.rbegin()+1;it!=arr.rend();it++) { 
      print_inst(opp(type),(*it).road);
      type=(*it).type;
    }
    cout<<endl;
	}
}

