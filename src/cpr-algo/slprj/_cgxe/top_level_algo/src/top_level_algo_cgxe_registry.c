#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                top_level_algo_cgxe
#include "simstruc.h"
#include "top_level_algo_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_top_level_algo_method_dispatcher(S, SS_CALL_MDL_START, NULL);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }
}

#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlInitializeConditions method directly.\n");
}

#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlUpdate method directly.\n");
}

static void mdlOutputs(SimStruct* S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlOutputs method directly.\n");
}

static void mdlTerminate(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlTerminate method directly.\n");
}

static void mdlInitializeSizes(SimStruct *S)
{
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static mxArray* cgxe_get_supported_modules(void)
{
  mxArray* mxModules = mxCreateCellMatrix(10, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1045570702;
  checksumData[1] = 3444188254;
  checksumData[2] = 1022672671;
  checksumData[3] = 1823433663;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1214982610;
  checksumData[1] = 42111540;
  checksumData[2] = 1340819598;
  checksumData[3] = 929149275;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2003035033;
  checksumData[1] = 73837569;
  checksumData[2] = 2277457727;
  checksumData[3] = 2242818014;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2239718544;
  checksumData[1] = 557490607;
  checksumData[2] = 4124034513;
  checksumData[3] = 213765454;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2853900239;
  checksumData[1] = 2060058737;
  checksumData[2] = 210110441;
  checksumData[3] = 3395256230;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3142323052;
  checksumData[1] = 1537670463;
  checksumData[2] = 3352335916;
  checksumData[3] = 1392836029;
  mxSetCell(mxModules, 5, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3158472342;
  checksumData[1] = 894983615;
  checksumData[2] = 1801793498;
  checksumData[3] = 153307088;
  mxSetCell(mxModules, 6, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3226332344;
  checksumData[1] = 947649504;
  checksumData[2] = 3063166953;
  checksumData[3] = 2567313448;
  mxSetCell(mxModules, 7, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3351036133;
  checksumData[1] = 112290977;
  checksumData[2] = 1455214769;
  checksumData[3] = 2187708879;
  mxSetCell(mxModules, 8, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3994087876;
  checksumData[1] = 934322577;
  checksumData[2] = 1995362955;
  checksumData[3] = 2871285046;
  mxSetCell(mxModules, 9, mxChksum);
  return mxModules;
}

static int cgxe_process_get_checksums(int nlhs, mxArray* plhs[], int nrhs, const
  mxArray* prhs[])
{
  const char* checksumFields[] = { "modules", "model", "makefile", "target",
    "overall" };

  mxArray* mxChecksum = mxCreateStructMatrix(1, 1, 5, checksumFields);
  mxSetField(mxChecksum, 0, "modules", cgxe_get_supported_modules());

  {
    mxArray* mxModelChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxModelChksum);
    checksumData[0] = 766594728;
    checksumData[1] = 455141901;
    checksumData[2] = 1357653381;
    checksumData[3] = 1397361153;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 515039516;
    checksumData[1] = 3380425437;
    checksumData[2] = 3800225128;
    checksumData[3] = 532790914;
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
    checksumData[0] = 2911221907;
    checksumData[1] = 2308967934;
    checksumData[2] = 2419390157;
    checksumData[3] = 1906300239;
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
    checksumData[0] = 3728413085;
    checksumData[1] = 633059693;
    checksumData[2] = 3614021826;
    checksumData[3] = 3908148619;
    mxSetField(mxChecksum, 0, "overall", mxOverallChksum);
  }

  plhs[0] = mxChecksum;
  return 1;
}

static int cgxe_mex_unlock_call(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  while (mexIsLocked()) {
    mexUnlock();
  }

  return 1;
}

static SimStruct* cgxe_unpack_simstruct(const mxArray *mxS)
{
  uint32_T *uintPtr = (uint32_T*)malloc(sizeof(SimStruct*));
  int nEl = sizeof(SimStruct*)/sizeof(uint32_T);
  uint32_T *uintDataPtr = (uint32_T *)mxGetData(mxS);
  int el;
  SimStruct *S;
  for (el=0; el < nEl; el++) {
    uintPtr[el] = uintDataPtr[el];
  }

  memcpy(&S,uintPtr,sizeof(SimStruct*));
  free(uintPtr);
  return S;
}

static int cgxe_get_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_top_level_algo_method_dispatcher(S, SS_CALL_MDL_GET_SIM_STATE,
    (void *) (plhs));
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_set_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_top_level_algo_method_dispatcher(S, SS_CALL_MDL_SET_SIM_STATE,
    (void *) prhs[2]);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_get_BuildInfoUpdate(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "cwNyIKkyC0OdDSJrIGzuBB") == 0) {
    extern mxArray *cgxe_cwNyIKkyC0OdDSJrIGzuBB_BuildInfoUpdate(void);
    plhs[0] = cgxe_cwNyIKkyC0OdDSJrIGzuBB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "dxCR6TiNaP3voJJHbi3NYF") == 0) {
    extern mxArray *cgxe_dxCR6TiNaP3voJJHbi3NYF_BuildInfoUpdate(void);
    plhs[0] = cgxe_dxCR6TiNaP3voJJHbi3NYF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "NazBzNHwlkR43DNJhA8laF") == 0) {
    extern mxArray *cgxe_NazBzNHwlkR43DNJhA8laF_BuildInfoUpdate(void);
    plhs[0] = cgxe_NazBzNHwlkR43DNJhA8laF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "iJDmYSRVZ22ftJv6gOHCc") == 0) {
    extern mxArray *cgxe_iJDmYSRVZ22ftJv6gOHCc_BuildInfoUpdate(void);
    plhs[0] = cgxe_iJDmYSRVZ22ftJv6gOHCc_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "gMMMjlPA30Bjcn0FnG7YkD") == 0) {
    extern mxArray *cgxe_gMMMjlPA30Bjcn0FnG7YkD_BuildInfoUpdate(void);
    plhs[0] = cgxe_gMMMjlPA30Bjcn0FnG7YkD_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "1sy0u1MMYmRxAkQgNuPdNH") == 0) {
    extern mxArray *cgxe_1sy0u1MMYmRxAkQgNuPdNH_BuildInfoUpdate(void);
    plhs[0] = cgxe_1sy0u1MMYmRxAkQgNuPdNH_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "KV6DfIYgmaO3SnMByff32") == 0) {
    extern mxArray *cgxe_KV6DfIYgmaO3SnMByff32_BuildInfoUpdate(void);
    plhs[0] = cgxe_KV6DfIYgmaO3SnMByff32_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "QdJq2kuDrIDch37Jjqw0oF") == 0) {
    extern mxArray *cgxe_QdJq2kuDrIDch37Jjqw0oF_BuildInfoUpdate(void);
    plhs[0] = cgxe_QdJq2kuDrIDch37Jjqw0oF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "4AFu0YWUn0wmiH5SxFX14") == 0) {
    extern mxArray *cgxe_4AFu0YWUn0wmiH5SxFX14_BuildInfoUpdate(void);
    plhs[0] = cgxe_4AFu0YWUn0wmiH5SxFX14_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "tiw4bWAqD5YW2zyv4ESMwG") == 0) {
    extern mxArray *cgxe_tiw4bWAqD5YW2zyv4ESMwG_BuildInfoUpdate(void);
    plhs[0] = cgxe_tiw4bWAqD5YW2zyv4ESMwG_BuildInfoUpdate();
    return 1;
  }

  return 0;
}

