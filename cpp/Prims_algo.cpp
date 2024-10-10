#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];

int prim(int source, int n)
{
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    vector<int> visitOrder;

    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        st.erase(st.begin());

        if (vis[v]) continue;
        vis[v] = 1;
        visitOrder.push_back(v);

        for (auto child : g[v])
        {
            int child_v = child.first;
            int weight = child.second;

            if (!vis[child_v] && weight < dist[child_v])
            {
                dist[child_v] = weight;
                st.insert({dist[child_v], child_v});
            }
        }
    }

    cout << "Order of nodes visited in MST: ";
    for (int v : visitOrder)
    {
        cout << v << " ";
    }
    cout << endl;

    int mst_weight = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF)
        {
            mst_weight += dist[i];
        }
    }
    return mst_weight;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes (n) and the number of edges (m): ";
    cin >> n >> m;
    cout << "Now enter " << m << " edges in the format: node1 node2 weight" << endl;
    
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }
    
    cout << "The weight of the Minimum Spanning Tree is: " << prim(1, n) << endl;
}
