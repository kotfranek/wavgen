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
 * File:   EShapeConverter.h
 * Author: kret
 *
 * Created on March 16, 2016, 10:00 PM
 */

#ifndef ESHAPECONVERTER_H
#define ESHAPECONVERTER_H

#include "audio/types.h"
#include "audio/TextEnumConverter.h"

namespace audio
{
    template <typename T,unsigned S>
    constexpr inline unsigned arraySize(const T (&v)[S]) 
    { 
        return S; 
    }
    
    typedef EnumDescriptor<ESignalShape> TSignalShape;
    
    constexpr TSignalShape SIGNAL_SHAPES[] =
    {
        { ESignalShape_Saw, "saw", "Saw-Shape Signal" },
        { ESignalShape_Sin, "sin", "Sinus-Shape Signal" },
        { ESignalShape_Triangle, "triangle", "Triangle-Shape Signal" },
        { ESignalShape_Square, "square", "Square-Shape Signal" },
        { ESignalShape_Invalid, "invalid", "Unknown Signal Shape" },        
    };
    
    typedef EnumDescriptor<ESampleFormat> TSampleFormat;
    
    constexpr TSampleFormat SAMPLE_FORMATS[] =
    {
        { ESampleFormat_BE16, "BE16", "16-bit Big-Endian" },
        { ESampleFormat_LE16, "LE16", "16-bit Little-Endian" },
        { ESampleFormat_Float, "Float", "32-bit IEEE 754 float" },
        { ESampleFormat_Invalid, "invalid", "Unknown Sample Format" },
    };   
    
    typedef EnumDescriptor<EError> TError;
    
    constexpr TError ERRORS[] = 
    {
        { EError_FSampl, "Sampling Freq.", "Sampling frequency not sufficient" },
        { EError_Shape, "Shape", "Unsupported signal shape" },
        { EError_Amplitude, "Amplitude", "Invalid amplitude" },        
        { EError_Format, "Format", "Unsupported output format" },
        { EError_MemAlloc, "Memory Alloc.", "Insufficient memory" },
        { EError_FileSave, "File", "Saving sample to file failed" },
        { EError_NoError, "Success", "Operation succeeded" },
    };
    
    typedef TextEnumConverter< ESignalShape, SIGNAL_SHAPES, arraySize( SIGNAL_SHAPES ) > TSignalShapeConverter;
    typedef TextEnumConverter< ESampleFormat, SAMPLE_FORMATS, arraySize( SAMPLE_FORMATS ) > TSampleFormatConverter;
    typedef TextEnumConverter< EError, ERRORS, arraySize( ERRORS ) > TErrorConverter;
}

#endif /* ESHAPECONVERTER_H */

