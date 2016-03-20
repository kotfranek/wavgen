/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneratorFactory.h
 * Author: kret
 *
 * Created on March 20, 2016, 7:11 PM
 */

#ifndef GENERATORFACTORY_H
#define GENERATORFACTORY_H

#include <cstdint>
#include "audio/types.h"
#include "IGenerator.h"


namespace audio
{
    class IGenerator;
        
    /**
     * Create a Signal Generator matching the given shape.
     * User responsible for object removal
     * @param shape
     * @return NULL if shape not recognized
     */
    IGenerator* createGenerator( const ESignalShape shape
        , const uint32_t f, const uint32_t fSampl );
}

#endif /* GENERATORFACTORY_H */

