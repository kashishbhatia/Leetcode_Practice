class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <int> row(1,1);
        vector<vector<int>> res;
        res.push_back(row);

        vector<int> prevRow;
        prevRow = row;
        int prevRowSize = row.size();

       for (int i=1; i < numRows; i++) {
           
           int newSize = prevRowSize+1;
           vector <int> nextRow (newSize, 0);

           for (int j=0; j < newSize; j++) {
               int up = j;
               if (up < prevRowSize)
                    nextRow[j] = prevRow[j];

               int diagUp = j-1;
               if (diagUp >=0)
                    nextRow[j] += prevRow[diagUp];
           }

           res.push_back(nextRow);
           prevRow = nextRow;
           prevRowSize = nextRow.size();

       }
       return res; 
    }
};


//I used DP by storing the prev row values
// and calc. next row by traversing up and diagUp to prevrow to get curr row value

//visualize using matrix
