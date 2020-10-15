#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>
#include<math.h>
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

bool perfect_square(lli x) {
  lli s=sqrt(x);
  return s*s==x;
}
lli foo(vector<lli> arr) {
  lli ans=1e18;
  lli curans=0;
  for(auto x:arr){
    curans=0;
    for(auto y:arr)
      curans+=abs(x-y);
    ans=min(ans, curans);
  }
  return ans;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<lli> > mat(n, vector<lli> (m, 0));
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> mat[i][j];
  int max_n=n/2;
  int max_m=m/2;
  if(n%2==0)
    max_n--;
  if(m%2==0)
    max_m--;
  lli ans=0;
  for(int i=0; i<=max_n; i++) {
    for(int j=0; j<=max_m; j++) {
      lli top=mat[i][j];
      lli bottom=mat[n-i-1][j];
      lli tright=mat[i][m-j-1];
      lli bright=mat[n-i-1][m-j-1];
      if(i==n-i-1 and j==m-j-1) {
        ans+=foo({top, tright});
      } else if(i==n-1-i) {
        ans+=foo({top, tright});
      } else if(j==m-1-j){
        ans+=foo({top, bottom});
      } else {
        ans+=foo({top, bottom, tright, bright});
      }
    }
  }
  cout << ans << endl;
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

