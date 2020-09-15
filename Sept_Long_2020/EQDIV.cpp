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
      ans = ans*a;
    a = a*a;
    b >>= 1;
  }
  return ans;
}

int k;
void solve() {
  lli n;
  cin >> n;
  set<lli, greater<lli> > s;
  for(int i=1; i<=n; i++)
    s.insert(i*i*i*i);
  
  while(s.size()!=1) {
    auto e1=*s.begin();
    s.erase(s.begin());
    auto e2=*s.begin();
    s.erase(s.begin());
    s.insert(e1-e2);
  }
  cout << *s.begin() << endl;
}

string compli(string temp) {
  if(temp=="01")
    return "10";
  else
    return "01";
}

// Solution for 4
string zero_four="10010110011010010110100110010110";
vector<lli> val_four={1, 15, 64, 158, 271, 317, 126, 34, 253, 13, 92, 30, 47, 31, 2, 0, 1, 13, 0, 0, 9, 1, 0, 0, 1, 5, 0, 0, 5, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0};
vector<string> ans_string_four={
"0",
"01",
"001",
"0001",
"00001",
"000001",
"0000001",
"11010001",
"111110001",
"0101001001",
"00000101001",
"110010101001",
"0010110101001",
"11111110000101",
"100001110101001",
"1111000111110001",
"11010111100000011",
"111111001011110001",
"0111101101001000011",
"11110101001000100011",
"000000000100100100011",
"0010110000100000001011",
"11110111011001000010011",
"111101100001001000001011",
"1010001010000001000000111",
"00010100000100010000110101",
"110000111111100001000000111",
"1110100000111010000100000111",
"10101011101110100000101010101",
"101001101100100100000000100111",
"0010011110001000100000000010111",
"11101111101001010000000000001111",
"111100111001000010100000000001111",
"0101010001000000000100010000010111",
"10111000110100101000000010000001111",
"011010101011100010000000000100001111",
"0000000101000100000001000000000111011",
"10001010101100001000000000000000101111",
"111111011011101000001000000000000101111",
"1111110110110011101000000000000000011111",
"00111010101001100000000000100000000011111",
"000000010000000101000001010000000000011111",
"1110101100111110001000000000000100000011111",
"11111011111010100001000000000000001000011111",
"010000010000010000000101000000000001000011111",
"1111100010101010101000000000000000000001011111",
"10101011111010101000010000000000000000000111111",
"110110111011111000001000001000000000000000111111",
"1111101100101011101000000000000100000000000111111",
"00000010010010000000000100000000000100000000111111",
"101011111111101010100001000000000000010000000111111",
"1011111111001010001000000010000000000000100000111111",
"00110110100001000000000000000000000000000000010111111",
"111110111110101111000001000000000000000000000010111111",
"0110111111101000101010000010000000000000000000001111111",
"11111110111110111100001000000000100000000000000001111111",
"101011000110101010101000000000000000001000000000001111111",
"0101000010011000001000000000000000000000000100000001111111",
"11111010111011101000101000000000000000000000010000001111111",
"111011101010101111001010000000000000000000000000100001111111",
"0011001000000010000001000000000000000000000000000000101111111",
"10111011100111111010101000100000000000000000000000000101111111",
"111010101110101000111010000000001000000000000000000000011111111"
};

void solve_four() {
  lli n;
  cin >> n;
  if(n<=63) {
    cout << val_four[n-1] << endl;
    cout << ans_string_four[n-1] << endl;
  } else {
    int start=0;
    int ans=0;
    if(n%32!=0) {
      ans=val_four[31+n%32];
      cout << ans << endl;
      cout << ans_string_four[31+n%32];
      n-=32+n%32;
    } else {
      cout << 0 << endl;
    }
    for(int i=0; i<n; i+=32) {
      cout << zero_four;
    }
    cout << endl;
  }
}


// Solution for k=3

vector<lli> val_three={1, 7, 18, 28, 25, 7, 26, 4, 5, 1, 12, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0};

