#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linked_list.h"
#include "imagen.h"
#include <QPixmap>
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
    /*void save_binary(linked_list<imagen>vs)//guardando
    {
        ofstream salidaBinary;
        salidaBinary.open("ficheroBinario.dat",ios::out|ios::binary);
        for(int i=0; i<vs.size();i++)
            {
                salidaBinary.write((char*)&get_name(vs[i]),sizeof(int));
                int a = my_size(vs[i].str);
                string b = vs[i].str;
                salidaBinary.write((char*)&a,sizeof(int));
                for(int j = 0; j<a; j++)
                {
                    salidaBinary.write((char*)&b[j],sizeof(char));
                }
            }
        salidaBinary.close();
    }*/
    char *a;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionimagen_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
