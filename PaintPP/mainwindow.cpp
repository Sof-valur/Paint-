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
    doDraw = false;
    doErrase = false;
    doFill =false;
    doLine = false;

    MainWindow::paintColor = Color(0,0,0);
    MainWindow::brush = 0;
    ui->plainTextEdit->setPlainText(0);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vertRot()
{


    Image temp =Image(MainWindow::bmpToWork.width(),MainWindow::bmpToWork.height());
    int i = 0;
    for(int y =MainWindow::bmpToWork.height()-1;y>=0;y-- ){
        for(int x =0;x<MainWindow::bmpToWork.width()-1;x++ ){

            temp.SetColor(MainWindow::bmpToWork.GetColor(x,i),x,y);

        }
        i++;
    }


    MainWindow::bmpToWork = temp;
    MainWindow::unedit = temp;
    MainWindow::refreshDisplay();
}

void MainWindow::horRot()
{
    Image temp =Image(MainWindow::bmpToWork.width(),MainWindow::bmpToWork.height());
    int i = 0;
    for(int x =MainWindow::bmpToWork.width()-1;x>=0;x-- ){
        for(int y =0;y<MainWindow::bmpToWork.height()-1;y++ ){

            temp.SetColor(MainWindow::bmpToWork.GetColor(i,y),x,y);

        }
        i++;
    }


    MainWindow::bmpToWork = temp;
    MainWindow::unedit = temp;
    MainWindow::refreshDisplay();

}

void MainWindow::rightRot()
{
    Image temp =Image(MainWindow::bmpToWork.height(),MainWindow::bmpToWork.width());
    int i = 0;
    int j = 0;
    for(int x =0;x<MainWindow::bmpToWork.height()-1;x++ ){
        for( int y =MainWindow::bmpToWork.width()-1;y>=0;y--){

            temp.SetColor(MainWindow::bmpToWork.GetColor(i,j),x,y);
            i++;
        }
        i=0;
        j++;
    }

    MainWindow::bmpToWork = temp;
    MainWindow::unedit = temp;
    MainWindow::refreshDisplay();

}

void MainWindow::goDelete(int x, int y)
{
    BFS bfsOBJ;

    MainWindow::bmpToWork = bfsOBJ.bfs_delete(MainWindow::bmpToWork,MainWindow::unedit,positions(x,y));
    MainWindow::unedit = MainWindow::bmpToWork;
    MainWindow::refreshDisplay();
    doFill = false;
    ui->Fill->setCheckState(Qt::Unchecked);
}

void MainWindow::goFill(int x, int y)
{
    BFS bfsOBJ;

    MainWindow::bmpToWork = bfsOBJ.flood_fill(MainWindow::bmpToWork,positions(x,y),MainWindow::paintColor);
    MainWindow::unedit = MainWindow::bmpToWork;
    MainWindow::refreshDisplay();
    doFill = false;
    ui->Fill->setCheckState(Qt::Unchecked);

}

void MainWindow::refreshDisplay()
{
    Image temp =Image(MainWindow::bmpToWork.width(),MainWindow::bmpToWork.height());
    int i = 0;
    for(int y =MainWindow::bmpToWork.height()-1;y>=0;y-- ){
        for(int x =0;x<MainWindow::bmpToWork.width()-1;x++ ){

            temp.SetColor(MainWindow::bmpToWork.GetColor(x,i),x,y);

        }
        i++;
    }

    temp.Export("temp.bmp");

    imageqt.load("temp.bmp");
    ui->Image_lbl->resize(MainWindow::bmpToWork.width(),MainWindow::bmpToWork.height());
    ui->Image_lbl->setPixmap(QPixmap::fromImage(imageqt));
}

void MainWindow::grayScale()
{

    Image temp = Image(MainWindow::bmpToWork.width(),MainWindow::bmpToWork.height());
    for(int y = 0;y<MainWindow::bmpToWork.height()-1;y++){
        for(int x = 0;x<=MainWindow::bmpToWork.width()-1;x++){
            Color tempCol = MainWindow::bmpToWork.GetColor(x,y);
            temp.SetColor(Color((tempCol.r*0.3+tempCol.g*0.59+tempCol.b*0.11),(tempCol.r*0.3+tempCol.g*0.59+tempCol.b*0.11),(tempCol.r*0.3+tempCol.g*0.59+tempCol.b*0.11)),x,y);
        }
    }
    MainWindow::bmpToWork = temp;
    refreshDisplay();
}

