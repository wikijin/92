//
// Created by TwoDog on 2017/4/25.
//

#include <iostream>
#include <string>
#include "Element.h"

using namespace std;

int Element::copyOfcount = 0;

/***** Complete this class. *****/

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    value = other.value;
    Element::copyOfcount++;

    /***** Complete this class. *****/
}

/**
 * Destructor.
 */
Element::~Element()
{
    /***** Complete this class. *****/
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

bool Element::operator < (const Element &other) const {return value < other.get_value();}
//bool Element::operator > (const Element &a, const Element &b) {return a.get_value() > b.get_value();}
bool Element::operator > (const Element &other)const {return value > other.get_value();}
ostream& operator<<(ostream& os, const Element &other) {os << other.value; return os;}
int Element::get_copy_count() {return Element::copyOfcount;}
int Element::get_destructor_count() {return Element::copyOfcount;}
void Element::reset() {Element::copyOfcount = 0;}

