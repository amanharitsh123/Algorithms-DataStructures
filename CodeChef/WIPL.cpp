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

#define N 4002
#define K 4002

int dp[N][K];
int prev_selected[N][K];
vector<int> arr;
vector<int> get_selected_elements(int n, int k) {
  vector<int> ans;
  while(k>0 and n>0) {
    //cout << "k is " << k << endl;
    int cur=prev_selected[n][k];
    ans.push_back(cur-1);
    n=prev_selected[n][k-arr[cur-1]];
    k-=arr[cur-1];
  }
  return ans;
}

void solve() {
  memset(dp, inf, sizeof(dp));
  memset(prev_selected, -1, sizeof(prev_selected));
  int n, k;
  cin >> n >> k;
  arr.clear();
  input(arr, n);
  sortall(arr);
  for(int i=1; i<=n; i++) {
    dp[i][k]=dp[i-1][k];
    prev_selected[i][0]=0;
    dp[i][0]=0;
    prev_selected[i][k]=prev_selected[i-1][k];
    prev_selected[i][arr[i-1]]=i;
    for(int sum=K-1; sum>0; sum--) {
      int other=sum-arr[i-1];
      if(other<0) { 
        other=sum;
        dp[i][other]=dp[i-1][other];
        prev_selected[i][other]=prev_selected[i-1][other];
        continue;
      }
      if(dp[i][sum]>(dp[i-1][other]+1)) {
        dp[i][sum]=dp[i-1][other]+1;
        prev_selected[i][sum]=i;
        prev_selected[i][other]=prev_selected[i-1][other];
      }
    }
  }
  while(k<K and dp[n][k]==inf) ++k;
  if(k==K) {
    cout << -1 << endl;
    return;
  }
  //cout << "prev selected " << prev_selected[n][k] << endl;
  //cout << "minimum elements for k " << dp[n][k] << endl;
  vector<int> indices = get_selected_elements(n, k);
  //cout << "seleceted indices are ";
  //output(indices);
  map<int, int> mp;
  for(auto x:indices) mp[x]=1;
  int count=0, cursum=0, i=n-1;
  for(i=n-1; i>=0 and cursum<k; i--) {
    if(mp.find(i)!=mp.end())
      continue;
    cursum+=arr[i];
    count++;
  }
  if(cursum<k) {
    cout << -1 << endl;
    return;
  }
  cout << count+dp[n][k] << endl;;
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

