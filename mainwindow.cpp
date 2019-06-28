#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imagen p(":v", "C:/Users/DELL/Pictures/Saved Pictures/artificial-intelligence.jpg", "ppp");
    li.push_back(p);
    //imagen s(":,v","C:/Users/DELL/Pictures/Saved Pictures/ojo.jpg","sss" );
    //li.push_back(s);
    //imagen t("c:","C:/Users/DELL/Pictures/Saved Pictures/photo-manipulation-eye-wallpaper.jpg","ttt");
    //li.push_back(t);
    //imagen c(":c","C:/Users/DELL/Pictures/Saved Pictures/siri.jpg","ccc");
    //li.push_back(c);
    it=li.begin();


    string general = "<p>NAME: "+ get_name(p) +"</p>"+"<p>PATH: "+get_path(p)+"</p>"+"<p>LABEL: "+get_label(p)+"</p>";
    a = new char[general.size()];
    a[general.size()]=0;
    for(size_t i=0;i<general.size();i++){
        a[i]=general[i];
    }
    ui->label_2->setText(a);


    string txt=get_path(*it);
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label->setPixmap(pix);

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
    imagen p(":v", utf8_text, "ppp");
    li.push_back(p);
    //save_binary(li);
}
