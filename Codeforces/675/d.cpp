#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>
#include<queue>
using namespace std;
typedef long long int lli;

#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define space ' '
#define kick(t) cout << "Case #" << t << ":" << endl;

typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

lli mul(lli a, lli b) {
  return (a%MOD*b%MOD)%MOD;
}

lli power(lli a,lli b) {
  lli ans = 1;
  while(b > 0) {
    if(b&1)
      ans = mul(ans, a);
    a = mul(a,a);;
    b >>= 1;
  }
  return ans;
}

struct coordx {
  lli x, y;
  bool operator<(const coordx& o) const{
    if(x!=o.x)
      return x<o.x;
    return y<o.y;
  }
bool operator==(const coordx &p) const
	{
		return x == p.x && y == p.y;
	}
  lli operator-(const coordx& o) {
    return abs(o.x-x)+abs(o.y-y);
  }
};

struct coord {
  lli i, x, y;
  bool operator<(const coord& o) const{
    if(x!=o.x)
      return x<o.x;
    return y<o.y;
  }
bool operator==(const coord &p) const
	{
		return x == p.x && y == p.y;
	}
  lli operator-(const coord& o) {
    return min(abs(o.x-x), abs(o.y-y));
  }
};

bool fast=false;
lli manhattan_dist(coord x, coord y) {
  lli xd=abs(x.x-y.x);
  lli yd=abs(x.y-y.y);
  if(fast)
    return min(xd, yd);
  return xd+yd;
}


void solve() {
  lli n, m;
  cin >> n >> m;
  vector<coord> arr;
  lli x, y;
  lli sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;
  coord start={-1, sx, sy};
  coord end={-1, fx, fy};
  for(int i=0; i<m; i++) {
      cin >> x >> y;
      if(x==fx and y==fy)
        fast=true;
      arr.pb({i, x, y});
  }
  vector<coord> original=arr;
  sortall(arr);
  vector<vector<int> > adj(m);
  lli u, v;
  for(int i=0; i<m; i++) {
    u=arr[i].i;
    if(i!=0) {
      v=arr[i-1].i;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    if(i!=m-1) {
      v=arr[i+1].i;
      adj[u].pb(v);
      adj[v].pb(u);
    }
  }
  for(auto &ele:arr)
    swap(ele.x, ele.y);

  sortall(arr);
  set<pl> q;
  vector<lli> dist(m, 1e18);
  for(int i=0; i<m; i++) {
    u=arr[i].i;
    if(i!=0) {
      v=arr[i-1].i;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    if(i!=m-1) {
      v=arr[i+1].i;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    swap(arr[i].x, arr[i].y);
    q.insert({arr[i]-start, arr[i].i});
    dist[arr[i].i]=arr[i]-start;
    swap(arr[i].x, arr[i].y);
  }
  vector<bool> visited(m, false);
  while(q.size()) {
    auto top=*q.begin();
    q.erase(q.begin());
    int u=top.second;
    lli d=top.first;
    visited[u]=true;
    for(auto v:adj[u]) {
      if(visited[v])
        continue;
      lli w=original[v]-original[u];
      if(d+w<dist[v]) {
        if(q.find({dist[v], v})!=q.end())
          q.erase(q.find({dist[v], v}));
        dist[v]=d+w;
        q.insert({dist[v], v});
      }
    }
  }
  lli ans=1e18;
  for(int i=0; i<m; i++) {
    ans=min(ans, dist[i]+manhattan_dist(original[i], end));
  }
  cout << ans << endl;
}



/*void solve() {
  lli n, m;
  cin >> n >> m;
  lli sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;
  vector<coordx> arrx;
  vector<coordy> arry;
  vector<vector<pl> > adj;
  lli x, y;
  map<coordx, int> number;
  arrx={{sx,sy}};
  for(int i=0; i<m; i++) {
    cin >> x >> y;
    arrx.push_back({x, y});
    arry.push_back({x, y});
  }
  sortall(arrx);
  sortall(arry);
  for(int i=1; i<=m; i++) {
    
  }
  priority_queue< pair<lli, coord> > q;
  lli ans=1e18;
  q.push({0, {sx, sy}});
  coord dest={fx, fy};
  output(arr);
  while(q.size()) {
    auto top=q.top();
    q.pop();
    cout <<top.first<<space<<top.second.x << space << top.second.y << endl;
    ans=min(ans, abs(top.second.x-dest.x)+abs(top.second.x-dest.y)+top.first);
    auto left=upper_bound(arr.begin(), arr.end(), (coord) top.second)-arr.begin();
    cout << "left is " << left << endl;
    if(left!=arr.size()) {
      lli x=arr[left].x;
      lli i=left;
      while(i<arr.size() and arr[i].x==x and visited[arr[i]]==false) {
        q.push({arr[i]-top.second+top.first, arr[i]});
        visited[arr[i]]=true;
        i++;
      }
    }
    left=lower_bound(arr.begin(), arr.end(), (coord) top.second)-arr.begin()-1;
    if(left!=-1) {
      lli x=arr[left].x;
      lli i=left;
      while(i>=0 and arr[i].x==x and visited[arr[i]]==false) {
        q.push({arr[i]-top.second+top.first, arr[i]});
        visited[arr[i]]=true;
        i--;
      }
    }
  }
  cout << ans << endl;
}*/

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

