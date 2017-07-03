/*
 * FingerStrokeAssistance.h
 *
 * Code generation for model "FingerStrokeAssistance".
 *
 * Model version              : 1.1275
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Mon Jul 03 13:01:17 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FingerStrokeAssistance_h_
#define RTW_HEADER_FingerStrokeAssistance_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef FingerStrokeAssistance_COMMON_INCLUDES_
# define FingerStrokeAssistance_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "xpcimports.h"
#endif                                 /* FingerStrokeAssistance_COMMON_INCLUDES_ */

#include "FingerStrokeAssistance_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_FingerStrokeAssistance RT_MODEL_FingerStrokeAssistance_T

/* Definition for use in the target main file */
#define FingerStrokeAssistance_rtModel RT_MODEL_FingerStrokeAssistance_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals for system '<S31>/MATLAB Function' */
typedef struct {
  real_T output1;                      /* '<S31>/MATLAB Function' */
  real_T output2;                      /* '<S31>/MATLAB Function' */
} B_MATLABFunction_FingerStroke_T;

/* Block signals for system '<S43>/gainramp' */
typedef struct {
  real_T val;                          /* '<S43>/gainramp' */
  real_T state1[4];                    /* '<S43>/gainramp' */
} B_gainramp_FingerStrokeAssist_T;

