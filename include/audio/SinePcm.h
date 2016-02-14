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

#ifndef SINEPCM_H
#define SINEPCM_H

#include <stdint.h>
#include <ostream>

namespace audio
{

enum EFormat
{
    EFormat_LE16,
    EFormat_BE16,
    EFormat_Float,
    EFormat_Invalid
};


EFormat getFormatbyName( const char* name );

class SinePcm
{
public:
    /* Sample type */
    typedef float TSample;    
    
    
    /**
     * Default constructor
     * @arg fSampl Audio I/O sampling freqency in Hz, eg 44100 or 48000
     */
    explicit SinePcm( const uint32_t smpFreq );
    
    
    ~SinePcm();
    
    
    /**
     * Initialize the sample with the sine signal of given frequency
     * @arg freqency Signal Frequency in Hz
     * @arg amplitude
     * @arg duration Length in milliseconds
     */
    bool init( const uint32_t freqency, const uint8_t amplitude, const uint32_t duration );
    
    
    /**
     * Copy part of the sample into a Play-Buffer
     * @arg destination
     * @arg samples
     */
    void copyToBuffer( void* destination, const uint32_t samples );
    
    
    /**
     * Store the raw sample buffer into the given Output Stream
     * 
     */
    void toStream( ::std::ostream& output ) const;
    
private:
    /* Clean the data */
    void cleanUp();
    
    
    /**
     * Check if given frequency signal can be generated
     */
    bool checkFreqency( const uint32_t freq ) const;
    
    
    /* Get samples count */
    uint32_t samplesCount() const
    {
        return ( m_samplingFreq * m_duration ) / 1000U;
    }
    
    
    /* Audio Sampling Frequency */
    const uint32_t m_samplingFreq;
    
    
    /* Sample duration in ms */
    uint32_t m_duration;
    
    
    /* Sample buffer */
    uint8_t* m_sampleBuffer;
};

}

#endif // SINEPCM_H
