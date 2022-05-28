#ifndef BFS_H
#define BFS_H
#include "image.h"
#include <queue>

struct positions{
    int x,y, cost, from;


    positions(int x, int y);
    positions();
};

class BFS
{
public:
    BFS();
    int w,h;
    Image flood_fill(Image toFill,positions firstPos,Color newColor);
    Image bfs_delete(Image toDelete, Image unedit, positions start);
    Image straightLine(Image toFill,positions firstPos,positions lastPos,Color newColor);
};

#endif // BFS_H
