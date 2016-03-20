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
 * File:   types.h
 * Author: kret
 *
 * Created on March 15, 2016, 11:16 PM
 */

#ifndef TYPES_H
#define TYPES_H

namespace audio
{
    /* Single sample */
    typedef float TSample;       
        
    /* Audio sample format */
    enum ESampleFormat
    {
        ESampleFormat_LE16,
        ESampleFormat_BE16,
        ESampleFormat_Float,
        ESampleFormat_Invalid,
    };
    
    enum ESignalShape
    {
        ESignalShape_Sin,
        ESignalShape_Saw,
        ESignalShape_Square,
        ESignalShape_Triangle,
        ESignalShape_Invalid,
    };
    
    enum EError
    {
        EError_FSampl,
        EError_Shape,
        EError_Amplitude,
        EError_Duration,
        EError_Format,
        EError_MemAlloc,
        EError_FileSave,
        EError_NoError,
        EError_Other,        
    };
};

#endif /* TYPES_H */

