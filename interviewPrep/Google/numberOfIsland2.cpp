// https://www.codingninjas.com/studio/problems/number-of-islands-ii_1266048
class DisjointSet{
	private: 
		int N;
		vector <int> parent;
		vector <int> size;
	public:
		DisjointSet(int n){
			N = n;
			for(int i=0;i<n;i++){
				parent.push_back(i);
				size.push_back(1);
			}
		}

		int findParent(int ind){
			if(parent[ind]==ind) return ind;
			return parent[ind] = findParent(parent[ind]);
		}

		void findUnion(int u,int v){
			int pu = findParent(u);
			int pv = findParent(v);
			if(pu==pv) return;
			int su = size[pu];
			int sv = size[pv];
			if(su>sv){
				parent[pv] = pu;
				size[su]+=sv;
			}else{
				parent[pu] = pv;
				size[sv]+=su;
			}
		}
};

int X[4] = {1,-1,0,0};
int Y[4] = {0,0,-1,1};

bool isValid(int x,int y,int n,int m){
	return x>=0 && x<n && y>=0 && y<m;
}
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	DisjointSet ds(n*m);
	vector <vector <int>> mat(n,vector <int> (m,0));
	vector <int> ans;
	int count = 0;
	for(auto i:q){
		int x = i[0];
		int y = i[1];
		if(mat[x][y]){
			ans.push_back(count);
			continue;
		}
		mat[x][y] = 1;
		count++;
		for(int j=0;j<4;j++){
			int nx = x+X[j], ny = y+Y[j];
			if(isValid(nx,ny,n,m) && mat[nx][ny]){
				int ind1 = x*m+y, ind2 = nx*m+ny;
				if(ds.findParent(ind1)!=ds.findParent(ind2)){
					ds.findUnion(ind1,ind2);
					count--;
				}
			}	
		}
		ans.push_back(count);
	}
	return ans;
	// Write your code here.
}