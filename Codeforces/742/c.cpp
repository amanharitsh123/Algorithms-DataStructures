#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>
#include<numeric>

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
#define kick(t) cout << "Case #" << t+1 << ":" << endl;

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

#define N 10
#define M 1<<15

string inp;
lli dp[N][M];

lli foo(int n, int mask) {
  cout << n << space << mask << endl;
  // base case
  
  if(n<0) {
    if(mask == 0) return 1;
    else return -1;
  }

  // Pre computed values
  if(dp[n][mask] != -1) {
    return dp[n][mask];
  }

  int num = inp[n] - '0';
  int new_mask = 0;
  if(mask & (1<<n)) { 
    --num;
    new_mask = mask ^ (1<<n);
  }

  num = (10+num)%10;
  lli intPairs = foo(n-1, new_mask);
  lli ans = 0;
  if(intPairs != -1) {
    ans = (num+1) * intPairs;
  }
/*
  lli carryPairs = foo(n-1, mask | (1<<(n-2)));
  if(carryPairs != -1) {
    ans  += 9-num + carryPairs;
  }
*/
  return dp[n][mask] = ans;
}

void solve(int testcase) {
  lli ans = 0;
  memset(dp, -1, sizeof(dp));
  cin >> inp;
  cout << foo(inp.size()-1, 0) - 2<< endl; 
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin>>testcases;
  for(int testcase=0; testcase<testcases; testcase++) {
    solve(testcase);
  }
}

