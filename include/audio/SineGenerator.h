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

#include <cstdint>
#include "audio/IGenerator.h"

namespace audio
{    
    /**
     * Generate a reference SINE wave form
     */
    class SineGenerator : public IGenerator
    {
    public:
        /**
         * Constructor
         * @param f Signal Frequency [Hz]
         * @param fSampl Sampling Frequency [Hz]
         */
        SineGenerator( const uint32_t f, const uint32_t fSampl );

        /**
         * Destructor
         */
        virtual ~SineGenerator()
        {        
        }
        
        
        /**
         * @see IGenerator
         */
        virtual TSample sample( const size_t index );
        
    private:          
        /* Angle factor */
        const TSample m_angleFactor;
    };
};

#endif /* SINEGENERATOR_H */

