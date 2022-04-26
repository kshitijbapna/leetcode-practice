class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& ps) {
        //In the Prim's algorithm, we are building a tree starting from some initial point. We track all connected points in visited. For the         //current point, we add its edges to the min heap. Then, we pick a smallest edge that connects to a point that is not visited. Repeat         //till all points are visited.
        int n = ps.size(), res = 0, i = 0, connected = 0;
        vector<bool> visited(n);
        priority_queue<pair<int, int>> pq;
        while (++connected < n) {
            visited[i] = true;
            for (int j = 0; j < n; ++j)
                if (!visited[j])
                    pq.push({-(abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1])), j});
            while (visited[pq.top().second])
                pq.pop();
            res -= pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return res;
    }
};