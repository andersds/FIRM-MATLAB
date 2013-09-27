/* Include files */

#include "blascompat32.h"
#include "asbswarm_lib_sfun.h"
#include "c2_asbswarm_lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "asbswarm_lib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_b_dim                       (1.0)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[6] = { "dim", "nargin", "nargout", "u",
  "Val", "Idx" };

/* Function Declarations */
static void initialize_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance);
static void initialize_params_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance);
static void enable_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance);
static void disable_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_asbswarm_lib
  (SFc2_asbswarm_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_asbswarm_lib
  (SFc2_asbswarm_libInstanceStruct *chartInstance);
static void set_sim_state_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance);
static void sf_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct *chartInstance);
static void initSimStructsc2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct *chartInstance,
  const mxArray *c2_Idx, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_eml_extremum(SFc2_asbswarm_libInstanceStruct *chartInstance,
  real_T c2_x[6], real_T c2_extremum[3], int32_T c2_indx[3]);
static void c2_eml_int_forloop_overflow_check(SFc2_asbswarm_libInstanceStruct
  *chartInstance);
static void c2_b_eml_int_forloop_overflow_check(SFc2_asbswarm_libInstanceStruct *
  chartInstance, int32_T c2_a, int32_T c2_b);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_asbswarm_lib, const char_T
  *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_asbswarm_libInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_asbswarm_lib = 0U;
}

static void initialize_params_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance)
{
  real_T c2_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'dim' in the parent workspace.\n");
  sf_mex_import_named("dim", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_dim = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_asbswarm_lib
  (SFc2_asbswarm_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_asbswarm_lib
  (SFc2_asbswarm_libInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[3];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[3];
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T (*c2_Val)[3];
  real_T (*c2_Idx)[3];
  c2_Idx = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Val = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3), FALSE);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_u[c2_i0] = (*c2_Idx)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_Val)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_asbswarm_lib;
  c2_c_u = c2_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i2;
  real_T c2_dv1[3];
  int32_T c2_i3;
  real_T (*c2_Val)[3];
  real_T (*c2_Idx)[3];
  c2_Idx = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Val = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "Idx",
                      c2_dv0);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    (*c2_Idx)[c2_i2] = c2_dv0[c2_i2];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "Val",
                      c2_dv1);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    (*c2_Val)[c2_i3] = c2_dv1[c2_i3];
  }

  chartInstance->c2_is_active_c2_asbswarm_lib = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_asbswarm_lib");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_asbswarm_lib(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance)
{
}

