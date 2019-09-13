#include<iostream>
typedef long long int lli;
using namespace std;
int main() {
    lli n;
    cin>>n;
    lli arr[n];
    lli ans=0;
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(lli i=1;i<n;i++)
    {
        if(abs(arr[i]-arr[i-1])>=abs(arr[i-1]-1))
        {
            ans+=abs(arr[i]-arr[i-1]);
        }else
        {
            arr[i]=1;
            ans+=abs(arr[i-1]-1);
        }
    }
    cout<<ans<<endl;
}