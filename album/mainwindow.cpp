#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ifstream ficheroEntrada;
    ficheroEntrada.open ("ficheroBinario.dat", ios::in | ios::binary);
    ficheroEntrada.seekg(0, ios::end);
    int tamanyo = ficheroEntrada.tellg();
    ficheroEntrada.close();
    QMessageBox msgBox;
    bool aux = false;
    if(tamanyo == 0)
    {

        msgBox . setText( "El ficheo está vacío se mostrará una imagen por defecto" );
        msgBox . exec();
        imagen p(":v", "C:/Users/DELL/Pictures/Saved Pictures/artificial-intelligence.jpg", "ppp");
        li.push_back(p);
        string general = "<p>NAME: "+ get_name(p) +"</p>"+"<p>PATH: "+get_path(p)+"</p>"+"<p>LABEL: "+get_label(p)+"</p>";
        a = new char[general.size()];
        a[general.size()]=0;
        for(size_t i=0;i<general.size();i++){
            a[i]=general[i];
        }
        ui->label_2->setText(a);

        it=li.begin();
        string txt=get_path(*it);
        a=new char[txt.size()];
        a[txt.size()]=0;
        for(size_t i=0;i<txt.size();i++){
            a[i]=txt[i];
        }
        pix={a};
        ui->label->setPixmap(pix);
    }
    else {
        msgBox . setText( "El fichero se leyó correctamente" );
        msgBox . exec();
        binaryLoad(li);
        imagen p = li.begin().operator*();
        string general = "<p>NAME: "+ get_name(p) +"</p>"+"<p>PATH: "+get_path(p)+"</p>"+"<p>LABEL: "+get_label(p)+"</p>";
        a = new char[general.size()];
        a[general.size()]=0;
        for(size_t i=0;i<general.size();i++){
            a[i]=general[i];
        }
        ui->label_2->setText(a);

        it=li.begin();
        string txt=get_path(*it);
        a=new char[txt.size()];
        a[txt.size()]=0;
        for(size_t i=0;i<txt.size();i++){
            a[i]=txt[i];
        }
        pix={a};
        ui->label->setPixmap(pix);
    }
    //binaryLoad(li);
    //imagen p = li.begin().operator*();
    /*imagen p(":v", "C:/Users/DELL/Pictures/Saved Pictures/artificial-intelligence.jpg", "ppp");
    li.push_back(p);*/

    /*string general = "<p>NAME: "+ get_name(p) +"</p>"+"<p>PATH: "+get_path(p)+"</p>"+"<p>LABEL: "+get_label(p)+"</p>";
    a = new char[general.size()];
    a[general.size()]=0;
    for(size_t i=0;i<general.size();i++){
        a[i]=general[i];
    }
    ui->label_2->setText(a);

    it=li.begin();
    string txt=get_path(*it);
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label->setPixmap(pix);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ++it;
    if(it!=nullptr)
    {
    }
    else{
        it=li.begin();
    }
    string txt=get_path(*it);
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label->setPixmap(pix);

    txt="<p>NAME: "+ get_name(*it) +"</p>"+"<p>PATH: "+get_path(*it)+"</p>"+"<p>LABEL: "+get_label(*it)+"</p>";
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    ui->label_2->setText(a);
}

void MainWindow::on_pushButton_2_clicked()
{

    if(it!=li.begin())
    {
        --it;
    }
    else{
        it=li.end();
    }
    string txt=get_path(*it);
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label->setPixmap(pix);

    txt="<p>NAME: "+ get_name(*it) +"</p>"+"<p>PATH: "+get_path(*it)+"</p>"+"<p>LABEL: "+get_label(*it)+"</p>";
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }


    ui->label_2->setText(a);
}

void MainWindow::on_actionimagen_triggered()
{
    QString file_name = QFileDialog :: getOpenFileName(this, "open a file","C:/Users/DELL/Pictures/Saved Pictures");
    std::string utf8_text = file_name.toUtf8().constData();
    QString file = QFileDialog :: getSaveFileName(this,"open a file","c:/");
    imagen p(":v", utf8_text, "ppp");
    li.push_back(p);
    save_binary(li);
}

void MainWindow::on_actionFront_triggered()
{
    if(li.size()==0)
    {
        save_binary(li);
    }
    if(li.size()==1)
    {
        li.remove_front();
    }
    else {
        li.remove_front();
        save_binary(li);
    }
}

void MainWindow::on_actionBack_triggered()
{
    if(li.size()==0)
    {
        save_binary(li);
    }
    if(li.size()==1)
    {
        li.remove_back();
    }
    else {
        li.remove_back();
        save_binary(li);
    }
}
