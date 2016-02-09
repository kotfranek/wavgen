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

#include "SinePcm.h"
#include <cstddef>
#include <cstring>
#include <cmath>
#include <new>

// Debug printf
#include <cstdio>

/* Internal only */
namespace 
{
    /* 2 * PI Constant */
    const double DEF_2_PI = 2.0 * 3.141592653589793238462643383279502884;
    

    
    struct AudioFormatInfo
    {
        bool isFormat( const char* name ) const
        {
            return 0 == strcmp( m_formatName, name );
        }
        
        const ::audio::EFormat m_format;
        const char* m_formatName;
        const uint8_t m_sampleSize;
    };
    
    
    const AudioFormatInfo INVALID = { ::audio::EFormat_Invalid, "----", 0U };
    
    
    const AudioFormatInfo SAMPLE_FORMATS[] = 
    {
        { ::audio::EFormat_LE16, "LE16", 2U }, 
        { ::audio::EFormat_BE16, "LE16", 2U },
        { ::audio::EFormat_Float, "FLOAT", 4U },
    };
    
    
    const size_t SAMPLE_FORMATS_NUM = sizeof( SAMPLE_FORMATS ) / sizeof( SAMPLE_FORMATS[ 0 ] );
    
    /* Single sample */
    class SingleSample
    {
    public:
        /**
         * Constructor
         * @arg Value 
         */
        SingleSample( const double& value = 0.0 )
            : m_value( value )
        {
        }
        
        
        /* Store as little-endian */
        void littleEndian( void* output ) const
        {
            uint8_t* ptr = reinterpret_cast<uint8_t*>( output );
            const int16_t sample = toInt16();
            ptr[ 0U ] = ( sample & 0xFF );
            ptr[ 1U ] = ( ( sample >> 8U ) & 0xFF );
        }
        
        
        /* Store as big-endian */
        void bigEndian( void* output ) const
        {
            uint8_t* ptr = reinterpret_cast<uint8_t*>( output );
            const int16_t sample = toInt16();
            
            ptr[ 1U ] = ( sample & 0xFF );
            ptr[ 0U ] = ( ( sample >> 8U ) & 0xFF );
        } 
        
        
        /* Store as 32-bit floating-point */
        void ffloat( void* output ) const
        {
            float* ptr = reinterpret_cast<float*>( output );
            *ptr = m_value;
        }
        
    private:
        uint16_t toInt16() const
        {
            return static_cast<int16_t>( m_value + 0.5F );
        }
        
        /* Sample value as floating point */
        const float m_value;
    };
}

namespace audio
{
    
EFormat getFormatbyName( const char* name )
{
    EFormat result = EFormat_Invalid;
    
    for ( size_t i = 0U; i < SAMPLE_FORMATS_NUM; i++ )
    {
        if ( SAMPLE_FORMATS[ i ].isFormat( name ) )
        {
            result = SAMPLE_FORMATS[ i ].m_format;
            break;
        }
    }
    
    return result;
}


SinePcm::SinePcm( const uint32_t smpFreq )
    : m_samplingFreq( smpFreq )
    , m_duration( 0U )
    , m_sampleBuffer( NULL )
{

}

bool SinePcm::init( const uint32_t freqency, const float amplitude, const uint32_t duration )
{  
    bool result = false;
    
    if ( checkFreqency( freqency ) )
    {
        if ( m_duration != duration )
        {
            cleanUp();
            m_duration = duration;
            m_sampleBuffer = new (::std::nothrow) uint8_t[ samplesCount() * sizeof( TSample ) ];
        }
                
        const double angleFactor = ( double( freqency ) * DEF_2_PI ) / double( m_samplingFreq );
               
        for ( uint32_t i = 0U; i < samplesCount(); i++ )
        {
            const double sinAux = amplitude * ::std::sin( i * angleFactor );
            SingleSample( sinAux ).ffloat( m_sampleBuffer + ( i * sizeof( TSample ) ) );            
        }
        
        result = true;
    }
    
    return result;
}


void SinePcm::copyToBuffer( void* destination, const uint32_t samples )
{
    if ( NULL != destination && NULL != m_sampleBuffer )
    {
        ::memcpy( destination, m_sampleBuffer, samples * sizeof( TSample ) );
    }
}


void audio::SinePcm::toStream( std::ostream& output ) const
{
    output.write( reinterpret_cast<char*>( m_sampleBuffer ), samplesCount() * sizeof( TSample ) );
}



void SinePcm::cleanUp()
{
    delete[] m_sampleBuffer;    
    m_sampleBuffer = NULL;
    m_duration = 0U;
}


bool SinePcm::checkFreqency( const uint32_t freq ) const
{
    return ( 0U != freq && m_samplingFreq >= ( freq * 2U ) );
}



SinePcm::~SinePcm()
{
	cleanUp();
}

};
