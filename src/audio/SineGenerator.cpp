/*
 * Copyright (c) 2016, Przemysław Podwapiński <p.podwapinski@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY Przemysław Podwapiński ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Przemysław Podwapiński BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* 
 * File:   SineGenerator.cpp
 * Author: kret
 * 
 * Created on March 18, 2016, 12:13 AM
 */

#include "audio/SineGenerator.h"
#include <cmath>

namespace
{
    /* 2 * PI Constant */
    const ::audio::TSample DEF_2_PI = 2.0 * 3.141592653589793238462643383279502884;  

    /**
     * Calculate the Angle Factor
     * @param f
     * @param fSampl
     * @return angle factor
     */
    ::audio::TSample angleFactor( const uint32_t f, const uint32_t fSampl )
    {
        ::audio::TSample result = 0.0;
        
        if ( 0 != fSampl )
        {
            result = ( ::audio::TSample( f ) * DEF_2_PI ) / ::audio::TSample( fSampl );
        }
        
        return result;
    }
}

namespace audio
{

    SineGenerator::SineGenerator( const uint32_t f, const uint32_t fSampl )
    : IGenerator()
    , m_angleFactor( ::angleFactor( f, fSampl ) )
{
}
    
    TSample SineGenerator::sample( const size_t index )
    {
        return ::std::sin( TSample( index ) * m_angleFactor );
    }

};


