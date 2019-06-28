#include "imagen.h"

imagen::imagen(string name_ , string path_, string label_)
{
    name = name_;
    path = path_;
    label = label_;
}
string get_path(imagen i)
{
    return  i.path;
}
string get_name(imagen i)
{
    return  i.name;
}
string get_label(imagen i)
{
    return  i.label;
}

