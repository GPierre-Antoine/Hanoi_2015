//
// Created by Pierre-Antoine on 02/11/2015.
//

#include "Disc.h"

nsHanoi::Disc::Disc (const nsHanoi::Point & A, const nsHanoi::Point & B, const nsHanoi::Point & D, const nsHanoi::Point & E, const unsigned char psize) :
Cube(A,B,D,E), size (psize)
{

}
