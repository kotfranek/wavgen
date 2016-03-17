/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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
    class WaveParameters;
    
    class PcmSample 
    {
    public:
        PcmSample();
        ~PcmSample();
        
        EError generate( const WaveParameters& params );
        
        /**
         * Write the previously generated sample into an output stream
         * @param output
         * @param format Output format
         * @return EError_NoError in case of success
         */
        EError toStream( ::std::ostream& output, const ESampleFormat format ) const;
    private:

        /* Sample buffer */
        float* m_buffer;
        
        /* Sample buffer length */
        size_t m_bufferLength;
        
        /* Sample length after all justifications. Does not equal buffer size */
        size_t m_sampleLength;                               
    };    
}; // namespace audio

#endif /* PCMSAMPLE_H */

