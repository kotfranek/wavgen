/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PcmSample.cpp
 * Author: kret
 * 
 * Created on March 17, 2016, 10:52 PM
 */

#include "audio/PcmSample.h"

namespace audio
{

PcmSample::PcmSample() 
    : m_buffer( NULL )
    , m_bufferLength( 0U )
    , m_sampleLength( 0U )
{
}


PcmSample::~PcmSample() 
{
}
    
}
