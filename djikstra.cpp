long long dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src, int dest) {
    
    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    vector<long long> dist(n, 1e18);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {

        auto [d, u] = pq.top();
        pq.pop();

        // Skip outdated entries
        if (d > dist[u]) continue;

        // Reached destination
        if (u == dest) {
            return dist[u];
        }

        for (auto [v, wt] : adj[u]) {

            if (dist[u] + wt < dist[v]) {

                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return -1; // destination unreachable
}
