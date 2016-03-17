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
 * File:   TextEnumConverter.h
 * Author: kret
 *
 * Created on March 16, 2016, 8:44 PM
 */

#ifndef TEXTENUMCONVERTER_H
#define TEXTENUMCONVERTER_H

#include <string.h>

namespace audio
{
    /* Universal Enumerator to Text Descriptor */
    template<typename ENUM>struct EnumDescriptor
    {
        typedef ENUM value_type;
        
        /* Enumerator */
        const value_type m_value;         
        
        /* Parameter Name */
        const char* m_name;

        /* Description */
        const char* m_description;       
    };
        
    
    /**
     * A template helper class allowing easy handling of 
     * Enumeration-and-text handling.
     * 
     * Provide the type, array pointer with Descriptors and it's size.
     * This allows an efficient mapping between the enum value and defined enum 
     * name in both ways. Additionally it provides access to enum's description.
     * 
     * The last array's element has to be a record holding an invalid item, 
     * which is returned in case of no matching results.
     */
    template<typename ENUM, const EnumDescriptor<ENUM>* PTR, size_t SIZE> class TextEnumConverter
    {
    public:
        typedef EnumDescriptor<ENUM> TEnumStruct;
        
        inline const char* name( const typename TEnumStruct::value_type value ) const
        {
            return findDescriptor( value ).m_name;        
        }
        
        inline const char* description( const typename TEnumStruct::value_type value ) const
        {           
            return findDescriptor( value ).m_description;
        }
                
                
        typename TEnumStruct::value_type enumeration( const char* name ) const
        {
            for ( size_t i = 0U; i < SIZE; i++ )
            {
                if ( 0 == strcmp( PTR[ i ].m_name, name ) )
                {
                    return PTR[ i ].m_value;
                }
            }
            
            return INVALID.m_value; 
        }                
        
    private:
        
        const TEnumStruct& findDescriptor( const typename TEnumStruct::value_type value ) const
        {
            for ( size_t i = 0U; i < SIZE; i++ )
            {
                if ( PTR[ i ].m_value == value )
                {
                    return PTR[ i ];
                }
            }
            
            return INVALID;            
        }
        
        /* Invalid item: always last array element */
        static constexpr const TEnumStruct& INVALID = PTR[ SIZE - 1U ];
    };
}; // namespace audio

#endif /* TEXTENUMCONVERTER_H */