void MainWindow::negative()
{

    Image temp = Image(MainWindow::bmpToWork.width(),MainWindow::bmpToWork.height());
    for(int y = 0;y<MainWindow::bmpToWork.height()-1;y++){
        for(int x = 0;x<=MainWindow::bmpToWork.width()-1;x++){
            Color tempCol = MainWindow::bmpToWork.GetColor(x,y);
            temp.SetColor(Color((1-tempCol.r),(1-tempCol.g),(1-tempCol.b)),x,y);
        }
    }
    MainWindow::bmpToWork = temp;
    refreshDisplay();
}

void MainWindow::psycho()
{
    Image temp = Image(MainWindow::bmpToWork.width(),MainWindow::bmpToWork.height());
        for(int y = 0;y<MainWindow::bmpToWork.height()-1;y++){
            for(int x = 0;x<=MainWindow::bmpToWork.width()-1;x++){
                Color tempCol = MainWindow::bmpToWork.GetColor(x,y);
                temp.SetColor(Color((tempCol.r/0.3),(tempCol.g/0.59),(tempCol.b/0.11)),x,y);
            }
        }
        MainWindow::bmpToWork = temp;
        refreshDisplay();
}

void MainWindow::magmatic()
{

    Image temp = Image(MainWindow::bmpToWork.width(),MainWindow::bmpToWork.height());

    for(int y = 0;y<MainWindow::bmpToWork.height()-1;y++){
        for(int x = 0;x<=MainWindow::bmpToWork.width()-1;x++){
            Color tempCol = MainWindow::bmpToWork.GetColor(x,y);
            int tempR = ((tempCol.r*10)*0.393+(tempCol.g*10)*0.769+(tempCol.b*10)*0.189);
            int tempG = ((tempCol.r*10)*0.349+(tempCol.g*10)*0.686+(tempCol.b*10)*0.168);
            int tempB = ((tempCol.r*10)*0.272+(tempCol.g*10)*0.534+(tempCol.b*10)*0.131);
            temp.SetColor(Color((tempR/10),(tempG/10),(tempB/10)),x,y);
        }
    }
    MainWindow::bmpToWork = temp;
    refreshDisplay();
}

//Check the mouse position when clicked

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{

   //qDebug()<<"drawing in"<<ev->pos().x()<<","<<ev->pos().y();

   if(doDraw ||  doErrase){
   if(ev->pos().x()<bmpToWork.width() && ev->pos().x()>0 && ev->pos().y()<bmpToWork.height() && ev->pos().y()>0){
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

// Checks if the mouse is clicked

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(!bmpToWork.empty()){
        startPos = positions(ev->pos().x(),ev->pos().y());

        Color tempWork =bmpToWork.GetColor(ev->pos().x(),ev->pos().y()) ;
        Color tempUnedit =unedit.GetColor(ev->pos().x(),ev->pos().y()) ;
        if(doErrase&&doFill){
            if(tempWork.r!=tempUnedit.r || tempWork.g !=tempUnedit.g || tempWork.b!=tempUnedit.b){
            goDelete(ev->pos().x(),ev->pos().y());
            }
        }
        if(doFill){
             MainWindow::goFill(ev->pos().x(),ev->pos().y());
        }
    }
    }


void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    if(doLine){
        if(ev->pos().x() == startPos.x){

            for(int x = startPos.x;x<ev->pos().x();x++){
                set_color(x,ev->pos().y());
            }

        }if(ev->pos().y() == startPos.y){
            for(int y = startPos.y;y<ev->pos().y();y++){
                set_color(ev->pos().x(),y);
            }
        }
        ui->Fill->setCheckState(Qt::Unchecked);
    }

}


//Loads the bitmap into the program

void MainWindow::on_Load_Image_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.bmp)"));

    imageqt.load(filename);

    MainWindow::bmpToWork.Read(filename.toStdString().c_str());
    MainWindow::unedit = MainWindow::bmpToWork;
   vertRot();

}

