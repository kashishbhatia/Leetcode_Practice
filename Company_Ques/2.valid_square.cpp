
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set <int> st;

        //p1 and p2
        int d1 = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
        st.insert(d1);

        //p1 and p3
        int d2 = pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2);
        st.insert(d2);

        //p1 and p4
        int d3 = pow(p1[0] - p4[0], 2) + pow(p1[1] - p4[1], 2);
        st.insert(d3);

        //p2 and p3
        int d4 = pow(p2[0] - p3[0], 2) + pow(p2[1] - p3[1], 2);
        st.insert(d4);

        //p2 and p4
        int d5 = pow(p2[0] - p4[0], 2) + pow(p2[1] - p4[1], 2);
        st.insert(d5);

        //p3 and p4
        int d6 = pow(p3[0] - p4[0], 2) + pow(p3[1] - p4[1], 2);
        st.insert(d6);

        //only 2 unique elements are present in set and
        //element with 0 distance not present
        return (st.size() == 2) && (st.count(0) == 0);
    }


int main()
{

   vector<int> p1;
   p1.push_back(0);
   p1.push_back(0);

   vector<int> p2;
   p2.push_back(1);
   p2.push_back(1);

   vector<int> p3;
   p3.push_back(1);
   p3.push_back(0);

   vector<int> p4;
   p4.push_back(0);
   p4.push_back(1);

   printf("Is this valid square : %u\n", validSquare(p1, p2, p3, p4));

   return 0;
}
