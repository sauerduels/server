/*
* remod:    cryptomod.cpp
* date:     2011
* author:   degrave
*
* some hash cubescript bindings
*/


#include "cube.h"
#include "hashlibpp.h"
#include "remod.h"

EXTENSION(CRYPTO);

// shared/crypto.cpp
namespace tiger
{
    typedef unsigned long long int chunk;

    union hashval
    {
        uchar bytes[3*8];
        chunk chunks[3];
    };

    void hash(const uchar *str, int length, hashval &val);
}

namespace remod {

    // Return Tiger 192 bit hash
    void cs_tiger192(const char *str)
    {
        // staff from shared/crypto.cpp
        string ref;
        char *hash = &ref[0]; // get pointer to first element
        tiger::hashval hv;
        tiger::hash((uchar *)str, strlen(str), hv);
        loopi(sizeof(hv.bytes)/8)
        {
            #if BYTE_ORDER == LITTLE_ENDIAN
            tiger::chunk c = hv.chunks[i];

            *hash++ = "0123456789abcdef"[(c>>60)&0xF];
            *hash++ = "0123456789abcdef"[(c>>56)&0xF];
            *hash++ = "0123456789abcdef"[(c>>52)&0xF];
            *hash++ = "0123456789abcdef"[(c>>48)&0xF];
            *hash++ = "0123456789abcdef"[(c>>44)&0xF];
            *hash++ = "0123456789abcdef"[(c>>40)&0xF];
            *hash++ = "0123456789abcdef"[(c>>36)&0xF];
            *hash++ = "0123456789abcdef"[(c>>32)&0xF];
            *hash++ = "0123456789abcdef"[(c>>28)&0xF];
            *hash++ = "0123456789abcdef"[(c>>24)&0xF];
            *hash++ = "0123456789abcdef"[(c>>20)&0xF];
            *hash++ = "0123456789abcdef"[(c>>16)&0xF];
            *hash++ = "0123456789abcdef"[(c>>12)&0xF];
            *hash++ = "0123456789abcdef"[(c>>8 )&0xF];
            *hash++ = "0123456789abcdef"[(c>>4 )&0xF];
            *hash++ = "0123456789abcdef"[c&0xF];
            #else
            tiger::chunk c = hv.chunks[i];

            *hash++ = "0123456789abcdef"[c&0xF];
            *hash++ = "0123456789abcdef"[(c>>4 )&0xF];
            *hash++ = "0123456789abcdef"[(c>>8 )&0xF];
            *hash++ = "0123456789abcdef"[(c>>12)&0xF];
            *hash++ = "0123456789abcdef"[(c>>16)&0xF];
            *hash++ = "0123456789abcdef"[(c>>20)&0xF];
            *hash++ = "0123456789abcdef"[(c>>24)&0xF];
            *hash++ = "0123456789abcdef"[(c>>28)&0xF];
            *hash++ = "0123456789abcdef"[(c>>32)&0xF];
            *hash++ = "0123456789abcdef"[(c>>36)&0xF];
            *hash++ = "0123456789abcdef"[(c>>40)&0xF];
            *hash++ = "0123456789abcdef"[(c>>44)&0xF];
            *hash++ = "0123456789abcdef"[(c>>48)&0xF];
            *hash++ = "0123456789abcdef"[(c>>52)&0xF];
            *hash++ = "0123456789abcdef"[(c>>56)&0xF];
            *hash++ = "0123456789abcdef"[(c>>60)&0xF];
            #endif
        }

        *hash = '\0';

        result(ref);
    }

    // Return md5 hash
    void cs_md5(const char *str)
    {
        std::string stdhash;
        string hash;

        // used hashlib2plus examples
        // creating a wrapper object
        hashwrapper *myWrapper = new md5wrapper();

        // create a hash from a string
        stdhash = myWrapper->getHashFromString(str);

        // free memory
        delete myWrapper;

        // convert std::string to string
        strcpy (hash, stdhash.c_str());

        result(hash);
    }

    // Return SHA-1 160 bit hash
    void cs_sha1(const char *str)
    {
        std::string stdhash;
        string hash;

        hashwrapper *myWrapper = new sha1wrapper();
        stdhash = myWrapper->getHashFromString(str);
        delete myWrapper;

        strcpy (hash, stdhash.c_str());
        result(hash);
    }

    // Return SHA-2 256 bit hash
    void cs_sha256(const char *str)
    {
        std::string stdhash;
        string hash;

        hashwrapper *myWrapper = new sha256wrapper();
        stdhash = myWrapper->getHashFromString(str);
        delete myWrapper;

        strcpy (hash, stdhash.c_str());
        result(hash);
    }

    // Return SHA-2 384 bit hash
    void cs_sha384(const char *str)
    {
        std::string stdhash;
        string hash;

        hashwrapper *myWrapper = new sha384wrapper();
        stdhash = myWrapper->getHashFromString(str);
        delete myWrapper;

        strcpy (hash, stdhash.c_str());
        result(hash);
    }

    // Return SHA-2 512 bit hash
    void cs_sha512(const char *str)
    {
        std::string stdhash;
        string hash;

        hashwrapper *myWrapper = new sha512wrapper();
        stdhash = myWrapper->getHashFromString(str);
        delete myWrapper;

        strcpy (hash, stdhash.c_str());
        result(hash);
    }

    /**
    * Calculate the tiger192 hash of a string
    * @group crypto
    * @arg1 string
    * @return returns tiger192 hash of string
    * @example echo (tiger192 "test") // 8d1fd829fc83b37af1e5ba697ce8680d1d8bc430d76682f1
    */
    COMMANDN(tiger192, cs_tiger192, "s");

    /**
    * Calculate the md5 hash of a string
    * @group crypto
    * @arg1 string
    * @return returns md5 hash of string
    * @example echo (md5 "test") // 098f6bcd4621d373cade4e832627b4f6
    */
    COMMANDN(md5, cs_md5, "s");

    /**
    * Calculate the sha1 hash of a string
    * @group crypto
    * @arg1 string
    * @return returns sha1 hash of string
    * @example echo (sha1 "test") // a94a8fe5ccb19ba61c4c0873d391e987982fbbd3
    */
    COMMANDN(sha1, cs_sha1, "s");

    /**
    * Calculate the sha256 hash of a string
    * @group crypto
    * @arg1 string
    * @return returns sha256 hash of string
    * @example echo (sha256 "test") // 9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08
    */
    COMMANDN(sha256, cs_sha256, "s");

    /**
    * Calculate the sha384 hash of a string
    * @group crypto
    * @arg1 string
    * @return returns sha384 hash of string
    * @example echo (sha384 "test") // 768412320f7b0aa5812fce428dc4706b3cae50e02a64caa16a782249bfe8efc4b7ef1ccb126255d196047dfedf17a0a9
    */
    COMMANDN(sha384, cs_sha384, "s");

    /**
    * Calculate the sha512 hash of a string
    * @group crypto
    * @arg1 string
    * @return returns sha512 hash of string
    * @example echo (sha512 "test") // ee26b0dd4af7e749aa1a8ee3c10ae9923f618980772e473f8819a5d4940e0db27ac185f8a0e1d5f84f88bc887fd67b143732c304cc5fa9ad8e6f57f50028a8ff
    */
    COMMANDN(sha512, cs_sha512, "s");
}
