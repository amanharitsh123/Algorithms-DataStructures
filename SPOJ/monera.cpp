#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli n,prev=0;
    cin >> n;
    lli arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *temp = new int[n]();

    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            temp[i] = 1;
            prev = 1;
        }
        else if(arr[i]<arr[i-1])
        {
            temp[i] = 0;
            prev = 0;
        }else
        {
            temp[i] = prev;
        }

    }
    lli i = 0;
    while(arr[i]==arr[i+1])
        ++i;
    if(arr[i]>arr[i+1])
        temp[i]=1;
    else
    {
        temp[i] = 0;
    }
    
    lli count = 1;++i;
    for(;i<n;i++)
    {
        if(temp[i] != temp[i-1])
            count += 1;
    }
    cout<<count<<endl;
    return 0;
}