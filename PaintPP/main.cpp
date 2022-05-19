#include "mainwindow.h"
#include "image.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    const int width = 640;
    const int height = 480;

    Image piporin(width,height);

    for(int y = 0; y<height;y++){

        for(int x = 0; x<width;x++){

             piporin.SetColor(Color((float)x/(float)width,1.0f-((float)x/(float)width),(float)y/(float)height),x,y);

        }
    }
    piporin.Export("image1.bmp");

    //Image copy(0,0);

    //copy.Read("image1.bmp");
    //copy.Export("copy.bmp");



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
