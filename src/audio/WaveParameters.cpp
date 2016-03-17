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
 * File:   WaveParameters.cpp
 * Author: kret
 * 
 * Created on March 17, 2016, 8:23 PM
 */

#include "audio/WaveParameters.h"
#include "audio/TextEnumConverter.h"
#include "audio/TypeConverters.h"

namespace audio 
{

WaveParameters::WaveParameters( const uint32_t freq, const uint8_t amplitude
    , const uint32_t samplFreq, const char* shape, const char* format ) 
    : m_frequency( freq )
    , m_samplingFrequency( samplFreq )
    , m_amplitude( amplitude )
    , m_shape( TSignalShapeConverter().enumeration( shape ) )
    , m_outputFormat( TSampleFormatConverter().enumeration( format ) )
{

}


EError WaveParameters::validate() const
{    
    if ( m_samplingFrequency < 2U * m_frequency )
    {
        return EError_FSampl;
    }
    
    if ( m_amplitude > 100U )
    {
        return EError_Amplitude;
    }
    
    if ( m_duration == 0U )
    {
        return EError_Duration;
    }
    
    if ( m_shape == ESignalShape_Invalid )
    {
        return EError_Shape;
    }
    
    if ( m_outputFormat == ESampleFormat_Invalid )
    {
        return EError_Format;
    }
    
    return EError_NoError;
}


::std::string WaveParameters::toString() const
{
    ::std::string result;
    
    return result;
}
 
};