//Saves the image in a directory

void MainWindow::on_Save_image_clicked()
{

    QFileDialog save_file;
    save_file.setOptions(QFileDialog::DontUseNativeDialog);
    save_file.setDefaultSuffix(".bmp");
    std::string filename = save_file.getSaveFileName(this,tr("save"),"",tr("Images(*.bmp)")).toStdString();
    qDebug()<<filename.c_str();


    if(!filename.empty()){
        vertRot();
        MainWindow::bmpToWork.Export(filename.c_str());
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
    if(MainWindow::doErrase){
        for(int tempy =y;tempy<=y+MainWindow::brush;tempy++ ){
            if(!y+brush>bmpToWork.height()){
            for(int tempx =x;tempx<=x+MainWindow::brush;tempx++ ){
            if(!x+brush>bmpToWork.width()){
                imageqt.setPixelColor(tempx,tempy,QColor((int)255*MainWindow::unedit.GetColor(tempx,tempy).r,(int)255*MainWindow::unedit.GetColor(tempx,tempy).g,(int)255*MainWindow::unedit.GetColor(tempx,tempy).b));
                MainWindow::bmpToWork.SetColor(Color(MainWindow::unedit.GetColor(tempx,tempy).r,MainWindow::unedit.GetColor(tempx,tempy).g,MainWindow::unedit.GetColor(tempx,tempy).b),tempx,tempy);
            }

}
    }
        }
    }else{

    for(int tempy =y;tempy<=y+MainWindow::brush;tempy++ ){
        for(int tempx =x;tempx<=x+MainWindow::brush;tempx++ ){

            imageqt.setPixelColor(tempx,tempy,QColor((int)255*MainWindow::paintColor.r,(int)255*MainWindow::paintColor.g,(int)255*MainWindow::paintColor.b));
            MainWindow::bmpToWork.SetColor(Color(MainWindow::paintColor.r,MainWindow::paintColor.g,MainWindow::paintColor.b),tempx,tempy);
        }
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
        MainWindow::bmpToWork = Image(std::stoi(width),std::stoi(height));
        for(int y=0;y<std::stoi(height);y++){
            for(int x=0;x<std::stoi(width);x++){
                MainWindow::bmpToWork.SetColor(Color(1.0,1.0,1.0),x,y);
            }
        }


        MainWindow::bmpToWork.Export("new_piporin.bmp");
        MainWindow::unedit = MainWindow::bmpToWork;
        imageqt.load("new_piporin.bmp");

        //MainWindow::piporin.Read("new_piporin.bmp");

        ui->Image_lbl->resize(MainWindow::bmpToWork.width(),MainWindow::bmpToWork.height());
        ui->Image_lbl->setPixmap(QPixmap::fromImage(imageqt));
    }else{
        //error case
        QMessageBox warning;
        warning.setText("Elija la dimension deseada");
        warning.exec();
    }



}

//opens the color pickewr and sets the drawing color
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


void MainWindow::on_Errase_clicked()
{
    if(MainWindow::doErrase){
        MainWindow::doErrase = false;
    }else{
        MainWindow::doErrase = true;
    }
}



void MainWindow::on_Fill_clicked()
{
    if(MainWindow::doFill){
            MainWindow::doFill = false;
        }else{
            MainWindow::doFill = true;
        }
}


void MainWindow::on_VertFlip_clicked()
{
    std::string flipType = ui->flipType->currentText().toStdString();
    if(flipType == "Vertical"){
        vertRot();
    }
    if(flipType == "Horizontal"){
        horRot();
    }
    if(flipType == "Rotate"){
        rightRot();
    }
}


void MainWindow::on_doFilter_clicked()
{
    std::string filter = ui->Filters->currentText().toStdString();
    if(filter=="grayscale"){
        grayScale();
    }
    if(filter=="negative"){
        negative();
    }
    if(filter=="psycho"){
        psycho();
    }
    if(filter=="magmatic"){
        magmatic();
    }
}




