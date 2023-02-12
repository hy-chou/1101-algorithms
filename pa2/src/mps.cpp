// *****************************************************************************
//  File       [mps.cpp]
//  Author     [HsuanYu CHOU]
//  Synopsis   [The implementation of the MPS class]
//  Modify     [2021-11-20 HsuanYu CHOU]
// *****************************************************************************

#include <vector>
#include "mps.h"

using namespace std;

MPS::MPS() {}

void MPS::GoBackTo(int i, int j)
{
  int k = set[j];
  int x = mark[i][j];

  if (x == '1')
    GoBackTo(i, j - 1);
  else if (x == '3')
  {
    GoBackTo(i, k - 1);
    GoBackTo(k + 1, j - 1);

    subset.push_back(j);
    subset.push_back(k);
  }
  else if (x == '2')
  {
    GoBackTo(i + 1, j - 1);

    subset.push_back(j);
    subset.push_back(k);
  }
}

int MPS::GetM(int i, int j)
{
  if (i < 0 || N2 <= i || j < 0 || N2 <= j || i == j)
    return (0);
  if (M[i][j])
    return (M[i][j]);

  int k = set[j];

  if (k < i || j < k)
  {
    M[i][j] = GetM(i, j - 1);
    mark[i][j] = '1';
  }
  else if (i < k && k <= j)
  {
    int a = GetM(i, j - 1);
    int b = GetM(i, k - 1) + 1 + GetM(k + 1, j - 1);

    M[i][j] = (a > b) ? a : b;
    mark[i][j] = (a > b) ? '1' : '3';
  }
  else
  {
    M[i][j] = GetM(i + 1, j - 1) + 1;
    mark[i][j] = '2';
  }
  return (M[i][j]);
}

int MPS::Core()
{
  M = new int *[N2];
  mark = new char *[N2];
  for (int i = 0; i < N2; ++i)
  {
    M[i] = new int[N2];
    mark[i] = new char[N2];
    for (int j = 0; j < N2; ++j)
    {
      M[i][j] = 0;
      mark[i][j] = 0;
    }
  }

  int max = GetM(0, N2 - 1);

  GoBackTo(0, N2 - 1);

  for (int i = 0; i < N2; ++i)
  {
    delete[] mark[i];
    delete[] M[i];
  }
  delete[] mark;
  delete[] M;

  return (max);
}
