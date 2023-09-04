#include "huffmanCoding.h"

int main(int argc, char const *argv[])
{
    string message = "aabbbbabbbcccdddeeeccceeeddeee";
    string encode = huffmanCode(message);

    cout << encode << "\n";

    return 0;
}