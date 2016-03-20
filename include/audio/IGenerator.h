/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IGenerator.h
 * Author: kret
 *
 * Created on March 18, 2016, 12:10 AM
 */

#ifndef IGENERATOR_H
#define IGENERATOR_H

#include <cstddef>
#include "audio/types.h"

namespace audio
{
    /* Max amplitude that can be used for reference singal generator */
    static const TSample AMPLITUDE_MAX = 100.0 * 1000.0;
    
    class IGenerator
    {
    public:
        virtual ~IGenerator()
        {            
        };
        
        /**
         * Generate the sample at given index
         * @param i index
         * @return sample
         */
        virtual TSample sample( const size_t i ) = 0;
        
    protected:
        IGenerator()
        {            
        };
    };
}

#endif /* IGENERATOR_H */

