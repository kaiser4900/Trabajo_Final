#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include "mainwindow.h"

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
                c3[size_string] = '\0';
                change_label(s,c3);
                v.push_back(s);
        }
    }
    ficheroEntrada.close();
}
#endif // LOAD_SAVE_H
