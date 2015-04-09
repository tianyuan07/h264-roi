/*******************************************************************************
**                                  LibChaos                                  **
**                                 zhashable.h                                **
**                          (c) 2015 Zennix Studios                           **
*******************************************************************************/
#ifndef ZHASHABLE
#define ZHASHABLE

#include "ztypes.h"

namespace LibChaos {

class ZHashable {
public:
    virtual zu64 mapHash() const = 0;
};

}

#endif // ZHASHABLE

