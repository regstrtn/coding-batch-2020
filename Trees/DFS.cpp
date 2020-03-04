int count; //global variable

# initialize all pre with -1
# initialize all post with -1
1. visited (all 0)
2. parent (all -1)
3. pre (all -1)
4. post (all -1)


class graph{
public:
	int n; 
	vector<vector<int> > adj;
	graph(int n) {
		this->n = n; 
		adj.resize(n); 
	}
}

bool hasCycle(vector<int> & visited, int i, 
	vector<int> & parent, 
	vector<int> & pre, 
	vector<int> & post) {


	
	if(visited[i]) return; 
	visited[i] = 1;
	int j = 0; 

	pre[i] = count; count++; 

	for(j=0;j<adj[i].size();j++) {
		int k = adj[i][j]; 
		if(!visited[k])
			parent[k] = i; 

		//Check for cycle
		if(pre[k] < pre[i] && post[k] == -1 && k != parent[i])
			return true; 

		bool flag = hasCycle(visited, k, parent, pre, post); 
		if(!flag) continue;
		else return true; 
	}

	post[i] = count; count++; 
	return false; 
}



//WATCH THOSE LECTURES

//TOPOLOGICAL SORT