static void sf_c2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct *chartInstance)
{
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  real_T c2_u[6];
  uint32_T c2_debug_family_var_map[6];
  real_T c2_c_dim;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 2.0;
  real_T c2_Val[3];
  real_T c2_Idx[3];
  int32_T c2_i8;
  real_T c2_varargin_1[6];
  int32_T c2_i9;
  real_T c2_b_varargin_1[6];
  int32_T c2_iindx[3];
  real_T c2_extremum[3];
  int32_T c2_i10;
  real_T c2_indx[3];
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  real_T (*c2_b_Idx)[3];
  real_T (*c2_b_Val)[3];
  real_T (*c2_b_u)[6];
  c2_b_Idx = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_Val = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 6; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_u)[c2_i4], 0U);
  }

  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_Val)[c2_i5], 1U);
  }

  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_Idx)[c2_i6], 2U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c2_dim, 3U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i7 = 0; c2_i7 < 6; c2_i7++) {
    c2_u[c2_i7] = (*c2_b_u)[c2_i7];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_c_dim, 0U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 2U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_u, 3U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_Val, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Idx, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  c2_c_dim = c2_b_dim;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i8 = 0; c2_i8 < 6; c2_i8++) {
    c2_varargin_1[c2_i8] = c2_u[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 6; c2_i9++) {
    c2_b_varargin_1[c2_i9] = c2_varargin_1[c2_i9];
  }

  c2_eml_extremum(chartInstance, c2_b_varargin_1, c2_extremum, c2_iindx);
  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_indx[c2_i10] = (real_T)c2_iindx[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_Val[c2_i11] = c2_extremum[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
    c2_Idx[c2_i12] = c2_indx[c2_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    (*c2_b_Val)[c2_i13] = c2_Val[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    (*c2_b_Idx)[c2_i14] = c2_Idx[c2_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_asbswarm_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_asbswarm_lib(SFc2_asbswarm_libInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i15;
  real_T c2_b_inData[3];
  int32_T c2_i16;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_asbswarm_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbswarm_libInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i15 = 0; c2_i15 < 3; c2_i15++) {
    c2_b_inData[c2_i15] = (*(real_T (*)[3])c2_inData)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    c2_u[c2_i16] = c2_b_inData[c2_i16];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct *chartInstance,
  const mxArray *c2_Idx, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Idx), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Idx);
}

static void c2_b_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv2[3];
  int32_T c2_i17;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
    c2_y[c2_i17] = c2_dv2[c2_i17];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Idx;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i18;
  SFc2_asbswarm_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbswarm_libInstanceStruct *)chartInstanceVoid;
  c2_Idx = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Idx), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Idx);
  for (c2_i18 = 0; c2_i18 < 3; c2_i18++) {
    (*(real_T (*)[3])c2_outData)[c2_i18] = c2_y[c2_i18];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  real_T c2_b_inData[6];
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_asbswarm_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbswarm_libInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i19 = 0;
  for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
    for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
      c2_b_inData[c2_i21 + c2_i19] = (*(real_T (*)[6])c2_inData)[c2_i21 + c2_i19];
    }

    c2_i19 += 2;
  }

  c2_i22 = 0;
  for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
    for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
      c2_u[c2_i24 + c2_i22] = c2_b_inData[c2_i24 + c2_i22];
    }

    c2_i22 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_asbswarm_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbswarm_libInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_asbswarm_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbswarm_libInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_asbswarm_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static void c2_eml_extremum(SFc2_asbswarm_libInstanceStruct *chartInstance,
  real_T c2_x[6], real_T c2_extremum[3], int32_T c2_indx[3])
{
  int32_T c2_i25;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_i;
  int32_T c2_a;
  int32_T c2_ixstart;
  int32_T c2_b_a;
  int32_T c2_ixstop;
  real_T c2_mtmp;
  int32_T c2_itmp;
  int32_T c2_cindx;
  real_T c2_b_x;
  boolean_T c2_b;
  int32_T c2_c_a;
  int32_T c2_i26;
  int32_T c2_b_ix;
  int32_T c2_c_ix;
  int32_T c2_d_a;
  real_T c2_c_x;
  boolean_T c2_b_b;
  int32_T c2_e_a;
  int32_T c2_i27;
  int32_T c2_d_ix;
  int32_T c2_f_a;
  real_T c2_g_a;
  real_T c2_c_b;
  boolean_T c2_p;
  real_T c2_b_mtmp;
  int32_T c2_b_itmp;
  int32_T c2_h_a;
  int32_T c2_i_a;
  boolean_T exitg1;
  for (c2_i25 = 0; c2_i25 < 3; c2_i25++) {
    c2_indx[c2_i25] = 1;
  }

  c2_ix = 0;
  c2_iy = 0;
  c2_eml_int_forloop_overflow_check(chartInstance);
  for (c2_i = 1; c2_i < 4; c2_i++) {
    c2_a = c2_ix + 1;
    c2_ix = c2_a;
    c2_ixstart = c2_ix;
    c2_b_a = c2_ixstart + 1;
    c2_ixstop = c2_b_a;
    c2_mtmp = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c2_ixstart), 1, 6, 1, 0) - 1];
    c2_itmp = 1;
    c2_cindx = 1;
    c2_b_x = c2_mtmp;
    c2_b = muDoubleScalarIsNaN(c2_b_x);
    if (c2_b) {
      c2_c_a = c2_ixstart + 1;
      c2_i26 = c2_c_a;
      c2_b_eml_int_forloop_overflow_check(chartInstance, c2_i26, c2_ixstop);
      c2_b_ix = c2_i26;
      exitg1 = FALSE;
      while ((exitg1 == 0U) && (c2_b_ix <= c2_ixstop)) {
        c2_c_ix = c2_b_ix;
        c2_d_a = c2_cindx + 1;
        c2_cindx = c2_d_a;
        c2_ixstart = c2_c_ix;
        c2_c_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_c_ix), 1, 6, 1, 0) - 1];
        c2_b_b = muDoubleScalarIsNaN(c2_c_x);
        if (!c2_b_b) {
          c2_mtmp = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_c_ix), 1, 6, 1, 0) - 1];
          exitg1 = TRUE;
        } else {
          c2_b_ix++;
        }
      }
    }

    if (c2_ixstart < c2_ixstop) {
      c2_e_a = c2_ixstart + 1;
      c2_i27 = c2_e_a;
      c2_b_eml_int_forloop_overflow_check(chartInstance, c2_i27, c2_ixstop);
      for (c2_d_ix = c2_i27; c2_d_ix <= c2_ixstop; c2_d_ix++) {
        c2_c_ix = c2_d_ix;
        c2_f_a = c2_cindx + 1;
        c2_cindx = c2_f_a;
        c2_g_a = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_c_ix), 1, 6, 1, 0) - 1];
        c2_c_b = c2_mtmp;
        c2_p = (c2_g_a < c2_c_b);
        if (c2_p) {
          c2_mtmp = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_c_ix), 1, 6, 1, 0) - 1];
          c2_itmp = c2_cindx;
        }
      }
    }

    c2_b_mtmp = c2_mtmp;
    c2_b_itmp = c2_itmp;
    c2_h_a = c2_iy + 1;
    c2_iy = c2_h_a;
    c2_extremum[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_iy), 1, 3, 1, 0) - 1] = c2_b_mtmp;
    c2_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_iy), 1, 3, 1, 0) - 1] = c2_b_itmp;
    c2_i_a = c2_ix + 1;
    c2_ix = c2_i_a;
  }
}

