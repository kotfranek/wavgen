/*
 * Copyright (c) 2016, Przemysław Podwapiński <p.podwapinski@gmail.com>
 * All rights reserved.
 *
 * Distributed under The FreeBSD License
 * https://www.freebsd.org/copyright/freebsd-license.html
 */

/* 
 * File:   SquareGenerator.h
 * Author: kret
 *
 * Created on March 20, 2016, 8:36 PM
 */

#ifndef SQUAREGENERATOR_H
#define SQUAREGENERATOR_H

#include <cstdint>
#include "audio/IGenerator.h"

namespace audio
{    
    /**
     * Generate a reference Square wave form
     */
    class SquareGenerator : public IGenerator
    {
    public:
        /**
         * Constructor
         * @param f Signal Frequency [Hz]
         * @param fSampl Sampling Frequency [Hz]
         */
        SquareGenerator( const uint32_t f, const uint32_t fSampl );

        /**
         * Destructor
         */
        virtual ~SquareGenerator()
        {        
        }
        
        
        /**
         * @see IGenerator
         */
        virtual TSample sample( const size_t index );
        
    private:                 
        /* Samples count per period */
        const uint32_t m_periodLength;    
    };
};


#endif /* SQUAREGENERATOR_H */

