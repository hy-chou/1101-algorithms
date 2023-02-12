#ifndef __CB_H__
#define __CB_H__

class CB
{
public:
    int n;
    int m;

    int Prim(int **, int);
    int dPrim(int **, int);

private:
    bool *isPicked;
    int totalPicked;
    int *parent;

    int getHead(int);
};

#endif
