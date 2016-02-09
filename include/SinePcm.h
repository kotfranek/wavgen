/*
 * Copyright 2016 Przemyslaw Podwapinski <p.podwapinski@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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
    bool init( const uint32_t freqency, const float amplitude, const uint32_t duration );
    
    
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
