#include "mainwindow.h"
#include <QMouseEvent>
#include "ui_mainwindow.h"
#include <QMessageBox>

//start the main window

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Image_lbl->setMouseTracking(true);
    MainWindow::doDraw = false;
    MainWindow::doErrase = false;
    MainWindow::paintColor = Color(0,0,0);
    MainWindow::brush = 0;

}


MainWindow::~MainWindow()
{
    delete ui;
}

//Check the mouse position when clicked

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{

   qDebug()<<"drawing in"<<ev->pos().x()<<","<<ev->pos().y();
   if(MainWindow::doDraw || MainWindow::doErrase){
   if(ev->pos().x()<imageqt.width() && ev->pos().x()>0 && ev->pos().y()<imageqt.height() && ev->pos().y()>0){
       MainWindow::set_color(ev->pos().x(),ev->pos().y());
       ui->Image_lbl->setPixmap(QPixmap::fromImage(imageqt));
       QWidget::mouseMoveEvent(ev);
   }
   else{
       //error case
       QMessageBox warning;
       warning.setText("Fuera de margen");
       warning.exec();
   }
   }
}


//Loads the bitmap into the program

void MainWindow::on_Load_Image_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.bmp)"));

    imageqt.load(filename);

    MainWindow::piporin.Read(filename.toStdString().c_str());

    ui->Image_lbl->resize(MainWindow::piporin.width(),MainWindow::piporin.height());
    ui->Image_lbl->setPixmap(QPixmap::fromImage(imageqt));
}

//Saves the image in a directory

void MainWindow::on_Save_image_clicked()
{

    QFileDialog save_file;
    save_file.setOptions(QFileDialog::DontUseNativeDialog);
    save_file.setDefaultSuffix(".bmp");
    std::string filename = save_file.getSaveFileName(this,tr("save"),"",tr("Images(*.bmp)")).toStdString();
    qDebug()<<filename.c_str();
    MainWindow::piporin.Export(filename.c_str());
    if(!filename.empty()){
        QMessageBox warning;
        warning.setText("Imagen guardada");
        warning.exec();
    }else{
        //error case
        QMessageBox warning;
        warning.setText("No se pudo guardar la imagen");
        warning.exec();
    }

}

//Changes a pixel color

void MainWindow::set_color(int x, int y)
{
    for(int tempy =y;tempy<=y+MainWindow::brush;tempy++ ){
        for(int tempx =x;tempx<=x+MainWindow::brush;tempx++ ){

            imageqt.setPixelColor(tempx,tempy,QColor((int)255*MainWindow::paintColor.r,(int)255*MainWindow::paintColor.g,(int)255*MainWindow::paintColor.b));
            MainWindow::piporin.SetColor(Color(MainWindow::paintColor.r,MainWindow::paintColor.g,MainWindow::paintColor.b),tempx,tempy);
        }
    }

}


//Creates a new bitmap defined by the user

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

        ui->Image_lbl->resize(MainWindow::piporin.width(),MainWindow::piporin.height());
        ui->Image_lbl->setPixmap(QPixmap::fromImage(imageqt));
    }else{
        //error case
        QMessageBox warning;
        warning.setText("Elija la dimension deseada");
        warning.exec();
    }



}


void MainWindow::on_Color_bttn_clicked()
{
    QColorDialog color;
    QColor a = color.getColor();
    qDebug()<<a.redF()<<", "<<a.greenF()<<", "<<a.blueF();
    MainWindow::paintColor = Color(a.redF(),a.greenF(),a.blueF());
}





void MainWindow::on_Draw_clicked()
{
    if(MainWindow::doDraw){
        MainWindow::doDraw = false;
    }else{
        MainWindow::doDraw = true;
    }
}


void MainWindow::on_horizontalSlider_sliderReleased()
{
    MainWindow::brush = ui->horizontalSlider->value();
    ui->plainTextEdit->setPlainText(QString::fromStdString( std::to_string(MainWindow::brush)));
}

