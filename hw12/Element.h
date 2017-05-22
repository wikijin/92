//
// Created by TwoDog on 2017/4/25.
//

#ifndef HW12_ELEMENT_H
#define HW12_ELEMENT_H

//#ifndef DATA_H_
//#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;
    bool operator < (const Element &other) const;
    bool operator > (const Element &other) const;
    //bool operator > (const Element& a, const Element& b);
    friend ostream& operator<<(ostream& os, const Element& element);
    static int get_copy_count();
    static int get_destructor_count();
    static void reset();

    /***** Complete this class. *****/

private:
    long value;
    static int copyOfcount;
};

//#endif /* DATA_H_ */


#endif //HW12_ELEMENT_H
