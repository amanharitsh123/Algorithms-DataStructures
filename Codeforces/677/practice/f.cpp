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

void solve() {
  int n, m, k;
  cin >> n >> m >>k;
  int dp[n+1][m+1][m/2+1][k];
  memset(dp, -inf, sizeof(dp));
  int ele, c;
  for(c=0; c<m/2+1; c++)
    dp[0][m][c][0]=0;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin >> ele;
      int rem=ele%k;
      dp[i][j][0][0]=0;
      int prevj=j-1;
      int previ=i;
      int prevc=0;
      if(j==1)
        prevj=m, previ=i-1;
      for(c=0; c<m/2+1; c++) {
        if(j==1)
          prevc=m/2;
        else
          prevc=c-1;
        for(int off=0; off<k and prevc>=0; off++) {
          int prev=(rem+off)%k;
          if(c==0) {
            prevc=max(prevc, 0);
            dp[i][j][c][prev]=dp[previ][prevj][prevc][prev];
            continue;
          }
          dp[i][j][c][prev]=max(dp[i][j][c][prev], max(dp[i][j][c-1][prev], max(ele+dp[previ][prevj][prevc][off], dp[previ][prevj][c][prev])));
          dp[i][j][c][prev]=max(dp[i][j][c][prev], dp[previ][prevj][prevc][prev]);
        }
      }
      if(j!=m)
        continue;
      for(int off=0; off<k; off++)
        cout << dp[i][j][m/2][off] << space;
      cout << endl;
    }
  }
  cout << max(dp[n][m][m/2][0], 0) << endl;
  return;
  // testing 
  /*for(int i=1; i<=n; i++) {
    for(int off=0; off<k; off++) {
      cout << dp[i][m][m/2][off] << space;
    }
    cout << endl;
  }*/

  int ans[n+1][k];
  memset(ans, -1, sizeof(ans));
  for(int rem=0; rem<k; rem++) {
    ans[1][rem]=dp[1][m][m/2][rem];
  }
  
/*for(int i=1; i<=n; i++) {
    for(int rem=0; rem<k; rem++)
      cout << ans[i][rem] << space;
    cout << endl;
  }
cout << "processing" << endl;*/
  for(int i=2; i<=n; i++) {
    for(int x=0; x<k; x++) {
      for(int y=0; y<k; y++) {
        int rem=(x+y)%k;
        if(dp[i][m][m/2][x]!=-1 and ans[i-1][y]!=-1)
          ans[i][rem]=max(ans[i][rem], max(ans[i-1][rem], dp[i][m][m/2][x]+ans[i-1][y]));
        else
          ans[i][rem]=max(ans[i][rem], ans[i-1][rem]);
      }
    }
  }
  /*for(int i=1; i<=n; i++) {
    for(int rem=0; rem<k; rem++)
      cout << ans[i][rem] << space;
    cout << endl;
  }*/
  ans[n][0]=max(ans[n][0], 0);
  cout << ans[n][0] << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

