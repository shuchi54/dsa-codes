The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.
Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.
Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
1. They share a row. 
2. They share a column. 
3. They share a diagonal. 
  
  
  #include<bits/stdc++.h>
using namespace std;

int board[10][10];

bool isPossible(int n, int row, int col,vector<int>&rows,vector<int>&d1,vector<int>&d2){
//   //same column
//   for(int i=row-1; i>=0; i--){
//     if(board[i][col]==1){
//       return false;
//     }
//   }
  
//   //upper left diagnol
//   for(int i=row-1,j=col-1; i>=0 && j>=0; i--, j--){
//     if(board[i][j]==1){
//       return false;
//     }
//   }
  
//   //upper right diagnol
//   for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++){
//     if(board[i][j]==1){
//       return false;
//     }
//   }
  
//   return true;
       if ((rows[col] == -1) && (d1[row+col] == -1) && (d2[row-col + n - 1] == -1))
        {
            return true;
        }   
    return false;
}

void nQueenHelper(int n, int row, vector<vector<int>>&ans,vector<int>&rows,vector<int>&d1,vector<int>&d2){
  
  //Base case
  if(row==n) {
    //we have reached some solution.
    //Print the board matrix
    //return
     vector<int>res;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        res.push_back(board[i][j]);
      }
      
    }
    ans.push_back(res);
    return ;

    
    
  }
  
  //for that particulat row check all columns ->smaller problem move
  //place at all possible positions and move to smaller problem
  for(int j=0; j<n; j++){
    if(isPossible(n,row, j, rows,d1,d2)){
      board[row][j] = 1;
      rows[j] = d1[row+j] = d2[row-j+n-1] =  1;
      nQueenHelper(n, row+1,ans,rows,d1,d2);
      rows[j] = d1[row+j] = d2[row-j+n-1] =  -1;
      board[row][j] = 0;
    }
  } 
  return;
}
 

vector<vector<int>> nQueens(int n){
  
  //setting board
  memset(board, 0, 10*10*sizeof(int));
  vector<vector<int>> ans;
  vector<int> rows(n,-1), d1(2*n,-1), d2(2*n,-1);
  nQueenHelper(n,0,ans, rows, d1, d2);
  return ans;
  
}


