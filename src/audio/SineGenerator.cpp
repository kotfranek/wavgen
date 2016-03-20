/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SineGenerator.cpp
 * Author: kret
 * 
 * Created on March 18, 2016, 12:13 AM
 */

#include "audio/SineGenerator.h"
#include <cmath>

namespace
{
    /* 2 * PI Constant */
    const ::audio::TSample DEF_2_PI = 2.0 * 3.141592653589793238462643383279502884;  

    /**
     * Calculate the Angle Factor
     * @param f
     * @param fSampl
     * @return angle factor
     */
    ::audio::TSample angleFactor( const uint32_t f, const uint32_t fSampl )
    {
        ::audio::TSample result = 0.0;
        
        if ( 0 != fSampl )
        {
            result = ( ::audio::TSample( f ) * DEF_2_PI ) / ::audio::TSample( fSampl );
        }
        
        return result;
    }
}

namespace audio
{

    SineGenerator::SineGenerator( const uint32_t f, const uint32_t fSampl )
    : IGenerator()
    , m_angleFactor( ::angleFactor( f, fSampl ) )
{
}
    
    TSample SineGenerator::sample( const size_t index )
    {
        return ::std::sin( TSample( index ) * m_angleFactor );
    }

};


