#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include "digest.h"

std::string get_digest(const std::string &str){
  unsigned char hash[SHA_DIGEST_LENGTH];

  SHA256_CTX sha;
  SHA256_Init(&sha);
  SHA256_Update(&sha, str.c_str(), str.size());
  SHA256_Final(hash, &sha);

  std::stringstream ss;

  for(int i = 0; i < SHA_DIGEST_LENGTH; i++){
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>( hash[i] );
  }
  return ss.str();
}


