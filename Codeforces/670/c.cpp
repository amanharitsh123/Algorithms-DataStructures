#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>

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

vector<vector<int> > adj;
vector<int> size_tree;
int count_centroids=0, n=0;
int max_size=inf;
vector<int> found_centroids;
void dfs(int src, int parent) {
  int curmax=0;
  for(auto v:adj[src]) {
    if(v==parent)
      continue;
    dfs(v, src);
    size_tree[src]+=size_tree[v];
    curmax=max(curmax, size_tree[v]);
  }
  size_tree[src]++;
  curmax=max(curmax, n-size_tree[src]);
  if(curmax==max_size) {
    ++count_centroids;
    found_centroids.pb(src);
  }
  else if(curmax<max_size) {
    found_centroids={src};
    count_centroids=1;
  }
  max_size=min(max_size, curmax);
}

int fl(int src, int parent) {
  int l=-1;
  if(adj[src].size()==1)
    return src;
  for(auto v:adj[src]) {
    if(v==parent)
      continue;
    l=fl(v, src);
  }
  return l;
}

void leaves_shift() {
  int l=fl(found_centroids[1], found_centroids[0]);
  cout << l+1 << space <<adj[l][0]+1 << endl;
  cout << found_centroids[0]+1 << space << l+1 << endl;
}

void solve() {
  // find centroids but how? 
  // In O(n)
  // using dfs
  int u, v;
  cin >> n;
  adj.clear();
  adj.resize(n);
  size_tree.clear();
  size_tree.resize(n, 0);
  max_size=inf;
  found_centroids.clear();
  for(int i=0; i<n-1; i++) {
    cin >> u >> v, --u, --v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(0, -1);
  if(found_centroids.size()==1) {
    cout << 1 <<space<<adj[0][0]+1 << endl;
    cout << 1 <<space<<adj[0][0]+1 << endl;
  } else {
    leaves_shift();
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin>>testcases;
  while(testcases--) {
    solve();
  }
}

