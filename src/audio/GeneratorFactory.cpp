/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneratorFactory.cpp
 * Author: kret
 * 
 * Created on March 20, 2016, 7:11 PM
 */

#include <new>

#include "audio/GeneratorFactory.h"

#include "audio/SineGenerator.h"
#include "audio/SawToothGenerator.h"
#include "audio/TriangleGenerator.h"
#include "audio/SquareGenerator.h"

namespace audio
{
    IGenerator* createGenerator( const ESignalShape shape
        , const uint32_t f, const uint32_t fSampl  )
    {
        IGenerator* result = NULL;
        
        switch ( shape )
        {
            case ESignalShape_Sin:
                result = new ( ::std::nothrow ) SineGenerator( f, fSampl );
                break;
                
            case ESignalShape_Saw:
                result = new ( ::std::nothrow ) SawToothGenerator( f, fSampl );
                break;   
                
            case ESignalShape_Triangle:
                result = new ( ::std::nothrow ) TriangleGenerator( f, fSampl );
                break; 
            
            case ESignalShape_Square:
                result = new ( ::std::nothrow ) SquareGenerator( f, fSampl );
                break;                 
                
            case ESignalShape_Invalid:
            default:                
                break; 
        }
        
        return result;
    }
}

