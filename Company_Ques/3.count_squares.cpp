/* Finding the squares in a plane given n points */
//Ref : https://stackoverflow.com/questions/3831144/finding-the-squares-in-a-plane-given-n-points

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//assuming A and B are diagnol vertices
void getOtherTwoCoordinates(pair<int, int> A, pair<int, int> B, pair<int, int> &C, pair<int, int> &D)
{

#if 0   
        int midX = (a.x + c.y) / 2;
        int midY = (a.y + c.y) / 2;

        int Ax = a.x - midX;
        int Ay = a.y - midY;
        int bX = midX - Ay;
        int bY = midY + Ax;
#endif
//output may give wrong answers as all of these are declared intergers
        int midX = (A.first + B.second) / 2;
        int midY = (A.second + B.second) / 2;

        int Ax = A.first - midX;
        int Ay = A.second - midY;
        int cX = midX - Ay;
        int cY = midY + Ax;

        C.first = cX;
        C.second = cY;

        int Bx = B.first - midX;
        int By = B.second - midY;
        int dX = midX - By;
        int dY = midY + Bx;
        
        D.first = dX;
        D.second = dY;

}


int SquareCount(vector< pair<int, int> > points) {

   set < pair<int, int> > s;
   int count = 0;

   s.insert(points.begin(), points.end());

   vector< pair<int, int> > :: iterator i, j;
   for (i = points.begin(); i != points.end(); i++) {
      for (j = points.begin(); j != points.end(); j++) {
         if (i == j) continue;

         pair<int, int> C, D;
         getOtherTwoCoordinates(*i, *j, C, D);

         if (s.find(C) != s.end() &&
             s.find(D) != s.end()) {
            count++;
           
            printf("POINT %d: ...\n", count);
            printf("\tpoint 1 : (%d, %d)\n", i->first, i->second);
            printf("\tpoint 2 : (%d, %d)\n", j->first, j->second);
            printf("\tpoint 3 : (%d, %d)\n", C.first, C.second);
            printf("\tpoint 4 : (%d, %d)\n", D.first, D.second);
         }
      }
   }

   return count;
}


int main()
{
   vector< pair<int, int> > points;

   points.push_back(make_pair(0, 1));  
   points.push_back(make_pair(2, 1));  
   points.push_back(make_pair(2, 2));  
   points.push_back(make_pair(1, 0));  
   points.push_back(make_pair(1, 1));  
   points.push_back(make_pair(0, 0));  
   points.push_back(make_pair(1, 2));  
   //points.push_back(make_pair(1, 3));  


   printf("Valid sq count : %u\n", SquareCount(points));  

   return 0;
}

