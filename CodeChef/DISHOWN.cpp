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

int parent[10000];


lli find(vector<lli> &parent,lli i) {
    while(i!=parent[i]) {
      parent[i]=parent[parent[i]];
      i=parent[i];
    }
    return i;
}

void uni(vector<lli> &parent,vector<lli> &rank,lli x,lli y) { 
    lli p1=find(parent,x);
    lli p2=find(parent,y);
    if(rank[p1]>rank[p2]) {
      parent[p2]=p1;
    } else if(rank[p1]<rank[p2]){
      parent[p1]=p2;
    }
}


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    vector<lli> scores;
    cin>>n;
    input(scores,n);
    vector<lli> parent;
    vector<lli> rank;
    for(lli i=0;i<n;i++)
      parent.push_back(i),rank.push_back(1);
    lli q;
    cin>>q;
    while(q--) {
      lli x,y,t;
      cin>>t>>x,--x;

      if(t==0) {
        cin>>y,--y;
        if(find(parent,x)==find(parent,y))
          cout<<"Invalid query!"<<endl;
        else
          uni(parent,scores,x,y);
      } else
        cout<<find(parent,x)+1<<endl;;
    }
	}
}

