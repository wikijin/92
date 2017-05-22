#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>

#include "Coordinate.h"

using namespace std;

/**
 * City data.
 */
class City
{
public:
    // Constructor and destructor.
    City();
    virtual ~City();

    // Getters.
    string get_name() const;
    string get_state() const;
    Coordinate get_coordinate() const;

    // Overloaded stream I/O operators.
    friend ostream& operator <<(ostream& outs, const City& city);
    friend istream& operator >>(istream& ins, City& city);

private:
    string name;
    string state;
    Coordinate coordinate;
};

#endif /* CITY_H_ */
