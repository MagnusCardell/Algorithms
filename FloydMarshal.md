Given a directed graph. Find the length of every shortest path between every single pair of nodes


For i=1 ro n:
    For j=1 to n:
        dist(i,j,0) = inf
For all (i,j) in E:
    dist(i,j,0) = L(i,j)
For k=1 to n:
    For i=1 ro n:
        For j=1 to n:
            dist(i,j,k) = min{ dist(i,j,k-1) + dist(k,j,k-1) , dist(i,j,k-1)}


Source code:
youtube.com/watch?v=4OQeCuLYj-4

int main(){
    vector<vector<int>> graph;
    for(int i=0; i<num_nodes; ++i){
        vector<int>tmp;
        graph.push_back(tmp);
    }
    for(int i=0; i<num_nodes; ++i){
        
    })
}