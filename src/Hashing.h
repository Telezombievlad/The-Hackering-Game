#ifndef CRACKME_HASHING
#define CRACKME_HASHING

#include "md5.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>

int hashPasses = 0;

uint64_t hashPass(uint8_t* toEncrypt, uint64_t toEncryptLen, uint8_t* trueHash)
{
	assert(toEncrypt);
	assert(trueHash);

	uint8_t result[16];

	MD5_CTX mdContext;
	MD5_Init (&mdContext);
	MD5_Update(&mdContext, toEncrypt, toEncryptLen);
	MD5_Final(result, &mdContext);

	for (unsigned i = 0; i < 16; ++i)
	{
		if (result[i] != trueHash[i]) return 0;
	}

	++hashPasses;

	return 1;
}

const uint8_t* salt = "1_aL>X~?";
const uint64_t SALT_SIZE = 8;

uint64_t hashPassSalty(uint8_t* toEncrypt, uint64_t toEncryptLen, uint8_t* trueHash)
{
	assert(toEncrypt);
	assert(trueHash);

	uint8_t* saltyToEncrypt = (uint8_t*) calloc(toEncryptLen + SALT_SIZE, sizeof(*saltyToEncrypt));
	assert(saltyToEncrypt);

	memcpy(saltyToEncrypt,                toEncrypt, toEncryptLen);
	memcpy(saltyToEncrypt + toEncryptLen, salt,      SALT_SIZE   );

	uint8_t result[16];

	MD5_CTX mdContext;
	MD5_Init (&mdContext);
	MD5_Update(&mdContext, saltyToEncrypt, toEncryptLen + SALT_SIZE);
	MD5_Final(result, &mdContext);

	for (unsigned i = 0; i < 16; ++i)
	{
		if (result[i] != trueHash[i]) return 0;
	}

	return 1;
}


#endif  // CRACKME_HASHING