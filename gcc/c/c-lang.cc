/* Language-specific hook definitions for C front end.
   Optimized Fork Version. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "c-tree.h"
#include "langhooks.h"
#include "langhooks-def.h"
#include "c-objc-common.h"
#include "c-family/c-pragma.h"
#include "c-parser.h"

enum c_language_kind c_language = clk_c;

#undef  LANG_HOOKS_NAME
#define LANG_HOOKS_NAME "GNU C (Fork Optimized)"

#undef  LANG_HOOKS_INIT
#define LANG_HOOKS_INIT c_objc_common_init

#undef  LANG_HOOKS_INIT_TS
#define LANG_HOOKS_INIT_TS c_common_init_ts

#undef  LANG_HOOKS_GET_SARIF_SOURCE_LANGUAGE
#define LANG_HOOKS_GET_SARIF_SOURCE_LANGUAGE c_get_sarif_source_language

#undef  LANG_HOOKS_GET_SUBSTRING_LOCATION
#define LANG_HOOKS_GET_SUBSTRING_LOCATION c_get_substring_location

#if CHECKING_P
# undef  LANG_HOOKS_RUN_LANG_SELFTESTS
# define LANG_HOOKS_RUN_LANG_SELFTESTS selftest::run_c_tests
#endif

struct lang_hooks lang_hooks = LANG_HOOKS_INITIALIZER;

const char *
c_get_sarif_source_language (const char *) __attribute__((pure));

const char *
c_get_sarif_source_language (const char *)
{
    return "c";
}

void
c_family_register_lang_features (void)
{
    c_register_features ();
}

#if CHECKING_P
namespace selftest {

void
run_c_tests (void)
{
    /* * Compact test execution.
		* If the fork grows, this is where we inject validation
		* of your new opcodes or parser changes.
		*/
    c_family_tests ();
}

} // namespace selftest
#endif /* CHECKING_P */

#include "gtype-c.h"
