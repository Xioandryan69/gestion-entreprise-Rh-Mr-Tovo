#pragma once

#include "PageRouteur.h"

class Web {
    private:
        PageRouteur& pageRouteur;
    public:
        Web(PageRouteur& pr);
        
        void declarationDesRoutesWeb();
};