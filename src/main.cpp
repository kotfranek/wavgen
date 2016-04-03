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

#include <stdint.h>
#include <iostream>
#include <fstream>
#include "audio/TextEnumConverter.h"
#include "audio/TypeConverters.h"
#include "audio/WaveParameters.h"
#include "audio/PcmSample.h"
#include "audio/PcmGenerator.h"
#include <tclap/CmdLine.h>

namespace
{  
    /* Program name */
    const ::std::string PROGRAM_NAME( "Sound Test" );
    
    /* Program Version */
    const ::std::string PROGRAM_VER( "0.1.0" );
    
    /* Extra usge info */
    const ::std::string USE_MESSAGE( "\
\rDefaults:\n\
\r- amplitude\t: 100%\n\
\r- format\t: LE16\n\
\r- duration\t: 1000 ms\n\
\r- smp.rate\t: 44100 Hz\n\
" );
    
    /* Print generator summary */
    void printSummary( const uint32_t frequency, const uint8_t amplitude )
    {
        const int32_t num = ::printf(" %s ver.: %s", ::PROGRAM_NAME.c_str(), ::PROGRAM_VER.c_str() );
        ::putchar( '\n' );
        
        for ( int32_t i = 0; i <= num; i++ )
        {
            ::putchar('-');
        }
        
        ::putchar( '\n' );
        
        ::printf( "frequency\t: %u\n", frequency );
        ::printf( "amplitude\t: %u\n", amplitude );        
    }       
}

int32_t main( int argc, const char * const * argv )
{
    ::TCLAP::CmdLine cmd( ::USE_MESSAGE, ' ', "none", false );

    ::TCLAP::ValueArg<uint32_t> freqArg( "f", "frequency", "Signal frequency", true, 1000, "Hz" );
    ::TCLAP::ValueArg<uint32_t> freqSmpArg( "s", "sample_rate", "Signal Sampling frequency", false, 44100, "Hz" );
    ::TCLAP::ValueArg<uint16_t> amplArg( "a", "amplitude", "Signal amplitude in %", false, 100, "0..100" );
    ::TCLAP::ValueArg<std::string> outputFileArg( "o", "output", "Output file to store the raw audio sample", true, "", "file_name" );
    ::TCLAP::ValueArg<std::string> formatArg( "e", "format", "Sample format: LE16, BE16 or FLOAT", false, "BE16", "format_name" );
    ::TCLAP::ValueArg<std::string> wavShapeArg( "w", "wave", "Wave shape: sin, saw, triangle or square", false, "sin", "shape_name" );
    ::TCLAP::ValueArg<uint32_t> lengthArg( "t", "time", "Sample duration", false, 1000, "ms" );
    ::TCLAP::SwitchArg loopArg( "l", "loop_enable", "Enable playing of the sample in loops (fill with complete periods)" );    

    cmd.add( lengthArg );
    cmd.add( formatArg );
    cmd.add( freqSmpArg );
    cmd.add( loopArg );
    cmd.add( wavShapeArg );
    
    cmd.add( outputFileArg );    
    cmd.add( amplArg );
    cmd.add( freqArg );    
        
    try
    {        
        cmd.parse( argc, argv );
    }
    catch ( TCLAP::ArgException &e )
    {
        std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    }
    
    const ::std::string& fileName = outputFileArg.getValue();
    const ::std::string& shape = wavShapeArg.getValue();
    const ::std::string& format = formatArg.getValue();
    
    const uint32_t frequency = freqArg.getValue();
    const uint32_t freqSampl = freqSmpArg.getValue();
    const uint32_t length = lengthArg.getValue();
    const uint8_t amplitude = amplArg.getValue();
    
    ::printSummary( frequency, amplitude );
    
    {
        using namespace audio;
        
        WaveParameters waveParams( frequency, amplitude, freqSampl, length, shape.c_str(), format.c_str() );

        const EError errorParams = waveParams.validate();

        if ( EError_NoError == errorParams )
        {
            PcmGenerator pcmGen;
            if ( EError_NoError == pcmGen.generate( waveParams.getContext() ) )
            {
                if ( !fileName.empty() )
                {
                    ::std::ofstream rawFile( fileName.c_str(), ::std::ios::binary | ::std::ios::trunc );

                    pcmGen.sample().toStream( rawFile, ESampleFormat_Float );
                    rawFile.close();
                    ::printf( "Sample stored to file '%s'\n", fileName.c_str() );
                }
            }
        }
        else
        {
            ::printf( "Error: %s\n", TErrorConverter().description( errorParams ) );
        }
        
    }
    return 0;
}