vector<string> ans_string_three={
"0",
"10",
"110",
"1110",
"11110",
"101110",
"0001110",
"00110110",
"011010110",
"0111111010",
"11110010110",
"001011100110",
"1111101111100",
"10100110010110",
"001111010111100",
"0110100110010110",
"00010110111110010",
"010011010101011010",
"1100110110100111100",
"01011111110111111000",
"100111111110101101100",
"1111111111111110111000",
"10001111101111110111000",
"101011110110111110111000",
"0001111011111111111110000",
"10110011010111111111110000",
"011101101111111011111110000"
};

string zero_three="0110100110010110";
void solve_three() {
  lli n;
  cin >> n;
  if(n<=27) {
    cout << val_three[n-1] << endl;
    cout << ans_string_three[n-1] << endl;
  } else {
    int start=0;
    int ans=0;
    if(n%16!=0) {
      int offset=n%16;
      if(offset<=11) {
        ans=val_three[15+offset];
        cout << ans << endl;
        cout << ans_string_three[15+offset];
        n-=16+offset;
      } else {
        ans=val_three[offset-1];
        cout << ans << endl;
        cout << ans_string_three[offset-1];
        n-=n%16;
      }
    } else {
      cout << 0 << endl;
    }
    for(int i=0; i<n; i+=16) {
      cout << zero_three;
    }
    cout << endl;
  }
}



vector<lli> val={1, 3, 4, 2, 3, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0};
vector<string> ans_string={
"0",
"10",
"110",
"1110",
"10110",
"010110",
"0010110",
"10010110",
"100111010",
"1011011010",
"01000111010",
"111111110010",
"1110111101100",
"00101111110100",
"001101111111000"
};

string zero="01101001";

void solve_two_opt() {
  lli n;
  cin >> n;
  if(n<=15) {
    cout << val[n-1] << endl;
    cout << ans_string[n-1] << endl;
  } else {
    int start=0;
    int ans=0;
    if(n%8!=0) {
      ans=val[7+n%8];
      cout << ans << endl;
      cout << ans_string[7+n%8];
      n-=8+n%8;
    } else {
      cout << 0 << endl;
    }
    for(int i=0; i<n; i+=8) {
      cout << zero;
    }
    cout << endl;
  }
}

void solve_one() {
  lli n;
  cin >> n;
  if(n==1) {
    cout << 1 << endl << 1 << endl;
    return;
  }
  lli min_diff=1e9;
  lli cnt_back=0, ind=-1;
  lli sum_back=0;
  lli total_sum=0;
  for(int i=1; i<=n; i++)
    total_sum+=power(i, k);
  lli target=total_sum/2;
  for(int back=1; back<n and min_diff!=0; back++) {
    sum_back+=n-back+1;
    lli lo=0, hi=n-back;
    while(lo<=hi) {
      lli mid=(lo+hi)/2;
      if(sum_back+mid==target) {
        min_diff=(total_sum-2*target);
        ind=mid;
        cnt_back=back;
        break;
      } else if(sum_back+mid>target) {
        lli cur_diff=abs(total_sum-(sum_back+mid)-(sum_back+mid));
        if(cur_diff<min_diff) {
          min_diff=cur_diff;
          ind=mid;
          cnt_back=back;
        }
        hi=mid-1;
      } else {
        lli cur_diff=abs(total_sum-(sum_back+mid)-(sum_back+mid));
        if(cur_diff<min_diff) {
          min_diff=cur_diff;
          ind=mid;
          cnt_back=back;
        }
        lo=mid+1;
      }
    }
  }
  string ans(n, '0');
  int i=n-1;
  while(cnt_back--)
    ans[i]='1', i--;
  if(ind!=0)
  ans[ind-1]='1';
  cout << min_diff << endl;
  cout << ans << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin>>k>>testcases;
  while(testcases--) {
    if(k==1)
      solve_one();
    else if(k==2)
      solve_two_opt();
    else if(k==3)
      solve_three();
    else 
      solve_four();
  }
}


