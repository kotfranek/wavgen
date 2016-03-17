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
 * File:   PcmSample.cpp
 * Author: kret
 * 
 * Created on March 17, 2016, 10:52 PM
 */

#include "audio/PcmSample.h"
#include "audio/SampleContext.h"

namespace audio
{

PcmSample::PcmSample() 
    : m_buffer( NULL )
    , m_bufferLength( 0U )
    , m_sampleLength( 0U )
{
}


EError PcmSample::generate( const SampleContext& params )
{
    EError result = EError_Other;
    
    const auto numSamples = params.getSamplesCount();
    
    if ( prepareBuffer( numSamples ) )
    {
        
    }
    else
    {
        result = EError_MemAlloc;
    }
    
    return result;
}


bool PcmSample::prepareBuffer( const size_t size )
{
    bool result = false;
    
    if ( NULL == m_buffer )
    {
        result = allocateBuffer( size );
    }
    else
    {
        /* Buffer exists and can hold the new signal */
        if ( m_bufferLength >= size )
        {
            m_bufferLength = size;
            result = EError_NoError;
        }
        else
        {
            deleteBuffer();
            result = allocateBuffer( size );
        }
    }    
    
    return result;
}


bool PcmSample::allocateBuffer( const size_t size )
{
    bool result = false;
    
    m_buffer = new ( ::std::nothrow ) TSample[ size ];

    if ( NULL != m_buffer )
    {
        m_bufferLength = size;
        result = true;
    }
    
    return result;    
}


void PcmSample::deleteBuffer()
{
    delete[] m_buffer;
    m_bufferLength = 0U;
}


PcmSample::~PcmSample() 
{
    deleteBuffer();
}
    
}
