#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
#define take_input(arr,n) for(lli I=0;I<n;I++) cin>>arr[I]
#define vi vector<lli>

int type(vi &arr,int i,int j)
{
    if(arr[i]<arr[j])
        return 1;
    return 0;
}

int main() {
	lli n,q;
    cin>>n>>q;
    vector<lli> arr(n,0);
    take_input(arr,n);
    while(q--)
    {
        lli l,r,t1,t2;
        cin>>l>>r;
        --l;
        --r; 
        t1=type(arr,l,l+1);
        t2=type(arr,r-1,r);
        if(t1^t2)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
}

