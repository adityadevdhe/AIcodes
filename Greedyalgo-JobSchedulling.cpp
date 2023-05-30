#include<bits/stdc++.h>
using namespace std;

struct Job{
    char id;
    int dead;
    int profit;
};

bool comparision(Job a,Job b){
    return(a.profit>b.profit);
}

void printJob(Job arr[],int n)
{
    sort(arr,arr+n,comparision);
    int result[n];
    bool slot[n];
    for(int i=0;i<n;++i)
    {
        slot[i]=false;
    }
    
    
    for(int i=0;i<n;++i)
    {
        for(int j= min(n,arr[i].dead) - 1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                slot[j]=true;
                result[j]=i;
                break;
            }
        }
    }
    cout<<"Results\n";
    for(int i=0;i<n;++i)
    {
        if(slot[i])
        {
            cout<< arr[result[i]].id <<endl;
        }
    }
}

int main()
{
    Job arr[]={{'a',2,125},
                {'b',1,19},
                {'c',2,27},
                {'d',1,25},
                {'e',3,15}
        
    };
    int n= sizeof(arr)/sizeof(arr[0]);
    printJob(arr,n);
    
}