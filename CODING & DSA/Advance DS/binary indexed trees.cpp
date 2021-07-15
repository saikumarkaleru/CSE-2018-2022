.BINARY INDEXED TREE

void update(int x, int val)       //add "val" at index "x"
{
    for(; x <= n; x += x&-x)
          BIT[x] += val;
}
int query(int x)      //returns the sum of first x elements in given array a[]
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}
int main()
{
     scanf(“%d”, &n);               //index 1
     int i;
     for(i = 1; i <= n; i++)               
     {
           scanf(“%d”, &a[i]);
           update(i, a[i]);
     }
     printf(“sum of first 10 elements is %d\n”, query(10));
     printf(“sum of all elements in range [2, 7] is %d\n”, query(7) – query(2-1));
     return 0;
}
 
Associative. i.e f(f(a,b),c)=f(a,f(b,c)) this is true even for seg-tree
Has an inverse. eg:
Addition has inverse subtraction (this example we have discussed)
Multiplication has inverse division
gcd() has no inverse, so we can’t use BIT to calculate range gcd’s
Sum of matrices has inverse
Product of matrices would have inverse if it is given that matrices are degenerate i.e. determinant of any matrix is not equal to 0
applications
Binary Indexed Tree can be used to count inversions in an array in O(NlogN) time. 


