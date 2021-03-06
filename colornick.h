/***************************************************************************
               colornick.h  -  alternative nick spelling support include
                             -------------------
    begin                : Sat Jun 07 2003
    copyright            : (C) 2001-2003 by Alexander Bilichenko
    email                : pricer@mail.ru
 ***************************************************************************/

#ifndef COLORNICK_H_INCLUDED
#define COLORNICK_H_INCLUDED

#include "basetypes.h"
#include <tr1/unordered_map>

#define MAX_REAL_NICK_SIZE        30
#define MAX_ALT_NICK_SIZE        300

class CAltNamesParser {
private:
        int classinit;
        WCFILE *f;
        char ifname[1000];
        std::tr1::unordered_map<DWORD, char*> nmap;
#pragma pack(1)
        typedef struct _AltNamesStruct {
                DWORD uid;
                char rname[MAX_REAL_NICK_SIZE];
                char aname[MAX_ALT_NICK_SIZE];
        } AltNamesStruct, *PAltNamesStruct;
#pragma pack(4)
public:
        CAltNamesParser(const char *fname, bool &init);
        ~CAltNamesParser();

        int AddAltName(DWORD uid, char *name, char *altname);
        int DeleteAltName(DWORD uid);
        int NameToAltName(DWORD uid, char *altname);
};

#endif
