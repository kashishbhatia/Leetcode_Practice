/*
 * Implement a method to draw a circle. You are not allowed to use math library functions such as sqrt, sin, or cos.
 *
 * For example, given r = 2 (radius), return the following points to plot:
 *
 * (0,0), (0,1),(0,2), (1,0), (1,1), (2,0), (0,-1), (0,-2), (-1,0), (-1,1), (1,-1), (-1,-1),(-2,0)
 * Note that all points satisfy the equation: x^2 + y^2 <= r^2.
 *
 * Find points that lie inside the circle with given radius assuming center at (0,0).
 */

/*
 * SOLUTION
 * ==========
 *
 * Considering the centre is fixed at the origin(0,0) point in the 2D plane:
 * Consider the co ordinates of a square with centre as origin and length of each side as 2r.
 * Now look for each co ordinate point and its distance from the centre. If the distance is less than or equals to radius then add it to the list of answers. The only problem in using the euclidian distance formula is to not use the sqrt function. No problem. Just compare the whole sum of squares thing with the square of the radius. They said not to use square root. I just squared the whole equation
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>   //for pair
using namespace std;

  vector< pair<int, int> > drawCircle(int r)
  {
    vector< pair<int, int> > list;
    int l = -r;
    int u = r;
    for (int i = l; i <= u; i++)
    {
      //for (int j = u; j >= l; j--)  OR
      for (int j = l; j <= u; j++)
      {
        if (i * i + j * j <= r * r)
        {
          list.push_back(make_pair(i, j));
        }
      }
    }
    return list;
  }



int main()
{
   vector< pair<int, int> > ans = drawCircle(2);

   vector< pair<int, int> > :: iterator i;      //somehow auto not working
   for (i = ans.begin(); i != ans.end(); i++) { 
      printf("point : (%d, %d)\n", i->first, i->second);
   }

   return 0;

}

//FURETHER IMPROVEMENTS
//https://github.com/wolfsniper2388/Tech_Interviews/blob/master/others/draw_circle.py <<------ USING BINARY SEARCH
