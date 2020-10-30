#include "MemUtils.h"
#include <cstdlib>
#include <cstring>

ptr_t MemUtils::mallocAndFillInternal(size_t len, int init_val)
{
    ptr_t buf = malloc(len);
    if (!buf) {
        return nullptr;
    }
    memset(buf, init_val, len);
    return buf;
}
