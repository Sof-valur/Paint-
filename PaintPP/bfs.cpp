#include "bfs.h"
#include <iostream>



BFS::BFS()
{

}

Image BFS::flood_fill(Image toFill, positions firstPos, Color newColor)
{
    std::cout << "into flood"<<"\n";
    w = toFill.width();
    h = toFill.height();
    Color oldColor = toFill.GetColor(firstPos.x,firstPos.y);
    std::queue<positions> toVisit;
    std::vector<bool> visited = std::vector<bool>(w*h);

    for (int j=0;j<h-1;j++){

        for (int i=0;i<w-1;i++){

           visited[j*w+i] = false;

        }

    }
    toVisit.push(firstPos);
    //int z = 0;
    while(!toVisit.empty()){

        positions tempPos = toVisit.front();
        int x = tempPos.x;
        int y = tempPos.y;
        //std::cout<<visited.size()<<"  "<<visited[y*w+x]<<std::endl;
        Color temp = toFill.GetColor(x,y);
        //std::cout << "into loop: "<<x<<" "<<y<<std::endl;
        if(x<0 || x >= w || y<0 || y >= h || temp.r != oldColor.r || temp.g != oldColor.g || temp.b != oldColor.b){
            visited[y*w+x] = true;
            //z++;
            toVisit.pop();
        }
        else{
            //z++;
            toFill.SetColor(newColor,x,y);
            visited[y*w+x] = true;
            //toVisit.front();
            if(!(y-1<0) && !(y+1>=h)){
                if(!visited[(y+1)*w+x]){
                    toVisit.push(positions(x,y+1));
                }
                if(!visited[(y-1)*w+x]){
                    toVisit.push(positions(x,y-1));
                }
            }

            if(!(x-1<0)&&!(x+1>=w)){
                if(!visited[y*w+(x+1)]){
                    toVisit.push(positions(x+1,y));
                }
                if(!visited[y*w+(x-1)]){
                    toVisit.push(positions(x-1,y));
                }
            }

            toVisit.pop();
        }
    }
    //std::cout << "after while"<<std::endl;
    return toFill;

}

positions::positions(int x, int y)
    :x(x),y(y)
{

}
