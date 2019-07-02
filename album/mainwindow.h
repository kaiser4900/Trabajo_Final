#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linked_list.h"
#include "imagen.h"
#include <QPixmap>
#include "QMessageBox"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPixmap pix;
    linked_list<imagen> li;
    linked_list<imagen>::iterator it;
    QMessageBox msgBox;

    void save_binary(linked_list <imagen> &v)
    {
        ofstream salidaBinary;
        salidaBinary.open("ficheroBinario.dat",ios::out|ios::binary);
        int  tmp;
        for(linked_list <imagen>::iterator it= v.begin();it!=++v.end();++it){
            tmp=get_name(*it).size();
            salidaBinary.write((char *)&tmp, sizeof(int));
            salidaBinary.write( get_name(*it).c_str(), get_name(*it).size());
            tmp= get_path(*it).size();
            salidaBinary.write((char *)&tmp, sizeof(int));
            salidaBinary.write( get_path(*it).c_str(), get_path(*it).size());
            tmp= get_label(*it).size();
            salidaBinary.write((char *)&tmp, sizeof(int));
            salidaBinary.write( get_label(*it).c_str(), get_label(*it).size());
        }
        salidaBinary.close();
    }
    void binaryLoad(linked_list <imagen> &v)
    {
        ifstream ficheroEntrada;
        ficheroEntrada.open("ficheroBinario.dat",ios::binary);
        if(ficheroEntrada.fail())
        {
            QMessageBox msgBox;
            msgBox . setText( "Error al abrir el fichero" );
            msgBox . exec();
            exit(1);
        }
        else
        {
            imagen s;
            int size_string;
            while(ficheroEntrada.read((char*)&size_string,sizeof(int))){

                    char c[size_string + 1];
                    ficheroEntrada.read((char*)&c,size_string);
                    c[size_string] = '\0';
                    change_name(s,c);
                    ficheroEntrada.read((char *)&size_string,sizeof(int));
                    char c2[size_string+1];
                    ficheroEntrada.read((char*)&c2,size_string);
                    c2[size_string] = '\0';
                    change_path(s,c2);
                    ficheroEntrada.read((char *)&size_string,sizeof(int));
                    char c3[size_string+1];
                    ficheroEntrada.read((char*)&c3,size_string);
                    change_label(s,c3);
                    v.push_back(s);
            }
        }
        ficheroEntrada.close();
    }
    char *a;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionimagen_triggered();

    void on_actionFront_triggered();

    void on_actionBack_triggered();

    void on_add_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
