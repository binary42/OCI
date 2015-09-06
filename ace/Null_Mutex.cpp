/**
 * @file Null_Mutex.cpp
 *
 * $Id: Null_Mutex.cpp 2622 2015-08-13 18:30:00Z mitza $
 *
 * @author Justin Wilson <wilsonj@ociweb.com>
 */

#include "ace/Null_Mutex.h"

#if defined (ACE_HAS_ALLOC_HOOKS)
# include "ace/Malloc_Base.h"
#endif /* ACE_HAS_ALLOC_HOOKS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Null_Mutex)

ACE_END_VERSIONED_NAMESPACE_DECL
