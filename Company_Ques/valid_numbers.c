#include <stdio.h>


int mod (int i, int p)
{
   return (i % p);
}

int validIndex(int i)
{
   int digit = 0;
   int index = 0;
   int isValid = 1; //asuming it is a valid number

   while (i != 0) {
      digit = i % 10;

      // if index is even and digit is also even(not odd)     
      if ((index%2 == 0) && (digit%2 == 0)) {
         isValid = 0;
         break;
      } else if ((index%2 != 0) && (digit%2 != 0)) {  // if index is odd and digit is also odd
         isValid = 0;
         break;
      }

      i = i/10;
      index++;
   }   

   return isValid;
}


int validNum(int l, int r, int p)
{
   int i, cnt = 0;
   for (i = l; i <= r; i++) {
      if ((mod(i, p) == 0) && validIndex(i)) {
         cnt++;
      }
   }

   return cnt;
}

int main()
{

   int p = 37;
   int l = 100, r = 2500;

   int res = validNum(l, r, p);

   printf("valid numbers =%d\n", res);

   return 0;
}
