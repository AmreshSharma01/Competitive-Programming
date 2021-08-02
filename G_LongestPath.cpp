//link:https://www.geeksforgeeks.org/longest-path-in-a-directed-acyclic-graph-dynamic-programming/
#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define inf 1e9

//here: graph[i] represents the ith node and vector represents the neighbours of the ith node
// dp[i] is the length of longest path that start at node i
vector<int> graph[100005];
int dp[100005];

int solve(int src)
{
    if (dp[src] != -1)
    {
        return dp[src];
    }
    bool leaf = 1;
    int bestChild = 0;
    for (int child : graph[src])
    {
        leaf = 0;
        bestChild = max(bestChild, solve(child));
    }
    return dp[src] = leaf ? 0 : 1 + bestChild;
}
int main()
{
    int n, m;
    cin >> n >> m;
    // n is the no. of nodes
    // m is the no. of edges
    memset(dp, -1, sizeof dp);
    F(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int ans = 0;
    // Traverse and find the maximum of all dp[i]
    F(i, 1, n + 1)
    {
        ans = max(ans, solve(i));
    }
    cout << ans;

    return 0;
}

/*
// C++ program to find the longest
// path in the DAG

#include <bits/stdc++.h>
using namespace std;

// Function to traverse the DAG
// and apply Dynamic Programming
// to find the longest path
void dfs(int node, vector<int> adj[], int dp[], bool vis[])
{
	// Mark as visited
	vis[node] = true;

	// Traverse for all its children
	for (int i = 0; i < adj[node].size(); i++) {

		// If not visited
		if (!vis[adj[node][i]])
			dfs(adj[node][i], adj, dp, vis);

		// Store the max of the paths
		dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
	}
}

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

// Function that returns the longest path
int findLongestPath(vector<int> adj[], int n)
{
	// Dp array
	int dp[n + 1];
	memset(dp, 0, sizeof dp);

	// Visited array to know if the node
	// has been visited previously or not
	bool vis[n + 1];
	memset(vis, false, sizeof vis);

	// Call DFS for every unvisited vertex
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i, adj, dp, vis);
	}

	int ans = 0;

	// Traverse and find the maximum of all dp[i]
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	return ans;
}

// Driver Code
int main()
{
	int n = 5;
	vector<int> adj[n + 1];

	// Example-1
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 3, 2);
	addEdge(adj, 2, 4);
	addEdge(adj, 3, 4);

	cout << findLongestPath(adj, n);
	return 0;
}
*/