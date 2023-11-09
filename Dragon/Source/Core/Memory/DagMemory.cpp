#include "DagMemory.h"
#include "Core/Console.h"

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

namespace Dragon
{
    namespace Memo
    {
        void *Allocate(DagU64 size)
        {
            return malloc(size);
        }

        void Free(void *Block)
        {
            free(Block);
        }

        void *Set(void *Block, DagU32 value, DagU64 size)
        {
            return memset(Block, value, size);
        }

        void *Zero(void *Block, DagU64 size)
        {
            return Set(Block, 0, size);
        }

        void *Copy(void *Block, const void *Source, DagU64 size)
        {
            return memcpy(Block, Source, size);
        }
    }
}