// *****************************************************************************
//  File       [main.cpp]
//  Author     [HsuanYu CHOU]
//  Synopsis   [The main program to solve the Maximum Planar Subset problem]
//  Modify     [2021-11-20 HsuanYu CHOU]
// *****************************************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include "mps.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "usage: mps <input_file> <output_file>" << endl;
        return 1;
    }

    // INPUT //
    MPS tool;
    fstream fin(argv[1]);

    fin >> tool.N2;
    tool.set = new int[tool.N2];
    for (int i = 0; i < tool.N2 / 2; ++i)
    {
        int a, b;

        fin >> a >> b;
        tool.set[a] = b;
        tool.set[b] = a;
    }
    fin.close();

    // CORE //
    int max = tool.Core();

    delete[] tool.set;

    // OUTPUT //
    fstream fout;
    fout.open(argv[2], ios::out);
    fout << max << endl;
    for (unsigned long i = 0; i < tool.subset.size(); i += 2)
        fout << tool.subset.at(i) << ' ' << tool.subset.at(i + 1) << endl;
    fout.close();

    return 0;
}
