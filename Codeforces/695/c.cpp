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

void solve(int testcase) {
  int n[3];
  for(int i=0; i<3; i++) cin >> n[i];
  vector<lli> mat[3];
  lli total_sum=0;
  lli ans=0;
  for(int i=0; i<3; i++) {
    input(mat[i], n[i]);
    sortall(mat[i]);
    total_sum=accumulate(all(mat[i]), total_sum);
  }
  for(int i=0; i<3; i++) {
    for(int j=0; j<n[i]; j++) {
      lli m1=mat[i][j];
      for(int k=0; k<3; k++) {
        m1=mat[i][j];
        if(k==i) continue;
        int closest_ind=lower_bound(all(mat[k]), m1) - mat[k].begin();
        for(int off=-1; off<=1; off++) {
          m1=mat[i][j];
          if(closest_ind+off >=0 and closest_ind+off<n[k]) {
            int t=closest_ind+off;
            lli m2=mat[k][t];
            // chosen m1 and m2
            // m1-(s2-m2)-s3
            // m2-(s1-m1)
            lli cursum1=total_sum-accumulate(all(mat[i]), 0LL)-m2;
            lli cursum2=accumulate(all(mat[i]), 0LL)-m1;
            cout << m1 << space << m2 << space << ans << endl;
            cout << "cursum1= " << cursum1 << " cursum2= " <<cursum2 << endl;
            m1-=cursum1;
            m2-=cursum2;
            ans=max(ans, m1-m2);
            ans=max(ans, m2-m1);
          }
        }
      }
    }
  }
  cout << "final ans is ";
  cout << ans << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin >> testcases;
  for(int testcase=0; testcase<testcases; testcase++) {
    solve(testcase);
  }
}

