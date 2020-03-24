#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
typedef long long int lli;
using namespace std;
const lli N=1e5;
lli tree[N];

void upd(int i,int x) {
  for(++i;i<N;i+=i&-i) tree[i]+=x;
}

lli query(int i) {
  lli sum=0;
  for(;i>0;i-=i&-i)
    sum+=tree[i];
  return sum;
}

struct event {
  lli y, t, i;
  bool operator<(const event &o) const {
    return make_pair(y, t)<make_pair(o.y, o.t);
  }
};

struct lines {
  lli x1,x2,y,ans;
};

int main() {
	lli t;
	cin>>t;
	while(t--) {
    lli n,q;
    cin>>n>>q;
    // Taking points input
    vector<lli> points(n);
    vector<lines> queries; 
    for(lli i=0;i<n;i++) cin>>points[i];
    vector<event> queue;

    // Creating segments
    for(lli i=0;i<n-1;i++) {
      // add segments
      queue.push_back({min(points[i+1],points[i]),1,i});
      // remove segment
      queue.push_back({max(points[i+1],points[i]),3,i});
    }

    // Take queries input and process
    for(lli i=0;i<q;i++){
      lli x1,x2,y;
      cin>>x1>>x2>>y;
      queries.push_back({x1-1,x2-1,y,0});
      queue.push_back({y,2,i});
    }
    sort(queue.begin(),queue.end());

    for(auto e:queue) {
      lli ans=0;
     if(e.t==1) {
       upd(e.i,1);
     } else if(e.t==2) {
       ans+=query(queries[e.i].x2)-query(queries[e.i].x1);
       queries[e.i].ans=ans;
     } else {
      upd(e.i,-1);
     }
    
  }
    for(auto e:queries)
      cout<<e.ans<<endl;
	}
}

