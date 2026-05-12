#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        
        //travel cost +tax cost so 2 will be there ;
        //for each node that to;

        struct edge{
            int to;
            ll cost1;
            ll cost2;
        };

        vector<vector<edge>> adj(n);
        vector<int> ans(n);

        for(auto &i : roads){

            int u = i[0];
            int v = i[1];
            ll cost = i[2];
            ll tax = i[3];

            adj[u].push_back({v, cost, cost * tax});
            adj[v].push_back({u, cost, cost * tax});
        }

        //use 2 dijakstra and store the answer;
        //dikstara 1;

        for(int i = 0; i < n; i++){

            //to reach each node that is 
            vector<ll> distance(n, 1e18);

            //diatance and vertex kind here 
             priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> pq;
            distance[i] = 0;
            pq.push({0, i});
            while(!pq.empty()){
                auto [d, u] = pq.top();
                pq.pop();
                if(distance[u] < d) continue;
                //edges explore 
                for(auto &e : adj[u]){

                    int to = e.to;
                    ll c = e.cost1;

                    if(distance[to] > d + c){

                        //update this one ;
                        //edge relaxation;

                        distance[to] = d + c;
                        pq.push({distance[to], to});
                    }
                }
            }

            vector<ll> distance2(n, 1e18);
            priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> pq_2;
            distance2[i] = 0;
            pq_2.push({0, i});
            //brute force 
            while(!pq_2.empty()){
                auto [d, u] = pq_2.top();
                pq_2.pop();

                if(d > distance2[u]) continue;

                for(auto &e : adj[u]){

                    int to = e.to;
                    ll t = e.cost2;

                    if(distance2[to] > d + t){

                        distance2[to] = d + t;
                        pq_2.push({distance2[to], to});
                    }
                }
            }
            ll mini = 1e18;
            for(int j = 0; j < n; j++){

                if(distance[j] != 1e18 and distance2[j] != 1e18){

                    mini = min(
                        mini,
                        distance[j] + distance2[j] + prices[j]
                    );
                }
            }

            ans[i] = (int)mini;
        }

        return ans;
    }
};