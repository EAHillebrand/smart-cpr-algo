/* Include files */

#include "top_level_algo_cgxe.h"
#include "m_2GpPLsa2NpR4LFOrvnLIcE.h"

unsigned int cgxe_top_level_algo_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 1433114769 &&
      ssGetChecksum1(S) == 1530178702 &&
      ssGetChecksum2(S) == 1055042332 &&
      ssGetChecksum3(S) == 287638129) {
    method_dispatcher_2GpPLsa2NpR4LFOrvnLIcE(S, method, data);
    return 1;
  }

  return 0;
}
