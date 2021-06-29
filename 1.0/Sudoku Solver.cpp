// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
     bool solve(vector<vector<char>>& board) {
      for(int i=0; i<board.size(); i++){
          for(int j=0; j<board[0].size(); j++){
              if(board[i][j]=='.'){
                  for(char c='1';c<='9'; c++){
                      if(isValid(board,i,j,c)){
                          board[i][j] = c;
                          if(solve(board)==true)
                              return true;
                          
                          else
                              board[i][j] = '.';
                          
                          
                      }
                      
                  }
                  
                  //if for entire for loop(all nos) on board for that particular character not getting true 
                  return false;
                  
              }
          }
      }
         
         //no . found, everything filled got sudoko
         return true;
     }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0; i<9; i++){
            
            
            if(board[i][col]==c){
                //vah column
                return false;
            }
            
            if(board[row][i]==c){
                //vah row
                return false;
            }
            
            //need to check small square particular
            int rsmall = 3*(row/3)+i/3;
            int csmall = 3*(col/3)+ i%3;
            if(board[rsmall][csmall]==c){
                return false;
            }
            
        }
        
        return true;
    }
};
