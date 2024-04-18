// #include <iostream>
// #include <unordered_map>
// #include <list>
// #include <vector>
// using namespace std;



// // vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges){
// //     vector<int> ans[n];
// //     for(int i = 0; i < m ; i++){
// //         int u = edges[i][0];
// //         int v = edges[i][1];

// //         ans[u].push_back(v);
// //         ans[v].push_back(u);
// //     }

// //     vector<vector<int>> adj;
// //     for(int i = 0;i < n;i++){
// //         adj[i].push_back(i);
// //         for(int j = 0; j < ans[i].size(); j++){
// //             adj[i].push_back(ans[i][j]);
// //         }
// //     }
// //     return adj;
// // }



// template <typename T>
// class graph{
//     public:
//     unordered_map<T, list<T>> adj;

//     void addEdge(T u, T v, bool direction){
//         // direction = 0 -> undirected graph
//         // direction = 1 -> directed graph

//         // create an edge from u to v
//         adj[u].push_back(v);
//         if(direction == 0){
//             adj[v].push_back(u);
//         }
//     }

//     void printAdjList(){
//         for(auto i : adj){
//             cout << i.first << " -> ";
//             for(auto j : i.second){
//                 cout << j << ", ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main(){
//     int n;
//     cout << "Enter the number of nodes : " << endl;
//     cin >> n;

//     int m;
//     cout << "Enter the number of edges : " << endl;
//     cin >> m;
//     graph<int> g;
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         g.addEdge(u, v, 0);
//     }

//     g.printAdjList();
//     return 0;
// }



// #include <iostream>
// #include <unordered_map>
// #include <list>
// using namespace std;

// template <typename T>
// class graph{
//     public:
//     unordered_map<T, list<T>> adj;

//     void addEdge(T u, T v, bool direction){
//         // direction = 0(Undirected graph)
//         // direction = 1(Directed graph)
//         adj[u].push_back(v);
//         if(direction == 0){
//             adj[v].push_back(u);
//         }
//     }

//     void printAdjList(){
//         for(auto i : adj){
//             cout << i.first << " -> ";
//             for(auto j : i.second){
//                 cout << j << " ";
//             }
//             cout << endl;
//         }
//     }
// };


// int main(){
//     int n,m;
//     cout << "Please enter the number of nodes : " << endl;
//     cin >> n;

//     cout << "Please enter the number of edges : " << endl;
//     cin >> m;

//     graph<int> g;

//     for(int i = 0; i < m ; i++){
//         int u,v;
//         cin >> u >> v;
//         g.addEdge(u, v, 0);
//     }

//     g.printAdjList();
//     return 0;
// }




// BFS -> Breadth First Search (Traversal Technique)

// void prepareAdjList(unordered_map<int,list<int>> &adjList, vector<pair<int,int>> &edges){
//     for(int i = 0; i < edges.size(); i++){
//         int u = edges[i].first;
//         int v = edges[i].second;

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
// }

// void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &ans, int node){
//     queue<int> q;
//     q.push(node);
//     visited[node] = 1;

//     while(!q.empty()){
//         int frontNode = q.front();
//         q.pop();

//         // store frontnode into ans;
//         ans.push_back(frontNode);

//         // traverse all neighbourse of frontNode
//         for(auto i : adjList[frontNode]){
//             if(!visited[i]){
//                 q.push(i);
//                 visited[i] = 1;
//             }
//         }
//     }
// }

// vector<int> BFS(int vertex, vector<pair<int,int>>, edges){
//     unordered_map<int,list<int>> adjList;
//     vector<int> ans;
//     unordered_map<int,bool> visited;
//     prepareAdjList(adjList, edges);

//     // traverse all componenets of graph

//     for(int i = 0; i < vertex; i++){
//         if(!visited[i]){
//             bfs(adjList, visited, ans, i);
//         }
//     }
//     return ans;
// }
