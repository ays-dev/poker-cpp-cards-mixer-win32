#include <iostream>
#include <windows.h>
#include <wincrypt.h>
#include "src/dSFMT.h"

using namespace std;

union ArrayToInteger
{
    uint32_t integer;
    byte array[DSFMT_MEXP];
};

struct Deck
{
    double value;
    int key;
    char name[4];
};


int compare(const void* pi1, const void* pi2)
{
    double i1 = *(double*)pi1;
    double i2 = *(double*)pi2;

    return (i1 < i2) ? -1 : 1;
}

int main()
{
    ArrayToInteger converter;
    HCRYPTPROV hProvider = 0;
    const DWORD dwLength = DSFMT_MEXP;
    BYTE pbBuffer[dwLength] = {};
    int i = 0;
    Deck deck[48];
    char Tableau [48][4]= {"2t","2ca","2co","2p","3t","3ca","3co","3p","4t","4ca","4co","4t","5t","5ca","5co","5p","6t","6ca","6o","6p","7t","7ca","7co","7p","8t","8ca","8co","8p","9t","9ca","9co","9p","Vt","Vca","Vco","Vp","Dt","Dca","Dco","Dp","Rt","Rca","Rco","Rp","At","Aca","Aco","Ap"};

    if (!::CryptAcquireContextW(&hProvider, 0, 0, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_SILENT))
        return 1;

    if (!::CryptGenRandom(hProvider, dwLength, pbBuffer))
    {
        ::CryptReleaseContext(hProvider, 0);
        return 1;
    }


    for(unsigned int i=0; i < sizeof(pbBuffer); i++)
    {
        converter.array[i]=pbBuffer[i];
    }

    init_gen_rand(converter.integer);

    for(i=0; i<48; i++)
    {
        deck[i].name[0] = Tableau[i][0];
        deck[i].name[1] = Tableau[i][1];
        deck[i].name[2] = Tableau[i][2];
        deck[i].name[3] = Tableau[i][3];
        deck[i].value = genrand_close_open();
    }
    qsort(deck, 48, sizeof *deck, compare);
    for(i=0; i<48; i++)
    {
        cout << "Carte: " << deck[i].name << endl;
    }

    if (!::CryptReleaseContext(hProvider, 0))
        return 1;

}

