Given a source point (sx, sy) and a destination point (dx, dy), the task is to check if it is possible to reach the destination point using the following valid moves:
(a, b) -> (a + b, b)
(a, b) -> (a, a + b)
Your task is to find if it is possible to reach the destination point using only the desired moves or not.
For Example:
For the coordinates, source point = (1, 1) and destination point = (3, 5)
The output will be true as the destination point can be reached using the following sequence of moves:
(1, 1) -> (1, 2) -> (3, 2) -> (3, 5)
  
  
  //TLE
  bool helper(int sx, int sy, int dx, int dy, int cx, int cy){
       if(cx>dx || cy>dy){
           return false;
       }
    
       if(cx==dx && cy==dy){
           return true;
       }
       
       bool smallans1 = helper(sx,sy,dx,dy,cx+cy,cy);
       if(smallans1){
           return true;
       }
       bool smallans2 = helper(sx,sy,dx,dy,cx, cx+cy);
       if(smallans2){
           return true;
       }
    
      return false;
       
       
       
        
    }

bool reachDestination(int sx, int sy, int dx, int dy) {
    // Write your code here
    int cx = sx;
    int cy = sy;
   return helper(sx,sy,dx,dy,cx,cy);
        
     
}



//optimised
//linear complexity


bool reachDestination(int sx, int sy, int dx, int dy) {
    if(sx==dx && sy==dy){
        return true;
    }
    
    //base case
    if(dx<sx || dy<sy){
        return false;
    }
    
    
    if(dx>dy){
       if(reachDestination(sx,sy,dx-dy,dy)){
           return true;
       }
    }
    else{
        if(reachDestination(sx,sy, dx, dy-dx)){
            return true;
        }
    }
    
    return false;
    
}
