// Java implementation of the approach 
import java.util.*; 

class GFG 
{ 

	// Function to return the count 
	// of elements in arr[] which are 
	// less than the given key 
	static int countLessThan(int arr[], int n, int key) 
	{ 
		int l = 0, r = n - 1; 
		int index = -1; 
	
		// Modified binary search 
		while (l <= r) 
		{ 
			int m = (l + r) / 2; 
	
			if (arr[m] < key) 
			{ 
				l = m + 1; 
				index = m; 
			} 
			else
			{ 
				r = m - 1; 
			} 
		} 
	
		return (index + 1); 
	} 
	
	// Function to return the count 
	// of elements in arr[] which are 
	// greater than the given key 
	static int countGreaterThan(int arr[], int n, int key) 
	{ 
		int l = 0, r = n - 1; 
		int index = -1; 
	
		// Modified binary search 
		while (l <= r) 
		{ 
			int m = (l + r) / 2; 
	
			if (arr[m] <= key) 
			{ 
				l = m + 1; 
			} 
			else
			{ 
				r = m - 1; 
				index = m; 
			} 
		} 
	
		if (index == -1) 
			return 0; 
		return (n - index); 
	} 
	
	// Function to return the count 
	// of the required triplets 
	static int countTriplets(int n, int a[], int b[], int c[]) 
	{ 
		// Sort all three arrays 
		Arrays.sort(a) ; 
		Arrays.sort(b); 
		Arrays.sort(c); 
	
		int count = 0; 
	
		// Iterate for all the elements of array B 
		for (int i = 0; i < n; ++i) 
		{ 
			int current = b[i]; 
		
	
			// Count of elements in A[] 
			// which are less than the 
			// chosen element from B[] 
			int low = countLessThan(a, n, current); 
	
			// Count of elements in C[] 
			// which are greater than the 
			// chosen element from B[] 
			int high = countGreaterThan(c, n, current); 
	
			// Update the count 
			count += (low * high); 
		} 
	
		return count; 
	} 
	
	// Driver code 
	public static void main(String args[]) 
	{ 
		int a[] = { 1, 5 }; 
		int b[] = { 2, 4 }; 
		int c[] = { 3, 6 }; 
		int size = a.length; 
	
		System.out.println(countTriplets(size, a, b, c)); 
	
	} 
} 
// This code is contributed by Arnab Kundu 
