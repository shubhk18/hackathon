# Hackathon - Wrapper Security Library

Some of the cryptographic algorithms are prone to attack and are considered non-safe. MD5- Hashing algorithm is one of them.
Please refer below document which describes MD5 being deprecated in new OpenSSL versions -
https://en.wikipedia.org/wiki/MD5

# Test Evidence -
We have APP1 that generates checksum for a string.

CASE 1- There are two apps - app1 and app2. app1 generated md5 hash as it was using openssl standards.
app2 generated sha1 hash as it had descent security standards.

Now, when both hash values are compared. There was mismatch.

<img width="534" alt="Screenshot 2023-09-14 at 6 01 19 PM" src="https://github.com/shubhk18/hackathon/assets/5305495/0e77c371-3cb6-4b6a-aa79-e15240cfc6d9">


CASE 2-
app3 doesnt have to worry about specifying latest standards. They are already taken care by wrapper code. It will make sure to pick best hashing algorithm SHA256.
app3 user have to just call wrapper APIs defined in digest.h.

<img width="477" alt="Screenshot 2023-09-14 at 5 51 18 PM" src="https://github.com/shubhk18/hackathon/assets/5305495/b761a6c9-3da9-42fe-a426-92aa006a6b0d">