static void c2_eml_int_forloop_overflow_check(SFc2_asbswarm_libInstanceStruct
  *chartInstance)
{
}

static void c2_b_eml_int_forloop_overflow_check(SFc2_asbswarm_libInstanceStruct *
  chartInstance, int32_T c2_a, int32_T c2_b)
{
  int32_T c2_b_a;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  boolean_T c2_safe;
  int32_T c2_i28;
  static char_T c2_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i29;
  static char_T c2_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_b_a = c2_a;
  c2_b_b = c2_b;
  if (c2_b_a > c2_b_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  c2_safe = !c2_overflow;
  if (c2_safe) {
  } else {
    for (c2_i28 = 0; c2_i28 < 34; c2_i28++) {
      c2_u[c2_i28] = c2_cv0[c2_i28];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i29 = 0; c2_i29 < 5; c2_i29++) {
      c2_b_u[c2_i29] = c2_cv1[c2_i29];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_asbswarm_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbswarm_libInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i30;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i30, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i30;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_asbswarm_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbswarm_libInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_asbswarm_lib, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_asbswarm_lib), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_asbswarm_lib);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_asbswarm_libInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_asbswarm_libInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_asbswarm_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4033332720U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1824062296U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1960234416U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3888942696U);
}

mxArray *sf_c2_asbswarm_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("C8lqL6520iSXAf0Y4BWhwG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_asbswarm_lib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"Idx\",},{M[1],M[5],T\"Val\",},{M[8],M[0],T\"is_active_c2_asbswarm_lib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_asbswarm_lib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_asbswarm_libInstanceStruct *chartInstance;
    chartInstance = (SFc2_asbswarm_libInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_asbswarm_libMachineNumber_,
           2,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_asbswarm_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_asbswarm_libMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_asbswarm_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Val");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Idx");
          _SFD_SET_DATA_PROPS(3,10,0,0,"dim");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,128);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          real_T (*c2_u)[6];
          real_T (*c2_Val)[3];
          real_T (*c2_Idx)[3];
          c2_Idx = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_Val = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_Val);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_Idx);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_dim);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_asbswarm_libMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "fggKhge2anNt9sByeLL1wF";
}

static void sf_opaque_initialize_c2_asbswarm_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_asbswarm_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_asbswarm_lib((SFc2_asbswarm_libInstanceStruct*)
    chartInstanceVar);
  initialize_c2_asbswarm_lib((SFc2_asbswarm_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_asbswarm_lib(void *chartInstanceVar)
{
  enable_c2_asbswarm_lib((SFc2_asbswarm_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_asbswarm_lib(void *chartInstanceVar)
{
  disable_c2_asbswarm_lib((SFc2_asbswarm_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_asbswarm_lib(void *chartInstanceVar)
{
  sf_c2_asbswarm_lib((SFc2_asbswarm_libInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_asbswarm_lib(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_asbswarm_lib
    ((SFc2_asbswarm_libInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_asbswarm_lib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_asbswarm_lib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_asbswarm_lib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_asbswarm_lib((SFc2_asbswarm_libInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_asbswarm_lib(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_asbswarm_lib(S);
}

static void sf_opaque_set_sim_state_c2_asbswarm_lib(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c2_asbswarm_lib(S, st);
}

static void sf_opaque_terminate_c2_asbswarm_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_asbswarm_libInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_asbswarm_lib((SFc2_asbswarm_libInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_asbswarm_lib_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_asbswarm_lib((SFc2_asbswarm_libInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_asbswarm_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_asbswarm_lib((SFc2_asbswarm_libInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_asbswarm_lib(SimStruct *S)
{
  /* Actual parameters from chart:
     dim
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for dim*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_asbswarm_lib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(814781037U));
  ssSetChecksum1(S,(2436183175U));
  ssSetChecksum2(S,(936075691U));
  ssSetChecksum3(S,(227691671U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_asbswarm_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_asbswarm_lib(SimStruct *S)
{
  SFc2_asbswarm_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbswarm_libInstanceStruct *)malloc(sizeof
    (SFc2_asbswarm_libInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_asbswarm_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_asbswarm_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_asbswarm_lib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_asbswarm_lib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_asbswarm_lib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_asbswarm_lib;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_asbswarm_lib;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_asbswarm_lib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_asbswarm_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_asbswarm_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_asbswarm_lib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_asbswarm_lib;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_asbswarm_lib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_asbswarm_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_asbswarm_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_asbswarm_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_asbswarm_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}