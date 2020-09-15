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

#define N 2002
int right_up[N][N];
int left_up[N][N];
int right_down[N][N];
int left_down[N][N];
char mat[N][N];
void solve() {
  memset(right_up, 0, sizeof(right_up));
  memset(left_up, 0, sizeof(left_up));
  memset(right_down, 0, sizeof(right_down));
  memset(left_down, 0, sizeof(left_down));
  memset(mat, 'Q', sizeof(mat));
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      cin >> mat[i][j];
  
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      int l=1, u=1, c=2;
      if(mat[i][j-1]==mat[i][j])
        l=left_up[i][j-1]+1;
      if(mat[i-1][j]==mat[i][j])
        u=left_up[i-1][j]+1;
      if(mat[i-1][j-1]==mat[i][j])
        c=left_up[i-1][j-1]+2;
      left_up[i][j]=min(l, u);
      left_up[i][j]=min(left_up[i][j], c);
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=m; j>=1; j--) {
      int l=1, u=1, c=2;
      if(mat[i][j+1]==mat[i][j])
        l=right_up[i][j+1]+1;
      if(mat[i-1][j]==mat[i][j])
        u=right_up[i-1][j]+1;
      if(mat[i-1][j+1]==mat[i][j])
        c=right_up[i-1][j+1]+2;
      right_up[i][j]=min(l, u);
      right_up[i][j]=min(right_up[i][j], c);
    }
  }

  for(int i=n; i>=1; i--) {
    for(int j=1; j<=m; j++) {
      int l=1, u=1, c=2;
      if(mat[i][j-1]==mat[i][j])
        l=left_down[i][j-1]+1;
      if(mat[i+1][j]==mat[i][j])
        u=left_down[i+1][j]+1;
      if(mat[i+1][j-1]==mat[i][j])
        c=left_down[i+1][j-1]+2;
      left_down[i][j]=min(l, u);
      left_down[i][j]=min(left_down[i][j], c);
    }
  }

  lli ans=0;
  for(int i=n; i>=1; i--) {
    for(int j=m; j>=1; j--) {
      int l=1, u=1, c=2;
      if(mat[i][j+1]==mat[i][j])
        l=right_down[i][j+1]+1;
      if(mat[i+1][j]==mat[i][j])
        u=right_down[i+1][j]+1;
      if(mat[i+1][j+1]==mat[i][j])
        c=right_down[i+1][j+1]+2;
      right_down[i][j]=min(l, u);
      right_down[i][j]=min(right_down[i][j], c);
      int curans=1e8;
      curans=min(curans, left_down[i][j]);
      curans=min(curans, right_up[i][j]);
      curans=min(curans, left_up[i][j]);
      curans=min(curans, right_down[i][j]);
      ans+=curans;
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

