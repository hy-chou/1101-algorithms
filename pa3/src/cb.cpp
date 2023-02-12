#include "cb.h"

int CB::Prim(int **w, int totalW)
{
    isPicked = new bool[n];
    for (int i = 0; i < n; ++i)
        isPicked[i] = false;

    isPicked[0] = true;
    totalPicked = 0;
    while (totalPicked != n - 1)
    {
        int w_max = -404;
        int u_max = -1;
        int v_max = -1;

        for (int u = 0; u < n; ++u)
        {
            if (!isPicked[u])
                continue;
            for (int v = 0; v < n; ++v)
            {
                if (w[u][v] == 404 || w[u][v] <= w_max || isPicked[v])
                    continue;
                w_max = w[u][v];
                u_max = u;
                v_max = v;
            }
        }
        isPicked[v_max] = true;
        totalPicked += 1;
        totalW -= w_max;
        w[u_max][v_max] = 404;
        w[v_max][u_max] = 404;
    }

    delete[] isPicked;

    return totalW;
}

int CB::dPrim(int **w, int totalW)
{
    isPicked = new bool[n];
    parent = new int[n];
    for (int i = 0; i < n; ++i)
    {
        isPicked[i] = false;
        parent[i] = i;
    }

    while (true)
    {
        int w_max = -404;
        int u_max = -1;
        int v_max = -1;

        for (int u = n - 1; u >= 0; --u)
        {
            for (int v = 0; v < n; ++v)
            {
                if (w[u][v] == 404 || w[u][v] <= w_max || getHead(u) == getHead(v))
                    continue;
                w_max = w[u][v];
                u_max = u;
                v_max = v;
            }
        }

        if (w_max == -404)
            break;

        isPicked[u_max] = true;
        isPicked[v_max] = true;
        parent[v_max] = getHead(u_max);
        totalW -= w_max;
        w[u_max][v_max] = 404;
    }

    delete[] parent;
    delete[] isPicked;

    return totalW;
}

int CB::getHead(int v)
{
    while (parent[v] != v)
        v = parent[v];
    return (v);
}
