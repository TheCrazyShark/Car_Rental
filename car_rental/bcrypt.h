/********************
    This is a header file for bcrypt, which is a slow hashing algorithm
    We would be using this for our hashing function
********************/

#ifndef BCRYPT_H
#define BCRYPT_H
//#define BCRYPT_HASHSIZE(64)
#include<string>

using namespace std;
namespace bcrypt {
    string GenerateHash(string& password, unsigned rounds=12);
}

#endif
