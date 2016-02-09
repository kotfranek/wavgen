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
    
    ::std::cout << cmd.getMessage() << ": Generate Sine sample with f=" << freqArg.getValue() << " Hz" << ". Lenght=" << lengthArg.getValue() << " ms" << ::std::endl;
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
