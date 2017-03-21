#include "Coordinate.h"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

/***** Complete this file. *****/

istream& operator >>(istream& ins, Coordinate& coordinate)
{
    char drama;
    ins >> coordinate.latitude >> drama >> coordinate.longitude;
    return ins;
}