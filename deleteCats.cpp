///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <stdio.h>

#include "deleteCats.h"
#include "catDatabase.h"
#include "config.h"

void deleteAllCats(){
    while ( currentCatNum != 0 ) {
        deleteCat( 0 );
    }
}

bool deleteCat(int index){
    if( isValidIndex(index) ){
        for(int x = index; x < MAX_NUM_CATS - 1; x++){
            strcpy(catArray[x].name, catArray[x + 1].name);
            catArray[x].gender = catArray[x + 1].gender;
            catArray[x].breed = catArray[x + 1].breed;
            catArray[x].isFixed = catArray[x + 1].isFixed;
            catArray[x].weight = catArray[x + 1].weight;
            catArray[x].collarColor1 = catArray[x + 1].collarColor1;
            catArray[x].collarColor2 = catArray[x + 1].collarColor2;
            catArray[x].license = catArray[x + 1].license;
        }
        currentCatNum -= 1;
        return true;
    } else {
        fprintf( stderr, "%s: Index must be less than [%d]\n", PROGRAM_NAME, MAX_NUM_CATS);
        return false;
    }
}
