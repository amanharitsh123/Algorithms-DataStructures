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
  for(auto x:arr) cout<<x.x << space << x.y<<" ";
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

struct coordy {
  lli x, y;
  bool operator<(const coordy& o) const{
    if(x!=o.x)
      return x<o.x;
    return y<o.y;
  }
bool operator==(const coordy &p) const
	{
		return x == p.x && y == p.y;
	}
  lli operator-(const coordy& o) {
    return abs(o.x-x)+abs(o.y-y);
  }
};

void solve() {
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
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

