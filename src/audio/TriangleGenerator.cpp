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
 * File:   TriangleGenerator.cpp
 * Author: kret
 * 
 * Created on March 20, 2016, 6:20 PM
 */

#include "audio/TriangleGenerator.h"
#include "audio/utils.h"

namespace audio
{

    TriangleGenerator::TriangleGenerator( const uint32_t f, const uint32_t fSampl )
    : IGenerator()
    , m_periodLength( periodLength( f, fSampl ) )    
    , m_factor( 2.0 / TSample( m_periodLength ) )
{
}
    
    TSample TriangleGenerator::sample( const size_t index )
    {
        TSample result = 0.0;
        
        const size_t normalizedX = index % m_periodLength;
        const size_t breakPoint = m_periodLength / 2U;
        
        if ( normalizedX < breakPoint )
        {
            result = m_factor * TSample( normalizedX );
        }
        else if ( normalizedX == breakPoint )
        {
            result = 1.0F;
        }
        else
        {
            result = 1.0 - ( m_factor ) * TSample( normalizedX - breakPoint );
        }
        
        return ( 2.0 * result ) - 1.0;
    }

};

