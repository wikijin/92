//
// Created by TwoDog on 2017/4/25.
//

#ifndef HW12_DATAREVERSESORTED_H
#define HW12_DATAREVERSESORTED_H

//#ifndef DATAREVERSESORTED_H_
//#define DATAREVERSESORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for reverse-sorted data.
 */
class DataReverseSorted: public DataGenerator
{
public:
    DataReverseSorted();
    virtual ~DataReverseSorted();

    virtual void generate_data(vector<Element>& data, int size);
};

//#endif /* DATAREVERSESORTED_H_ */

#endif //HW12_DATAREVERSESORTED_H
