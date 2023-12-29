#include <stdio.h>

#if 0

pure storage buddy system bitmap
    Given a complete binary tree with nodes of values of either 1 or 0, the following rules always hold:
    (1) a node's value is 1 if and only if all its subtree nodes' values are 1
    (2) a leaf node can have value either 1 or 0
    Implement the following 2 APIs:
    set_bit(offset, length), set the bits at range from offset to offset+length-1
    clear_bit(offset, length), clear the bits at range from offset to offset+length-1
    
    i.e. The tree is like:
                 0
              /     \
             0        1
           /  \      /  \
          1    0    1    1
         /\   / \   / 
        1  1 1   0 1
        Since its complete binary tree, the nodes can be stored in an array:
        [0,0,1,1,0,1,1,1,1,1,0,1] 
        



#endif

int tree[] = {0,0,1,1,0,1,1,1,1,1,0,1};


void printTree(int tree[], int n)
{
   int i;
   for (i=0; i < n; i++) {
      printf("%d ", tree[i]);
   }

   printf("\n");

}


//iterative
void set_descendents1(int tree[], int index, int n)
{
   
   if (index >= n) return;

   int i = index;
   int left = 2*i+1;
   int right = 2*i+2;
   while (i < n && left < n && right < n) {
      //left child
      if ((left < n) && (left == 0)) {
         tree[left] = 1;
         left = 2*left + 1;
      }

      //right child
      if ((right < n) && (right == 0)) {
         tree[right] = 1;
         right = 2*right + 1;
      }

      else 
         break;
   } 
}


//recursive
void set_descendents2(int tree[], int index, int n)
{
   
   if (index >= n) return;

   int i = index;
   int left = 2*i+1;
   int right = 2*i+2;

   if ((left < n) && (left == 0)) {
      tree[left] = 1;
      set_descendents2(tree, left, n);
   }

   if ((right < n) && (right == 0)) {
      tree[right] = 1;
      set_descendents2(tree, right, n);
   }
}



void set_bit(int tree[], int offset, int len, int n)
{
   if (sizeof(tree) == 0 || offset < 0 || len < 0)
      return;

   int i;

   if (len > n) len = n;
   //TODO
   //terminating condn : min(offset + len, n) 

   for (i = offset; i < offset + len; i++) {

      if (tree[i] == 1) continue;

      //else set the bit
      tree[i] = 1;

      //now set all the descedents of this newly set node
      set_descendents2(tree, i, n);


      //now make sure to adjust ancestors if the sibling of this set node is also 1
      //if "i" is left node, the check for right sibling
      //else chck for its left sibling

      int ii = i;
      while (ii > 0) {     
         //if i is right child, check its sibling at left
         if (ii % 2 == 0 && tree[ii-1] == 1)
            tree[(ii-1)/2] = 1;

         //if i is left child, check its sibling at right
         else if (ii % 2 == 1 && ii+1 < n && tree[ii+1] == 1)
            tree[(ii-1)/2] = 1;

         //go up to its parent
         ii = (ii-1)/2;
      }
   }


   printTree(tree, n);
//OUTPUT :
//1 1 1 1 1 1 1 1 1 1 0 1 
}


void clear_bit(int tree[], int offset, int len, int n)
{  
   if (sizeof(tree) == 0 || offset < 0 || len < 0)
      return;
   
   int i;
   
   if (len > n) len = n;

   //TODO
   //terminating condn : min(offset + len, n) 
   for (i = offset; i < offset + len; i++) {
      
      //already cleared
      if (tree[i] == 0) continue;
    

      //else clear it
      tree[i] = 0;

      //alter descendants, any one of them
      int j = i;
      while (2*j+1 < n) {
         tree[2*j+1] = 0;
         j = 2*j+1; 
      }

      //alter ancestors
      j = i;
      while (j > 0) {
         //parent already unset, break
         if (tree[(j-1)/2] == 0)    break;

         tree[(j-1)/2] = 0;
         j = (j-1)/2;
      }

   }

   printTree(tree, n);
//OUTPUT:
//0 0 0 1 0 0 1 1 1 0 0 0 
}


int main()
{

   int n = sizeof(tree)/sizeof(tree[0]);

   int offset = 4;
   int len = 2;

/*
                 0
              /     \
             /       \
             0        1
           /  \      /  \
          1    0<- 1    1      this node is offset
         /\   / \   / 
        1  1 1   0 1

*/


   set_bit(tree, offset, len, n);

   offset = 4;
   len = 2;

   clear_bit(tree, offset, len, n);

   return 0;
}
