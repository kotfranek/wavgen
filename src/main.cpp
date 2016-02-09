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
#include "SinePcm.h"
#include <tclap/CmdLine.h>

using namespace std;

namespace
{
    const uint32_t SAMPLE_RATE = 44100U;
}

int32_t main( int argc, const char * const * argv )
{
    ::TCLAP::CmdLine cmd( "Sound Test", ' ', "none", false );

    ::TCLAP::ValueArg<uint32_t> freqArg("f","frequency","Signal frequency", true,1000,"Hz");
    ::TCLAP::ValueArg<float> amplArg("a","amplitude","Signal amplitude", true,1.0,"0.0..1.0");
    ::TCLAP::ValueArg<string> outputFileArg("o","output","Output file to store the raw audio sample", false, "","file_name");
    ::TCLAP::ValueArg<string> formatArg("e","format","Sample format: LE16, BE16 or FLOAT", false, "","format_name");
    ::TCLAP::ValueArg<uint32_t> lengthArg("t","time","Sample duration", false, 1000, "ms");
    
    cmd.add( freqArg );
    cmd.add( amplArg );
    cmd.add( lengthArg );
    cmd.add( formatArg );
    cmd.add( outputFileArg );
        
    try
    {        
        cmd.parse( argc, argv );
    }
    catch ( TCLAP::ArgException &e )
    {
        std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    }
    
    ::std::cout << cmd.getMessage() << ": Generate Sine sample with f=" << freqArg.getValue() 
            << " Hz" << ". Length=" << lengthArg.getValue() << " ms" << ::std::endl;
    
    ::std::cout << "Sample rate = " << SAMPLE_RATE << " Hz" << ::std::endl;
    
    ::audio::SinePcm sample1( SAMPLE_RATE );
    
    if ( sample1.init( freqArg.getValue(), 1.0F, lengthArg.getValue() ) )
    {
        if ( outputFileArg.isSet() )
        {
            ::std::ofstream rawFile( outputFileArg.getValue().c_str(), ::std::ios::binary | ::std::ios::trunc );
            
            sample1.toStream( rawFile );
            rawFile.close();
            ::std::cout << "Sample stored to file '" << outputFileArg.getValue() << "'" << ::std::endl;
        }
    }
    
    return 0;
}
