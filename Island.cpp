


int MaxIsland(int** mtx, int size) {
	bool** visited = new bool*[size];
	for (int i = 0; i < size; ++i) {
		visited[i] = new bool[size];
		for (int j = 0; j < size; ++j)
			visited[i][j] = false;
	}
	
	int max_island = 0;
	for (int r = 0; r < size; ++r) {
		for (int c = 0; c < size; ++c) {
			if (visited[r][c])
				continue;
			visited[r][c] = true;
			if (mtx[r][c] == 1) {
				int island_size = FindAllFrom(mtx, r, c, visited, size);
				if (island_size > max_island)
					max_island = island_size;
			}
		}
	}
	for (int i = 0; i < size; ++i)
		delete[] visited[i];
	delete[] visited;
	
	return max_island;
}				
	
int FindAllFrom(int** mtx, int r, int c, bool** visited, int size) {
	// We assume mtx[r][c] == 1
	int ret = 1;
	if (!visited[r][c + 1]) {
		visited[r][c + 1] = true;
		if (mtx[r][c + 1] == 1)
			ret += FindAllFrom(mtx, r, c + 1, visited, size);
	}
	if (!visited[r][c - 1]) {
		visited[r][c - 1] = true;
		if (mtx[r][c - 1] == 1)
			ret += FindAllFrom(mtx, r, c - 1, visited, size);
	}
	if (!visited[r + 1][c]) {
		visited[r + 1][c] = true;
		if  (mtx[r + 1][c] == 1)
			ret += FindAllFrom(mtx, r + 1, c, visited, size);
	}
	if (!visited[r - 1][c]) {
		visited[r - 1][c] = true;
		if (mtx[r - 1][c] == 1)
			ret += FindAllFrom(mtx, r - 1, c, visited, size);
	}
	return ret;
}
	
