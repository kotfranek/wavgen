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
 * File:   PcmSample.h
 * Author: kret
 *
 * Created on March 17, 2016, 10:52 PM
 */

#ifndef PCMSAMPLE_H
#define PCMSAMPLE_H

#include <ostream>
#include "audio/types.h"

namespace audio
{
    class SampleContext;
    
    class PcmSample 
    {
    public:
        PcmSample();
        ~PcmSample();
        
        /**
         * Generate the sample into internal buffer
         * @param params Sample settings
         * @return EError_NoError in case of success
         */
        EError generate( const SampleContext& params );
        
        /**
         * Write the previously generated sample into an output stream
         * @param output
         * @param format Output format
         * @return EError_NoError in case of success
         */
        EError toStream( ::std::ostream& output, const ESampleFormat format ) const;
    private:
        
        /**
         * Prepares the sample buffer. 
         * Create if not exist or just resize.
         * @param size new length
         * @return true on success
         */
        bool prepareBuffer( const size_t size );
        
        /**
         * Allocate new buffer with the given sample count
         * @param size
         * @return 
         */
        bool allocateBuffer( const size_t size );
        
        
        /**
         * Cleanup the sample buffer
         */
        void deleteBuffer();

        /* Sample buffer */
        TSample* m_buffer;
        
        /* Sample buffer length */
        size_t m_bufferLength;
        
        /* Sample length after all justifications. Does not equal buffer size */
        size_t m_sampleLength;                               
    };    
}; // namespace audio

#endif /* PCMSAMPLE_H */

