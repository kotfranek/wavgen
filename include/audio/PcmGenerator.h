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
        
    private:
        PcmGenerator(const PcmGenerator& orig);
    };

};

#endif /* PCMGENERATOR_H */

