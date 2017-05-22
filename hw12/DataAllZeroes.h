//
// Created by TwoDog on 2017/4/25.
//

#ifndef HW12_DATAALLZEROES_H
#define HW12_DATAALLZEROES_H

//#ifndef DATAALLZEROS_H_
//#define DATAALLZEROS_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for data that is all zeros.
 */
class DataAllZeros: public DataGenerator
{
public:
    DataAllZeros();
    virtual ~DataAllZeros();

    virtual void generate_data(vector<Element>& data, int size);
};

//#endif /* DATAALLZEROS_H_ */

#endif //HW12_DATAALLZEROES_H