/* Block signals (auto storage) */
typedef struct {
  real_T PCI6221AD1_o1;                /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o2;                /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o3;                /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o4;                /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o5;                /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o6;                /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o7;                /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o8;                /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o9;                /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o10;               /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o11;               /* '<S8>/PCI-6221 AD1' */
  real_T PCI6221AD1_o12;               /* '<S8>/PCI-6221 AD1' */
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<Root>/Data Type Conversion1' */
  real_T DataTypeConversion2;          /* '<Root>/Data Type Conversion2' */
  real_T Delay[2];                     /* '<S1>/Delay' */
  real_T DiscreteFilter1;              /* '<S1>/Discrete Filter1' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T Damping;                      /* '<S1>/Damping' */
  real_T Delay1;                       /* '<S1>/Delay1' */
  real_T Uk1;                          /* '<S14>/Delay Input1' */
  real_T DataTypeConversion_p;         /* '<S1>/Data Type Conversion' */
  real_T DiscreteTimeIntegrator;       /* '<S1>/Discrete-Time Integrator' */
  real_T UnitDelay;                    /* '<Root>/Unit Delay' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  real_T UnitDelay2;                   /* '<S9>/Unit Delay2' */
  real_T Uk1_o;                        /* '<S41>/Delay Input1' */
  real_T DataTypeConversion_o;         /* '<S9>/Data Type Conversion' */
  real_T DiscreteTimeIntegrator_e;     /* '<S9>/Discrete-Time Integrator' */
  real_T UnitDelay3[2];                /* '<Root>/Unit Delay3' */
  real_T UnitDelay2_p[2];              /* '<Root>/Unit Delay2' */
  real_T UnitDelay2_j;                 /* '<S10>/Unit Delay2' */
  real_T Uk1_m;                        /* '<S42>/Delay Input1' */
  real_T DataTypeConversion_a;         /* '<S10>/Data Type Conversion' */
  real_T DiscreteTimeIntegrator_k;     /* '<S10>/Discrete-Time Integrator' */
  real_T PCI6221ENC;                   /* '<S8>/PCI 6221 ENC ' */
  real_T PCI6221ENC1;                  /* '<S8>/PCI 6221 ENC 1' */
  real_T parLeftMode;                  /* '<S12>/parLeftMode' */
  real_T Saturation;                   /* '<S12>/Saturation' */
  real_T Gain[2];                      /* '<S8>/Gain' */
  real_T UnitDelay_g[2];               /* '<S8>/Unit Delay' */
  real_T Sum[2];                       /* '<S8>/Sum' */
  real_T UnitDelay1;                   /* '<Root>/Unit Delay1' */
  real_T UnitDelay1_n;                 /* '<S8>/Unit Delay1' */
  real_T Sum1;                         /* '<S3>/Sum1' */
  real_T Switch[2];                    /* '<S17>/Switch' */
  real_T Switch2[2];                   /* '<S17>/Switch2' */
  real_T Gain_d;                       /* '<S2>/Gain' */
  real_T Switch_g[2];                  /* '<S16>/Switch' */
  real_T Switch2_d[2];                 /* '<S16>/Switch2' */
  real_T Sum_h[2];                     /* '<S3>/Sum' */
  real_T DerivativeGain[2];            /* '<S15>/Derivative Gain' */
  real_T Filter[2];                    /* '<S15>/Filter' */
  real_T SumD[2];                      /* '<S15>/SumD' */
  real_T FilterCoefficient[2];         /* '<S15>/Filter Coefficient' */
  real_T IntegralGain[2];              /* '<S15>/Integral Gain' */
  real_T Integrator[2];                /* '<S15>/Integrator' */
  real_T ProportionalGain[2];          /* '<S15>/Proportional Gain' */
  real_T Sum_a[2];                     /* '<S15>/Sum' */
  real_T TSamp[2];                     /* '<S18>/TSamp' */
  real_T Uk1_d[2];                     /* '<S18>/UD' */
  real_T Diff[2];                      /* '<S18>/Diff' */
  real_T DiscreteFilter1_j[2];         /* '<S8>/Discrete Filter1' */
  real_T Gain1_l;                      /* '<S8>/Gain1' */
  real_T Switch_n[2];                  /* '<S28>/Switch' */
  real_T Switch2_l[2];                 /* '<S28>/Switch2' */
  real_T LowPass100Hz;                 /* '<S35>/Low Pass 100 Hz' */
  real_T LowPass100Hz1;                /* '<S35>/Low Pass 100 Hz1' */
  real_T Memory;                       /* '<S35>/Memory' */
  real_T Memory1;                      /* '<S35>/Memory1' */
  real_T UnitDelay1_g;                 /* '<S9>/Unit Delay1' */
  real_T UnitDelay1_d;                 /* '<S10>/Unit Delay1' */
  real_T parTrajMode;                  /* '<S12>/parTrajMode' */
  real_T RoundingFunction;             /* '<S12>/Rounding Function' */
  real_T Saturation1;                  /* '<S12>/Saturation1' */
  real_T parFixedDur;                  /* '<S12>/parFixedDur' */
  real_T Saturation2;                  /* '<S12>/Saturation2' */
  real_T Memory_g[4];                  /* '<S43>/Memory' */
  real_T parChangeRate;                /* '<S12>/parChangeRate' */
  real_T parKp1;                       /* '<S12>/parKp1' */
  real_T Memory_i[4];                  /* '<S44>/Memory' */
  real_T parKp2;                       /* '<S12>/parKp2' */
  real_T Memory_e[4];                  /* '<S45>/Memory' */
  real_T parKd1;                       /* '<S12>/parKd1' */
  real_T Memory_o[4];                  /* '<S46>/Memory' */
  real_T parKd2;                       /* '<S12>/parKd2' */
  real_T Memory_n[4];                  /* '<S47>/Memory' */
  real_T parKdV1;                      /* '<S12>/parKdV1' */
  real_T Memory_os[4];                 /* '<S48>/Memory' */
  real_T parKdV2;                      /* '<S12>/parKdV2' */
  real_T parFThresh;                   /* '<S12>/parFThresh' */
  real_T parForceTrigger;              /* '<S12>/parForceTrigger' */
  real_T parMarker;                    /* '<S12>/parMarker' */
  real_T parMaxTrajDur;                /* '<S12>/parMaxTrajDur' */
  real_T parPStop;                     /* '<S12>/parPStop' */
  real_T parVThresh;                   /* '<S12>/parVThresh' */
  real_T parWiggleAmp;                 /* '<S12>/parWiggleAmp' */
  real_T Gain2;                        /* '<S13>/Gain2' */
  real_T Gain_f[2];                    /* '<S13>/Gain' */
  real_T In1;                          /* '<S30>/In1' */
  real_T In1_g[2];                     /* '<S29>/In1' */
  real_T y_acc;                        /* '<S8>/MATLAB Function8' */
  real_T x_acc;                        /* '<S8>/MATLAB Function7' */
  real_T Z_acc;                        /* '<S8>/MATLAB Function6' */
  real_T Raw_avg_Z_acc;                /* '<S8>/MATLAB Function5' */
  real_T Raw_avg_x_acc;                /* '<S8>/MATLAB Function4' */
  real_T Raw_Average_Grip_Force;       /* '<S8>/MATLAB Function3' */
  real_T Raw_avg_y_acc;                /* '<S8>/MATLAB Function2' */
  real_T Pressure;                     /* '<S8>/MATLAB Function1' */
  real_T GripForce;                    /* '<S8>/MATLAB Function' */
  real_T state;                        /* '<Root>/MATLAB Function' */
  real_T f_ref[2];                     /* '<Root>/MATLAB Function' */
  real_T ramp_switch;                  /* '<Root>/MATLAB Function' */
  real_T fp_ramp_switch;               /* '<Root>/MATLAB Function' */
  real_T f_ref_lim;                    /* '<Root>/MATLAB Function' */
  real_T enc_trigger;                  /* '<Root>/MATLAB Function' */
  real_T p_trigger;                    /* '<Root>/MATLAB Function' */
  real_T pos_ref[2];                   /* '<Root>/MATLAB Function' */
  real_T pos_ref_Ulim;                 /* '<Root>/MATLAB Function' */
  real_T pos_ref_Llim;                 /* '<Root>/MATLAB Function' */
  boolean_T FixPtRelationalOperator;   /* '<S14>/FixPt Relational Operator' */
  boolean_T FixPtRelationalOperator_i; /* '<S41>/FixPt Relational Operator' */
  boolean_T FixPtRelationalOperator_f; /* '<S42>/FixPt Relational Operator' */
  boolean_T LowerRelop1[2];            /* '<S17>/LowerRelop1' */
  boolean_T UpperRelop[2];             /* '<S17>/UpperRelop' */
  boolean_T LowerRelop1_f[2];          /* '<S16>/LowerRelop1' */
  boolean_T UpperRelop_o[2];           /* '<S16>/UpperRelop' */
  boolean_T LowerRelop1_p[2];          /* '<S28>/LowerRelop1' */
  boolean_T UpperRelop_l[2];           /* '<S28>/UpperRelop' */
  B_gainramp_FingerStrokeAssist_T sf_gainramp_a;/* '<S48>/gainramp' */
  B_gainramp_FingerStrokeAssist_T sf_gainramp_f;/* '<S47>/gainramp' */
  B_gainramp_FingerStrokeAssist_T sf_gainramp_b;/* '<S46>/gainramp' */
  B_gainramp_FingerStrokeAssist_T sf_gainramp_id;/* '<S45>/gainramp' */
  B_gainramp_FingerStrokeAssist_T sf_gainramp_i;/* '<S44>/gainramp' */
  B_gainramp_FingerStrokeAssist_T sf_gainramp;/* '<S43>/gainramp' */
  B_MATLABFunction_FingerStroke_T sf_MATLABFunction_e;/* '<S33>/MATLAB Function' */
  B_MATLABFunction_FingerStroke_T sf_MATLABFunction_m;/* '<S31>/MATLAB Function' */
} B_FingerStrokeAssistance_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[2];              /* '<S1>/Delay' */
  real_T DiscreteFilter1_states;       /* '<S1>/Discrete Filter1' */
  real_T Delay1_DSTATE;                /* '<S1>/Delay1' */
  real_T DelayInput1_DSTATE;           /* '<S14>/Delay Input1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay2_DSTATE;            /* '<S9>/Unit Delay2' */
  real_T DelayInput1_DSTATE_l;         /* '<S41>/Delay Input1' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S9>/Discrete-Time Integrator' */
  real_T UnitDelay3_DSTATE[2];         /* '<Root>/Unit Delay3' */
  real_T UnitDelay2_DSTATE_f[2];       /* '<Root>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_h;          /* '<S10>/Unit Delay2' */
  real_T DelayInput1_DSTATE_j;         /* '<S42>/Delay Input1' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S10>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_h[2];        /* '<S8>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<Root>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_n;          /* '<S8>/Unit Delay1' */
  real_T Filter_DSTATE[2];             /* '<S15>/Filter' */
  real_T Integrator_DSTATE[2];         /* '<S15>/Integrator' */
  real_T UD_DSTATE[2];                 /* '<S18>/UD' */
  real_T DiscreteFilter1_states_g[2];  /* '<S8>/Discrete Filter1' */
  real_T LowPass100Hz_DSTATE[2];       /* '<S35>/Low Pass 100 Hz' */
  real_T LowPass100Hz1_DSTATE[2];      /* '<S35>/Low Pass 100 Hz1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S9>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_i;          /* '<S10>/Unit Delay1' */
  real_T DiscreteFilter1_tmp;          /* '<S1>/Discrete Filter1' */
  real_T DiscreteFilter1_tmp_d[2];     /* '<S8>/Discrete Filter1' */
  real_T Memory_PreviousInput;         /* '<S35>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S35>/Memory1' */
  real_T Memory_PreviousInput_k[4];    /* '<S43>/Memory' */
  real_T Memory_PreviousInput_n[4];    /* '<S44>/Memory' */
  real_T Memory_PreviousInput_b[4];    /* '<S45>/Memory' */
  real_T Memory_PreviousInput_j[4];    /* '<S46>/Memory' */
  real_T Memory_PreviousInput_i[4];    /* '<S47>/Memory' */
  real_T Memory_PreviousInput_c[4];    /* '<S48>/Memory' */
  real_T i;                            /* '<S8>/MATLAB Function5' */
  real_T buf[50];                      /* '<S8>/MATLAB Function5' */
  real_T bufSum;                       /* '<S8>/MATLAB Function5' */
  real_T i_a;                          /* '<S8>/MATLAB Function4' */
  real_T buf_e[50];                    /* '<S8>/MATLAB Function4' */
  real_T bufSum_l;                     /* '<S8>/MATLAB Function4' */
  real_T i_g;                          /* '<S8>/MATLAB Function3' */
  real_T buf_g[50];                    /* '<S8>/MATLAB Function3' */
  real_T bufSum_a;                     /* '<S8>/MATLAB Function3' */
  real_T i_o;                          /* '<S8>/MATLAB Function2' */
  real_T buf_i[50];                    /* '<S8>/MATLAB Function2' */
  real_T bufSum_e;                     /* '<S8>/MATLAB Function2' */
  real_T PCI6221DA_RWORK[6];           /* '<S8>/PCI-6221 DA' */
  void *PCI6221AD1_PWORK;              /* '<S8>/PCI-6221 AD1' */
  void *PCI6221ENC_PWORK;              /* '<S8>/PCI 6221 ENC ' */
  void *PCI6221ENC1_PWORK;             /* '<S8>/PCI 6221 ENC 1' */
  int_T PCI6221AD1_IWORK[41];          /* '<S8>/PCI-6221 AD1' */
  int_T PCI6221DA_IWORK[41];           /* '<S8>/PCI-6221 DA' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S62>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_h;                 /* '<S61>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S63>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_b;                 /* '<S59>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_o;                 /* '<S64>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_l;                 /* '<S60>/S-Function' */

  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S1>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_i;/* '<S9>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S10>/Discrete-Time Integrator' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S8>/Triggered Subsystem' */
  int8_T TriggeredSubsystem1_SubsysRanBC;/* '<S8>/Triggered Subsystem1' */
} DW_FingerStrokeAssistance_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem1_Trig_ZCE;/* '<S8>/Triggered Subsystem1' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S8>/Triggered Subsystem' */
} PrevZCX_FingerStrokeAssistance_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1[5];                      /* '<Root>/Out1' */
} ExtY_FingerStrokeAssistance_T;

