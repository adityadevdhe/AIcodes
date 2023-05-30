#include<bits/stdc++.h>
#include<string>

using namespace std;



void solve(bool board[][4],int row,bool cols[],bool ndiag[],bool rdiag[],string asf,int n)
{
    for (int col=0;col<n;++col)
    {
        
        if(row== n)
        {
            cout<<asf<<endl;
            return;
        }
        
        if(cols[col]==false && ndiag[row+col]==false && rdiag[row - col +  n - 1]==false )
        {
            board[row][col]=true;
            cols[col]=true;
            ndiag[row+col]=true;
            rdiag[row - col + n - 1] =true;
            solve(board,row+ 1,cols,ndiag,rdiag,asf + to_string(row) + "-"+ to_string(col)+" ",n);
             board[row][col]=false;
            cols[col]=false;
            ndiag[row+col]=false;
            rdiag[row - col + n - 1] =false;
        }
    }
}

int main()
{
    int n=4;
    int diagonal=2*n - 1;
    bool board[4][4];
    
    bool cols[n]={false};
    bool ndiag[diagonal]={false} ;
    bool rdiag[diagonal]= {false};
    solve(board,0,cols,ndiag,rdiag,"",n);
}
