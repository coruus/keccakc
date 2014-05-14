# Utils

Header files named `".*-impl.h"` contain static inline helper utilities.
They must be included in each file that uses them because `static` can
only be used for functions at file scope. `static inline` provokes modern
optimizing compilers into producing specialized and efficient machine code.
