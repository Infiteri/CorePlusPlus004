#pragma once

#include "Core/Base.h"

namespace Dragon
{
    namespace Memo
    {
        void *Allocate(DagU64 size);
        void Free(void *Block);
        void *Copy(void *Block, const void *Source, DagU64 size);
        void *Set(void *Block, DagU32 value, DagU64 size);
        void *Zero(void *Block, DagU64 size);
    };
}

#define DAG_NEW(type) (type *)Dragon::Memo::Allocate(sizeof(type))
#define DAG_DEL(block) Dragon::Memo::Free(block)
