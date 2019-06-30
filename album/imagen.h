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
    friend string get_path(imagen &i);
    friend string get_name(imagen &i);
    friend string get_label(imagen &i);
    friend void change_path(imagen & i,string str);
    friend void change_name(imagen & i,string str);
    friend void change_label(imagen & i,string str);
};

#endif // IMAGEN_H
