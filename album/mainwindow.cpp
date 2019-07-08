#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "load_save.h"
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
    if(tamanyo == 0)
    {

        msgBox . setText( "El ficheo está vacío se mostrará una imagen por defecto" );
        msgBox . exec();
        imagen p(":v", "C:/Users/DELL/Pictures/Saved Pictures/artificial-intelligence.jpg", "ppp");
        li.push_back(p);
        bst_i.insert(get_name(p),p);
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
    //ideA PARA ELEGIR EN QUE ARCHIVO GUARDAR QString file = QFileDialog :: getSaveFileName(this,"open a file","c:/");
    imagen p(":v", utf8_text, "ppp");
    li.push_back(p);
    bst_i.insert(get_name(p),p);
    save_binary(li);
}
void MainWindow::on_add_button_clicked()
{
    QString new_name = ui->input_name->text();
    QString new_label = ui->input_label->text();
    QString new_path = QFileDialog :: getOpenFileName(this, "Open a file","C:/Users/DELL/Pictures/Saved Pictures");
    std::string utf8_text = new_path.toUtf8().constData();
    string utf8_text_1 = new_name.toUtf8().constData();
    string utf8_text_3 = new_label.toUtf8().constData();
    imagen p(utf8_text_1, utf8_text, utf8_text_3);
    li.push_back(p);
    bst_i.insert(get_name(p),p);
    save_binary(li);
}
void MainWindow::on_search_clicked()
{
    QString search = ui->input_search->text();
    string utf8_text_1 = search.toUtf8().constData();
    if(bst_i.find(utf8_text_1))
    {
        msgBox . setText( "Encontrado" );
        msgBox . exec();
    }
    else {
        msgBox .setText("no encontrado");
        msgBox .exec();
    }
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

void MainWindow::on_actionthis_triggered()
{
    li.remove(it);
    save_binary(li);
}
