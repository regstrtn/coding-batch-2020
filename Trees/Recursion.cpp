vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> merged;
	int lena = left.size(); 
	int lenb = right.size(); 
	int i = 0, j = 0; 
	while(i<lena && j<lenb) {
		if(left[i]<=right[j]) {
			merged.push_back(left[i]); 
			i++; 
		}
		else {
			merged.push_back(right[j]); 
			j++; 
		}
	}
	while(i<lena) {
		merged.push_back(left[i]); 
		i++;
	}
	while(j<lenb) {
		merged.push_back(right[j]); 
		j++;
	}
	return merged; 
}

vector<int> mergeSort(vector<int> arr, int start, int end) {
	int lena = arr.size(); 
	if(end == start) {
		return vector<int> (1, arr[start]);
	} 
	int mid = (start + end)/2; 
	vector<int> left = mergeSort(arr, start, mid-1);
	vector<int> right = mergeSort(arr, mid+1, end); 
	vector<int> merged = merge(left, right); 
	return merged; 
}

int main() {
	vector<int> mergedArr = mergeSort(arr); 
}





/***** COIN CHANGE *****/


int numWaysToMakeChange( vector<int> S, int m, int n ) 
{ 
	//Base Cases: 
    //Base Case1: 
    //If we have reached n = 0, it means there is atleast 1 way to make this change
    if (n == 0) 
        return 1; 

	//Base case2: This cannot be solved, return 0      
    if (n < 0) 
        return 0; 
  
    // If there are no coins and n  
    // is greater than 0, then no 
    // solution exist
    if (m <=0 && n >= 1) 
        return 0; 
  
  	//Iterative case: 
  	//Way 1: do not include any coin on value S[m-1]
  	int count1 = numWaysToMakeChange(S, m-1, n);
  	//Way 2: include 1 coin of value S[m-1] 
  	//and see how many ways n-S[m-1] can be made 
  	
  	int count2 = numWaysToMakeChange(S, m, n-S[m-1]);
  	
  	return count1 + count2; 
} 



/**** COIN CHANGE *****/




//Array sum recursively

int arrSum(vector<int> arr) {
	int i = 0, len = arr.size(); 
	int sum = 0; 
	for(i=0;i<len;i++) sum = sum + arr[i];
	return sum; 
}


[0....n-2] + [n-1]

[0]


[0...n/2] [n/2...n-1]

[0]  [n/2]

int arrSumRecursively(vector<int> arr, int start, int end) {
	if(start == end) {
		return arr[start]; 
	}
	else {
		int sum = arrSumRecursively(arr, start, end-1); 
		sum = sum + arr[end];  //Do something with the result
		return sum; 
	}
}

[0 1 2]
start = 0
end = 2
1st iteration: 
	mid = 1
	left = 0, 1
	right = 1, 2

2nd iteration: 
	mid = (1+2)/2 = 1
	left = 1, 1
	right = 1, 2

int arrSumRecursively2(vector<int> arr, int start, int end) {
	if(start > end) {
		return 0; 
	}
	if(start == end) {
		return arr[start];
	}
	int mid = (start + end)/2;
	int leftSum = arrSumRecursively2(arr, start, mid);
	int rightSum = arrSumRecursively2(arr, mid, end); 
	
	int sum = leftSum + rightSum + arr[mid]; //Do something with the result
	return sum; 

}


1. Not handled all the base Cases





vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> merged;
	int lena = left.size(); 
	int lenb = right.size(); 
	int i = 0, j = 0; 

	while(i<lena && j<lenb) {
		if(left[i]<=right[j]) {
			merged.push_back(left[i]); 
			i++; 
		}
		else {
			merged.push_back(right[j]); 
			j++; 
		}
	}

	while(i<lena) {
		merged.push_back(left[i]); 
		i++;
	}
	while(j<lenb) {
		merged.push_back(right[j]); 
		j++;
	}
	return merged; 
}



vector<int> mergeSort(vector<int> arr, int start, int end) {
	int lena = arr.size(); 
	//Base case
	if(end == start) {
		//Making a new array of size 1.
		vector<int> newarr(1);
		newarr[0] = arr[start];
		return newarr;
	} 
	int mid = (start + end)/2; 
	vector<int> left = mergeSort(arr, start, mid);
	vector<int> right = mergeSort(arr, mid+1, end); 
	//Do something with the results
	vector<int> merged = merge(left, right); 
	return merged; 
}




int ispow2(int num) {
	if(num == 1) return 1; 
	if(num%2 != 0) return 0; 
	//Iterative case & Do Something
	return ispow2(num/2); 
}




int minWays(int num) {
//Base Case:
	if(num == 0) return 0; 
	if(ispow2(num)) return 1; 
	//Iterative cases:
	int k = 0; 
	while(pow(2, k) < num) {
			k++;
	}
	// k = 4
	int rem1 = num - pow(2, k-1);
	int rem2 = pow(2,k) - num;
	//Result combination part - inside the min function 
	return (1 + min(minWays(rem1), minWays(rem2))); 
}


r = 0, c = 0
N = 5, M = 5

int maxSumPath(vector<vector<int> > & arr, int r, int c, int N, int M) {

	int sum = 0; 
	if(r == N-1 && c == M-1) return arr[r][c];
	if(r == N-1) {		
		for(c; c < M; c++) sum = sum + arr[r][c]; 
		return sum; 
	}
	if(c == M-1) {
		for(r; r < N; r++) sum = sum + arr[r][c]; 
		return sum; 
	}

	int rightSum = arr[r][c] + maxSumPath(arr, r, c+1, N, M); 
	int downSum = arr[r][c] + maxSumPath(arr, r+1, c, N, M); 
	
	return max(rightSum, downSum); 
}


[1, 2, 5]

14

1 + 13 -> 1 way 
+
2 + 12 -> 1 way 
+
5 + 9 -> 1 way 

	9 : using 5. WaysToMake 4
	  : without using 5


waysToMake(14) = waysToMake(14-S[0]) + waysToMake(14-S[1]) 
				+ waysToMake(14-S[2]) 


m = length of coins array

int count( int S[], int m, int n )
{
    // If n is 0 then there is 1 solution 
    // (do not include any coin)
    if (n == 0)
        return 1;
      
    // If n is less than 0 then no 
    // solution exists
    if (n < 0)
        return 0;
  
    // If there are no coins and n 
    // is greater than 0, then no
    // solution exist
    if (m <=0 && n >= 1)
        return 0;
  
    // count is sum of solutions (i) 
    // including S[m-1] (ii) excluding S[m-1]
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}


			14 
	14				9		Right: 5,2,2 | 5,1,1,2 | 5,1,1,1,1 | Left: 
14		12		9		4
					  4   (Right: 2,2 & 1,1,2 | Left: 1,1,1,1)
					4  	2	
					  2  0
					 1
					1
				   0	




























