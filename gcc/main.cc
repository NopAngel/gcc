/* main.c: Entry point for the compiler (cc1/cc1plus).
   Modified for high-performance fork execution. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "diagnostic-core.h"
#include "toplev.h"



int
main (int argc, char **argv)
{
  toplev toplev_engine (NULL, true);
  int result = toplev_engine.main (argc, argv);

  if (flag_checking && !seen_error ())
    {
      toplev_engine.finalize ();
    }


  return result;
}
