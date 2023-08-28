int X[8] = {2,2,-2,-2,1,1,-1,-1};
int Y[8] = {1,-1,1,-1,2,-2,2,-2};


int minKnightMoves(int r,int c){
    set <pair <int,int>> vis;
    queue <pair <int,int>> Q;
    Q.push({0,0});
    int lev = 0;
    while(!Q.empty()){
        int sz = Q.size();
        while(sz--){
            auto [x,y] = Q.front();
            Q.pop();
            if(x==r && y==c) return lev;
            vis.insert({x,y});
            for(int i=0;i<8;i++){
                int nx = x+X[i];
                int ny = y+Y[i];
                if(vis.find({nx,ny})==vis.end()){
                    Q.push({nx,ny});
                }
            }
        }
        lev++;
    }
    return -1;
}

int main() {
    cout << minKnightMoves(2,1) << endl;
    cout << minKnightMoves(5,5) << endl;
    
}