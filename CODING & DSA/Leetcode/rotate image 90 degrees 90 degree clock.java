/*
The only thing that is different is to print the elements of the cycle in a clockwise direction 
i.e. An N x N matrix will have floor(N/2) square cycles. 
For example, a 3 X 3 matrix will have 1 cycle. 
The cycle is formed by its 1st row, last column, last row, and 1st column. 
For each square cycle, we swap the elements involved with the corresponding cell
 in the matrix in the clockwise direction. We just need a temporary variable for this.


Let size of row and column be 3. 
During first iteration – 
a[i][j] = Element at first index (leftmost corner top)= 1.
a[j][n-1-i]= Rightmost corner top Element = 3.
a[n-1-i][n-1-j] = Rightmost corner bottom element = 9.
a[n-1-j][i] = Leftmost corner bottom element = 7.
Move these elements in the clockwise direction. 
During second iteration – 
a[i][j] = 2.
a[j][n-1-j] = 6.
a[n-1-i][n-1-j] = 8.
a[n-1-j][i] = 4. 
Similarly, move these elements in the clockwise direction. 

*/

class GFG
{
static int N = 4;
static void rotate90Clockwise(int a[][])
{

	// Traverse each cycle
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = i; j < N - i - 1; j++)
		{

			// Swap elements of each cycle
			// in clockwise direction
			int temp = a[i][j];
			a[i][j] = a[N - 1 - j][i];
			a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
			a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
			a[j][N - 1 - i] = temp;
		}
	}
}

// Function for print matrix
static void printMatrix(int arr[][])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		System.out.print( arr[i][j] + " ");
		System.out.println();
	}
}

	public static void main (String[] args)
	{
			int arr[][] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };
	rotate90Clockwise(arr);
	printMatrix(arr);
	}
}

