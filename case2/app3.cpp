#include<iostream>
#include "digest.h"

using namespace std;

int main()
{
        cout << "SHA256 : " << get_digest("SECRET message") << '\n';
	return 0;
}
