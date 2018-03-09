#include "mainwindow.h"
#include "base/image.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    image img(500,500);
    for(int i=0;i<500;i++)
        for(int j=0;j<500;j++)
            img.drawPixel(i,j,RGB(0xf4,0x56,0xf1));
    QImage image(img.data.data(),img.width,img.height,QImage::Format_RGB888);
    w.drawImage(&image);
    return a.exec();
}
