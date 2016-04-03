/*
 * Copyright (c) 2016, Przemysław Podwapiński <p.podwapinski@gmail.com>
 * All rights reserved.
 *
 * Distributed under The FreeBSD License
 * https://www.freebsd.org/copyright/freebsd-license.html
 */

/* 
 * File:   PcmGenerator.h
 * Author: kret
 *
 * Created on April 3, 2016, 7:48 PM
 */

#ifndef PCMGENERATOR_H
#define PCMGENERATOR_H

#include "audio/types.h"
#include "audio/PcmSample.h"

namespace audio
{

    class SampleContext;
    
    class PcmGenerator 
    {
    public:
        PcmGenerator();
        ~PcmGenerator();
        
        /**
         * Generate the sample into internal buffer
         * @param params Sample settings
         * @return EError_NoError in case of success
         */
        EError generate( const SampleContext& params );
        
        /**
         * Scale the sample by the given factor
         * @param factor
         */
        void scale( const double factor );
        
        
        /**
         * Expose the const reference to the PcmSample object
         * @return 
         */
        const PcmSample& sample() const
        {
            return m_sample;
        }
        
    private:
        PcmGenerator(const PcmGenerator& orig);
        
        /* Sample Instance */
        PcmSample m_sample;
    };

};

#endif /* PCMGENERATOR_H */

