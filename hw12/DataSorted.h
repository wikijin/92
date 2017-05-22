//
// Created by TwoDog on 2017/4/25.
//

#ifndef HW12_DATASORTED_H
#define HW12_DATASORTED_H

//#ifndef DATASORTED_H_
//#define DATASORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for already sorted data.
 */
class DataSorted: public DataGenerator
{
public:
    DataSorted();
    virtual ~DataSorted();

    virtual void generate_data(vector<Element>& data, int size);
};

//#endif /* DATASORTED_H_ */

#endif //HW12_DATASORTED_H
