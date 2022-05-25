#ifndef BFS_H
#define BFS_H
#include "image.h"
#include <queue>

struct positions{
    int x,y;

    positions(int x, int y);
};

class BFS
{
public:
    BFS();
    int w,h;
    Image flood_fill(Image toFill,positions firstPos,Color newColor);
};

#endif // BFS_H