/*
 * Copyright (c) 2016, Przemysław Podwapiński <p.podwapinski@gmail.com>
 * All rights reserved.
 *
 * Distributed under The FreeBSD License
 * https://www.freebsd.org/copyright/freebsd-license.html
 */

/* 
 * File:   SquareGenerator.cpp
 * Author: kret
 * 
 * Created on March 20, 2016, 8:36 PM
 */

#include "audio/SquareGenerator.h"
#include "audio/utils.h"

namespace audio
{

    SquareGenerator::SquareGenerator( const uint32_t f, const uint32_t fSampl )
    : IGenerator()
    , m_periodLength( periodLength( f, fSampl ) )    
{
}
    
    TSample SquareGenerator::sample( const size_t index )
    {
        const size_t normalizedX = index % m_periodLength;
        
        return ( normalizedX <= ( m_periodLength / 2U ) ) ? 1.0 : -1.0 ;
    }

};

