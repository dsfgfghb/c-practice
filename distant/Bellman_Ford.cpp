#include <iostream>
#include <vector>
using namespace std;
#define BIG_NUM 1000000

struct Edge {
    int from, to, cost;
};

bool BellmanFord(const vector<Edge>& edges, int pointNum, int start, int* dis, int* pre) {

    fill(dis, dis + pointNum, INT_MAX);
    fill(pre, pre + pointNum, -1);
    dis[start] = 0;

    // 进行松弛操作
    for (int i = 0; i < pointNum - 1; ++i) {
        bool changed = false;
        for (const auto& edge : edges) {
            if (dis[edge.from] != INT_MAX && dis[edge.to] > dis[edge.from] + edge.cost) {
                dis[edge.to] = dis[edge.from] + edge.cost;
                pre[edge.to] = edge.from;
                changed = true;
            }
        }
        if (!changed) break; // 如果某一轮没有更新，提前退出
    }

    // 检测负权环
    for (const auto& edge : edges) {
        if (dis[edge.from] != INT_MAX && dis[edge.to] > dis[edge.from] + edge.cost) {
            return false; // 存在负权环
        }
    }

    return true; // 不存在负权环
}

int main() {
    int pointNum, edgeNum, start, end;
    cin >> pointNum >> edgeNum >> start >> end;

    vector<Edge> edges(edgeNum);
    for (int i = 0; i < edgeNum; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }

    vector<int> dis(pointNum, INT_MAX);
    vector<int> pre(pointNum, -1);

    if (BellmanFord(edges, pointNum, start, dis.data(), pre.data())) {
        cout << "Shortest distance: " << dis[end] << endl;
    } else {
        cout << "Negative cycle detected!" << endl;
    }
  
    return 0;
}
