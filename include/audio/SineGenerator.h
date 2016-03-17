/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SineGenerator.h
 * Author: kret
 *
 * Created on March 18, 2016, 12:13 AM
 */

#ifndef SINEGENERATOR_H
#define SINEGENERATOR_H

#include "audio/IGenerator.h"

namespace audio
{

    class SineGenerator : public IGenerator
    {
    public:
        SineGenerator();


        virtual ~SineGenerator()
        {        
        }
        
        /**
         * @see IGenerator
         */
        TSample sample( const size_t index );
        
    private:                
    };
};

#endif /* SINEGENERATOR_H */

