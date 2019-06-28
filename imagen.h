#ifndef IMAGEN_H
#define IMAGEN_H
#include <iostream>

using namespace  std;
class imagen
{
private:
    string name;
    string path;
    string label;
public:
    imagen(string name_="none" , string path_="none", string label_="none");
    //void save_binary(linked_list<imagen>vs);
    friend string get_path(imagen i);
    friend string get_name(imagen i);
    friend string get_label(imagen i);
};

#endif // IMAGEN_H
