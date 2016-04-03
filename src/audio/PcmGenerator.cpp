/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PcmGenerator.cpp
 * Author: kret
 * 
 * Created on April 3, 2016, 7:48 PM
 */

#include "audio/PcmGenerator.h"
#include "audio/SampleContext.h"
#include "audio/IGenerator.h"
#include "audio/GeneratorFactory.h"

namespace audio
{

PcmGenerator::PcmGenerator() 
{
}


EError PcmGenerator::generate( const SampleContext& params )
{
    EError result = EError_Other;
    
    const auto numSamples = params.getSamplesCount();
    
    if ( m_sample.prepareBuffer( numSamples ) )
    {
        IGenerator* gen = createGenerator( params.getShape()
            , params.getFrequency(), params.getSamplingFrequency() );
        
        if ( NULL != gen )
        {
            auto buffer = m_sample.data();
            const auto size = m_sample.length();
            
            for ( size_t i = 0; i < size; i++ )
            {
                buffer[ i ] = gen->sample( i );
            }
            
            delete gen;
            
            result = EError_NoError;
        }
        else
        {
            result = EError_Shape;
        }
    }
    else
    {
        result = EError_MemAlloc;
    }
    
    return result;
}


PcmGenerator::~PcmGenerator() 
{
}

};
