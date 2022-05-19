#include "mainwindow.h"
#include <QMouseEvent>
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setMouseTracking(false);
    ui->Image_lbl->setMouseTracking(true);
    ui->verticalFrame_2->setStyleSheet("background-color: rgb(255,255,255");

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
   qDebug()<<ev->pos().x()<<","<<ev->pos().y();


   qDebug()<<"drawing in"<<ev->pos().x()<<","<<ev->pos().y();
   if(ev->pos().x()<imageqt.width() && ev->pos().x()>0 && ev->pos().y()<imageqt.height() && ev->pos().y()>0){
       MainWindow::set_color(ev->pos().x(),ev->pos().y());
       imageqt.setPixelColor(ev->pos().x(),ev->pos().y(),QColor(0,0,0));
       QWidget::mouseMoveEvent(ev);
   }
   else{
       QMessageBox warning;
       warning.setText("Fuera de margen");
       warning.exec();
   }
}


void MainWindow::on_Load_Image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp)"));

    imageqt.load(filename);

    MainWindow::piporin.Read(filename.toStdString().c_str());
    //image = image.scaledToWidth(ui->Image_lbl->width(),Qt::SmoothTransformation);
    ui->Image_lbl->resize(MainWindow::piporin.width(),MainWindow::piporin.height());
    ui->Image_lbl->setPixmap(QPixmap::fromImage(imageqt));
}


void MainWindow::on_Save_image_clicked()
{
    //MainWindow::piporin.SetColor(Color(0,0,0),300,300);
    QFileDialog save_file;
    save_file.setDefaultSuffix(".bmp");
    std::string filename = save_file.getSaveFileName().toStdString();
    qDebug()<<filename.c_str();
    MainWindow::piporin.Export(filename.c_str());
    QMessageBox warning;
    warning.setText("Imagen guardada");
    warning.exec();
}

void MainWindow::set_color(int x, int y)
{
    MainWindow::piporin.SetColor(Color(0,0,0),x,y);
}


void MainWindow::on_New_Image_clicked()
{
    if(!ui->Width_num->toPlainText().isEmpty() && !ui->Height_num->toPlainText().isEmpty()){
        std::string width = ui->Width_num->toPlainText().toStdString();
        std::string height= ui->Height_num->toPlainText().toStdString();
        qDebug()<<width.c_str()<<" "<<height.c_str();
        MainWindow::piporin = Image(std::stoi(width),std::stoi(height));
        for(int y=0;y<std::stoi(height);y++){
            for(int x=0;x<std::stoi(width);x++){
                MainWindow::piporin.SetColor(Color(1.0,1.0,1.0),x,y);
            }
        }


        MainWindow::piporin.Export("new_piporin.bmp");

        imageqt.load("new_piporin.bmp");

        MainWindow::piporin.Read("new_piporin.bmp");
        //image = image.scaledToWidth(ui->Image_lbl->width(),Qt::SmoothTransformation);
        //ui->Image_lbl->resize(MainWindow::piporin.width(),MainWindow::piporin.height());
        ui->Image_lbl->setPixmap(QPixmap::fromImage(imageqt));
    }else{

        QMessageBox warning;
        warning.setText("Elija la dimension deseada");
        warning.exec();
    }



}

