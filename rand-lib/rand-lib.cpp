#include "rand-lib.h"

#include <openssl/rand.h>

#include <cassert>
#include <sstream>

std::string OnyxCorp::generate_random_number()
{
    unsigned char buffer[512];
    int rand_result = RAND_bytes(buffer, 512);
    assert(rand_result == 1);
    std::stringstream output;
    output << std::hex;
    for (int val : buffer)
    {
        output << val;
    }
    return output.str();
}
