#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col) {
    for(int i=row-1, j=col;i>=0;i--)
    {
        if(board[i][j]==1)
            return false;
    }
   for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
   {
       if(board[i][j]==1)
           return false;
   }
    for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++)
    {
        if(board[i][j]==1)
            return false;
    }
    return true;
}

void nQueenUtil(int row,vector<vector<int>>&board,vector<vector<int>>&ans,vector<int>&ds,int n)
{
    if(row==n)
    {
        ans.push_back(ds);
        return;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(board,row,col))
        {
            board[row][col]=1;
            ds.push_back(col+1);
            nQueenUtil(row+1,board,ans,ds,n);
            board[row][col]=0;
            ds.pop_back();
        }
    }
    return;
}



vector<vector<int>> nQueen(int n) {
    vector<vector<int>>ans;
    vector<int>ds;
    vector<vector<int>>board(n,vector<int>(n,0));
    nQueenUtil(0,board,ans,ds,n);
    return ans;
}


int main()
{

    int n;
    cout<<"Enter the size of the chess board\n";
    cin>>n;
    vector<vector<int>>res;
    res=nQueen(n);
    if(res.size()==0)
    {
        cout<<-1<<"\n";
    }
    else
    {
        for(int i=0;i<res.size();i++)
        {
            cout<<"[";
            for(auto j:res[i])
            {
                cout<<j<<" ";
            }
            cout<<"]\n";
        }
    }

    return 0;
}

