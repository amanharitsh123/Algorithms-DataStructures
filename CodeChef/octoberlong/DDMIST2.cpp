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

int d;
int n;
typedef struct point {
  vector<lli> dimensions;
  point(vector<lli> dim) {
    dimensions=dim;
  }
  lli operator-(const point& o) {
    lli ans=0;
    for(int i=0; i<d; i++) {
      ans+=abs(dimensions[i]-o.dimensions[i]);
    }
    return ans;
  }
} point;


vector<point> points;

lli cal(point pt) {
  lli ans=0;
  for(auto x:points){
    ans+=x-pt;
  }
  return ans;
}
vector<int> parent;
vector<int> cnt;

void make_set(int v) {
    parent[v] = v;
    cnt[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (cnt[a] < cnt[b])
            swap(a, b);
        parent[b] = a;
        cnt[a] += cnt[b];
    }
}

void brute() {
  priority_queue< pair<lli, pl> > queue;
  cin >> n >> d;
  parent.resize(n);
  cnt.resize(n);
  for(int i=0; i<n; i++) {
    vector<lli> dim;
    input(dim , d);
    points.emplace_back(dim);
    make_set(i);
  }
  vector<vector< pair<lli, pl> > > mem(1000001);
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      lli val=points[i]-points[j];
      mem[val].pb(mp(points[i]-points[j], mp(i, j)));
    }
  }
  lli j=1000000;
  lli ans=0;
  lli edges=0;
  while(edges!=n-1) {
    for(auto top:mem[j]) {
      if(find_set(top.second.first)!=find_set(top.second.second)) {
        ans+=top.first;
        ++edges;
      }
      union_sets(top.second.first, top.second.second);
      if(edges>n-1)
        break;
    }
    --j;
  }
  cout << ans << endl;
}

void solve() {
  cin >> n >> d;
  for(int i=0; i<n; i++) {
    vector<lli> dim;
    input(dim , d);
    points.emplace_back(dim);
  }
  lli ans=0;
  // find extremities and calculate ans
  for(int dd=0; dd<d; dd++) {
    point max_point({}), min_point({});
    lli d_max=-1e18, d_min=1e18;
    for(int i=0; i<n; i++) {
      if(points[i].dimensions[dd]>d_max) {
        d_max=points[i].dimensions[dd], max_point=points[i];
      }
      if(points[i].dimensions[dd]<d_min) {
        d_min=points[i].dimensions[dd], min_point=points[i];
      }
    }
    ans=max(ans, cal(max_point));
    ans=max(ans, cal(min_point));
  }
  cout << ans << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    brute();
  }
}


