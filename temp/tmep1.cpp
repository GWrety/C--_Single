int n, m, s, t; // s是源点，t是汇点
bool vis[MAXN];
int dfs(int p = s, int flow = INF)
{
    if (p == t)
        return flow; // 到达终点，返回这条增广路的流量
    vis[p] = true;
    for (int eg = head[p]; eg; eg = edges[eg].next)
    {
        int to = edges[eg].to, vol = edges[eg].w, c;
        // 返回的条件是残余容量大于0、未访问过该点且接下来可以达到终点（递归地实现）
        // 传递下去的流量是边的容量与当前流量中的较小值
        if (vol > 0 && !vis[to] && (c = dfs(to, min(vol, flow))) != -1)
        {
            edges[eg].w -= c;
            edges[eg ^ 1].w += c;
            // 这是链式前向星取反向边的一种简易的方法
            // 建图时要把cnt置为1，且要保证反向边紧接着正向边建立
            return c;
        }
    }
    return -1; // 无法到达终点
}
inline int FF()
{
    int ans = 0, c;
    while ((c = dfs()) != -1)
    {
        memset(vis, 0, sizeof(vis));
        ans += c;
    }
    return ans;
}





