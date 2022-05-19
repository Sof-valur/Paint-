#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "image.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Image piporin;


    void mouseMoveEvent(QMouseEvent *ev) override;
private slots:
    void on_Load_Image_clicked();

    void on_Save_image_clicked();

    void set_color(int x, int y);

    void on_New_Image_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
