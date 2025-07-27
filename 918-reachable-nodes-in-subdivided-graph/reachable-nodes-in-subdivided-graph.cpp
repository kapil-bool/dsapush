class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        //so here each node atmost can have maxMOves 
        //increase the cnt when only u reach a new station 
        //oh reachable from just node 0 so this is easy 
        //so its just bascic level question can be done with bfs
          vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            adj[u].push_back({v, cnt});
            adj[v].push_back({u, cnt});
        }

        // Use max heap: {remaining moves, node}
        priority_queue<pair<int, int>> pq;
        pq.push({maxMoves, 0});
        vector<int> seen(n, -1);
            // vector<int> seen(n, -1);
        //if i see it already visited ignore it and continue the serch
        while(!pq.empty()){
            // moves ,node higher moves first
            int c_moves=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(seen[node]!=-1) continue; //already considered //also if u think this mean the further possiblites have alro been explored in gerneral
            seen[node]=c_moves;
            for(auto neigh: adj[node]){
                //next, count;
                int node_next=neigh.first;
                int moves=neigh.second;
                //considered only if the c_moves +1 <=moves
                if(c_moves>=moves+1 and  seen[node_next]==-1){
                    //reduce the moves here and push into the queue
                    pq.push({c_moves -(moves+1),node_next});
                } 
            }
        }
        int count=0; //here diviion one are also there so that will be a twist

        for(int i=0;i<n;i++){
             if(seen[i]!=-1) count++;
        }
        //now also the divivded one can only be done if 
        //seen se he nikalunga no other way possible i guess
            for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = seen[u] != -1 ? seen[u] : 0;
            int b = seen[v] != -1 ? seen[v] : 0;
            count += min(cnt, a + b);
            //so here insted of counting normally here we are doing it like count the next moves from the both vertex if its less then its the ans if more than the answer is all 
        }

        return count;
    }
};