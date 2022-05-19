#include "mainwindow.h"
#include <QMouseEvent>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Image_lbl->setMouseTracking(true);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
   qDebug()<<ev->position().x()<<","<<ev->position().y();
   MainWindow::set_color(ev->position().x(),ev->position().y());
   QWidget::mouseMoveEvent(ev);
}


void MainWindow::on_Load_Image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp)"));
    QImage image;
    image.load(filename);

    MainWindow::piporin.Read(filename.toStdString().c_str());
    //image = image.scaledToWidth(ui->Image_lbl->width(),Qt::SmoothTransformation);
    ui->Image_lbl->resize(MainWindow::piporin.width(),MainWindow::piporin.height());
    ui->Image_lbl->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_Save_image_clicked()
{
    MainWindow::piporin.SetColor(Color(0,0,0),300,300);
    MainWindow::piporin.Export("piporin.bmp");
}

void MainWindow::set_color(int x, int y)
{
    MainWindow::piporin.SetColor(Color(0,0,0),x,y);
}


void MainWindow::on_New_Image_clicked()
{
    std::string width = ui->Width_num->toPlainText().toStdString();
    std::string height= ui->Height_num->toPlainText().toStdString();

    MainWindow::piporin = Image(std::stoi(width),std::stoi(height));
    MainWindow::piporin.Export("new_piporin.bmp");

}

