#include <iostream>
#include <vector>
#include <queue> // BFS
#include <stack> // DFS

using namespace std;




int compare(const vector<vector<int>> &graph, int start, int end) {
    queue<int> q;
    q.push(start);
    int counter = 0;
    while(!q.empty()) {
        int node = q.front();
        //cout <<node << ": ";
        if(node == end) {break;}
        q.pop();
        for(int edge : graph[node]) {
            q.push(edge);
        }
        counter++;
     //cout << "node: "<< node <<" counter: " << counter << endl;
    }
    return counter;
}

int main()
{
    vector<vector<int>> graph({
       {1, 3},
       {0, 3},
       {0, 1},
       {0, 1, 2}
    });

    int result = compare(graph, 0, 2);
    cout << result << endl;

    return 0;
}
