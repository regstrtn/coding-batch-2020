class minheap {
	vector<int> arr; //Depending on the question
	int h;
	int size;  
	heap(vector<int> & v) {
		int len = v.size(); 
		arr.resize(len+1); 
		h = len; //Index where insertion will happen
		size = 0;  
	}

	void siftUp(int k) {
		int parentK = k/2; 
		while(k > 1 && arr[k]>arr[k/2]) {
			swap(arr[k], arr[k/2]); 
			k = k/2;
		}
	}

	void siftDown(int k) {
		if(k > h/2) return; //k is already in last row
		int smallest = k; 
		int left = 2*k; 
		int right = 2*k+1; 
		if(left < h && arr[left] < arr[smallest]) 
			smallest = left; 
		if(right < h && arr[right] < arr[smallest] ) 
			smallest = right; 

		swap(arr[k], arr[smallest]);
		siftDown(smallest); 
	}

	int popMin() {
		if(h<=1) return -1; //Heap empty
		int minVal = arr[0]; 
		swap(arr[h-1], arr[0]); 
		siftDown(0);
		return minVal; 
	}

	void insertElement(int val) {
		arr[h++] = val; 
		siftUp(h-1); 
	}

	//3 operations: 
	//1. popMin()
	//2. insertElement()
}