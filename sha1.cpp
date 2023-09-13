#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

std::string sha(const std::string &str){
  unsigned char hash[SHA_DIGEST_LENGTH];

  SHA_CTX sha;
  SHA1_Init(&sha);
  SHA1_Update(&sha, str.c_str(), str.size());
  SHA1_Final(hash, &sha);

  std::stringstream ss;

  for(int i = 0; i < SHA_DIGEST_LENGTH; i++){
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>( hash[i] );
  }
  return ss.str();
}

int main() {
  std::cout << sha("Terminal Root") << '\n';
  return 0;
}

