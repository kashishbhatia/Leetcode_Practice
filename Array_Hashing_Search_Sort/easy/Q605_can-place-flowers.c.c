class Solution {
public:

//BRUTE FORCE

/*
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if (flowerbed.size() == 0 && n > 0 ||
            flowerbed.size() == 1 && flowerbed[0] == 1 && n > 0) {
            return false;
        }

        if (n==0) {
            return true;
        }

        for (int i=0; i < flowerbed.size();) {
            if (i==0) {
                if (flowerbed[i] == 0 && flowerbed[i+1] != 1) {
                    flowerbed[i] = 1;
                    i += 2;
                    n--;
                } else {
                    i++;
                }
            } else if (i == flowerbed.size()-1) {
                if (flowerbed[i] == 0 && flowerbed[i-1] != 1) {
                    flowerbed[i] = 1;
                    n--;
                }
                i++;    //incr i regardless
            } else {
                if (flowerbed[i] == 0 && flowerbed[i-1] != 1 &&
                     flowerbed[i+1] != 1) {
                    flowerbed[i] = 1;
                    i += 2;
                    n--;
                }
            }
        }

        if (n != 0)
            return false;

        return true; 
    }
*/

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 0 && n > 0 ||
            flowerbed.size() == 1 && flowerbed[0] == 1 && n > 0) {
            return false;
        }

        if (flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1) {
            return true;
        }

        if (n==0) {
            return true;
        }

        int i=0;
        while (i < flowerbed.size()) {
            if (flowerbed[i] == 1) {
                i += 2;
            } else {
                if (i == 0) {
                    if (flowerbed[i] == 0 && flowerbed[i+1] != 1) {
                        flowerbed[i] = 1;
                        n--;
                        if (n == 0) return true;
                        i += 2;
                    } else {
                        i++;
                    }
                    continue;
                }
                
                if (i == flowerbed.size()-1 ) {
                    if (flowerbed[i] == 0) {
                        flowerbed[i] = 1;
                        n--;
                        if (n == 0) return true;
                        i++;
                    }
                    continue;
                }
                
                if (flowerbed[i] == 0) {
                    if (flowerbed[i+1] != 1 && flowerbed[i-1] != 1){
                        flowerbed[i] = 1;
                        n--;
                        if (n == 0) return true;
                        i += 2;
                    } else {
                        i++;
                    }
                    continue;
                }
            }
        }
        if (n == 0)
            return true;

        return false; 

    }
};


/*

short greedy algo

  public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.length && count < n; i++) {
            if(flowerbed[i] == 0) {
        //get next and prev flower bed slot values. If i lies at the ends the next and prev are considered as 0. 
               int next = (i == flowerbed.length - 1) ? 0 : flowerbed[i + 1]; 
               int prev = (i == 0) ? 0 : flowerbed[i - 1];
               if(next == 0 && prev == 0) {
                   flowerbed[i] = 1;
                   count++;
               }
            }
        }
        
        return count == n;
    }

*/




