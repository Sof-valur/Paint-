#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Load_Image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp)"));
    QImage image;
    image.load(filename);
    image = image.scaledToWidth(ui->Image_lbl->width(),Qt::SmoothTransformation);
    ui->Image_lbl->setPixmap(QPixmap::fromImage(image));
}

