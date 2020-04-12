#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
#define int ll   
#define long int
#define pb push_back
#define all int i=0; i<n; i++

int abso(int k){
	if(k < 0)return -1 * k;
	else return k;
}
int ceilo(int l, int r){
	return l/r + min(l%r, int(1));
}
int flooro(int l, int r){
	return l/r;
}
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int t; cin>>t; while(t--){
		int l,r,g;
		cin>>l>>r>>g;
		
		int low = ceilo(l, g);
	
		low*=g;
		
		int high = flooro(r, g);
		high*=g;
		
		//cout<<low<<" "<<high<<endl;
		
		int s = (high-low)/g + 1;
		if(s !=1)cout<<s<<endl;
			
		else{
			if(g>=l && g<=r)cout<<1<<endl;
			else cout<<0<<endl;
		}
		
	}
	
}


