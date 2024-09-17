#include <stdio.h>


void
print_total(int n)
{

    int i = 0, r;
    const char* units[] = {"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    do {
        r = n % 1024;
        n /= 1024;
        i++;
    } while (n > 1024);

   printf("n is %u.%u %s\n", n, r, units[i]);



}
int main()
{
   print_total(1024 * 1024);    
   print_total(1024);    
   print_total(1023);    
   print_total(1024 * 1024 * 1025);    



   return 0;
}  
