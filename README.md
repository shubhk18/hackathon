# hackathon

MD5 deprecated-

https://en.wikipedia.org/wiki/MD5

<img width="402" alt="Screenshot 2023-09-13 at 6 59 42 PM" src="https://github.com/shubhk18/hackathon/assets/5305495/629676f2-8db1-4f54-914b-1c9880defb93">

both works-
cmd 1 - 
g++ -c -o digest.o digest.cpp -lcrypto
rcs WrapperLib.a digest.o 
g++ app1.cpp -o app WrapperLib.a
./app 

cmd 2 - trying to link libcrypto statically
g++ -c -o digest.o digest.cpp -l:libcrypto.a 
ar rcs WrapperLib.a digest.o 
g++ app1.cpp -o app WrapperLib.a
  ./app 



