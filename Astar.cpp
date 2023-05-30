#include<bits/stdc++.h>
using namespace std;

int g=0,n=3,temp;

void copy(int copy[][3],int start[][3])
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            copy[i][j]=start[i][j];
        }
    }
}

void print(int arr[][3])
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(arr[i][j]== -1)
            {
                cout<<'_'<<" ";
            }else{
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int heuristic(int start[][3],int goal[][3])
{
    int h=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(start[i][j] != goal[i][j] && start[i][j]!= -1)
            {
                h+=1;
            }
        }
    }
    return h+g;
}

void moveleft(int t[][3],int row,int col)
{
    temp=t[row][col];
    t[row][col]=t[row][col - 1];
    t[row][col - 1]=temp;
}

void moveright(int t[][3],int row,int col)
{
    temp=t[row][col];
    t[row][col]=t[row][col + 1];
    t[row][col + 1]=temp;
}

void moveup(int t[][3],int row,int col)
{
    temp=t[row][col];
    t[row][col]=t[row - 1][col];
    t[row - 1][col]=temp;
}

void movedown(int t[][3],int row,int col)
{
    temp=t[row][col];
    t[row][col]=t[row+ 1][col];
    t[row+ 1][col]=temp;
}

void movetile(int start[][3],int goal[][3])
{
    int emptycol=0;int emptyrow=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(start[i][j]==-1)
            {
                emptyrow=i;
                emptycol=j;
                break;
            }
        }
    }
    
    int t1[3][3];
    int t2[3][3];
    int t3[3][3];
    int t4[3][3];
    int f1=INT_MAX;
    int f2=INT_MAX;
    int f3=INT_MAX;
    int f4=INT_MAX;
    copy(t1,start);
    copy(t2,start);
    copy(t3,start);
    copy(t4,start);
    
    if(emptycol - 1>=0)
    {
        moveleft(t1,emptyrow,emptycol);
        f1=heuristic(t1,goal);
    }
    if(emptycol + 1<3)
    {
        moveright(t2,emptyrow,emptycol);
        f2=heuristic(t2,goal);
    }
    if(emptyrow - 1>=0)
    {
        moveup(t3,emptyrow,emptycol);
        f3=heuristic(t3,goal);
    }
    if(emptyrow + 1 < 3)
    {
        movedown(t4,emptyrow,emptycol);
        f4=heuristic(t4,goal);
    }
    
    if(f1<=f2 && f1<=f3 && f1<=f4)
    {
        moveleft(start,emptyrow,emptycol);
    }
    else if(f2<=f1 && f2<=f3 && f2<=f4)
    {
        moveright(start,emptyrow,emptycol);
    }
    else if(f3<=f1 && f3<=f2 && f3<=f4)
    {
        moveup(start,emptyrow,emptycol);
    }
    else
    {
        movedown(start,emptyrow,emptycol);
    }
    
    
    
    
    
}

void solve(int start[][3],int goal[][3])
{
    g++;
    movetile(start,goal);
    int f=heuristic(start,goal);
    if(f==g)
    {
        cout<<"Reached final state\n Depth: "<<g;
        return;
    }
    solve(start,goal);
}

int main()
{
    int n=3;
    int start[3][3];
    int goal[3][3];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>start[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>goal[i][j];
        }
    }
    solve(start,goal);
}