// *****************************************************************************
//  File       [mps.h]
//  Author     [HsuanYu CHOU]
//  Synopsis   [The header file of the MPS class]
//  Modify     [2021-11-20 HsuanYu CHOU]
// *****************************************************************************

#ifndef __MPS_H__
#define __MPS_H__

using namespace std;

class MPS
{
public:
    MPS();

    int Core();
    int N2;
    int *set;
    vector<int> subset;

private:
    int GetM(int, int);
    void GoBackTo(int, int);
    int **M;
    char **mark;
};

#endif