/* Backward compatible GRT Identifiers */
#define rtB                            FingerStrokeAssistance_B
#define BlockIO                        B_FingerStrokeAssistance_T
#define rtY                            FingerStrokeAssistance_Y
#define ExternalOutputs                ExtY_FingerStrokeAssistance_T
#define rtP                            FingerStrokeAssistance_P
#define Parameters                     P_FingerStrokeAssistance_T
#define rtDWork                        FingerStrokeAssistance_DW
#define D_Work                         DW_FingerStrokeAssistance_T
#define rtPrevZCSigState               FingerStrokeAssistance_PrevZCX
#define PrevZCSigStates                PrevZCX_FingerStrokeAssistance_T

/* Parameters (auto storage) */
struct P_FingerStrokeAssistance_T_ {
  real_T Alow[4];                      /* Variable: Alow
                                        * Referenced by:
                                        *   '<S35>/Low Pass 100 Hz'
                                        *   '<S35>/Low Pass 100 Hz1'
                                        */
  real_T Blow[2];                      /* Variable: Blow
                                        * Referenced by:
                                        *   '<S35>/Low Pass 100 Hz'
                                        *   '<S35>/Low Pass 100 Hz1'
                                        */
  real_T Clow[2];                      /* Variable: Clow
                                        * Referenced by:
                                        *   '<S35>/Low Pass 100 Hz'
                                        *   '<S35>/Low Pass 100 Hz1'
                                        */
  real_T Dlow;                         /* Variable: Dlow
                                        * Referenced by:
                                        *   '<S35>/Low Pass 100 Hz'
                                        *   '<S35>/Low Pass 100 Hz1'
                                        */
  real_T x0low[2];                     /* Variable: x0low
                                        * Referenced by:
                                        *   '<S35>/Low Pass 100 Hz'
                                        *   '<S35>/Low Pass 100 Hz1'
                                        */
  real_T DiscretePIDController_D;      /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S15>/Derivative Gain'
                                        */
  real_T DiscretePIDController_I;      /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S15>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S18>/UD'
                                          */
  real_T DiscretePIDController_N;      /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by: '<S15>/Filter Coefficient'
                                        */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S15>/Proportional Gain'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S14>/Delay Input1'
                                        */
  real_T DetectChange_vinit_a;         /* Mask Parameter: DetectChange_vinit_a
                                        * Referenced by: '<S41>/Delay Input1'
                                        */
  real_T DetectChange_vinit_d;         /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S42>/Delay Input1'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Out1_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S29>/Out1'
                                        */
  real_T Out1_Y0_o;                    /* Expression: [0]
                                        * Referenced by: '<S30>/Out1'
                                        */
  real_T PCI6221AD1_P1_Size[2];        /* Computed Parameter: PCI6221AD1_P1_Size
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P1[12];            /* Expression: channel
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P2_Size[2];        /* Computed Parameter: PCI6221AD1_P2_Size
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P2[12];            /* Expression: range
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P3_Size[2];        /* Computed Parameter: PCI6221AD1_P3_Size
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P3[12];            /* Expression: coupling
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P4_Size[2];        /* Computed Parameter: PCI6221AD1_P4_Size
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P4;                /* Expression: scantime
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P5_Size[2];        /* Computed Parameter: PCI6221AD1_P5_Size
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P5;                /* Expression: sampletime
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P6_Size[2];        /* Computed Parameter: PCI6221AD1_P6_Size
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P6;                /* Expression: slot
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P7_Size[2];        /* Computed Parameter: PCI6221AD1_P7_Size
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T PCI6221AD1_P7;                /* Expression: boardType
                                        * Referenced by: '<S8>/PCI-6221 AD1'
                                        */
  real_T Constant1_Value;              /* Expression: 0.1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant10_Value;             /* Expression: .3
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant2_Value;              /* Expression: -1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: -0.1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: .2
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: -.3
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T DiscreteFilter1_NumCoef[2];   /* Expression: [b_hp]
                                        * Referenced by: '<S1>/Discrete Filter1'
                                        */
  real_T DiscreteFilter1_DenCoef[2];   /* Expression: [a_hp]
                                        * Referenced by: '<S1>/Discrete Filter1'
                                        */
  real_T DiscreteFilter1_InitialStates;/* Expression: 0
                                        * Referenced by: '<S1>/Discrete Filter1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Damping_Gain;                 /* Expression: 1/1
                                        * Referenced by: '<S1>/Damping'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S1>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S1>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S1>/Discrete-Time Integrator'
                                          */
  real_T UnitDelay_InitialCondition;   /* Expression: 1
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;/* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                          * Referenced by: '<S9>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S9>/Discrete-Time Integrator'
                                        */
  real_T UnitDelay3_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay3'
                                        */
  real_T UnitDelay2_InitialCondition_a;/* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay2'
                                        */
  real_T UnitDelay2_InitialCondition_f;/* Expression: 0
                                        * Referenced by: '<S10>/Unit Delay2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                          * Referenced by: '<S10>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_l;  /* Expression: 0
                                        * Referenced by: '<S10>/Discrete-Time Integrator'
                                        */
  real_T PCI6221ENC_P1_Size[2];        /* Computed Parameter: PCI6221ENC_P1_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P1;                /* Expression: device
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P2_Size[2];        /* Computed Parameter: PCI6221ENC_P2_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P2;                /* Expression: channel
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P3_Size[2];        /* Computed Parameter: PCI6221ENC_P3_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P3;                /* Expression: countMode
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P4_Size[2];        /* Computed Parameter: PCI6221ENC_P4_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P4;                /* Expression: initCount
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P5_Size[2];        /* Computed Parameter: PCI6221ENC_P5_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P5;                /* Expression: reload
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P6_Size[2];        /* Computed Parameter: PCI6221ENC_P6_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P6;                /* Expression: indexPhase
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P7_Size[2];        /* Computed Parameter: PCI6221ENC_P7_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P7;                /* Expression: filter
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P8_Size[2];        /* Computed Parameter: PCI6221ENC_P8_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P8;                /* Expression: outmask
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P9_Size[2];        /* Computed Parameter: PCI6221ENC_P9_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P9;                /* Expression: sampleTime
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P10_Size[2];       /* Computed Parameter: PCI6221ENC_P10_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC_P10;               /* Expression: slot
                                        * Referenced by: '<S8>/PCI 6221 ENC '
                                        */
  real_T PCI6221ENC1_P1_Size[2];       /* Computed Parameter: PCI6221ENC1_P1_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P1;               /* Expression: device
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P2_Size[2];       /* Computed Parameter: PCI6221ENC1_P2_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P2;               /* Expression: channel
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P3_Size[2];       /* Computed Parameter: PCI6221ENC1_P3_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P3;               /* Expression: countMode
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P4_Size[2];       /* Computed Parameter: PCI6221ENC1_P4_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P4;               /* Expression: initCount
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P5_Size[2];       /* Computed Parameter: PCI6221ENC1_P5_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P5;               /* Expression: reload
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P6_Size[2];       /* Computed Parameter: PCI6221ENC1_P6_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P6;               /* Expression: indexPhase
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P7_Size[2];       /* Computed Parameter: PCI6221ENC1_P7_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P7;               /* Expression: filter
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P8_Size[2];       /* Computed Parameter: PCI6221ENC1_P8_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P8;               /* Expression: outmask
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P9_Size[2];       /* Computed Parameter: PCI6221ENC1_P9_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P9;               /* Expression: sampleTime
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P10_Size[2];      /* Computed Parameter: PCI6221ENC1_P10_Size
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T PCI6221ENC1_P10;              /* Expression: slot
                                        * Referenced by: '<S8>/PCI 6221 ENC 1'
                                        */
  real_T paremeters_must_be_one_Value; /* Expression: 1
                                        * Referenced by: '<S12>/paremeters_ must_be_one'
                                        */
  real_T parLeftMode_Gain;             /* Expression: 1
                                        * Referenced by: '<S12>/parLeftMode'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/4500.0
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_e; /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T UnitDelay1_InitialCondition_k;/* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay1'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S15>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S15>/Filter'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S18>/TSamp'
                                        */
  real_T DiscreteFilter1_NumCoef_g[2]; /* Expression: [b_lp]
                                        * Referenced by: '<S8>/Discrete Filter1'
                                        */
  real_T DiscreteFilter1_DenCoef_a[2]; /* Expression: [a_lp]
                                        * Referenced by: '<S8>/Discrete Filter1'
                                        */
  real_T DiscreteFilter1_InitialStates_c;/* Expression: 0
                                          * Referenced by: '<S8>/Discrete Filter1'
                                          */
  real_T Gain1_Gain_a;                 /* Expression: -1
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T PCI6221DA_P1_Size[2];         /* Computed Parameter: PCI6221DA_P1_Size
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P1[2];              /* Expression: channel
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P2_Size[2];         /* Computed Parameter: PCI6221DA_P2_Size
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P2[2];              /* Expression: range
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P3_Size[2];         /* Computed Parameter: PCI6221DA_P3_Size
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P3[2];              /* Expression: reset
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P4_Size[2];         /* Computed Parameter: PCI6221DA_P4_Size
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P4[2];              /* Expression: initValue
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P5_Size[2];         /* Computed Parameter: PCI6221DA_P5_Size
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P5;                 /* Expression: sampletime
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P6_Size[2];         /* Computed Parameter: PCI6221DA_P6_Size
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P6;                 /* Expression: slot
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P7_Size[2];         /* Computed Parameter: PCI6221DA_P7_Size
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T PCI6221DA_P7;                 /* Expression: boardType
                                        * Referenced by: '<S8>/PCI-6221 DA'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S35>/Memory'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S35>/Memory1'
                                        */
  real_T UnitDelay1_InitialCondition_o;/* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay1'
                                        */
  real_T UnitDelay1_InitialCondition_oy;/* Expression: 0
                                         * Referenced by: '<S10>/Unit Delay1'
                                         */
  real_T parTrajMode_Gain;             /* Expression: 1
                                        * Referenced by: '<S12>/parTrajMode'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 4
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  real_T parFixedDur_Gain;             /* Expression: 3
                                        * Referenced by: '<S12>/parFixedDur'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 10
                                        * Referenced by: '<S12>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: .25
                                        * Referenced by: '<S12>/Saturation2'
                                        */
  real_T Memory_X0_g[4];               /* Expression: zeros(1,4)
                                        * Referenced by: '<S43>/Memory'
                                        */
  real_T parChangeRate_Gain;           /* Expression: .05
                                        * Referenced by: '<S12>/parChangeRate'
                                        */
  real_T parKp1_Gain;                  /* Expression: 0
                                        * Referenced by: '<S12>/parKp1'
                                        */
  real_T Memory_X0_a[4];               /* Expression: zeros(1,4)
                                        * Referenced by: '<S44>/Memory'
                                        */
  real_T parKp2_Gain;                  /* Expression: 0
                                        * Referenced by: '<S12>/parKp2'
                                        */
  real_T Memory_X0_b[4];               /* Expression: zeros(1,4)
                                        * Referenced by: '<S45>/Memory'
                                        */
  real_T parKd1_Gain;                  /* Expression: 0.0
                                        * Referenced by: '<S12>/parKd1'
                                        */
  real_T Memory_X0_g0[4];              /* Expression: zeros(1,4)
                                        * Referenced by: '<S46>/Memory'
                                        */
  real_T parKd2_Gain;                  /* Expression: 0.0
                                        * Referenced by: '<S12>/parKd2'
                                        */
  real_T Memory_X0_bp[4];              /* Expression: zeros(1,4)
                                        * Referenced by: '<S47>/Memory'
                                        */
  real_T parKdV1_Gain;                 /* Expression: 0.0
                                        * Referenced by: '<S12>/parKdV1'
                                        */
  real_T Memory_X0_e[4];               /* Expression: zeros(1,4)
                                        * Referenced by: '<S48>/Memory'
                                        */
  real_T parKdV2_Gain;                 /* Expression: 0.0
                                        * Referenced by: '<S12>/parKdV2'
                                        */
  real_T parFThresh_Gain;              /* Expression: 0.25
                                        * Referenced by: '<S12>/parFThresh'
                                        */
  real_T parForceTrigger_Gain;         /* Expression: 0
                                        * Referenced by: '<S12>/parForceTrigger'
                                        */
  real_T parMarker_Gain;               /* Expression: 0
                                        * Referenced by: '<S12>/parMarker'
                                        */
  real_T parMaxTrajDur_Gain;           /* Expression: .4
                                        * Referenced by: '<S12>/parMaxTrajDur'
                                        */
  real_T parPStop_Gain;                /* Expression: 0.75
                                        * Referenced by: '<S12>/parPStop'
                                        */
  real_T parVThresh_Gain;              /* Expression: .375
                                        * Referenced by: '<S12>/parVThresh'
                                        */
  real_T parWiggleAmp_Gain;            /* Expression: .5
                                        * Referenced by: '<S12>/parWiggleAmp'
                                        */
  real_T Gain2_Gain;                   /* Expression: 7.66
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 7.66
                                        * Referenced by: '<S13>/Gain'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S1>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S1>/Delay1'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  boolean_T Constant_Value_i;          /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S5>/Constant'
                                        */
  boolean_T Constant_Value_j;          /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S7>/Constant'
                                        */
  boolean_T Constant_Value_b;          /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S6>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_FingerStrokeAssistance_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[4];
    SimStruct *childSFunctionPtrs[4];
    struct _ssBlkInfo2 blkInfo2[4];
    struct _ssSFcnModelMethods2 methods2[4];
    struct _ssSFcnModelMethods3 methods3[4];
    struct _ssStatesInfo2 statesInfo2[4];
    ssPeriodicStatesInfo periodicStatesInfo[4];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[12];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn3;
  } NonInlinedSFcns;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_FingerStrokeAssistance_T FingerStrokeAssistance_P;

