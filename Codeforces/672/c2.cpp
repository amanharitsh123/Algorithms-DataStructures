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
#define maxima(l) arr[l]>arr[l-1] and arr[l]>arr[l+1]
#define minima(l) arr[l]<arr[l-1] and arr[l]<arr[l+1]
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
  lli n, q, l, r;
  cin >> n >> q;
  vector<lli> arr={-inf};
  input(arr, n);
  arr.pb(-inf);
  lli max_sum=0, min_sum=0;
  for(int i=1; i<=n; i++) {
    if(arr[i]>arr[i-1] and arr[i]>arr[i+1])
      max_sum+=arr[i];
    if(arr[i]<arr[i-1] and arr[i]<arr[i+1])
      min_sum+=arr[i];
  }
  cout << max_sum-min_sum << endl;
  for(int tt=0; tt<q; tt++) {
    cin >> l >> r;
    map<lli, bool> processed;
    for(lli L=l-1; L<=l+1; L++) {
      if(minima(L))
        min_sum-=arr[L];
      if(maxima(L))
        max_sum-=arr[L];
      processed[L]=true;
    }
    for(lli R=r-1; R<=r+1; R++) {
      if(processed[R])
        continue;
      if(minima(R))
        min_sum-=arr[R];
      if(maxima(R))
        max_sum-=arr[R];
    }
    swap(arr[r], arr[l]);
    for(lli L=l-1; L<=l+1; L++) {
      if(minima(L))
        min_sum+=arr[L];
      if(maxima(L))
        max_sum+=arr[L];
      processed[L]=true;
    }
    for(lli R=r-1; R<=r+1; R++) {
      if(processed[R])
        continue;
      if(minima(R))
        min_sum+=arr[R];
      if(maxima(R))
        max_sum+=arr[R];
      processed[R]=true;
    }
    cout << max_sum-min_sum << endl;
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

