#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

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

bool possible(vector<int> &arr, int len) {
  multiset<int, greater<int> > p;
  //cout << "processing " << len << endl;
  for(auto x:arr) {
    //cout << x << " ";
    p.insert(x);
  }
  //cout << endl;
  while(*p.begin() > 1) {
    vector<int> st;
    int top=*p.begin();
    p.erase(p.begin());
    //cout << "top is " << top << endl;
      int l=len;
      multiset<int> q;
      while(l!=0 and p.size()) {
        if(*p.begin()==0)
          return false;
        q.insert(*p.begin()-1);
        p.erase(p.begin());
        --l;
      }
      if(l!=0)
        return false;
      top--;
      //cout << "top is " << top << endl;
      p.insert(top);
      for(auto x:q)
        if(x!=0)
          p.insert(x);
  }
  return true;
}

void solve() {
  int n, x;
  cin >> n;
  map<int, int> mp;
  for(int i=0; i<n; i++) {
    cin >> x;
    mp[x]++;
  }
  vector<int> arr;
  for(auto x:mp)
    arr.pb(x.second);
  int lo=0, hi=n-2;
  int ans=0;
  while(lo<=hi) {
    int mid=(lo+hi)/2;
    if(possible(arr, mid))
      ans=mid, lo=mid+1;
    else
      hi=mid-1;
  }
  cout << max(ans, (possible(arr, lo)?lo:-1)) << endl;
  //cout << "*****************************" << endl;
  /*lli p=0;
  vector<int> counts;
  n=arr.size();
  output(arr);
  for(int i=0; i<arr.size(); i++) {
    x=arr[i];
    if(x-p==0)
      continue;
    if(x-p!=1)
      counts.pb(n-1-i);
    p+=x;
  }
  cout << "Counts is "; output(counts);
  sort(all(counts));
  n=counts.size();
  counts.pb(INT_MAX);
  for(int i=0; i<n; i++) {
    int offset=dis/(i+1);
    ans=min(counts[0]+offset, counts[i+1]);
  }*/
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

