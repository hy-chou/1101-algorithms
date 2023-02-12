#include <iostream>
#include <fstream>
#include "cb.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "usage: cb <input_file> <output_file>" << endl;
        return 1;
    }

    // INPUT //
    CB tool;
    int **w;
    int totalW = 0;
    char eType;
    fstream fin(argv[1], ios::in);

    fin >> eType;
    fin >> tool.n;
    fin >> tool.m;
    w = new int *[tool.n];
    for (int i = 0; i < tool.n; ++i)
    {
        w[i] = new int[tool.n];
        for (int j = 0; j < tool.n; ++j)
            w[i][j] = 404;
    }
    for (int i = 0; i < tool.m; ++i)
    {
        int a, b, c;

        fin >> a >> b >> c;
        w[a][b] = c;
        if (eType == 'u')
            w[b][a] = c;
        totalW += c;
    }
    fin.close();

    // CORE //
    if (eType == 'u')
        totalW = tool.Prim(w, totalW);
    else if (eType == 'd')
        totalW = tool.dPrim(w, totalW);

    // OUTPUT //
    fstream fout;
    fout.open(argv[2], ios::out);
    fout << totalW << endl;
    for (int i = 0; i < tool.n; ++i)
    {
        for (int j = (eType == 'u' ? i + 1 : 0); j < tool.n; ++j)
        {
            if (w[i][j] != 404)
                fout << i << ' ' << j << ' ' << w[i][j] << endl;
        }
    }
    fout.close();

    for (int i = 0; i < tool.n; ++i)
        delete[] w[i];
    delete[] w;

    return 0;
}
