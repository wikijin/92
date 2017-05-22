//
// Created by TwoDog on 2017/4/25.
//

#include <string>
#include <vector>
#include "DataGenerator.h"

using namespace std;

/**
 * Constructor.
 * @param name the name of this generator.
 */
DataGenerator::DataGenerator(string name) : name(name) {}

/**
 * Destructor.
 */
DataGenerator:: ~DataGenerator() {}

/**
 * Getter
 * @return the name of this generator.
 */
string DataGenerator::get_name() { return name; }

