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
    bool doDraw, doErrase, doFill;
    Color paintColor;
    int brush;

    void Vert_Rot();
    void Hort_Rot();

    void goFill(int x, int y);
    void refreshDisplay();

    void mouseMoveEvent(QMouseEvent *ev) override;
private slots:
    void on_Load_Image_clicked();

    void on_Save_image_clicked();

    void set_color(int x, int y);

    void on_New_Image_clicked();

    void on_Color_bttn_clicked();

    void on_Draw_clicked();

    void on_horizontalSlider_sliderReleased();


    void on_Errase_clicked();

    void on_pushButton_clicked();

    void on_Fill_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
