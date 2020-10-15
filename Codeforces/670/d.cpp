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

int n;
vector<lli> arr;
vector<lli> diff;
lli pos_diff=0, neg_diff=0;

void find_max() {
  lli lo=-1e18, hi=1e18;
  while(lo<=hi) {
    lli mid=(lo+hi)/2;
    lli target=arr[0]-mid+pos_diff;
    if(mid==target) {
      cout << mid << endl;
      return;
    } else if(mid<target) {
      lo=mid+1;
    } else {
      hi=mid-1;
    }
  }
  cout << max(lo, arr[0]-lo+pos_diff) << endl;
}

void solve() {
  cin >> n;
  input(arr, n);
  for(int i=1; i<n; i++) {
    if(arr[i]>=arr[i-1])
      pos_diff+=arr[i]-arr[i-1];
    else
      neg_diff+=arr[i-1]-arr[i];
    diff.pb(arr[i]-arr[i-1]);
  }
  find_max();
  int q;
  cin >> q;
  for(int i=0; i<q; i++) {
    lli l, r, x;
    cin >> l >> r >> x;
    if(l==1)
      arr[0]+=x;
    l-=2;
    if(l!=-1) {
      lli prevdiff=diff[l];
      lli newdiff=diff[l]+x;
      if(prevdiff<0)
        neg_diff+=prevdiff;
      else
        pos_diff-=prevdiff;
      if(newdiff>=0)
        pos_diff+=newdiff;
      else
        neg_diff-=newdiff;
      diff[l]+=x;
    }
    r-=1;
    if(r!=diff.size() and r+1<arr.size()) {
      lli prevdiff=diff[r];
      lli newdiff=diff[r]-x;
      if(prevdiff<0)
        neg_diff+=prevdiff;
      else
        pos_diff-=prevdiff;
      if(newdiff>=0)
        pos_diff+=newdiff;
      else
        neg_diff-=newdiff;
      diff[r]-=x;
    }
    find_max();
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}