static int cgxe_get_fallback_info(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "cwNyIKkyC0OdDSJrIGzuBB") == 0) {
    extern mxArray *cgxe_cwNyIKkyC0OdDSJrIGzuBB_fallback_info(void);
    plhs[0] = cgxe_cwNyIKkyC0OdDSJrIGzuBB_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "dxCR6TiNaP3voJJHbi3NYF") == 0) {
    extern mxArray *cgxe_dxCR6TiNaP3voJJHbi3NYF_fallback_info(void);
    plhs[0] = cgxe_dxCR6TiNaP3voJJHbi3NYF_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "NazBzNHwlkR43DNJhA8laF") == 0) {
    extern mxArray *cgxe_NazBzNHwlkR43DNJhA8laF_fallback_info(void);
    plhs[0] = cgxe_NazBzNHwlkR43DNJhA8laF_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "iJDmYSRVZ22ftJv6gOHCc") == 0) {
    extern mxArray *cgxe_iJDmYSRVZ22ftJv6gOHCc_fallback_info(void);
    plhs[0] = cgxe_iJDmYSRVZ22ftJv6gOHCc_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "gMMMjlPA30Bjcn0FnG7YkD") == 0) {
    extern mxArray *cgxe_gMMMjlPA30Bjcn0FnG7YkD_fallback_info(void);
    plhs[0] = cgxe_gMMMjlPA30Bjcn0FnG7YkD_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "1sy0u1MMYmRxAkQgNuPdNH") == 0) {
    extern mxArray *cgxe_1sy0u1MMYmRxAkQgNuPdNH_fallback_info(void);
    plhs[0] = cgxe_1sy0u1MMYmRxAkQgNuPdNH_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "KV6DfIYgmaO3SnMByff32") == 0) {
    extern mxArray *cgxe_KV6DfIYgmaO3SnMByff32_fallback_info(void);
    plhs[0] = cgxe_KV6DfIYgmaO3SnMByff32_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "QdJq2kuDrIDch37Jjqw0oF") == 0) {
    extern mxArray *cgxe_QdJq2kuDrIDch37Jjqw0oF_fallback_info(void);
    plhs[0] = cgxe_QdJq2kuDrIDch37Jjqw0oF_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "4AFu0YWUn0wmiH5SxFX14") == 0) {
    extern mxArray *cgxe_4AFu0YWUn0wmiH5SxFX14_fallback_info(void);
    plhs[0] = cgxe_4AFu0YWUn0wmiH5SxFX14_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "tiw4bWAqD5YW2zyv4ESMwG") == 0) {
    extern mxArray *cgxe_tiw4bWAqD5YW2zyv4ESMwG_fallback_info(void);
    plhs[0] = cgxe_tiw4bWAqD5YW2zyv4ESMwG_fallback_info();
    return 1;
  }

  return 0;
}

#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

static int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray* plhs[], int nrhs,
  const mxArray* prhs[])
{
  char commandName[64];
  if (nrhs < 1 || !mxIsChar(prhs[0]))
    return 0;
  mxGetString(prhs[0], commandName, sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName, "get_checksums") == 0) {
    return cgxe_process_get_checksums(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_unlock") == 0) {
    return cgxe_mex_unlock_call(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_sim_state") == 0) {
    return cgxe_get_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "set_sim_state") == 0) {
    return cgxe_set_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_BuildInfoUpdate") == 0) {
    return cgxe_get_BuildInfoUpdate(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_fallback_info") == 0) {
    return cgxe_get_fallback_info(nlhs, plhs, nrhs, prhs);
  }

  return 0;
}

#include "simulink.c"
