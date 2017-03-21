#include "City.h"

    /***** Complete this file. *****/

ostream& operator <<(ostream& outs, const City& city)
{
    //NO
}

istream& operator >>(istream& ins, City& city)
{
    char drama;
    ins >> city.name;
    ins >> drama;
    ins >> city.state;
    ins >> drama;
    ins >> city.coordinate;
    return ins;
}