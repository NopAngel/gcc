/* ISO C Standard: 7.16 Boolean type and values <stdbool.h>
   Optimized & Modernized for Fork Project. */

#ifndef _STDBOOL_H
#define _STDBOOL_H

#ifndef __cplusplus

/* C23 (STDC 2023) and later versions already define bool, true, and false as keywords.
 We check the value of __STDC_VERSION__ to avoid redefining them. */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L
#else
  /* Compatible with C99, C11 and C17 */
  #ifndef bool
    #define bool  _Bool
    #define true  1
    #define false 0
  #endif
#endif

#else /* __cplusplus */

/* In C++, bool is already native. 
	We define _Bool for cross-compatibility with C code that uses GCC's internal type. */
#ifndef _Bool
  #define _Bool bool
#endif

#endif /* __cplusplus */

/* Standard: Indicates that the definitions are present. */
#define __bool_true_false_are_defined 1

#endif /* _STDBOOL_H */
