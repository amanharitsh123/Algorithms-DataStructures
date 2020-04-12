#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
using namespace std;
typedef unsigned  long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  T temp;
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

vector< vector<lli>  > dp(1001,vector<lli> {1001,0});

lli binomialCoeff(lli n, lli k)  
{  
    // Base Cases  
    if (k == 0 || k == n)  
        return 1;  
  
    // Recur  
    return binomialCoeff(n - 1, k - 1) +  
                binomialCoeff(n - 1, k);  
}  

lli ncr(lli n, lli r) {
  
  	lli p = 1, k = 1; 
  
	if (n - r < r) 
		r = n - r; 

	if (r != 0) { 
		while (r) { 
			p *= n; 
			k *= r; 

			long long m = __gcd(p, k); 

			p /= m; 
			k /= m; 

			n--; 
			r--; 
		} 

	} 

	else
		p = 1; 

	return p;
} 

void precompute() {
  dp[1][1]=1;
  for(lli i=1;i<=1000;i++) {
    for(lli j=1;j<=1000;j++) {
      cout<<i<<" here  "<<j<<endl;
      dp[i][j]=dp[i-1][j]+dp[i][j-1];
      if(dp[i][j]<0) {
        cout<<"Overflow "<<endl;
        return;
      }
    }
  }
} 

int main() {
  
  lli testcases;
	cin>>testcases;
  precompute();
  cout<<"precompute done"<<endl;
	while(testcases--) {
    lli n,m;
    cin>>n>>m;
    double ans=dp[n][m]/double(ncr(n,m));
    printf("%.6lf",ans);
	}
}

