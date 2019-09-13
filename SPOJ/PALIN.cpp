#include<iostream>
#include<string.h>
#define limit 1000002
typedef long long int lli;
using namespace std;

void * inc_mid(char * arr, int n)
{
    lli mid=n/2;
    lli carry=1;
    lli temp;
    // cout<<mid<<endl;
    if(n%2==0)
        --mid;
    while(mid>=0)
    {
        temp=arr[mid]-'0'+carry;
        // cout<<"temp is "<<temp<<endl;
        if(temp>=10)
        {
            carry=1;
            temp=temp%10;
            arr[mid]='0'+temp;
            --mid;
        }
        else
        {
            arr[mid]='0'+temp;
            carry=0;
            break;
        }
    }
    // cout<<mid<<" aa "<<carry<<endl;
    if(mid<0 and carry==1)
    {
        for(int i=n;i>0;i--)
            {arr[i]=arr[i-1];
            // cout<<arr<<endl;
            }
        arr[0]='1';
        // cout<<arr<<endl;
    }
    // return arr;
}

char * solve(char * arr,bool hasinc)
{
    lli size;
    lli n=strlen(arr);
    lli back,front;
    back=n/2;
    front=n/2;
    bool mark=true;
    if(n%2!=0)
    {
            --front;
            ++back;
    }
    else
    {
            --front;
    }
    // cout<<"front is "<<front<<" back is "<<back<<endl;
    while(front>=0 and back<n)
    {
        if(arr[front]>arr[back])
        {
            mark=false;
            while(front>=0 and back<n)
            {
                arr[back]=arr[front];
                ++back;
                --front;
            }
            break;
        }
        else if (arr[back]>arr[front])
        {
            mark=false;
            if(!hasinc)
            {
                inc_mid(arr,n);
                // cout<<"after increment "<<arr<<endl;
                return solve(arr,true);
            }else
            {
                arr[back]=arr[front];
                ++back;
                --front;
            }
            
        } else
        {
            ++back;
            --front;
        }
    }
    if(mark and !hasinc)
    {
        // cout<<arr<<endl;
        inc_mid(arr,n);
        // cout<<"pali after increment "cout<<arr<<endl;
        return solve(arr,true);
    }
    return arr;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char *st=new char[limit];
        cin>>st;
        // cout<<"size if "<<strlen(st)<<endl;
        // inc_mid(st,strlen(st));
        // cout<<st<<endl;
        cout<<solve(st,false)<<endl;
    }
    return 0;
}

// 2
// 808
// 2133