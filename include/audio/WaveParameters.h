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
 * File:   WaveParameters.h
 * Author: kret
 *
 * Created on March 17, 2016, 8:23 PM
 */

#ifndef WAVEPARAMETERS_H
#define WAVEPARAMETERS_H

#include <stdint.h>
#include <string>
#include "audio/types.h"

namespace audio
{

    class WaveParameters 
    {
    public:
        /**
         * Wave Signal Parameter Context
         * 
         * @param freq
         * @param amplitude
         * @param samplFreq
         * @pram duration in ms
         * @param shape
         * @param format
         */
        WaveParameters( const uint32_t freq, const uint8_t amplitude
                , const uint32_t samplFreq, const uint32_t duration
                , const char* shape, const char* format 
                );
        
        /**
         * Check if the given parameters are valid and generation will succeed
         * @return error value
         */
        EError validate() const;
        
        
        /**
         * Generate a summary
         * @return C++ string with data
         */
        ::std::string toString() const;
        
        /**
         * Get the signal frequency
         * @return 
         */
        uint32_t getFrequency() const
        {
            return m_frequency;
        }        
        
        /**
         * Get the sampling frequency
         * @return 
         */
        uint32_t getSamplingFrequency() const
        {
            return m_samplingFrequency;
        }
        
        /**
         * Get the signal amplitude
         * @return 
         */
        uint8_t getAmplitude() const
        {
            return m_amplitude;
        }
        
        
        /**
         * Get sample length in ms
         * @return 
         */
        uint32_t getDuration() const
        {
            return m_duration;
        }
        
        
        /**
         * Get the output format
         * @return 
         */
        ESampleFormat getFormat() const
        {
            return m_outputFormat;
        }
        
        
        /**
         * Get the signal shape
         * @return 
         */
        ESignalShape getShape() const
        {
            return m_shape;
        }
        
    private:
        /* Signal frequency */
        const uint32_t m_frequency;
        
        /* Sampling frequency */
        const uint32_t m_samplingFrequency;
        
        /* Signal amplitude (%) */
        const uint8_t m_amplitude;
        
        /* Length in ms */
        const uint32_t m_duration;
        
        /* Signal shape */
        const ::audio::ESignalShape m_shape;
        
        /* Output format */
        const ::audio::ESampleFormat m_outputFormat;
    };

};

#endif /* WAVEPARAMETERS_H */

