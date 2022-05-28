#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include "image.h"
#include "bfs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Image bmpToWork;
    Image unedit;
    QImage imageqt;
    bool doDraw, doErrase, doFill, doLine;
    Color paintColor;
    int brush;

    positions startPos;

    void vertRot();
    void horRot();
    void rightRot();

    void goDelete(int x, int y);
    void goFill(int x, int y);
    void refreshDisplay();

    void grayScale();
    void negative();
    void psycho();
    void magmatic();

    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
private slots:
    void on_Load_Image_clicked();

    void on_Save_image_clicked();

    void set_color(int x, int y);

    void on_New_Image_clicked();

    void on_Color_bttn_clicked();

    void on_Draw_clicked();

    void on_horizontalSlider_sliderReleased();

    void on_Errase_clicked();

    void on_Fill_clicked();

    void on_VertFlip_clicked();

    void on_doFilter_clicked();

    void on_Line_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