/* Block signals (auto storage) */
extern B_FingerStrokeAssistance_T FingerStrokeAssistance_B;

/* Block states (auto storage) */
extern DW_FingerStrokeAssistance_T FingerStrokeAssistance_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_FingerStrokeAssistance_T FingerStrokeAssistance_Y;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_FingerStrokeAssistance_T FingerStrokeAssistance_PrevZCX;

/*====================*
 * External functions *
 *====================*/
extern FingerStrokeAssistance_rtModel *FingerStrokeAssistance(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  FingerStrokeAssistance_GetCAPIStaticMap(void);

/* Real-time Model object */
extern RT_MODEL_FingerStrokeAssistance_T *const FingerStrokeAssistance_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FingerStrokeAssistance'
 * '<S1>'   : 'FingerStrokeAssistance/HL Controller'
 * '<S2>'   : 'FingerStrokeAssistance/LL Force Controller'
 * '<S3>'   : 'FingerStrokeAssistance/LL Position Controller'
 * '<S4>'   : 'FingerStrokeAssistance/MATLAB Function'
 * '<S5>'   : 'FingerStrokeAssistance/ON//OFF'
 * '<S6>'   : 'FingerStrokeAssistance/One Finger Mode// Two Finger Mode'
 * '<S7>'   : 'FingerStrokeAssistance/Position Control // Force Control'
 * '<S8>'   : 'FingerStrokeAssistance/Robot'
 * '<S9>'   : 'FingerStrokeAssistance/Subsystem'
 * '<S10>'  : 'FingerStrokeAssistance/Subsystem1'
 * '<S11>'  : 'FingerStrokeAssistance/Subsystem2'
 * '<S12>'  : 'FingerStrokeAssistance/parameters'
 * '<S13>'  : 'FingerStrokeAssistance/signals'
 * '<S14>'  : 'FingerStrokeAssistance/HL Controller/Detect Change'
 * '<S15>'  : 'FingerStrokeAssistance/LL Position Controller/Discrete PID Controller'
 * '<S16>'  : 'FingerStrokeAssistance/LL Position Controller/Saturation Dynamic1'
 * '<S17>'  : 'FingerStrokeAssistance/LL Position Controller/Saturation Dynamic2'
 * '<S18>'  : 'FingerStrokeAssistance/Robot/Discrete Derivative'
 * '<S19>'  : 'FingerStrokeAssistance/Robot/MATLAB Function'
 * '<S20>'  : 'FingerStrokeAssistance/Robot/MATLAB Function1'
 * '<S21>'  : 'FingerStrokeAssistance/Robot/MATLAB Function2'
 * '<S22>'  : 'FingerStrokeAssistance/Robot/MATLAB Function3'
 * '<S23>'  : 'FingerStrokeAssistance/Robot/MATLAB Function4'
 * '<S24>'  : 'FingerStrokeAssistance/Robot/MATLAB Function5'
 * '<S25>'  : 'FingerStrokeAssistance/Robot/MATLAB Function6'
 * '<S26>'  : 'FingerStrokeAssistance/Robot/MATLAB Function7'
 * '<S27>'  : 'FingerStrokeAssistance/Robot/MATLAB Function8'
 * '<S28>'  : 'FingerStrokeAssistance/Robot/Saturation Dynamic'
 * '<S29>'  : 'FingerStrokeAssistance/Robot/Triggered Subsystem'
 * '<S30>'  : 'FingerStrokeAssistance/Robot/Triggered Subsystem1'
 * '<S31>'  : 'FingerStrokeAssistance/Robot/account for handedness'
 * '<S32>'  : 'FingerStrokeAssistance/Robot/account for handedness force'
 * '<S33>'  : 'FingerStrokeAssistance/Robot/account for handedness1'
 * '<S34>'  : 'FingerStrokeAssistance/Robot/account for handedness2'
 * '<S35>'  : 'FingerStrokeAssistance/Robot/filtered force output'
 * '<S36>'  : 'FingerStrokeAssistance/Robot/gravDir'
 * '<S37>'  : 'FingerStrokeAssistance/Robot/account for handedness/MATLAB Function'
 * '<S38>'  : 'FingerStrokeAssistance/Robot/account for handedness force/MATLAB Function'
 * '<S39>'  : 'FingerStrokeAssistance/Robot/account for handedness1/MATLAB Function'
 * '<S40>'  : 'FingerStrokeAssistance/Robot/account for handedness2/MATLAB Function'
 * '<S41>'  : 'FingerStrokeAssistance/Subsystem/Detect Change'
 * '<S42>'  : 'FingerStrokeAssistance/Subsystem1/Detect Change'
 * '<S43>'  : 'FingerStrokeAssistance/parameters/gain transition'
 * '<S44>'  : 'FingerStrokeAssistance/parameters/gain transition1'
 * '<S45>'  : 'FingerStrokeAssistance/parameters/gain transition2'
 * '<S46>'  : 'FingerStrokeAssistance/parameters/gain transition3'
 * '<S47>'  : 'FingerStrokeAssistance/parameters/gain transition4'
 * '<S48>'  : 'FingerStrokeAssistance/parameters/gain transition5'
 * '<S49>'  : 'FingerStrokeAssistance/parameters/gain transition/gainramp'
 * '<S50>'  : 'FingerStrokeAssistance/parameters/gain transition1/gainramp'
 * '<S51>'  : 'FingerStrokeAssistance/parameters/gain transition2/gainramp'
 * '<S52>'  : 'FingerStrokeAssistance/parameters/gain transition3/gainramp'
 * '<S53>'  : 'FingerStrokeAssistance/parameters/gain transition4/gainramp'
 * '<S54>'  : 'FingerStrokeAssistance/parameters/gain transition5/gainramp'
 * '<S55>'  : 'FingerStrokeAssistance/signals/Scope (xPC) '
 * '<S56>'  : 'FingerStrokeAssistance/signals/Scope (xPC) 1'
 * '<S57>'  : 'FingerStrokeAssistance/signals/Scope (xPC) 2'
 * '<S58>'  : 'FingerStrokeAssistance/signals/Scope (xPC) 3'
 * '<S59>'  : 'FingerStrokeAssistance/signals/Scope (xPC) 4'
 * '<S60>'  : 'FingerStrokeAssistance/signals/Scope (xPC) 5'
 * '<S61>'  : 'FingerStrokeAssistance/signals/Scope (xPC) 6'
 * '<S62>'  : 'FingerStrokeAssistance/signals/Scope (xPC) 7'
 * '<S63>'  : 'FingerStrokeAssistance/signals/Scope (xPC) 8'
 * '<S64>'  : 'FingerStrokeAssistance/signals/Scope (xPC) 9'
 */
#endif                                 /* RTW_HEADER_FingerStrokeAssistance_h_ */
