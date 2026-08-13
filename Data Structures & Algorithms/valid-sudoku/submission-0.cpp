class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>>rows(9,vector<bool>(9,false));
        vector<vector<bool>>cols(9,vector<bool>(9,false));
        vector<vector<bool>>box(9,vector<bool>(9,false));
        
        for(int row =0; row<9; row++)
        {
            for(int col = 0; col<9; col++)
            {
                char currentcell = board[row][col];

                if( currentcell =='.')
                {
                    continue;
                }
                int digitIndex = currentcell - '0'-1;
                int subBox = (row/3)*3+(col/3);

                if(rows[row][digitIndex] || cols[col][digitIndex] || box[subBox][digitIndex])
                {
                    return false;
                }
                rows[row][digitIndex]=true;
                cols[col][digitIndex]=true;
                box[subBox][digitIndex]=true;
            }
        }
        return true;
        
    }
};
