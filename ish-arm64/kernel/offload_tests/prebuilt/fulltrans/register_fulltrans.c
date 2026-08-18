/* AUTO-GENERATED: full-libpython-translation registration (PoC).
 * 1192 spec_fns from tools/prebuilt_gadget_gen/translate.py.
 * Gated: ISH_FULLTRANS=0x<libpython_base>; optional ISH_FT_LIMIT=N (bisect). */
#include <stdlib.h>
#include "kernel/native_offload.h"
#include "emu/arch/arm64/cpu.h"
#include "emu/tlb.h"
uint64_t g_ft_base;
void ft__init(struct cpu_state*,struct tlb*);
void ft__Py_DisplaySourceLine(struct cpu_state*,struct tlb*);
void ft_PyErr_Display(struct cpu_state*,struct tlb*);
void ft_PyException_GetCause(struct cpu_state*,struct tlb*);
void ft_PyTraceBack_Print(struct cpu_state*,struct tlb*);
void ft__PyOS_URandomNonblock(struct cpu_state*,struct tlb*);
void ft_PyInit__string(struct cpu_state*,struct tlb*);
void ft_PyInit_atexit(struct cpu_state*,struct tlb*);
void ft_PyInit_gc(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Replace(struct cpu_state*,struct tlb*);
void ft_PyContextVar_New(struct cpu_state*,struct tlb*);
void ft_PyInit__symtable(struct cpu_state*,struct tlb*);
void ft_PyState_AddModule(struct cpu_state*,struct tlb*);
void ft_PyInit__tracemalloc(struct cpu_state*,struct tlb*);
void ft__PyCrossInterpreterData_RegisterClass(struct cpu_state*,struct tlb*);
void ft__Py_AtExit(struct cpu_state*,struct tlb*);
void ft_PyInit_pwd(struct cpu_state*,struct tlb*);
void ft__Py_DecRef(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeUTF16(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeUTF32(struct cpu_state*,struct tlb*);
void ft__PyCrossInterpreterData_UnregisterClass(struct cpu_state*,struct tlb*);
void ft_PyUnicode_GetDefaultEncoding(struct cpu_state*,struct tlb*);
void ft__PyEval_GetSwitchInterval(struct cpu_state*,struct tlb*);
void ft_PyObject_GenericSetDict(struct cpu_state*,struct tlb*);
void ft__PyEval_SignalReceived(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_IsTracing(struct cpu_state*,struct tlb*);
void ft_PyThreadState_Get(struct cpu_state*,struct tlb*);
void ft_Py_EndInterpreter(struct cpu_state*,struct tlb*);
void ft_PySequence_InPlaceConcat(struct cpu_state*,struct tlb*);
void ft_PyNumber_InPlaceMatrixMultiply(struct cpu_state*,struct tlb*);
void ft__PyOS_URandom(struct cpu_state*,struct tlb*);
void ft_PyOS_BeforeFork(struct cpu_state*,struct tlb*);
void ft_PyOS_AfterFork_Parent(struct cpu_state*,struct tlb*);
void ft__PyTime_FromMillisecondsObject(struct cpu_state*,struct tlb*);
void ft_PyUnicode_ReadChar(struct cpu_state*,struct tlb*);
void ft_PyErr_SyntaxLocationObject(struct cpu_state*,struct tlb*);
void ft__PyTraceback_Add(struct cpu_state*,struct tlb*);
void ft__Py_add_one_to_index_F(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_compare_direct(struct cpu_state*,struct tlb*);
void ft_PyBuffer_GetPointer(struct cpu_state*,struct tlb*);
void ft_PyBuffer_FillContiguousStrides(struct cpu_state*,struct tlb*);
void ft_PyAIter_Check(struct cpu_state*,struct tlb*);
void ft_PyByteArray_Size(struct cpu_state*,struct tlb*);
void ft_PyByteArray_AsString(struct cpu_state*,struct tlb*);
void ft__PyBytes_Find(struct cpu_state*,struct tlb*);
void ft__PyBytes_ReverseFind(struct cpu_state*,struct tlb*);
void ft_PyVectorcall_NARGS(struct cpu_state*,struct tlb*);
void ft__Py_c_prod(struct cpu_state*,struct tlb*);
void ft_PyException_GetArgs(struct cpu_state*,struct tlb*);
void ft_PyException_SetArgs(struct cpu_state*,struct tlb*);
void ft_PyExceptionClass_Name(struct cpu_state*,struct tlb*);
void ft_PyGen_GetCode(struct cpu_state*,struct tlb*);
void ft_Py_UniversalNewlineFgets(struct cpu_state*,struct tlb*);
void ft_PyFloat_GetMax(struct cpu_state*,struct tlb*);
void ft_PyFloat_GetMin(struct cpu_state*,struct tlb*);
void ft__PyFrame_IsEntryFrame(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetGlobals(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetBuiltins(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetLasti(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetGenerator(struct cpu_state*,struct tlb*);
void ft_PyFunction_SetVectorcall(struct cpu_state*,struct tlb*);
void ft_PyUnstable_Long_IsCompact(struct cpu_state*,struct tlb*);
void ft_PyUnstable_Long_CompactValue(struct cpu_state*,struct tlb*);
void ft_PyODict_New(struct cpu_state*,struct tlb*);
void ft_Py_IncRef(struct cpu_state*,struct tlb*);
void ft_Py_DecRef(struct cpu_state*,struct tlb*);
void ft__Py_IncRef(struct cpu_state*,struct tlb*);
void ft__Py_BreakPoint(struct cpu_state*,struct tlb*);
void ft__PyObject_IsFreed(struct cpu_state*,struct tlb*);
void ft_PyObject_GET_WEAKREFS_LISTPTR(struct cpu_state*,struct tlb*);
void ft_Py_XNewRef(struct cpu_state*,struct tlb*);
void ft_Py_Is(struct cpu_state*,struct tlb*);
void ft_Py_IsNone(struct cpu_state*,struct tlb*);
void ft_Py_IsTrue(struct cpu_state*,struct tlb*);
void ft_Py_IsFalse(struct cpu_state*,struct tlb*);
void ft__PyMem_GetAllocatorName(struct cpu_state*,struct tlb*);
void ft_PyStructSequence_SetItem(struct cpu_state*,struct tlb*);
void ft_PyStructSequence_GetItem(struct cpu_state*,struct tlb*);
void ft_PyType_GetDict(struct cpu_state*,struct tlb*);
void ft_PyType_ClearCache(struct cpu_state*,struct tlb*);
void ft_PyUnstable_Type_AssignVersionTag(struct cpu_state*,struct tlb*);
void ft_PyType_GetFlags(struct cpu_state*,struct tlb*);
void ft_PyType_SUPPORTS_WEAKREFS(struct cpu_state*,struct tlb*);
void ft_PyObject_GetTypeData(struct cpu_state*,struct tlb*);
void ft_PyType_GetTypeDataSize(struct cpu_state*,struct tlb*);
void ft__PyUnicode_ToTitlecase(struct cpu_state*,struct tlb*);
void ft__PyWeakref_GetWeakrefCount(struct cpu_state*,struct tlb*);
void ft_PyEval_GetFuncDesc(struct cpu_state*,struct tlb*);
void ft_PyUnstable_Eval_RequestCodeExtraIndex(struct cpu_state*,struct tlb*);
void ft_PyCompile_OpcodeStackEffect(struct cpu_state*,struct tlb*);
void ft_PyCode_Optimize(struct cpu_state*,struct tlb*);
void ft_PyObject_CheckReadBuffer(struct cpu_state*,struct tlb*);
void ft__PyErr_GetExcInfo(struct cpu_state*,struct tlb*);
void ft__PyErr_GetHandledException(struct cpu_state*,struct tlb*);
void ft_PyErr_GetHandledException(struct cpu_state*,struct tlb*);
void ft__PyErr_SetHandledException(struct cpu_state*,struct tlb*);
void ft_PyErr_SetHandledException(struct cpu_state*,struct tlb*);
void ft_PyErr_GetExcInfo(struct cpu_state*,struct tlb*);
void ft_PyErr_SetExcInfo(struct cpu_state*,struct tlb*);
void ft_PyUnstable_InterpreterFrame_GetCode(struct cpu_state*,struct tlb*);
void ft_PyUnstable_InterpreterFrame_GetLasti(struct cpu_state*,struct tlb*);
void ft_PyEval_ThreadsInitialized(struct cpu_state*,struct tlb*);
void ft_PyEval_InitThreads(struct cpu_state*,struct tlb*);
void ft__PyEval_SignalAsyncExc(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_size(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_len(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_foreach(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_new(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_clear(struct cpu_state*,struct tlb*);
void ft_PyState_FindModule(struct cpu_state*,struct tlb*);
void ft_PyImport_GetMagicTag(struct cpu_state*,struct tlb*);
void ft_PyStatus_Error(struct cpu_state*,struct tlb*);
void ft_PyStatus_NoMemory(struct cpu_state*,struct tlb*);
void ft_PyStatus_Exit(struct cpu_state*,struct tlb*);
void ft_PyStatus_IsError(struct cpu_state*,struct tlb*);
void ft_PyStatus_IsExit(struct cpu_state*,struct tlb*);
void ft_Py_GetArgcArgv(struct cpu_state*,struct tlb*);
void ft__PyDebugAllocatorStats(struct cpu_state*,struct tlb*);
void ft__PyTuple_DebugMallocStats(struct cpu_state*,struct tlb*);
void ft__PyDict_DebugMallocStats(struct cpu_state*,struct tlb*);
void ft__PyList_DebugMallocStats(struct cpu_state*,struct tlb*);
void ft__PyFloat_DebugMallocStats(struct cpu_state*,struct tlb*);
void ft__PyObject_DebugTypeStats(struct cpu_state*,struct tlb*);
void ft__PyObject_DebugMallocStats(struct cpu_state*,struct tlb*);
void ft_Py_GetPath(struct cpu_state*,struct tlb*);
void ft_Py_GetPrefix(struct cpu_state*,struct tlb*);
void ft_Py_GetExecPrefix(struct cpu_state*,struct tlb*);
void ft_Py_GetProgramFullPath(struct cpu_state*,struct tlb*);
void ft_Py_GetPythonHome(struct cpu_state*,struct tlb*);
void ft_Py_GetProgramName(struct cpu_state*,struct tlb*);
void ft__Py_str_to_int(struct cpu_state*,struct tlb*);
void ft__Py_IsFinalizing(struct cpu_state*,struct tlb*);
void ft__Py_IsCoreInitialized(struct cpu_state*,struct tlb*);
void ft_Py_IsInitialized(struct cpu_state*,struct tlb*);
void ft__Py_CoerceLegacyLocale(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_IsRunningMain(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_RequiresIDRef(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_RequireIDRef(struct cpu_state*,struct tlb*);
void ft_PyThreadState_GetID(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_Head(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_Main(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_Next(struct cpu_state*,struct tlb*);
void ft__PyGILState_GetInterpreterStateUnsafe(struct cpu_state*,struct tlb*);
void ft__PyCrossInterpreterData_Init(struct cpu_state*,struct tlb*);
void ft__PyCrossInterpreterData_InitWithSize(struct cpu_state*,struct tlb*);
void ft__PyCrossInterpreterData_Clear(struct cpu_state*,struct tlb*);
void ft__PyCrossInterpreterData_NewObject(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_GetEvalFrameFunc(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_SetEvalFrameFunc(struct cpu_state*,struct tlb*);
void ft__PyTime_MulDiv(struct cpu_state*,struct tlb*);
void ft_PyThread_exit_thread(struct cpu_state*,struct tlb*);
void ft_PyUnstable_PerfMapState_Init(struct cpu_state*,struct tlb*);
void ft__PyThread_at_fork_reinit(struct cpu_state*,struct tlb*);
void ft_PyThread_create_key(struct cpu_state*,struct tlb*);
void ft_PyThread_delete_key(struct cpu_state*,struct tlb*);
void ft_PyThread_delete_key_value(struct cpu_state*,struct tlb*);
void ft_PyThread_set_key_value(struct cpu_state*,struct tlb*);
void ft_PyThread_get_key_value(struct cpu_state*,struct tlb*);
void ft_PyThread_ReInitTLS(struct cpu_state*,struct tlb*);
void ft_PyGILState_GetThisThreadState(struct cpu_state*,struct tlb*);
void ft_PyThread_get_stacksize(struct cpu_state*,struct tlb*);
void ft_PyThread_set_stacksize(struct cpu_state*,struct tlb*);
void ft_PyThread_tss_alloc(struct cpu_state*,struct tlb*);
void ft_PyThread_tss_free(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_GetTracebackLimit(struct cpu_state*,struct tlb*);
void ft_PyOS_mystricmp(struct cpu_state*,struct tlb*);
void ft_Py_EncodeLocale(struct cpu_state*,struct tlb*);
void ft__Py_EncodeLocaleRaw(struct cpu_state*,struct tlb*);
void ft__Py_write_noraise(struct cpu_state*,struct tlb*);
void ft__Py_DumpDecimal(struct cpu_state*,struct tlb*);
void ft__Py_DumpHexadecimal(struct cpu_state*,struct tlb*);
void ft__Py_DumpASCII(struct cpu_state*,struct tlb*);
void ft__Py_DumpTraceback(struct cpu_state*,struct tlb*);
void ft__Py_DumpTracebackThreads(struct cpu_state*,struct tlb*);
void ft__Py_closerange(struct cpu_state*,struct tlb*);
void ft_PyGC_Enable(struct cpu_state*,struct tlb*);
void ft_PyGC_Disable(struct cpu_state*,struct tlb*);
void ft_PyGC_IsEnabled(struct cpu_state*,struct tlb*);
void ft_PyObject_GC_IsTracked(struct cpu_state*,struct tlb*);
void ft_PyObject_GC_IsFinalized(struct cpu_state*,struct tlb*);
void ft_PyUnstable_GC_VisitObjects(struct cpu_state*,struct tlb*);
void ft__PyOS_InterruptOccurred(struct cpu_state*,struct tlb*);
void ft_PyOS_Readline(struct cpu_state*,struct tlb*);
void ft_PyErr_DisplayException(struct cpu_state*,struct tlb*);
void ft_Py_FatalError(struct cpu_state*,struct tlb*);
void ft__Py_FatalErrorFunc(struct cpu_state*,struct tlb*);
void ft_Py_FdIsInteractive(struct cpu_state*,struct tlb*);
void ft__PyContext_NewHamtForTests(struct cpu_state*,struct tlb*);
void ft__PyThreadState_Init(struct cpu_state*,struct tlb*);
void ft_PyEval_ReleaseLock(struct cpu_state*,struct tlb*);
void ft_PyEval_ReleaseThread(struct cpu_state*,struct tlb*);
void ft__Py_FatalRefcountErrorFunc(struct cpu_state*,struct tlb*);
void ft__PyObject_Dump(struct cpu_state*,struct tlb*);
void ft__PyObject_AssertFailed(struct cpu_state*,struct tlb*);
void ft__PyUnicode_CheckConsistency(struct cpu_state*,struct tlb*);
void ft__PyDict_CheckConsistency(struct cpu_state*,struct tlb*);
void ft_PyEval_EvalFrameEx(struct cpu_state*,struct tlb*);
void ft_PyEval_EvalFrame(struct cpu_state*,struct tlb*);
void ft_PyImport_ImportModuleNoBlock(struct cpu_state*,struct tlb*);
void ft_PyType_GetName(struct cpu_state*,struct tlb*);
void ft_PyObject_HasAttr(struct cpu_state*,struct tlb*);
void ft_PyObject_HasAttrString(struct cpu_state*,struct tlb*);
void ft_PyErr_BadInternalCall(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_GetID(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_IDInitref(struct cpu_state*,struct tlb*);
void ft_PyUnicode_GetSize(struct cpu_state*,struct tlb*);
void ft_PyType_AddWatcher(struct cpu_state*,struct tlb*);
void ft_PyDict_AddWatcher(struct cpu_state*,struct tlb*);
void ft_PyFunction_AddWatcher(struct cpu_state*,struct tlb*);
void ft_PyCode_AddWatcher(struct cpu_state*,struct tlb*);
void ft_PyCapsule_GetName(struct cpu_state*,struct tlb*);
void ft_PyCapsule_GetDestructor(struct cpu_state*,struct tlb*);
void ft_PyCapsule_GetContext(struct cpu_state*,struct tlb*);
void ft_PyCapsule_SetName(struct cpu_state*,struct tlb*);
void ft_PyCapsule_SetDestructor(struct cpu_state*,struct tlb*);
void ft_PyCapsule_SetContext(struct cpu_state*,struct tlb*);
void ft_PyCapsule_SetPointer(struct cpu_state*,struct tlb*);
void ft__PyTime_FromTimeval(struct cpu_state*,struct tlb*);
void ft__PyDeadline_Get(struct cpu_state*,struct tlb*);
void ft_PyEval_AcquireLock(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_ClearTraces(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_GetMemory(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_ResetPeak(struct cpu_state*,struct tlb*);
void ft_PyUnstable_WritePerfMapEntry(struct cpu_state*,struct tlb*);
void ft_PyUnstable_PerfMapState_Fini(struct cpu_state*,struct tlb*);
void ft_PyThreadState_New(struct cpu_state*,struct tlb*);
void ft_PyTraceMalloc_Untrack(struct cpu_state*,struct tlb*);
void ft_PyThreadState_Delete(struct cpu_state*,struct tlb*);
void ft_PyThreadState_DeleteCurrent(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_IDIncref(struct cpu_state*,struct tlb*);
void ft_PyThreadState_SetAsyncExc(struct cpu_state*,struct tlb*);
void ft_Py_AtExit(struct cpu_state*,struct tlb*);
void ft__PyEval_AddPendingCall(struct cpu_state*,struct tlb*);
void ft_Py_AddPendingCall(struct cpu_state*,struct tlb*);
void ft_PyMem_SetupDebugHooks(struct cpu_state*,struct tlb*);
void ft_Py_SetPath(struct cpu_state*,struct tlb*);
void ft_Py_SetPythonHome(struct cpu_state*,struct tlb*);
void ft_Py_SetProgramName(struct cpu_state*,struct tlb*);
void ft__Py_SetProgramFullPath(struct cpu_state*,struct tlb*);
void ft_Py_SetStandardStreamEncoding(struct cpu_state*,struct tlb*);
void ft_PyImport_ExtendInittab(struct cpu_state*,struct tlb*);
void ft_PyImport_AppendInittab(struct cpu_state*,struct tlb*);
void ft_PyConfig_SetBytesString(struct cpu_state*,struct tlb*);
void ft_PyConfig_SetArgv(struct cpu_state*,struct tlb*);
void ft_Py_PreInitializeFromBytesArgs(struct cpu_state*,struct tlb*);
void ft_Py_PreInitializeFromArgs(struct cpu_state*,struct tlb*);
void ft_Py_PreInitialize(struct cpu_state*,struct tlb*);
void ft_PyObject_GetArenaAllocator(struct cpu_state*,struct tlb*);
void ft_PyObject_SetArenaAllocator(struct cpu_state*,struct tlb*);
void ft_PyObject_AsWriteBuffer(struct cpu_state*,struct tlb*);
void ft__PyErr_SetNone(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_LookUpID(struct cpu_state*,struct tlb*);
void ft__PyCrossInterpreterData_Release(struct cpu_state*,struct tlb*);
void ft__PyCrossInterpreterData_ReleaseAndRawFree(struct cpu_state*,struct tlb*);
void ft__PyErr_SetFromPyStatus(struct cpu_state*,struct tlb*);
void ft_PyContext_Exit(struct cpu_state*,struct tlb*);
void ft_PyType_ClearWatcher(struct cpu_state*,struct tlb*);
void ft_PyType_Watch(struct cpu_state*,struct tlb*);
void ft_PyType_Unwatch(struct cpu_state*,struct tlb*);
void ft_PyPickleBuffer_Release(struct cpu_state*,struct tlb*);
void ft_PyTraceMalloc_Track(struct cpu_state*,struct tlb*);
void ft_PyUnstable_Object_GC_NewWithExtraData(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsUCS4Copy(struct cpu_state*,struct tlb*);
void ft__PyUnicodeWriter_PrepareKindInternal(struct cpu_state*,struct tlb*);
void ft__PyUnicodeWriter_WriteLatin1String(struct cpu_state*,struct tlb*);
void ft_PyObject_Init(struct cpu_state*,struct tlb*);
void ft_PyBuffer_FromContiguous(struct cpu_state*,struct tlb*);
void ft_PyContext_Copy(struct cpu_state*,struct tlb*);
void ft_PyContext_CopyCurrent(struct cpu_state*,struct tlb*);
void ft_PyContext_New(struct cpu_state*,struct tlb*);
void ft_PyInstanceMethod_New(struct cpu_state*,struct tlb*);
void ft_PyCode_GetCode(struct cpu_state*,struct tlb*);
void ft__PyDict_NewPresized(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_GetDict(struct cpu_state*,struct tlb*);
void ft__PyObject_NextNotImplemented(struct cpu_state*,struct tlb*);
void ft_PyCFunction_NewEx(struct cpu_state*,struct tlb*);
void ft_PyCFunction_New(struct cpu_state*,struct tlb*);
void ft_PyDict_Watch(struct cpu_state*,struct tlb*);
void ft_PyDict_Unwatch(struct cpu_state*,struct tlb*);
void ft_PyDict_ClearWatcher(struct cpu_state*,struct tlb*);
void ft_PyFunction_ClearWatcher(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetVar(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetVarString(struct cpu_state*,struct tlb*);
void ft_PyUnicodeTranslateError_GetStart(struct cpu_state*,struct tlb*);
void ft_PyUnicodeTranslateError_GetEnd(struct cpu_state*,struct tlb*);
void ft_PyUnicodeEncodeError_GetReason(struct cpu_state*,struct tlb*);
void ft_PyUnicodeDecodeError_GetReason(struct cpu_state*,struct tlb*);
void ft_PyUnicodeTranslateError_GetReason(struct cpu_state*,struct tlb*);
void ft_PyCode_ClearWatcher(struct cpu_state*,struct tlb*);
void ft_PyObject_CopyData(struct cpu_state*,struct tlb*);
void ft_PyObject_AsReadBuffer(struct cpu_state*,struct tlb*);
void ft_PyObject_AsCharBuffer(struct cpu_state*,struct tlb*);
void ft_PyPickleBuffer_FromObject(struct cpu_state*,struct tlb*);
void ft_PySequence_Repeat(struct cpu_state*,struct tlb*);
void ft_PySequence_InPlaceRepeat(struct cpu_state*,struct tlb*);
void ft_PyObject_GetAIter(struct cpu_state*,struct tlb*);
void ft__Py_device_encoding(struct cpu_state*,struct tlb*);
void ft__PyErr_BadInternalCall(struct cpu_state*,struct tlb*);
void ft_PyMemoryView_GetContiguous(struct cpu_state*,struct tlb*);
void ft_PyGen_NewWithQualName(struct cpu_state*,struct tlb*);
void ft_PyGen_New(struct cpu_state*,struct tlb*);
void ft_PyAsyncGen_New(struct cpu_state*,struct tlb*);
void ft__PyCrossInterpreterData_Lookup(struct cpu_state*,struct tlb*);
void ft__PyObject_GetCrossInterpreterData(struct cpu_state*,struct tlb*);
void ft__PyObject_CheckCrossInterpreterData(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Resize(struct cpu_state*,struct tlb*);
void ft__PyUnicode_WideCharString_Converter(struct cpu_state*,struct tlb*);
void ft__PyUnicode_WideCharString_Opt_Converter(struct cpu_state*,struct tlb*);
void ft_PyCode_GetVarnames(struct cpu_state*,struct tlb*);
void ft_PyCode_GetCellvars(struct cpu_state*,struct tlb*);
void ft_PyCode_GetFreevars(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_GetTraceback(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_GetTracedMemory(struct cpu_state*,struct tlb*);
void ft_PyCoro_New(struct cpu_state*,struct tlb*);
void ft_PySys_AddAuditHook(struct cpu_state*,struct tlb*);
void ft__Py_DumpExtensionModules(struct cpu_state*,struct tlb*);
void ft_PyCFunction_GetSelf(struct cpu_state*,struct tlb*);
void ft_PyCFunction_GetFlags(struct cpu_state*,struct tlb*);
void ft_PySlice_GetIndices(struct cpu_state*,struct tlb*);
void ft__PyLong_UnsignedInt_Converter(struct cpu_state*,struct tlb*);
void ft__PyLong_Size_t_Converter(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_GetTraces(struct cpu_state*,struct tlb*);
void ft_PyDict_Values(struct cpu_state*,struct tlb*);
void ft__PyState_AddModule(struct cpu_state*,struct tlb*);
void ft_PyState_RemoveModule(struct cpu_state*,struct tlb*);
void ft_PyFunction_GetCode(struct cpu_state*,struct tlb*);
void ft_PyFunction_GetGlobals(struct cpu_state*,struct tlb*);
void ft_PyFunction_GetDefaults(struct cpu_state*,struct tlb*);
void ft_PyFunction_SetDefaults(struct cpu_state*,struct tlb*);
void ft_PyFunction_GetKwDefaults(struct cpu_state*,struct tlb*);
void ft_PyFunction_SetKwDefaults(struct cpu_state*,struct tlb*);
void ft_PyFunction_GetClosure(struct cpu_state*,struct tlb*);
void ft_PyFunction_SetClosure(struct cpu_state*,struct tlb*);
void ft_PyFunction_SetAnnotations(struct cpu_state*,struct tlb*);
void ft_PyUnstable_Code_GetExtra(struct cpu_state*,struct tlb*);
void ft_PyUnstable_Code_SetExtra(struct cpu_state*,struct tlb*);
void ft_PyMethod_Function(struct cpu_state*,struct tlb*);
void ft_PyMethod_Self(struct cpu_state*,struct tlb*);
void ft_PyInstanceMethod_Function(struct cpu_state*,struct tlb*);
void ft_PyCell_Get(struct cpu_state*,struct tlb*);
void ft__PyBytes_DecodeEscape(struct cpu_state*,struct tlb*);
void ft_PyContext_Enter(struct cpu_state*,struct tlb*);
void ft_PyErr_SetInterruptEx(struct cpu_state*,struct tlb*);
void ft_PyErr_SetInterrupt(struct cpu_state*,struct tlb*);
void ft_PyDict_GetItemString(struct cpu_state*,struct tlb*);
void ft__PySys_GetAttr(struct cpu_state*,struct tlb*);
void ft_PySys_HasWarnOptions(struct cpu_state*,struct tlb*);
void ft_PyEval_EvalCodeEx(struct cpu_state*,struct tlb*);
void ft__PyUnicode_FromId(struct cpu_state*,struct tlb*);
void ft__PyUnicode_EqualToASCIIId(struct cpu_state*,struct tlb*);
void ft__PyObject_GetAttrId(struct cpu_state*,struct tlb*);
void ft__PyObject_SetAttrId(struct cpu_state*,struct tlb*);
void ft__PyObject_LookupAttrId(struct cpu_state*,struct tlb*);
void ft__PyDict_GetItemIdWithError(struct cpu_state*,struct tlb*);
void ft__PyDict_DelItemId(struct cpu_state*,struct tlb*);
void ft_PyUnicode_InternImmortal(struct cpu_state*,struct tlb*);
void ft_PyStructSequence_InitType2(struct cpu_state*,struct tlb*);
void ft_PyStructSequence_InitType(struct cpu_state*,struct tlb*);
void ft__PyDict_SetItemId(struct cpu_state*,struct tlb*);
void ft_PySys_GetXOptions(struct cpu_state*,struct tlb*);
void ft_PySys_AddWarnOptionUnicode(struct cpu_state*,struct tlb*);
void ft_PySys_AddWarnOption(struct cpu_state*,struct tlb*);
void ft_PySys_AddXOption(struct cpu_state*,struct tlb*);
void ft__PyThread_CurrentFrames(struct cpu_state*,struct tlb*);
void ft__PyThread_CurrentExceptions(struct cpu_state*,struct tlb*);
void ft_PyFunction_GetAnnotations(struct cpu_state*,struct tlb*);
void ft__PyType_LookupId(struct cpu_state*,struct tlb*);
void ft__PyObject_LookupSpecialId(struct cpu_state*,struct tlb*);
void ft_PyVectorcall_Call(struct cpu_state*,struct tlb*);
void ft__PyExc_CreateExceptionGroup(struct cpu_state*,struct tlb*);
void ft__PyErr_CheckSignals(struct cpu_state*,struct tlb*);
void ft_PyEval_CallObjectWithKeywords(struct cpu_state*,struct tlb*);
void ft_PyCodec_Decoder(struct cpu_state*,struct tlb*);
void ft_PyCodec_Encoder(struct cpu_state*,struct tlb*);
void ft_PyCodec_KnownEncoding(struct cpu_state*,struct tlb*);
void ft_PyByteArray_FromObject(struct cpu_state*,struct tlb*);
void ft_PyIter_Send(struct cpu_state*,struct tlb*);
void ft_PySlice_GetIndicesEx(struct cpu_state*,struct tlb*);
void ft__Py_Uid_Converter(struct cpu_state*,struct tlb*);
void ft__Py_Gid_Converter(struct cpu_state*,struct tlb*);
void ft__PyInterpreterID_LookUp(struct cpu_state*,struct tlb*);
void ft_PyEval_GetFuncName(struct cpu_state*,struct tlb*);
void ft_PyModule_GetFilename(struct cpu_state*,struct tlb*);
void ft__PyImport_ClearExtension(struct cpu_state*,struct tlb*);
void ft__Py_UTF8_Edit_Cost(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsUTF32String(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsUTF16String(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeLocaleAndSize(struct cpu_state*,struct tlb*);
void ft__Py_get_inheritable(struct cpu_state*,struct tlb*);
void ft__Py_set_inheritable_async_safe(struct cpu_state*,struct tlb*);
void ft__Py_fstat(struct cpu_state*,struct tlb*);
void ft__Py_get_blocking(struct cpu_state*,struct tlb*);
void ft__Py_set_blocking(struct cpu_state*,struct tlb*);
void ft_PyObject_Print(struct cpu_state*,struct tlb*);
void ft__PyErr_SetLocaleString(struct cpu_state*,struct tlb*);
void ft_PyErr_SetFromErrnoWithFilename(struct cpu_state*,struct tlb*);
void ft__Py_stat(struct cpu_state*,struct tlb*);
void ft_PyCodec_StreamWriter(struct cpu_state*,struct tlb*);
void ft_PyCodec_StreamReader(struct cpu_state*,struct tlb*);
void ft__Py_GetConfigsAsDict(struct cpu_state*,struct tlb*);
void ft_PySys_SetPath(struct cpu_state*,struct tlb*);
void ft_PySys_SetArgvEx(struct cpu_state*,struct tlb*);
void ft_PySys_SetArgv(struct cpu_state*,struct tlb*);
void ft_PyUnicode_RSplit(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Find(struct cpu_state*,struct tlb*);
void ft_PyMapping_Values(struct cpu_state*,struct tlb*);
void ft_PyObject_Length(struct cpu_state*,struct tlb*);
void ft__Py_strhex_bytes(struct cpu_state*,struct tlb*);
void ft_PyMapping_Length(struct cpu_state*,struct tlb*);
void ft_PySequence_DelSlice(struct cpu_state*,struct tlb*);
void ft_PySequence_SetSlice(struct cpu_state*,struct tlb*);
void ft_PyObject_DelItemString(struct cpu_state*,struct tlb*);
void ft_PySequence_Length(struct cpu_state*,struct tlb*);
void ft_PyBytes_ConcatAndDel(struct cpu_state*,struct tlb*);
void ft__PyEval_SetProfile(struct cpu_state*,struct tlb*);
void ft__PyErr_ChainExceptions(struct cpu_state*,struct tlb*);
void ft_PyErr_SetImportErrorSubclass(struct cpu_state*,struct tlb*);
void ft_PyErr_SetImportError(struct cpu_state*,struct tlb*);
void ft_PyMapping_HasKeyString(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_GetMainModule(struct cpu_state*,struct tlb*);
void ft_PyMapping_HasKey(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsCharmapString(struct cpu_state*,struct tlb*);
void ft__PyImport_GetModuleId(struct cpu_state*,struct tlb*);
void ft_PyUnstable_Code_New(struct cpu_state*,struct tlb*);
void ft__PyCompile_OptimizeCfg(struct cpu_state*,struct tlb*);
void ft__PyDictView_Intersect(struct cpu_state*,struct tlb*);
void ft__PyExc_PrepReraiseStar(struct cpu_state*,struct tlb*);
void ft_PyUnstable_Exc_PrepReraiseStar(struct cpu_state*,struct tlb*);
void ft__PyDict_ContainsId(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetLocals(struct cpu_state*,struct tlb*);
void ft_PyFrame_FastToLocalsWithError(struct cpu_state*,struct tlb*);
void ft_PyFrame_FastToLocals(struct cpu_state*,struct tlb*);
void ft_PyEval_GetLocals(struct cpu_state*,struct tlb*);
void ft_PyImport_ExecCodeModuleObject(struct cpu_state*,struct tlb*);
void ft_PyImport_ExecCodeModuleWithPathnames(struct cpu_state*,struct tlb*);
void ft_PyImport_ExecCodeModuleEx(struct cpu_state*,struct tlb*);
void ft_PyImport_ExecCodeModule(struct cpu_state*,struct tlb*);
void ft__PyType_CheckConsistency(struct cpu_state*,struct tlb*);
void ft__PyObject_CheckConsistency(struct cpu_state*,struct tlb*);
void ft__PyCompile_Assemble(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeUTF7(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Translate(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeUnicodeEscape(struct cpu_state*,struct tlb*);
void ft__PyUnicode_DecodeUnicodeEscapeInternal(struct cpu_state*,struct tlb*);
void ft_PyFile_FromFd(struct cpu_state*,struct tlb*);
void ft_PyFile_OpenCode(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsDecodedObject(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsDecodedUnicode(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsEncodedObject(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_Clear(struct cpu_state*,struct tlb*);
void ft_PyErr_Print(struct cpu_state*,struct tlb*);
void ft_PyErr_PrintEx(struct cpu_state*,struct tlb*);
void ft__PyErr_Print(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_IDDecref(struct cpu_state*,struct tlb*);
void ft__PyInterpreterID_New(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_GetIDObject(struct cpu_state*,struct tlb*);
void ft_PyEval_SetProfile(struct cpu_state*,struct tlb*);
void ft_PyEval_SetProfileAllThreads(struct cpu_state*,struct tlb*);
void ft_PyEval_SetTrace(struct cpu_state*,struct tlb*);
void ft__Py_open(struct cpu_state*,struct tlb*);
void ft_PyErr_ProgramText(struct cpu_state*,struct tlb*);
void ft_PyErr_SyntaxLocationEx(struct cpu_state*,struct tlb*);
void ft_PyErr_SyntaxLocation(struct cpu_state*,struct tlb*);
void ft_PyRun_SimpleString(struct cpu_state*,struct tlb*);
void ft_PyRun_String(struct cpu_state*,struct tlb*);
void ft_Py_CompileString(struct cpu_state*,struct tlb*);
void ft_Py_CompileStringFlags(struct cpu_state*,struct tlb*);
void ft_PyMarshal_ReadLastObjectFromFile(struct cpu_state*,struct tlb*);
void ft_Py_NewInterpreterFromConfig(struct cpu_state*,struct tlb*);
void ft__PyCompile_CodeGen(struct cpu_state*,struct tlb*);
void ft_PyFile_SetOpenCodeHook(struct cpu_state*,struct tlb*);
void ft_PyRun_InteractiveOneObject(struct cpu_state*,struct tlb*);
void ft_PyRun_InteractiveOneFlags(struct cpu_state*,struct tlb*);
void ft_PyRun_InteractiveOne(struct cpu_state*,struct tlb*);
void ft_PyRun_InteractiveLoopFlags(struct cpu_state*,struct tlb*);
void ft_PyRun_InteractiveLoop(struct cpu_state*,struct tlb*);
void ft_PyRun_SimpleFileExFlags(struct cpu_state*,struct tlb*);
void ft_PyRun_SimpleFile(struct cpu_state*,struct tlb*);
void ft_PyRun_SimpleFileEx(struct cpu_state*,struct tlb*);
void ft_PyRun_AnyFileExFlags(struct cpu_state*,struct tlb*);
void ft_PyRun_AnyFile(struct cpu_state*,struct tlb*);
void ft_PyRun_AnyFileEx(struct cpu_state*,struct tlb*);
void ft_PyRun_AnyFileFlags(struct cpu_state*,struct tlb*);
void ft_PyRun_FileExFlags(struct cpu_state*,struct tlb*);
void ft_PyRun_File(struct cpu_state*,struct tlb*);
void ft_PyRun_FileEx(struct cpu_state*,struct tlb*);
void ft_Py_ExitStatusException(struct cpu_state*,struct tlb*);
void ft_Py_Initialize(struct cpu_state*,struct tlb*);
void ft_PyOS_AfterFork(struct cpu_state*,struct tlb*);
void ft_Py_Main(struct cpu_state*,struct tlb*);
void ft__PyErr_DisplayException(struct cpu_state*,struct tlb*);
void ft_PyOS_InterruptOccurred(struct cpu_state*,struct tlb*);
void ft__PyOS_IsMainThread(struct cpu_state*,struct tlb*);
void ft__Py_Get_Getpath_CodeObject(struct cpu_state*,struct tlb*);
void ft_PyMem_RawMalloc(struct cpu_state*,struct tlb*);
void ft_PyThread_get_thread_ident(struct cpu_state*,struct tlb*);
void ft_PyMem_RawFree(struct cpu_state*,struct tlb*);
void ft_PyObject_Hash(struct cpu_state*,struct tlb*);
void ft__Py_HashBytes(struct cpu_state*,struct tlb*);
void ft_PyMem_RawCalloc(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_get(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_set(struct cpu_state*,struct tlb*);
void ft_PyList_New(struct cpu_state*,struct tlb*);
void ft__PyObject_GC_New(struct cpu_state*,struct tlb*);
void ft__Py_NewReference(struct cpu_state*,struct tlb*);
void ft_PyTuple_New(struct cpu_state*,struct tlb*);
void ft__PyUnicode_InternImmortal(struct cpu_state*,struct tlb*);
void ft_PyMem_Malloc(struct cpu_state*,struct tlb*);
void ft_PyMem_Calloc(struct cpu_state*,struct tlb*);
void ft_PyMem_Free(struct cpu_state*,struct tlb*);
void ft__PyUnicode_InternMortal(struct cpu_state*,struct tlb*);
void ft_PySequence_Tuple(struct cpu_state*,struct tlb*);
void ft_PyList_AsTuple(struct cpu_state*,struct tlb*);
void ft__PyObject_GC_NewVar(struct cpu_state*,struct tlb*);
void ft__Py_Dealloc(struct cpu_state*,struct tlb*);
void ft_PyObject_GC_UnTrack(struct cpu_state*,struct tlb*);
void ft__PyTrash_cond(struct cpu_state*,struct tlb*);
void ft__PyThreadState_GetCurrent(struct cpu_state*,struct tlb*);
void ft__PyThreadState_UncheckedGet(struct cpu_state*,struct tlb*);
void ft__PyTrash_begin(struct cpu_state*,struct tlb*);
void ft__PyTrash_end(struct cpu_state*,struct tlb*);
void ft_PyType_IsSubtype(struct cpu_state*,struct tlb*);
void ft_PyDict_Contains(struct cpu_state*,struct tlb*);
void ft_PyCMethod_New(struct cpu_state*,struct tlb*);
void ft_PyObject_IS_GC(struct cpu_state*,struct tlb*);
void ft_PyType_GenericAlloc(struct cpu_state*,struct tlb*);
void ft_PyUnicode_InternFromString(struct cpu_state*,struct tlb*);
void ft_PyUnicode_New(struct cpu_state*,struct tlb*);
void ft_PyObject_Free(struct cpu_state*,struct tlb*);
void ft_PyTuple_Pack(struct cpu_state*,struct tlb*);
void ft_PyLong_FromVoidPtr(struct cpu_state*,struct tlb*);
void ft_PyLong_FromUnsignedLong(struct cpu_state*,struct tlb*);
void ft__PyLong_New(struct cpu_state*,struct tlb*);
void ft_PyWeakref_NewRef(struct cpu_state*,struct tlb*);
void ft_PyObject_GC_Track(struct cpu_state*,struct tlb*);
void ft_PyObject_GC_Del(struct cpu_state*,struct tlb*);
void ft_PyUnicode_FromStringAndSize(struct cpu_state*,struct tlb*);
void ft_PyErr_Occurred(struct cpu_state*,struct tlb*);
void ft_PyObject_GetItemData(struct cpu_state*,struct tlb*);
void ft__PyType_GetDict(struct cpu_state*,struct tlb*);
void ft_PyLong_FromSsize_t(struct cpu_state*,struct tlb*);
void ft_PyLong_FromLong(struct cpu_state*,struct tlb*);
void ft_PyDict_GetItemWithError(struct cpu_state*,struct tlb*);
void ft_PyObject_SetAttr(struct cpu_state*,struct tlb*);
void ft_PyObject_GenericSetAttr(struct cpu_state*,struct tlb*);
void ft__PyType_Lookup(struct cpu_state*,struct tlb*);
void ft__PyDict_GetItem_KnownHash(struct cpu_state*,struct tlb*);
void ft__PyObject_New(struct cpu_state*,struct tlb*);
void ft_PyObject_GetItem(struct cpu_state*,struct tlb*);
void ft_PyStructSequence_New(struct cpu_state*,struct tlb*);
void ft_PyLong_AsSsize_t(struct cpu_state*,struct tlb*);
void ft_PyList_Append(struct cpu_state*,struct tlb*);
void ft_PyMem_Realloc(struct cpu_state*,struct tlb*);
void ft_PyObject_GetIter(struct cpu_state*,struct tlb*);
void ft__Py_CheckFunctionResult(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_GetConfig(struct cpu_state*,struct tlb*);
void ft_PyBool_FromLong(struct cpu_state*,struct tlb*);
void ft_PyObject_SetItem(struct cpu_state*,struct tlb*);
void ft_PyUnicode_CompareWithASCIIString(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsUTF8AndSize(struct cpu_state*,struct tlb*);
void ft__PyUnicode_FromASCII(struct cpu_state*,struct tlb*);
void ft_PyBytes_FromStringAndSize(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_Get(struct cpu_state*,struct tlb*);
void ft_PyDict_Next(struct cpu_state*,struct tlb*);
void ft__PyDict_Next(struct cpu_state*,struct tlb*);
void ft__PyObject_LookupSpecial(struct cpu_state*,struct tlb*);
void ft_PyObject_GetAttr(struct cpu_state*,struct tlb*);
void ft__PyObject_FastCallDictTstate(struct cpu_state*,struct tlb*);
void ft__PyDict_GetItemStringWithError(struct cpu_state*,struct tlb*);
void ft__PyArena_AddPyObject(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeUTF8(struct cpu_state*,struct tlb*);
void ft__PyArena_Malloc(struct cpu_state*,struct tlb*);
void ft__PyToken_TwoChars(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsPrintable(struct cpu_state*,struct tlb*);
void ft__PyToken_OneChar(struct cpu_state*,struct tlb*);
void ft_PyFunction_New(struct cpu_state*,struct tlb*);
void ft_PyFunction_NewWithQualName(struct cpu_state*,struct tlb*);
void ft_PyTuple_Size(struct cpu_state*,struct tlb*);
void ft_PyTuple_GetItem(struct cpu_state*,struct tlb*);
void ft_PyObject_Vectorcall(struct cpu_state*,struct tlb*);
void ft__PyObject_LookupAttr(struct cpu_state*,struct tlb*);
void ft_PyDescr_IsData(struct cpu_state*,struct tlb*);
void ft_PyType_GenericNew(struct cpu_state*,struct tlb*);
void ft__PyObject_GenericGetAttrWithDict(struct cpu_state*,struct tlb*);
void ft__PyArg_CheckPositional(struct cpu_state*,struct tlb*);
void ft_PyNumber_Add(struct cpu_state*,struct tlb*);
void ft_PyOS_strtol(struct cpu_state*,struct tlb*);
void ft_PyOS_strtoul(struct cpu_state*,struct tlb*);
void ft__PyUnicode_DecodeUnicodeEscapeInternal2(struct cpu_state*,struct tlb*);
void ft__PyUnicodeWriter_Finish(struct cpu_state*,struct tlb*);
void ft_PyObject_Realloc(struct cpu_state*,struct tlb*);
void ft__Py_NewReferenceNoTotal(struct cpu_state*,struct tlb*);
void ft__PyUnicode_EqualToASCIIString(struct cpu_state*,struct tlb*);
void ft_PyObject_GetAttrString(struct cpu_state*,struct tlb*);
void ft_PyModule_GetState(struct cpu_state*,struct tlb*);
void ft_PyCallable_Check(struct cpu_state*,struct tlb*);
void ft__PyFunction_Vectorcall(struct cpu_state*,struct tlb*);
void ft__PyBytesWriter_Prepare(struct cpu_state*,struct tlb*);
void ft__PyBytesWriter_Finish(struct cpu_state*,struct tlb*);
void ft_PyObject_GetBuffer(struct cpu_state*,struct tlb*);
void ft_PySequence_Contains(struct cpu_state*,struct tlb*);
void ft_PyBuffer_FillInfo(struct cpu_state*,struct tlb*);
void ft_PyObject_RichCompareBool(struct cpu_state*,struct tlb*);
void ft_PyBuffer_Release(struct cpu_state*,struct tlb*);
void ft_PyObject_RichCompare(struct cpu_state*,struct tlb*);
void ft_PyUnicode_RichCompare(struct cpu_state*,struct tlb*);
void ft__PyUnicodeWriter_WriteASCIIString(struct cpu_state*,struct tlb*);
void ft__PyUnicodeWriter_WriteStr(struct cpu_state*,struct tlb*);
void ft__PyErr_SetObject(struct cpu_state*,struct tlb*);
void ft_PyObject_CallOneArg(struct cpu_state*,struct tlb*);
void ft_PyException_GetTraceback(struct cpu_state*,struct tlb*);
void ft__PyErr_Restore(struct cpu_state*,struct tlb*);
void ft_PyErr_ExceptionMatches(struct cpu_state*,struct tlb*);
void ft__PyErr_ExceptionMatches(struct cpu_state*,struct tlb*);
void ft_PyErr_GivenExceptionMatches(struct cpu_state*,struct tlb*);
void ft_PyErr_GetRaisedException(struct cpu_state*,struct tlb*);
void ft_PyErr_SetRaisedException(struct cpu_state*,struct tlb*);
void ft_PyErr_Clear(struct cpu_state*,struct tlb*);
void ft__PyModuleSpec_IsInitializing(struct cpu_state*,struct tlb*);
void ft_PyTraceBack_Here(struct cpu_state*,struct tlb*);
void ft__PyTraceBack_FromFrame(struct cpu_state*,struct tlb*);
void ft_PyException_SetTraceback(struct cpu_state*,struct tlb*);
void ft_PyObject_IsTrue(struct cpu_state*,struct tlb*);
void ft__PyObject_Call_Prepend(struct cpu_state*,struct tlb*);
void ft_PyNumber_AsSsize_t(struct cpu_state*,struct tlb*);
void ft__PyNumber_Index(struct cpu_state*,struct tlb*);
void ft__PyDict_MergeEx(struct cpu_state*,struct tlb*);
void ft_PyObject_Call(struct cpu_state*,struct tlb*);
void ft__PyObject_Call(struct cpu_state*,struct tlb*);
void ft_PyLong_AsLong(struct cpu_state*,struct tlb*);
void ft_PyLong_AsLongAndOverflow(struct cpu_state*,struct tlb*);
void ft_PySet_New(struct cpu_state*,struct tlb*);
void ft_PySet_Add(struct cpu_state*,struct tlb*);
void ft_PySet_Discard(struct cpu_state*,struct tlb*);
void ft__PyUnicode_Equal(struct cpu_state*,struct tlb*);
void ft_PySet_Contains(struct cpu_state*,struct tlb*);
void ft_PyNumber_InPlaceOr(struct cpu_state*,struct tlb*);
void ft_PyObject_Calloc(struct cpu_state*,struct tlb*);
void ft_PyObject_Format(struct cpu_state*,struct tlb*);
void ft_PyNumber_Lshift(struct cpu_state*,struct tlb*);
void ft_PyObject_Str(struct cpu_state*,struct tlb*);
void ft_PyErr_CheckSignals(struct cpu_state*,struct tlb*);
void ft__PyUnicode_JoinArray(struct cpu_state*,struct tlb*);
void ft_PyNumber_Negative(struct cpu_state*,struct tlb*);
void ft_PyUnicode_FindChar(struct cpu_state*,struct tlb*);
void ft_PyObject_IsSubclass(struct cpu_state*,struct tlb*);
void ft__PyList_Extend(struct cpu_state*,struct tlb*);
void ft_PySequence_Fast(struct cpu_state*,struct tlb*);
void ft_PyObject_SelfIter(struct cpu_state*,struct tlb*);
void ft_PyObject_CallFinalizerFromDealloc(struct cpu_state*,struct tlb*);
void ft_PyObject_CallFinalizer(struct cpu_state*,struct tlb*);
void ft__PyGen_Finalize(struct cpu_state*,struct tlb*);
void ft__PyLong_AsInt(struct cpu_state*,struct tlb*);
void ft_PyImport_ImportModuleLevelObject(struct cpu_state*,struct tlb*);
void ft__PyBytes_Resize(struct cpu_state*,struct tlb*);
void ft__Py_HashPointer(struct cpu_state*,struct tlb*);
void ft_PyObject_ClearWeakRefs(struct cpu_state*,struct tlb*);
void ft_PyObject_CheckBuffer(struct cpu_state*,struct tlb*);
void ft_PyObject_LengthHint(struct cpu_state*,struct tlb*);
void ft__PyObject_HasLen(struct cpu_state*,struct tlb*);
void ft_PyObject_Size(struct cpu_state*,struct tlb*);
void ft__PyObject_VisitManagedDict(struct cpu_state*,struct tlb*);
void ft_PyEval_GetGlobals(struct cpu_state*,struct tlb*);
void ft__Py_HashPointerRaw(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_destroy(struct cpu_state*,struct tlb*);
void ft_PyObject_DelItem(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Join(struct cpu_state*,struct tlb*);
void ft__PyLong_AsByteArray(struct cpu_state*,struct tlb*);
void ft__PyLong_FromByteArray(struct cpu_state*,struct tlb*);
void ft_PyImport_Import(struct cpu_state*,struct tlb*);
void ft_PySlice_Unpack(struct cpu_state*,struct tlb*);
void ft__PyEval_SliceIndex(struct cpu_state*,struct tlb*);
void ft_PySlice_AdjustIndices(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsEncodedString(struct cpu_state*,struct tlb*);
void ft__PyBytesWriter_Init(struct cpu_state*,struct tlb*);
void ft__PyBytesWriter_Alloc(struct cpu_state*,struct tlb*);
void ft_PyObject_VectorcallMethod(struct cpu_state*,struct tlb*);
void ft_PyIndex_Check(struct cpu_state*,struct tlb*);
void ft_PyLong_FromUnsignedLongLong(struct cpu_state*,struct tlb*);
void ft_PyLong_FromLongLong(struct cpu_state*,struct tlb*);
void ft_PyNumber_Multiply(struct cpu_state*,struct tlb*);
void ft__PyLong_Sign(struct cpu_state*,struct tlb*);
void ft_PyType_GetModuleByDef(struct cpu_state*,struct tlb*);
void ft_PyBuffer_IsContiguous(struct cpu_state*,struct tlb*);
void ft_PySequence_GetItem(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsAlpha(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsDecimalDigit(struct cpu_state*,struct tlb*);
void ft__PyUnicode_ToDecimalDigit(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsDigit(struct cpu_state*,struct tlb*);
void ft__PyUnicode_ToDigit(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsNumeric(struct cpu_state*,struct tlb*);
void ft__PyUnicode_AsASCIIString(struct cpu_state*,struct tlb*);
void ft_PySequence_List(struct cpu_state*,struct tlb*);
void ft_PyObject_Repr(struct cpu_state*,struct tlb*);
void ft_PyNumber_Or(struct cpu_state*,struct tlb*);
void ft_PyNumber_Index(struct cpu_state*,struct tlb*);
void ft_PyNumber_FloorDivide(struct cpu_state*,struct tlb*);
void ft_PyIter_Check(struct cpu_state*,struct tlb*);
void ft_PyUnicode_FromEncodedObject(struct cpu_state*,struct tlb*);
void ft_PyNumber_Remainder(struct cpu_state*,struct tlb*);
void ft__PyUnicodeWriter_WriteSubstring(struct cpu_state*,struct tlb*);
void ft__PyLong_FormatWriter(struct cpu_state*,struct tlb*);
void ft__Py_convert_optional_to_ssize_t(struct cpu_state*,struct tlb*);
void ft__PyDict_MaybeUntrack(struct cpu_state*,struct tlb*);
void ft_PyDict_MergeFromSeq2(struct cpu_state*,struct tlb*);
void ft_PyMapping_Size(struct cpu_state*,struct tlb*);
void ft_PyBytes_Repr(struct cpu_state*,struct tlb*);
void ft__PyCode_CheckLineNumber(struct cpu_state*,struct tlb*);
void ft__PyUnicode_TransformDecimalAndSpaceToASCII(struct cpu_state*,struct tlb*);
void ft__PyLong_Format(struct cpu_state*,struct tlb*);
void ft__PyUnicode_InsertThousandsGrouping(struct cpu_state*,struct tlb*);
void ft_PyLong_AsDouble(struct cpu_state*,struct tlb*);
void ft_PyNumber_Rshift(struct cpu_state*,struct tlb*);
void ft_PyNumber_InPlaceLshift(struct cpu_state*,struct tlb*);
void ft_PyNumber_Absolute(struct cpu_state*,struct tlb*);
void ft__PyLong_Copy(struct cpu_state*,struct tlb*);
void ft_PyNumber_Divmod(struct cpu_state*,struct tlb*);
void ft_PyThreadState_EnterTracing(struct cpu_state*,struct tlb*);
void ft__PyLong_GCD(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsUnicodeEscapeString(struct cpu_state*,struct tlb*);
void ft__PyUnicode_EncodeUTF7(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeUTF7Stateful(struct cpu_state*,struct tlb*);
void ft_Py_NewRef(struct cpu_state*,struct tlb*);
void ft__PyUnicode_InternInPlace(struct cpu_state*,struct tlb*);
void ft_PyCFunction_Call(struct cpu_state*,struct tlb*);
void ft_Py_BytesMain(struct cpu_state*,struct tlb*);
void ft__PyRuntime_Initialize(struct cpu_state*,struct tlb*);
void ft_PyConfig_SetBytesArgv(struct cpu_state*,struct tlb*);
void ft__PyRuntimeState_Init(struct cpu_state*,struct tlb*);
void ft__PyMem_SetDefaultAllocator(struct cpu_state*,struct tlb*);
void ft_PyThread_allocate_lock(struct cpu_state*,struct tlb*);
void ft_PyThread_init_thread(struct cpu_state*,struct tlb*);
void ft_PyMem_SetAllocator(struct cpu_state*,struct tlb*);
void ft_PyThread_tss_create(struct cpu_state*,struct tlb*);
void ft__PyMem_RawStrdup(struct cpu_state*,struct tlb*);
void ft__Py_SetLocaleFromEnv(struct cpu_state*,struct tlb*);
void ft__Py_ResetForceASCII(struct cpu_state*,struct tlb*);
void ft__PyArgv_AsWstrList(struct cpu_state*,struct tlb*);
void ft_Py_DecodeLocale(struct cpu_state*,struct tlb*);
void ft__PyWideStringList_Clear(struct cpu_state*,struct tlb*);
void ft__Py_get_xoption(struct cpu_state*,struct tlb*);
void ft__Py_GetEnv(struct cpu_state*,struct tlb*);
void ft_PyWideStringList_Append(struct cpu_state*,struct tlb*);
void ft_PyWideStringList_Insert(struct cpu_state*,struct tlb*);
void ft__PyMem_RawWcsdup(struct cpu_state*,struct tlb*);
void ft_PyStatus_Exception(struct cpu_state*,struct tlb*);
void ft__Py_LegacyLocaleDetected(struct cpu_state*,struct tlb*);
void ft_PyConfig_Clear(struct cpu_state*,struct tlb*);
void ft_PyConfig_Read(struct cpu_state*,struct tlb*);
void ft_PyThread_acquire_lock(struct cpu_state*,struct tlb*);
void ft_PyThread_acquire_lock_timed(struct cpu_state*,struct tlb*);
void ft__PyTime_FromNanoseconds(struct cpu_state*,struct tlb*);
void ft_Py_GetBuildInfo(struct cpu_state*,struct tlb*);
void ft__Py_IsLocaleCoercionTarget(struct cpu_state*,struct tlb*);
void ft_PyStatus_Ok(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_New(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_Init(struct cpu_state*,struct tlb*);
void ft_PyMem_GetAllocator(struct cpu_state*,struct tlb*);
void ft__PyThreadState_New(struct cpu_state*,struct tlb*);
void ft__PyThreadState_Bind(struct cpu_state*,struct tlb*);
void ft_PyThread_get_thread_native_id(struct cpu_state*,struct tlb*);
void ft_PyThread_tss_get(struct cpu_state*,struct tlb*);
void ft_Py_GETENV(struct cpu_state*,struct tlb*);
void ft_PyGILState_Check(struct cpu_state*,struct tlb*);
void ft_PyThread_tss_is_created(struct cpu_state*,struct tlb*);
void ft_PyDescr_NewWrapper(struct cpu_state*,struct tlb*);
void ft_PyDescr_NewMethod(struct cpu_state*,struct tlb*);
void ft_PyDescr_NewClassMethod(struct cpu_state*,struct tlb*);
void ft_PyDescr_NewGetSet(struct cpu_state*,struct tlb*);
void ft_PyDescr_NewMember(struct cpu_state*,struct tlb*);
void ft_PyStaticMethod_New(struct cpu_state*,struct tlb*);
void ft_PyType_FromSpec(struct cpu_state*,struct tlb*);
void ft__PyType_CalculateMetaclass(struct cpu_state*,struct tlb*);
void ft_PyType_Ready(struct cpu_state*,struct tlb*);
void ft_PyType_Modified(struct cpu_state*,struct tlb*);
void ft_PyDict_SetItemString(struct cpu_state*,struct tlb*);
void ft__PyModule_CreateInitialized(struct cpu_state*,struct tlb*);
void ft_PyModuleDef_Init(struct cpu_state*,struct tlb*);
void ft_PyModule_New(struct cpu_state*,struct tlb*);
void ft_PyModule_AddFunctions(struct cpu_state*,struct tlb*);
void ft_PyModule_GetNameObject(struct cpu_state*,struct tlb*);
void ft_PyObject_SetAttrString(struct cpu_state*,struct tlb*);
void ft_PyModule_SetDocString(struct cpu_state*,struct tlb*);
void ft_PyModule_GetDict(struct cpu_state*,struct tlb*);
void ft_PyDict_Copy(struct cpu_state*,struct tlb*);
void ft_PyFile_NewStdPrinter(struct cpu_state*,struct tlb*);
void ft_PyMapping_GetItemString(struct cpu_state*,struct tlb*);
void ft_Py_GetVersion(struct cpu_state*,struct tlb*);
void ft__Py_gitversion(struct cpu_state*,struct tlb*);
void ft__Py_gitidentifier(struct cpu_state*,struct tlb*);
void ft_Py_GetCopyright(struct cpu_state*,struct tlb*);
void ft_Py_GetPlatform(struct cpu_state*,struct tlb*);
void ft_PyFloat_GetInfo(struct cpu_state*,struct tlb*);
void ft_PyLong_GetInfo(struct cpu_state*,struct tlb*);
void ft_PyHash_GetFuncDef(struct cpu_state*,struct tlb*);
void ft_PyList_Sort(struct cpu_state*,struct tlb*);
void ft__PyNamespace_New(struct cpu_state*,struct tlb*);
void ft_PyDict_Update(struct cpu_state*,struct tlb*);
void ft_PyThread_GetInfo(struct cpu_state*,struct tlb*);
void ft__PyImport_FixupBuiltin(struct cpu_state*,struct tlb*);
void ft_PyModule_GetDef(struct cpu_state*,struct tlb*);
void ft_PyList_SetItem(struct cpu_state*,struct tlb*);
void ft_PyDict_GetItem(struct cpu_state*,struct tlb*);
void ft__Py_GetConfig(struct cpu_state*,struct tlb*);
void ft__PyObject_NewVar(struct cpu_state*,struct tlb*);
void ft_PyErr_NewException(struct cpu_state*,struct tlb*);
void ft__PyObject_FastCall(struct cpu_state*,struct tlb*);
void ft_PyObject_VectorcallDict(struct cpu_state*,struct tlb*);
void ft__Py_fstat_noraise(struct cpu_state*,struct tlb*);
void ft_Py_CompileStringExFlags(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeFSDefault(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeFSDefaultAndSize(struct cpu_state*,struct tlb*);
void ft_Py_CompileStringObject(struct cpu_state*,struct tlb*);
void ft__PyArena_New(struct cpu_state*,struct tlb*);
void ft_PyImport_ImportFrozenModule(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsUTF8(struct cpu_state*,struct tlb*);
void ft__PyCode_Validate(struct cpu_state*,struct tlb*);
void ft_PyEval_EvalCode(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeUTF8Stateful(struct cpu_state*,struct tlb*);
void ft__PyDict_GetItemWithError(struct cpu_state*,struct tlb*);
void ft_PyMapping_Check(struct cpu_state*,struct tlb*);
void ft_PyDict_DelItem(struct cpu_state*,struct tlb*);
void ft__PyDict_DelItem_KnownHash(struct cpu_state*,struct tlb*);
void ft_PyObject_Type(struct cpu_state*,struct tlb*);
void ft__PyToken_ThreeChars(struct cpu_state*,struct tlb*);
void ft_PyImport_AddModule(struct cpu_state*,struct tlb*);
void ft_PyImport_AddModuleObject(struct cpu_state*,struct tlb*);
void ft_PyWeakref_GetObject(struct cpu_state*,struct tlb*);
void ft_PyInit__imp(struct cpu_state*,struct tlb*);
void ft_PyModule_FromDefAndSpec2(struct cpu_state*,struct tlb*);
void ft_PyModule_ExecDef(struct cpu_state*,struct tlb*);
void ft_PyModule_GetName(struct cpu_state*,struct tlb*);
void ft_PyModule_AddObjectRef(struct cpu_state*,struct tlb*);
void ft__PyImport_SetModuleString(struct cpu_state*,struct tlb*);
void ft_PyMapping_SetItemString(struct cpu_state*,struct tlb*);
void ft__PyDictView_New(struct cpu_state*,struct tlb*);
void ft__PyBytes_DecodeEscape2(struct cpu_state*,struct tlb*);
void ft_PyBytes_FromString(struct cpu_state*,struct tlb*);
void ft__PyStack_AsDict(struct cpu_state*,struct tlb*);
void ft__PyDict_Pop(struct cpu_state*,struct tlb*);
void ft_PyArg_ValidateKeywordArguments(struct cpu_state*,struct tlb*);
void ft__PyDict_HasOnlyStringKeys(struct cpu_state*,struct tlb*);
void ft_PyModule_AddType(struct cpu_state*,struct tlb*);
void ft__PyType_Name(struct cpu_state*,struct tlb*);
void ft_PyType_FromModuleAndSpec(struct cpu_state*,struct tlb*);
void ft_PyStructSequence_NewType(struct cpu_state*,struct tlb*);
void ft__PyStructSequence_NewType(struct cpu_state*,struct tlb*);
void ft_PyType_FromSpecWithBases(struct cpu_state*,struct tlb*);
void ft__PyModule_Add(struct cpu_state*,struct tlb*);
void ft__PyWarnings_Init(struct cpu_state*,struct tlb*);
void ft_PyInit__weakref(struct cpu_state*,struct tlb*);
void ft_PyModule_AddObject(struct cpu_state*,struct tlb*);
void ft_PyList_SetSlice(struct cpu_state*,struct tlb*);
void ft_PyUnicode_IsIdentifier(struct cpu_state*,struct tlb*);
void ft__PyUnicode_ScanIdentifier(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsXidStart(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsXidContinue(struct cpu_state*,struct tlb*);
void ft__PyConfig_AsDict(struct cpu_state*,struct tlb*);
void ft__PyWideStringList_AsList(struct cpu_state*,struct tlb*);
void ft_PySymtable_Lookup(struct cpu_state*,struct tlb*);
void ft__PyLong_NumBits(struct cpu_state*,struct tlb*);
void ft_PyList_Size(struct cpu_state*,struct tlb*);
void ft_PyLong_AsSize_t(struct cpu_state*,struct tlb*);
void ft_PyDict_Keys(struct cpu_state*,struct tlb*);
void ft__Py_wfopen(struct cpu_state*,struct tlb*);
void ft_PyFrozenSet_New(struct cpu_state*,struct tlb*);
void ft_PyErr_SetFromErrno(struct cpu_state*,struct tlb*);
void ft_PyErr_SetFromErrnoWithFilenameObjects(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeLocale(struct cpu_state*,struct tlb*);
void ft_PyException_GetContext(struct cpu_state*,struct tlb*);
void ft_PyNumber_Invert(struct cpu_state*,struct tlb*);
void ft__Py_wreadlink(struct cpu_state*,struct tlb*);
void ft_PyNumber_InPlaceAdd(struct cpu_state*,struct tlb*);
void ft_PyCapsule_New(struct cpu_state*,struct tlb*);
void ft__Py_DecodeUTF8_surrogateescape(struct cpu_state*,struct tlb*);
void ft_PyCapsule_GetPointer(struct cpu_state*,struct tlb*);
void ft_PySet_Size(struct cpu_state*,struct tlb*);
void ft__PyTime_FromMicrosecondsClamp(struct cpu_state*,struct tlb*);
void ft__PyErr_SetKeyError(struct cpu_state*,struct tlb*);
void ft__PyImport_ReleaseLock(struct cpu_state*,struct tlb*);
void ft_PyWrapper_New(struct cpu_state*,struct tlb*);
void ft__PyTime_FromSeconds(struct cpu_state*,struct tlb*);
void ft_PySequence_DelItem(struct cpu_state*,struct tlb*);
void ft__PyArena_Free(struct cpu_state*,struct tlb*);
void ft_PyInit__io(struct cpu_state*,struct tlb*);
void ft_PyDict_Clear(struct cpu_state*,struct tlb*);
void ft_PyModule_AddIntConstant(struct cpu_state*,struct tlb*);
void ft__Py_hashtable_hash_ptr(struct cpu_state*,struct tlb*);
void ft_PyThread_free_lock(struct cpu_state*,struct tlb*);
void ft_PyMarshal_Init(struct cpu_state*,struct tlb*);
void ft_PyInit_posix(struct cpu_state*,struct tlb*);
void ft_Py_Finalize(struct cpu_state*,struct tlb*);
void ft_Py_FinalizeEx(struct cpu_state*,struct tlb*);
void ft__PyObject_GC_Resize(struct cpu_state*,struct tlb*);
void ft_PyList_GetItem(struct cpu_state*,struct tlb*);
void ft_PyObject_Bytes(struct cpu_state*,struct tlb*);
void ft__PyImport_GetModuleAttrString(struct cpu_state*,struct tlb*);
void ft__PyImport_GetModuleAttr(struct cpu_state*,struct tlb*);
void ft_PyImport_ImportModuleLevel(struct cpu_state*,struct tlb*);
void ft_PyInit_time(struct cpu_state*,struct tlb*);
void ft__PyTime_localtime(struct cpu_state*,struct tlb*);
void ft_PyList_Insert(struct cpu_state*,struct tlb*);
void ft__PyBytesWriter_Resize(struct cpu_state*,struct tlb*);
void ft_PyInit_faulthandler(struct cpu_state*,struct tlb*);
void ft__Py_EncodeUTF8Ex(struct cpu_state*,struct tlb*);
void ft_PyObject_CallNoArgs(struct cpu_state*,struct tlb*);
void ft__PyCodec_Lookup(struct cpu_state*,struct tlb*);
void ft_PyCodec_RegisterError(struct cpu_state*,struct tlb*);
void ft_PyImport_ImportModule(struct cpu_state*,struct tlb*);
void ft_PyUnicode_EncodeFSDefault(struct cpu_state*,struct tlb*);
void ft_PyThreadState_GetInterpreter(struct cpu_state*,struct tlb*);
void ft__Py_EncodeLocaleEx(struct cpu_state*,struct tlb*);
void ft_PyEval_SaveThread(struct cpu_state*,struct tlb*);
void ft__PySet_NextEntry(struct cpu_state*,struct tlb*);
void ft_PyEval_RestoreThread(struct cpu_state*,struct tlb*);
void ft_PyErr_SetFromErrnoWithFilenameObject(struct cpu_state*,struct tlb*);
void ft__PyLong_FromUid(struct cpu_state*,struct tlb*);
void ft__PyUnicode_EQ(struct cpu_state*,struct tlb*);
void ft_PyFile_OpenCodeObject(struct cpu_state*,struct tlb*);
void ft_PyNumber_Check(struct cpu_state*,struct tlb*);
void ft_PyUnicode_FSConverter(struct cpu_state*,struct tlb*);
void ft__Py_read(struct cpu_state*,struct tlb*);
void ft__Py_SourceAsString(struct cpu_state*,struct tlb*);
void ft_PyInit__codecs(struct cpu_state*,struct tlb*);
void ft_PyMapping_Keys(struct cpu_state*,struct tlb*);
void ft_PyErr_SetObject(struct cpu_state*,struct tlb*);
void ft__PyErr_Clear(struct cpu_state*,struct tlb*);
void ft_PyCodec_LookupError(struct cpu_state*,struct tlb*);
void ft_PyCodec_Register(struct cpu_state*,struct tlb*);
void ft_PyInit__abc(struct cpu_state*,struct tlb*);
void ft_PyOS_setsig(struct cpu_state*,struct tlb*);
void ft_PyOS_getsig(struct cpu_state*,struct tlb*);
void ft_PyDictProxy_New(struct cpu_state*,struct tlb*);
void ft_PyMapping_Items(struct cpu_state*,struct tlb*);
void ft__PyObject_IsAbstract(struct cpu_state*,struct tlb*);
void ft_PyImport_GetModule(struct cpu_state*,struct tlb*);
void ft_PyModule_GetFilenameObject(struct cpu_state*,struct tlb*);
void ft_PyErr_SetString(struct cpu_state*,struct tlb*);
void ft__PyErr_SetString(struct cpu_state*,struct tlb*);
void ft__Py_IsValidFD(struct cpu_state*,struct tlb*);
void ft__PyCodec_LookupTextEncoding(struct cpu_state*,struct tlb*);
void ft__PyCodecInfo_GetIncrementalDecoder(struct cpu_state*,struct tlb*);
void ft_PySys_SetObject(struct cpu_state*,struct tlb*);
void ft__PyCodecInfo_GetIncrementalEncoder(struct cpu_state*,struct tlb*);
void ft__Py_ClearStandardStreamEncoding(struct cpu_state*,struct tlb*);
void ft_Py_GenericAlias(struct cpu_state*,struct tlb*);
void ft_PyVectorcall_Function(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_SetRunningMain(struct cpu_state*,struct tlb*);
void ft__PyType_GetDocFromInternalDoc(struct cpu_state*,struct tlb*);
void ft_PyObject_Dir(struct cpu_state*,struct tlb*);
void ft_PyException_SetCause(struct cpu_state*,struct tlb*);
void ft__PyUnicode_FindMaxChar(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetCode(struct cpu_state*,struct tlb*);
void ft__Py_wrealpath(struct cpu_state*,struct tlb*);
void ft__Py_fopen_obj(struct cpu_state*,struct tlb*);
void ft_Py_MakePendingCalls(struct cpu_state*,struct tlb*);
void ft__PyEval_MakePendingCalls(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsUTF8String(struct cpu_state*,struct tlb*);
void ft_PyRun_SimpleStringFlags(struct cpu_state*,struct tlb*);
void ft__PyRun_AnyFileObject(struct cpu_state*,struct tlb*);
void ft_PyRun_StringFlags(struct cpu_state*,struct tlb*);
void ft__Py_FdIsInteractive(struct cpu_state*,struct tlb*);
void ft__PyRun_SimpleFileObject(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Tailmatch(struct cpu_state*,struct tlb*);
void ft_PyImport_GetMagicNumber(struct cpu_state*,struct tlb*);
void ft__PyWeakref_ClearRef(struct cpu_state*,struct tlb*);
void ft_PyDict_Size(struct cpu_state*,struct tlb*);
void ft__Py_UniversalNewlineFgetsWithSize(struct cpu_state*,struct tlb*);
void ft_PyInit_itertools(struct cpu_state*,struct tlb*);
void ft_PyInit__operator(struct cpu_state*,struct tlb*);
void ft_PyType_FromMetaclass(struct cpu_state*,struct tlb*);
void ft_PyEval_MergeCompilerFlags(struct cpu_state*,struct tlb*);
void ft_PyErr_WarnExplicitObject(struct cpu_state*,struct tlb*);
void ft_PyUnicode_GetLength(struct cpu_state*,struct tlb*);
void ft__PySys_GetOptionalAttr(struct cpu_state*,struct tlb*);
void ft_PyFile_WriteObject(struct cpu_state*,struct tlb*);
void ft__PyUnicode_AsUTF8String(struct cpu_state*,struct tlb*);
void ft_PyFile_WriteString(struct cpu_state*,struct tlb*);
void ft__Py_write(struct cpu_state*,struct tlb*);
void ft_PyObject_AsFileDescriptor(struct cpu_state*,struct tlb*);
void ft__Py_dup(struct cpu_state*,struct tlb*);
void ft_PyLong_AsUnsignedLongLongMask(struct cpu_state*,struct tlb*);
void ft__PyErr_ProgramDecodedTextObject(struct cpu_state*,struct tlb*);
void ft_PyErr_Fetch(struct cpu_state*,struct tlb*);
void ft__PyErr_Fetch(struct cpu_state*,struct tlb*);
void ft_PyErr_Restore(struct cpu_state*,struct tlb*);
void ft_PyByteArray_Resize(struct cpu_state*,struct tlb*);
void ft__Py_WriteIndentedMargin(struct cpu_state*,struct tlb*);
void ft__Py_WriteIndent(struct cpu_state*,struct tlb*);
void ft_PyDict_DelItemString(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_SetNotRunningMain(struct cpu_state*,struct tlb*);
void ft__PyThreadState_DeleteExcept(struct cpu_state*,struct tlb*);
void ft_PyGC_Collect(struct cpu_state*,struct tlb*);
void ft_Py_Exit(struct cpu_state*,struct tlb*);
void ft__PyModule_Clear(struct cpu_state*,struct tlb*);
void ft__PyModule_ClearDict(struct cpu_state*,struct tlb*);
void ft__PyTraceMalloc_Stop(struct cpu_state*,struct tlb*);
void ft_PyThreadState_Clear(struct cpu_state*,struct tlb*);
void ft__PyObject_ClearManagedDict(struct cpu_state*,struct tlb*);
void ft__PyInterpreterState_HasFeature(struct cpu_state*,struct tlb*);
void ft_PyImport_GetModuleDict(struct cpu_state*,struct tlb*);
void ft__PyImport_FixupExtensionObject(struct cpu_state*,struct tlb*);
void ft_PyNumber_Power(struct cpu_state*,struct tlb*);
void ft_PyThread_tss_delete(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_Delete(struct cpu_state*,struct tlb*);
void ft_PyInit__sre(struct cpu_state*,struct tlb*);
void ft_PyModule_AddStringConstant(struct cpu_state*,struct tlb*);
void ft__PyRuntimeState_Fini(struct cpu_state*,struct tlb*);
void ft_PySlice_New(struct cpu_state*,struct tlb*);
void ft__PyPathConfig_ClearGlobal(struct cpu_state*,struct tlb*);
void ft__Py_ClearArgcArgv(struct cpu_state*,struct tlb*);
void ft__PyRuntime_Finalize(struct cpu_state*,struct tlb*);
void ft_PyNumber_InPlaceAnd(struct cpu_state*,struct tlb*);
void ft_PyInit__tokenize(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsASCIIString(struct cpu_state*,struct tlb*);
void ft__PyObject_RealIsInstance(struct cpu_state*,struct tlb*);
void ft__PyBytesWriter_Dealloc(struct cpu_state*,struct tlb*);
void ft_PyErr_WriteUnraisable(struct cpu_state*,struct tlb*);
void ft__PyErr_WriteUnraisableMsg(struct cpu_state*,struct tlb*);
void ft_PySeqIter_New(struct cpu_state*,struct tlb*);
void ft_PyNumber_Xor(struct cpu_state*,struct tlb*);
void ft_PyNumber_InPlaceXor(struct cpu_state*,struct tlb*);
void ft__PyGen_FetchStopIterationValue(struct cpu_state*,struct tlb*);
void ft__PyUnicode_FormatAdvancedWriter(struct cpu_state*,struct tlb*);
void ft_PyByteArray_FromStringAndSize(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Partition(struct cpu_state*,struct tlb*);
void ft__PyLong_FromBytes(struct cpu_state*,struct tlb*);
void ft_PySequence_Size(struct cpu_state*,struct tlb*);
void ft_PyClassMethod_New(struct cpu_state*,struct tlb*);
void ft_PyLong_FromUnicodeObject(struct cpu_state*,struct tlb*);
void ft__Py_string_to_number_with_underscores(struct cpu_state*,struct tlb*);
void ft__PySet_Update(struct cpu_state*,struct tlb*);
void ft_PySequence_GetSlice(struct cpu_state*,struct tlb*);
void ft__PySlice_FromIndices(struct cpu_state*,struct tlb*);
void ft_PyInit__locale(struct cpu_state*,struct tlb*);
void ft__PyDict_SetItem_KnownHash(struct cpu_state*,struct tlb*);
void ft_PyInit_errno(struct cpu_state*,struct tlb*);
void ft_PyUnicode_CopyCharacters(struct cpu_state*,struct tlb*);
void ft__Py_IsInterpreterFinalizing(struct cpu_state*,struct tlb*);
void ft_PyBytes_FromObject(struct cpu_state*,struct tlb*);
void ft_PyOS_mystrnicmp(struct cpu_state*,struct tlb*);
void ft_PyGILState_Ensure(struct cpu_state*,struct tlb*);
void ft_PyObject_CallObject(struct cpu_state*,struct tlb*);
void ft__PyDict_Contains_KnownHash(struct cpu_state*,struct tlb*);
void ft_PyErr_NewExceptionWithDoc(struct cpu_state*,struct tlb*);
void ft_PyGILState_Release(struct cpu_state*,struct tlb*);
void ft_PyThreadState_GetDict(struct cpu_state*,struct tlb*);
void ft__PyThreadState_GetDict(struct cpu_state*,struct tlb*);
void ft__Py_GetLocaleEncodingObject(struct cpu_state*,struct tlb*);
void ft__PyUnicode_ToLowercase(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsLowercase(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsTitlecase(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Splitlines(struct cpu_state*,struct tlb*);
void ft_PyUnicodeDecodeError_Create(struct cpu_state*,struct tlb*);
void ft_PyCodec_StrictErrors(struct cpu_state*,struct tlb*);
void ft__PyErr_GetTopmostException(struct cpu_state*,struct tlb*);
void ft_PyList_Reverse(struct cpu_state*,struct tlb*);
void ft_Py_GetRecursionLimit(struct cpu_state*,struct tlb*);
void ft__PyLong_FromDigits(struct cpu_state*,struct tlb*);
void ft_PyODict_SetItem(struct cpu_state*,struct tlb*);
void ft__PyTime_GetPerfCounterWithInfo(struct cpu_state*,struct tlb*);
void ft_PyCapsule_Import(struct cpu_state*,struct tlb*);
void ft_PyOS_double_to_string(struct cpu_state*,struct tlb*);
void ft__PyImport_SetModule(struct cpu_state*,struct tlb*);
void ft__PyUnicode_FormatLong(struct cpu_state*,struct tlb*);
void ft__PyEval_GetBuiltin(struct cpu_state*,struct tlb*);
void ft_PyNumber_ToBase(struct cpu_state*,struct tlb*);
void ft__PyUnicode_FastFill(struct cpu_state*,struct tlb*);
void ft__PyMem_Strdup(struct cpu_state*,struct tlb*);
void ft_PyThread_start_new_thread(struct cpu_state*,struct tlb*);
void ft_PyErr_WarnEx(struct cpu_state*,struct tlb*);
void ft__PyDeadline_Init(struct cpu_state*,struct tlb*);
void ft__PyTime_GetMonotonicClock(struct cpu_state*,struct tlb*);
void ft__PyTime_GetSystemClock(struct cpu_state*,struct tlb*);
void ft_PyThreadState_GetFrame(struct cpu_state*,struct tlb*);
void ft__PyTime_Add(struct cpu_state*,struct tlb*);
void ft__PyTime_AsTimespec_clamp(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetBack(struct cpu_state*,struct tlb*);
void ft_PyFrame_GetLineNumber(struct cpu_state*,struct tlb*);
void ft_PyUnstable_InterpreterFrame_GetLine(struct cpu_state*,struct tlb*);
void ft_PyLong_AsUnsignedLongLong(struct cpu_state*,struct tlb*);
void ft_PyLong_AsLongLong(struct cpu_state*,struct tlb*);
void ft__PyCodec_EncodeText(struct cpu_state*,struct tlb*);
void ft__PyUnicode_EncodeUTF16(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeUTF16Stateful(struct cpu_state*,struct tlb*);
void ft_PyErr_BadArgument(struct cpu_state*,struct tlb*);
void ft_PyNumber_InPlaceMultiply(struct cpu_state*,struct tlb*);
void ft__PyObject_FunctionStr(struct cpu_state*,struct tlb*);
void ft_PyInterpreterState_ThreadHead(struct cpu_state*,struct tlb*);
void ft_PyThreadState_Next(struct cpu_state*,struct tlb*);
void ft__PyEval_SliceIndexNotNone(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Split(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeRawUnicodeEscape(struct cpu_state*,struct tlb*);
void ft__PySys_GetSizeOf(struct cpu_state*,struct tlb*);
void ft_PyWeakref_NewProxy(struct cpu_state*,struct tlb*);
void ft_PyErr_NoMemory(struct cpu_state*,struct tlb*);
void ft__PyErr_NoMemory(struct cpu_state*,struct tlb*);
void ft__Py_strhex_bytes_with_sep(struct cpu_state*,struct tlb*);
void ft__PySequence_BytesToCharpArray(struct cpu_state*,struct tlb*);
void ft__Py_RestoreSignals(struct cpu_state*,struct tlb*);
void ft__Py_open_noraise(struct cpu_state*,struct tlb*);
void ft__Py_FreeCharPArray(struct cpu_state*,struct tlb*);
void ft__PyLong_FileDescriptor_Converter(struct cpu_state*,struct tlb*);
void ft_PyLong_AsUnsignedLongMask(struct cpu_state*,struct tlb*);
void ft__Py_strhex_with_sep(struct cpu_state*,struct tlb*);
void ft_Py_EnterRecursiveCall(struct cpu_state*,struct tlb*);
void ft__PyObject_GetState(struct cpu_state*,struct tlb*);
void ft__PyBytes_FromHex(struct cpu_state*,struct tlb*);
void ft__PyArg_BadArgument(struct cpu_state*,struct tlb*);
void ft_PyNumber_InPlaceRemainder(struct cpu_state*,struct tlb*);
void ft__PyBytes_FormatEx(struct cpu_state*,struct tlb*);
void ft__PyLong_FormatBytesWriter(struct cpu_state*,struct tlb*);
void ft_PyCodec_Encode(struct cpu_state*,struct tlb*);
void ft_PySequence_SetItem(struct cpu_state*,struct tlb*);
void ft__PyUnicode_EncodeCharmap(struct cpu_state*,struct tlb*);
void ft_PyLong_AsVoidPtr(struct cpu_state*,struct tlb*);
void ft_PyBytes_FromFormatV(struct cpu_state*,struct tlb*);
void ft__PyArg_NoPositional(struct cpu_state*,struct tlb*);
void ft__PyThreadState_DeleteCurrent(struct cpu_state*,struct tlb*);
void ft_PyComplex_FromDoubles(struct cpu_state*,struct tlb*);
void ft_PyNumber_InPlaceFloorDivide(struct cpu_state*,struct tlb*);
void ft__PyType_GetTextSignatureFromInternalDoc(struct cpu_state*,struct tlb*);
void ft_PyCodec_BackslashReplaceErrors(struct cpu_state*,struct tlb*);
void ft_PyUnicodeDecodeError_GetStart(struct cpu_state*,struct tlb*);
void ft_PyUnicodeDecodeError_GetEnd(struct cpu_state*,struct tlb*);
void ft_PyUnicodeDecodeError_GetObject(struct cpu_state*,struct tlb*);
void ft_PyUnicodeEncodeError_SetStart(struct cpu_state*,struct tlb*);
void ft_PyUnicodeDecodeError_SetStart(struct cpu_state*,struct tlb*);
void ft_PyUnicodeEncodeError_SetEnd(struct cpu_state*,struct tlb*);
void ft_PyUnicodeDecodeError_SetEnd(struct cpu_state*,struct tlb*);
void ft_PyUnicodeEncodeError_SetReason(struct cpu_state*,struct tlb*);
void ft_PyUnicodeDecodeError_SetReason(struct cpu_state*,struct tlb*);
void ft_PyUnicodeEncodeError_GetStart(struct cpu_state*,struct tlb*);
void ft_PyUnicodeEncodeError_GetEnd(struct cpu_state*,struct tlb*);
void ft_PyType_GetModuleState(struct cpu_state*,struct tlb*);
void ft_PyUnicode_DecodeCharmap(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsRawUnicodeEscapeString(struct cpu_state*,struct tlb*);
void ft_PyCodec_IncrementalEncoder(struct cpu_state*,struct tlb*);
void ft_PyCodec_IncrementalDecoder(struct cpu_state*,struct tlb*);
void ft_PyCodec_ReplaceErrors(struct cpu_state*,struct tlb*);
void ft_PyCodec_IgnoreErrors(struct cpu_state*,struct tlb*);
void ft_PyCodec_Unregister(struct cpu_state*,struct tlb*);
void ft_PyBytes_DecodeEscape(struct cpu_state*,struct tlb*);
void ft__PyUnicode_ToLowerFull(struct cpu_state*,struct tlb*);
void ft_PyUnicodeEncodeError_GetEncoding(struct cpu_state*,struct tlb*);
void ft_PyUnicodeDecodeError_GetEncoding(struct cpu_state*,struct tlb*);
void ft_PyCodec_NameReplaceErrors(struct cpu_state*,struct tlb*);
void ft_PyDict_Items(struct cpu_state*,struct tlb*);
void ft__PyGen_SetStopIterationValue(struct cpu_state*,struct tlb*);
void ft__PyTime_gmtime(struct cpu_state*,struct tlb*);
void ft_PyUnicode_Fill(struct cpu_state*,struct tlb*);
void ft__PyTime_AsTimespec(struct cpu_state*,struct tlb*);
void ft__PyLong_DivmodNear(struct cpu_state*,struct tlb*);
void ft__PyTime_AsTimevalTime_t(struct cpu_state*,struct tlb*);
void ft_PyUnicode_AsLatin1String(struct cpu_state*,struct tlb*);
void ft__PyUnicode_Copy(struct cpu_state*,struct tlb*);
void ft_PyUnicode_WriteChar(struct cpu_state*,struct tlb*);
void ft__Py_GetLocaleconvNumeric(struct cpu_state*,struct tlb*);
void ft_PyObject_ASCII(struct cpu_state*,struct tlb*);
void ft__PyEval_SetSwitchInterval(struct cpu_state*,struct tlb*);
void ft__PyObject_GetDictPtr(struct cpu_state*,struct tlb*);
void ft_PyDict_Merge(struct cpu_state*,struct tlb*);
void ft__Py_strhex(struct cpu_state*,struct tlb*);
void ft__PyLong_UnsignedLong_Converter(struct cpu_state*,struct tlb*);
void ft__PyLong_UnsignedLongLong_Converter(struct cpu_state*,struct tlb*);
void ft__PyTime_FromTimespec(struct cpu_state*,struct tlb*);
void ft_PyThreadState_Swap(struct cpu_state*,struct tlb*);
void ft__PyThreadState_Swap(struct cpu_state*,struct tlb*);
void ft_PyCFunction_GetFunction(struct cpu_state*,struct tlb*);
void ft__PyLong_Lshift(struct cpu_state*,struct tlb*);
void ft__PySequence_IterSearch(struct cpu_state*,struct tlb*);
void ft_PySequence_Count(struct cpu_state*,struct tlb*);
void ft_PySequence_Index(struct cpu_state*,struct tlb*);
void ft_PyNumber_MatrixMultiply(struct cpu_state*,struct tlb*);
void ft_PyObject_Not(struct cpu_state*,struct tlb*);
void ft__PyDict_SizeOf(struct cpu_state*,struct tlb*);
void ft_PyEval_GetFrame(struct cpu_state*,struct tlb*);
void ft_PyFrame_LocalsToFast(struct cpu_state*,struct tlb*);
void ft__PyUnicode_ToUpperFull(struct cpu_state*,struct tlb*);
void ft__PyUnicode_ToTitleFull(struct cpu_state*,struct tlb*);
void ft__PyTime_FromNanosecondsObject(struct cpu_state*,struct tlb*);
void ft__PyTime_AsNanosecondsObject(struct cpu_state*,struct tlb*);
void ft__PyTime_AsTimeval(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsCaseIgnorable(struct cpu_state*,struct tlb*);
void ft__PyUnicode_IsCased(struct cpu_state*,struct tlb*);
void ft_PyUnicodeTranslateError_SetStart(struct cpu_state*,struct tlb*);
void ft_PyUnicodeTranslateError_SetEnd(struct cpu_state*,struct tlb*);
void ft__PyTime_AsNanoseconds(struct cpu_state*,struct tlb*);
void ft_PyUnicodeTranslateError_SetReason(struct cpu_state*,struct tlb*);
void ft__PyThreadState_Prealloc(struct cpu_state*,struct tlb*);
void ft__PyTime_GetPerfCounter(struct cpu_state*,struct tlb*);
void ft__fini(struct cpu_state*,struct tlb*);
struct ft_row { const char *name; unsigned long off; prebuilt_fn fn; };
static struct ft_row ft_rows[] = {
    { "_init", 0x7aac8, ft__init },
    { "_Py_DisplaySourceLine", 0x7c620, ft__Py_DisplaySourceLine },
    { "PyErr_Display", 0x7cdf4, ft_PyErr_Display },
    { "PyException_GetCause", 0x7d5d0, ft_PyException_GetCause },
    { "PyTraceBack_Print", 0x7e834, ft_PyTraceBack_Print },
    { "_PyOS_URandomNonblock", 0x7f140, ft__PyOS_URandomNonblock },
    { "PyInit__string", 0x7f14c, ft_PyInit__string },
    { "PyInit_atexit", 0x7f15c, ft_PyInit_atexit },
    { "PyInit_gc", 0x7f400, ft_PyInit_gc },
    { "PyUnicode_Replace", 0x7fa5c, ft_PyUnicode_Replace },
    { "PyContextVar_New", 0x802f0, ft_PyContextVar_New },
    { "PyInit__symtable", 0x80474, ft_PyInit__symtable },
    { "PyState_AddModule", 0x806e4, ft_PyState_AddModule },
    { "PyInit__tracemalloc", 0x807a0, ft_PyInit__tracemalloc },
    { "_PyCrossInterpreterData_RegisterClass", 0x807b4, ft__PyCrossInterpreterData_RegisterClass },
    { "_Py_AtExit", 0x80af8, ft__Py_AtExit },
    { "PyInit_pwd", 0x80b68, ft_PyInit_pwd },
    { "_Py_DecRef", 0x80bcc, ft__Py_DecRef },
    { "PyUnicode_DecodeUTF16", 0x80bf4, ft_PyUnicode_DecodeUTF16 },
    { "PyUnicode_DecodeUTF32", 0x80bfc, ft_PyUnicode_DecodeUTF32 },
    { "_PyCrossInterpreterData_UnregisterClass", 0x80c04, ft__PyCrossInterpreterData_UnregisterClass },
    { "PyUnicode_GetDefaultEncoding", 0x80fb0, ft_PyUnicode_GetDefaultEncoding },
    { "_PyEval_GetSwitchInterval", 0x81cec, ft__PyEval_GetSwitchInterval },
    { "PyObject_GenericSetDict", 0x81d08, ft_PyObject_GenericSetDict },
    { "_PyEval_SignalReceived", 0x8206c, ft__PyEval_SignalReceived },
    { "_PyTraceMalloc_IsTracing", 0x8274c, ft__PyTraceMalloc_IsTracing },
    { "PyThreadState_Get", 0x82788, ft_PyThreadState_Get },
    { "Py_EndInterpreter", 0x82a78, ft_Py_EndInterpreter },
    { "PySequence_InPlaceConcat", 0x83134, ft_PySequence_InPlaceConcat },
    { "PyNumber_InPlaceMatrixMultiply", 0x835ec, ft_PyNumber_InPlaceMatrixMultiply },
    { "_PyOS_URandom", 0x83f50, ft__PyOS_URandom },
    { "PyOS_BeforeFork", 0x84730, ft_PyOS_BeforeFork },
    { "PyOS_AfterFork_Parent", 0x84b3c, ft_PyOS_AfterFork_Parent },
    { "_PyTime_FromMillisecondsObject", 0x84ba0, ft__PyTime_FromMillisecondsObject },
    { "PyUnicode_ReadChar", 0x84f34, ft_PyUnicode_ReadChar },
    { "PyErr_SyntaxLocationObject", 0x85020, ft_PyErr_SyntaxLocationObject },
    { "_PyTraceback_Add", 0x859e4, ft__PyTraceback_Add },
    { "_Py_add_one_to_index_F", 0x860b0, ft__Py_add_one_to_index_F },
    { "_Py_hashtable_compare_direct", 0x88488, ft__Py_hashtable_compare_direct },
    { "PyBuffer_GetPointer", 0x8884c, ft_PyBuffer_GetPointer },
    { "PyBuffer_FillContiguousStrides", 0x88898, ft_PyBuffer_FillContiguousStrides },
    { "PyAIter_Check", 0x88988, ft_PyAIter_Check },
    { "PyByteArray_Size", 0x889b8, ft_PyByteArray_Size },
    { "PyByteArray_AsString", 0x889c0, ft_PyByteArray_AsString },
    { "_PyBytes_Find", 0x889dc, ft__PyBytes_Find },
    { "_PyBytes_ReverseFind", 0x88a60, ft__PyBytes_ReverseFind },
    { "PyVectorcall_NARGS", 0x88a9c, ft_PyVectorcall_NARGS },
    { "_Py_c_prod", 0x88bc4, ft__Py_c_prod },
    { "PyException_GetArgs", 0x88be0, ft_PyException_GetArgs },
    { "PyException_SetArgs", 0x88bf8, ft_PyException_SetArgs },
    { "PyExceptionClass_Name", 0x88c18, ft_PyExceptionClass_Name },
    { "PyGen_GetCode", 0x88c20, ft_PyGen_GetCode },
    { "Py_UniversalNewlineFgets", 0x88c38, ft_Py_UniversalNewlineFgets },
    { "PyFloat_GetMax", 0x88c8c, ft_PyFloat_GetMax },
    { "PyFloat_GetMin", 0x88c98, ft_PyFloat_GetMin },
    { "_PyFrame_IsEntryFrame", 0x88ca4, ft__PyFrame_IsEntryFrame },
    { "PyFrame_GetGlobals", 0x88cc8, ft_PyFrame_GetGlobals },
    { "PyFrame_GetBuiltins", 0x88cf4, ft_PyFrame_GetBuiltins },
    { "PyFrame_GetLasti", 0x88d20, ft_PyFrame_GetLasti },
    { "PyFrame_GetGenerator", 0x88d44, ft_PyFrame_GetGenerator },
    { "PyFunction_SetVectorcall", 0x88d74, ft_PyFunction_SetVectorcall },
    { "PyUnstable_Long_IsCompact", 0x88d80, ft_PyUnstable_Long_IsCompact },
    { "PyUnstable_Long_CompactValue", 0x88d90, ft_PyUnstable_Long_CompactValue },
    { "PyODict_New", 0x88e74, ft_PyODict_New },
    { "Py_IncRef", 0x88e98, ft_Py_IncRef },
    { "Py_DecRef", 0x88eb0, ft_Py_DecRef },
    { "_Py_IncRef", 0x88eb4, ft__Py_IncRef },
    { "_Py_BreakPoint", 0x88ec8, ft__Py_BreakPoint },
    { "_PyObject_IsFreed", 0x88ecc, ft__PyObject_IsFreed },
    { "PyObject_GET_WEAKREFS_LISTPTR", 0x896bc, ft_PyObject_GET_WEAKREFS_LISTPTR },
    { "Py_XNewRef", 0x896c0, ft_Py_XNewRef },
    { "Py_Is", 0x896d8, ft_Py_Is },
    { "Py_IsNone", 0x896e4, ft_Py_IsNone },
    { "Py_IsTrue", 0x896f8, ft_Py_IsTrue },
    { "Py_IsFalse", 0x8970c, ft_Py_IsFalse },
    { "_PyMem_GetAllocatorName", 0x89720, ft__PyMem_GetAllocatorName },
    { "PyStructSequence_SetItem", 0x89810, ft_PyStructSequence_SetItem },
    { "PyStructSequence_GetItem", 0x8981c, ft_PyStructSequence_GetItem },
    { "PyType_GetDict", 0x89828, ft_PyType_GetDict },
    { "PyType_ClearCache", 0x89850, ft_PyType_ClearCache },
    { "PyUnstable_Type_AssignVersionTag", 0x898fc, ft_PyUnstable_Type_AssignVersionTag },
    { "PyType_GetFlags", 0x8992c, ft_PyType_GetFlags },
    { "PyType_SUPPORTS_WEAKREFS", 0x89934, ft_PyType_SUPPORTS_WEAKREFS },
    { "PyObject_GetTypeData", 0x89944, ft_PyObject_GetTypeData },
    { "PyType_GetTypeDataSize", 0x8995c, ft_PyType_GetTypeDataSize },
    { "_PyUnicode_ToTitlecase", 0x8ef38, ft__PyUnicode_ToTitlecase },
    { "_PyWeakref_GetWeakrefCount", 0x8ef74, ft__PyWeakref_GetWeakrefCount },
    { "PyEval_GetFuncDesc", 0x8ef90, ft_PyEval_GetFuncDesc },
    { "PyUnstable_Eval_RequestCodeExtraIndex", 0x8eff4, ft_PyUnstable_Eval_RequestCodeExtraIndex },
    { "PyCompile_OpcodeStackEffect", 0x8f048, ft_PyCompile_OpcodeStackEffect },
    { "PyCode_Optimize", 0x8f050, ft_PyCode_Optimize },
    { "PyObject_CheckReadBuffer", 0x8f0cc, ft_PyObject_CheckReadBuffer },
    { "_PyErr_GetExcInfo", 0x8f164, ft__PyErr_GetExcInfo },
    { "_PyErr_GetHandledException", 0x8f21c, ft__PyErr_GetHandledException },
    { "PyErr_GetHandledException", 0x8f270, ft_PyErr_GetHandledException },
    { "_PyErr_SetHandledException", 0x8f298, ft__PyErr_SetHandledException },
    { "PyErr_SetHandledException", 0x8f2bc, ft_PyErr_SetHandledException },
    { "PyErr_GetExcInfo", 0x8f2e8, ft_PyErr_GetExcInfo },
    { "PyErr_SetExcInfo", 0x8f324, ft_PyErr_SetExcInfo },
    { "PyUnstable_InterpreterFrame_GetCode", 0x8f380, ft_PyUnstable_InterpreterFrame_GetCode },
    { "PyUnstable_InterpreterFrame_GetLasti", 0x8f398, ft_PyUnstable_InterpreterFrame_GetLasti },
    { "PyEval_ThreadsInitialized", 0x8f3ac, ft_PyEval_ThreadsInitialized },
    { "PyEval_InitThreads", 0x8f3cc, ft_PyEval_InitThreads },
    { "_PyEval_SignalAsyncExc", 0x8f3d0, ft__PyEval_SignalAsyncExc },
    { "_Py_hashtable_size", 0x8f3e4, ft__Py_hashtable_size },
    { "_Py_hashtable_len", 0x8f424, ft__Py_hashtable_len },
    { "_Py_hashtable_foreach", 0x8f67c, ft__Py_hashtable_foreach },
    { "_Py_hashtable_new", 0x8f7c4, ft__Py_hashtable_new },
    { "_Py_hashtable_clear", 0x8f7d4, ft__Py_hashtable_clear },
    { "PyState_FindModule", 0x8f888, ft_PyState_FindModule },
    { "PyImport_GetMagicTag", 0x8f900, ft_PyImport_GetMagicTag },
    { "PyStatus_Error", 0x8f90c, ft_PyStatus_Error },
    { "PyStatus_NoMemory", 0x8f92c, ft_PyStatus_NoMemory },
    { "PyStatus_Exit", 0x8f954, ft_PyStatus_Exit },
    { "PyStatus_IsError", 0x8f970, ft_PyStatus_IsError },
    { "PyStatus_IsExit", 0x8f980, ft_PyStatus_IsExit },
    { "Py_GetArgcArgv", 0x8f990, ft_Py_GetArgcArgv },
    { "_PyDebugAllocatorStats", 0x8f9ac, ft__PyDebugAllocatorStats },
    { "_PyTuple_DebugMallocStats", 0x8fa70, ft__PyTuple_DebugMallocStats },
    { "_PyDict_DebugMallocStats", 0x8fb54, ft__PyDict_DebugMallocStats },
    { "_PyList_DebugMallocStats", 0x8fba0, ft__PyList_DebugMallocStats },
    { "_PyFloat_DebugMallocStats", 0x8fbec, ft__PyFloat_DebugMallocStats },
    { "_PyObject_DebugTypeStats", 0x8fc38, ft__PyObject_DebugTypeStats },
    { "_PyObject_DebugMallocStats", 0x8fc6c, ft__PyObject_DebugMallocStats },
    { "Py_GetPath", 0x90268, ft_Py_GetPath },
    { "Py_GetPrefix", 0x90284, ft_Py_GetPrefix },
    { "Py_GetExecPrefix", 0x90290, ft_Py_GetExecPrefix },
    { "Py_GetProgramFullPath", 0x9029c, ft_Py_GetProgramFullPath },
    { "Py_GetPythonHome", 0x902a8, ft_Py_GetPythonHome },
    { "Py_GetProgramName", 0x902b4, ft_Py_GetProgramName },
    { "_Py_str_to_int", 0x902f4, ft__Py_str_to_int },
    { "_Py_IsFinalizing", 0x903b8, ft__Py_IsFinalizing },
    { "_Py_IsCoreInitialized", 0x90400, ft__Py_IsCoreInitialized },
    { "Py_IsInitialized", 0x90410, ft_Py_IsInitialized },
    { "_Py_CoerceLegacyLocale", 0x90420, ft__Py_CoerceLegacyLocale },
    { "_PyInterpreterState_IsRunningMain", 0x90564, ft__PyInterpreterState_IsRunningMain },
    { "_PyInterpreterState_RequiresIDRef", 0x90578, ft__PyInterpreterState_RequiresIDRef },
    { "_PyInterpreterState_RequireIDRef", 0x90580, ft__PyInterpreterState_RequireIDRef },
    { "PyThreadState_GetID", 0x90590, ft_PyThreadState_GetID },
    { "PyInterpreterState_Head", 0x90598, ft_PyInterpreterState_Head },
    { "PyInterpreterState_Main", 0x905a8, ft_PyInterpreterState_Main },
    { "PyInterpreterState_Next", 0x905b8, ft_PyInterpreterState_Next },
    { "_PyGILState_GetInterpreterStateUnsafe", 0x905c0, ft__PyGILState_GetInterpreterStateUnsafe },
    { "_PyCrossInterpreterData_Init", 0x905d0, ft__PyCrossInterpreterData_Init },
    { "_PyCrossInterpreterData_InitWithSize", 0x90618, ft__PyCrossInterpreterData_InitWithSize },
    { "_PyCrossInterpreterData_Clear", 0x906e8, ft__PyCrossInterpreterData_Clear },
    { "_PyCrossInterpreterData_NewObject", 0x906f0, ft__PyCrossInterpreterData_NewObject },
    { "_PyInterpreterState_GetEvalFrameFunc", 0x906fc, ft__PyInterpreterState_GetEvalFrameFunc },
    { "_PyInterpreterState_SetEvalFrameFunc", 0x90714, ft__PyInterpreterState_SetEvalFrameFunc },
    { "_PyTime_MulDiv", 0x9072c, ft__PyTime_MulDiv },
    { "PyThread_exit_thread", 0x90830, ft_PyThread_exit_thread },
    { "PyUnstable_PerfMapState_Init", 0x90854, ft_PyUnstable_PerfMapState_Init },
    { "_PyThread_at_fork_reinit", 0x90930, ft__PyThread_at_fork_reinit },
    { "PyThread_create_key", 0x90968, ft_PyThread_create_key },
    { "PyThread_delete_key", 0x909e8, ft_PyThread_delete_key },
    { "PyThread_delete_key_value", 0x909ec, ft_PyThread_delete_key_value },
    { "PyThread_set_key_value", 0x909f4, ft_PyThread_set_key_value },
    { "PyThread_get_key_value", 0x90a10, ft_PyThread_get_key_value },
    { "PyThread_ReInitTLS", 0x90a14, ft_PyThread_ReInitTLS },
    { "PyGILState_GetThisThreadState", 0x90a78, ft_PyGILState_GetThisThreadState },
    { "PyThread_get_stacksize", 0x90a98, ft_PyThread_get_stacksize },
    { "PyThread_set_stacksize", 0x90ac8, ft_PyThread_set_stacksize },
    { "PyThread_tss_alloc", 0x90acc, ft_PyThread_tss_alloc },
    { "PyThread_tss_free", 0x90aec, ft_PyThread_tss_free },
    { "_PyTraceMalloc_GetTracebackLimit", 0x90b18, ft__PyTraceMalloc_GetTracebackLimit },
    { "PyOS_mystricmp", 0x90b28, ft_PyOS_mystricmp },
    { "Py_EncodeLocale", 0x90b98, ft_Py_EncodeLocale },
    { "_Py_EncodeLocaleRaw", 0x90ba0, ft__Py_EncodeLocaleRaw },
    { "_Py_write_noraise", 0x90ba8, ft__Py_write_noraise },
    { "_Py_DumpDecimal", 0x90c10, ft__Py_DumpDecimal },
    { "_Py_DumpHexadecimal", 0x90c98, ft__Py_DumpHexadecimal },
    { "_Py_DumpASCII", 0x90d30, ft__Py_DumpASCII },
    { "_Py_DumpTraceback", 0x91178, ft__Py_DumpTraceback },
    { "_Py_DumpTracebackThreads", 0x91180, ft__Py_DumpTracebackThreads },
    { "_Py_closerange", 0x9142c, ft__Py_closerange },
    { "PyGC_Enable", 0x91464, ft_PyGC_Enable },
    { "PyGC_Disable", 0x9149c, ft_PyGC_Disable },
    { "PyGC_IsEnabled", 0x914d0, ft_PyGC_IsEnabled },
    { "PyObject_GC_IsTracked", 0x91588, ft_PyObject_GC_IsTracked },
    { "PyObject_GC_IsFinalized", 0x915b8, ft_PyObject_GC_IsFinalized },
    { "PyUnstable_GC_VisitObjects", 0x915e4, ft_PyUnstable_GC_VisitObjects },
    { "_PyOS_InterruptOccurred", 0x91680, ft__PyOS_InterruptOccurred },
    { "PyOS_Readline", 0x918e8, ft_PyOS_Readline },
    { "PyErr_DisplayException", 0x91ad0, ft_PyErr_DisplayException },
    { "Py_FatalError", 0x91e88, ft_Py_FatalError },
    { "_Py_FatalErrorFunc", 0x91ebc, ft__Py_FatalErrorFunc },
    { "Py_FdIsInteractive", 0x91f14, ft_Py_FdIsInteractive },
    { "_PyContext_NewHamtForTests", 0x91fb4, ft__PyContext_NewHamtForTests },
    { "_PyThreadState_Init", 0x91fb8, ft__PyThreadState_Init },
    { "PyEval_ReleaseLock", 0x91fd8, ft_PyEval_ReleaseLock },
    { "PyEval_ReleaseThread", 0x92008, ft_PyEval_ReleaseThread },
    { "_Py_FatalRefcountErrorFunc", 0x923bc, ft__Py_FatalRefcountErrorFunc },
    { "_PyObject_Dump", 0x923d4, ft__PyObject_Dump },
    { "_PyObject_AssertFailed", 0x924f8, ft__PyObject_AssertFailed },
    { "_PyUnicode_CheckConsistency", 0x92658, ft__PyUnicode_CheckConsistency },
    { "_PyDict_CheckConsistency", 0x92adc, ft__PyDict_CheckConsistency },
    { "PyEval_EvalFrameEx", 0x93024, ft_PyEval_EvalFrameEx },
    { "PyEval_EvalFrame", 0x93058, ft_PyEval_EvalFrame },
    { "PyImport_ImportModuleNoBlock", 0x9308c, ft_PyImport_ImportModuleNoBlock },
    { "PyType_GetName", 0x93254, ft_PyType_GetName },
    { "PyObject_HasAttr", 0x9325c, ft_PyObject_HasAttr },
    { "PyObject_HasAttrString", 0x932fc, ft_PyObject_HasAttrString },
    { "PyErr_BadInternalCall", 0x935bc, ft_PyErr_BadInternalCall },
    { "PyInterpreterState_GetID", 0x93b34, ft_PyInterpreterState_GetID },
    { "_PyInterpreterState_IDInitref", 0x93b6c, ft__PyInterpreterState_IDInitref },
    { "PyUnicode_GetSize", 0x93d3c, ft_PyUnicode_GetSize },
    { "PyType_AddWatcher", 0x93f2c, ft_PyType_AddWatcher },
    { "PyDict_AddWatcher", 0x94164, ft_PyDict_AddWatcher },
    { "PyFunction_AddWatcher", 0x941e8, ft_PyFunction_AddWatcher },
    { "PyCode_AddWatcher", 0x946a0, ft_PyCode_AddWatcher },
    { "PyCapsule_GetName", 0x94788, ft_PyCapsule_GetName },
    { "PyCapsule_GetDestructor", 0x947c0, ft_PyCapsule_GetDestructor },
    { "PyCapsule_GetContext", 0x947f8, ft_PyCapsule_GetContext },
    { "PyCapsule_SetName", 0x94830, ft_PyCapsule_SetName },
    { "PyCapsule_SetDestructor", 0x94870, ft_PyCapsule_SetDestructor },
    { "PyCapsule_SetContext", 0x948b0, ft_PyCapsule_SetContext },
    { "PyCapsule_SetPointer", 0x948f0, ft_PyCapsule_SetPointer },
    { "_PyTime_FromTimeval", 0x94da8, ft__PyTime_FromTimeval },
    { "_PyDeadline_Get", 0x94e98, ft__PyDeadline_Get },
    { "PyEval_AcquireLock", 0x94ebc, ft_PyEval_AcquireLock },
    { "_PyTraceMalloc_ClearTraces", 0x95604, ft__PyTraceMalloc_ClearTraces },
    { "_PyTraceMalloc_GetMemory", 0x9565c, ft__PyTraceMalloc_GetMemory },
    { "_PyTraceMalloc_ResetPeak", 0x95724, ft__PyTraceMalloc_ResetPeak },
    { "PyUnstable_WritePerfMapEntry", 0x95780, ft_PyUnstable_WritePerfMapEntry },
    { "PyUnstable_PerfMapState_Fini", 0x95808, ft_PyUnstable_PerfMapState_Fini },
    { "PyThreadState_New", 0x95858, ft_PyThreadState_New },
    { "PyTraceMalloc_Untrack", 0x958a0, ft_PyTraceMalloc_Untrack },
    { "PyThreadState_Delete", 0x95928, ft_PyThreadState_Delete },
    { "PyThreadState_DeleteCurrent", 0x959c8, ft_PyThreadState_DeleteCurrent },
    { "_PyInterpreterState_IDIncref", 0x959f0, ft__PyInterpreterState_IDIncref },
    { "PyThreadState_SetAsyncExc", 0x95a3c, ft_PyThreadState_SetAsyncExc },
    { "Py_AtExit", 0x95af8, ft_Py_AtExit },
    { "_PyEval_AddPendingCall", 0x95b5c, ft__PyEval_AddPendingCall },
    { "Py_AddPendingCall", 0x95c08, ft_Py_AddPendingCall },
    { "PyMem_SetupDebugHooks", 0x95e64, ft_PyMem_SetupDebugHooks },
    { "Py_SetPath", 0x95ec4, ft_Py_SetPath },
    { "Py_SetPythonHome", 0x96034, ft_Py_SetPythonHome },
    { "Py_SetProgramName", 0x96120, ft_Py_SetProgramName },
    { "_Py_SetProgramFullPath", 0x9620c, ft__Py_SetProgramFullPath },
    { "Py_SetStandardStreamEncoding", 0x962f4, ft_Py_SetStandardStreamEncoding },
    { "PyImport_ExtendInittab", 0x963f8, ft_PyImport_ExtendInittab },
    { "PyImport_AppendInittab", 0x965bc, ft_PyImport_AppendInittab },
    { "PyConfig_SetBytesString", 0x96720, ft_PyConfig_SetBytesString },
    { "PyConfig_SetArgv", 0x96778, ft_PyConfig_SetArgv },
    { "Py_PreInitializeFromBytesArgs", 0x968c4, ft_Py_PreInitializeFromBytesArgs },
    { "Py_PreInitializeFromArgs", 0x96938, ft_Py_PreInitializeFromArgs },
    { "Py_PreInitialize", 0x9699c, ft_Py_PreInitialize },
    { "PyObject_GetArenaAllocator", 0x969f0, ft_PyObject_GetArenaAllocator },
    { "PyObject_SetArenaAllocator", 0x96a64, ft_PyObject_SetArenaAllocator },
    { "PyObject_AsWriteBuffer", 0x96c28, ft_PyObject_AsWriteBuffer },
    { "_PyErr_SetNone", 0x96e30, ft__PyErr_SetNone },
    { "_PyInterpreterState_LookUpID", 0x97004, ft__PyInterpreterState_LookUpID },
    { "_PyCrossInterpreterData_Release", 0x9717c, ft__PyCrossInterpreterData_Release },
    { "_PyCrossInterpreterData_ReleaseAndRawFree", 0x97184, ft__PyCrossInterpreterData_ReleaseAndRawFree },
    { "_PyErr_SetFromPyStatus", 0x971cc, ft__PyErr_SetFromPyStatus },
    { "PyContext_Exit", 0x974ac, ft_PyContext_Exit },
    { "PyType_ClearWatcher", 0x97730, ft_PyType_ClearWatcher },
    { "PyType_Watch", 0x9778c, ft_PyType_Watch },
    { "PyType_Unwatch", 0x97838, ft_PyType_Unwatch },
    { "PyPickleBuffer_Release", 0x978c4, ft_PyPickleBuffer_Release },
    { "PyTraceMalloc_Track", 0x981cc, ft_PyTraceMalloc_Track },
    { "PyUnstable_Object_GC_NewWithExtraData", 0x9831c, ft_PyUnstable_Object_GC_NewWithExtraData },
    { "PyUnicode_AsUCS4Copy", 0x989b0, ft_PyUnicode_AsUCS4Copy },
    { "_PyUnicodeWriter_PrepareKindInternal", 0x989d0, ft__PyUnicodeWriter_PrepareKindInternal },
    { "_PyUnicodeWriter_WriteLatin1String", 0x989f8, ft__PyUnicodeWriter_WriteLatin1String },
    { "PyObject_Init", 0x98b40, ft_PyObject_Init },
    { "PyBuffer_FromContiguous", 0x996f4, ft_PyBuffer_FromContiguous },
    { "PyContext_Copy", 0x99b88, ft_PyContext_Copy },
    { "PyContext_CopyCurrent", 0x99bd0, ft_PyContext_CopyCurrent },
    { "PyContext_New", 0x99bf4, ft_PyContext_New },
    { "PyInstanceMethod_New", 0x99f54, ft_PyInstanceMethod_New },
    { "PyCode_GetCode", 0x9a014, ft_PyCode_GetCode },
    { "_PyDict_NewPresized", 0x9a018, ft__PyDict_NewPresized },
    { "PyInterpreterState_GetDict", 0x9a058, ft_PyInterpreterState_GetDict },
    { "_PyObject_NextNotImplemented", 0x9a210, ft__PyObject_NextNotImplemented },
    { "PyCFunction_NewEx", 0x9a244, ft_PyCFunction_NewEx },
    { "PyCFunction_New", 0x9a24c, ft_PyCFunction_New },
    { "PyDict_Watch", 0x9a2c4, ft_PyDict_Watch },
    { "PyDict_Unwatch", 0x9a350, ft_PyDict_Unwatch },
    { "PyDict_ClearWatcher", 0x9a3dc, ft_PyDict_ClearWatcher },
    { "PyFunction_ClearWatcher", 0x9a43c, ft_PyFunction_ClearWatcher },
    { "PyFrame_GetVar", 0x9a4d8, ft_PyFrame_GetVar },
    { "PyFrame_GetVarString", 0x9a604, ft_PyFrame_GetVarString },
    { "PyUnicodeTranslateError_GetStart", 0x9a734, ft_PyUnicodeTranslateError_GetStart },
    { "PyUnicodeTranslateError_GetEnd", 0x9a738, ft_PyUnicodeTranslateError_GetEnd },
    { "PyUnicodeEncodeError_GetReason", 0x9a73c, ft_PyUnicodeEncodeError_GetReason },
    { "PyUnicodeDecodeError_GetReason", 0x9a74c, ft_PyUnicodeDecodeError_GetReason },
    { "PyUnicodeTranslateError_GetReason", 0x9a750, ft_PyUnicodeTranslateError_GetReason },
    { "PyCode_ClearWatcher", 0x9a788, ft_PyCode_ClearWatcher },
    { "PyObject_CopyData", 0x9a830, ft_PyObject_CopyData },
    { "PyObject_AsReadBuffer", 0x9ab94, ft_PyObject_AsReadBuffer },
    { "PyObject_AsCharBuffer", 0x9ab98, ft_PyObject_AsCharBuffer },
    { "PyPickleBuffer_FromObject", 0x9ab9c, ft_PyPickleBuffer_FromObject },
    { "PySequence_Repeat", 0x9aeb8, ft_PySequence_Repeat },
    { "PySequence_InPlaceRepeat", 0x9afbc, ft_PySequence_InPlaceRepeat },
    { "PyObject_GetAIter", 0x9b280, ft_PyObject_GetAIter },
    { "_Py_device_encoding", 0x9b34c, ft__Py_device_encoding },
    { "_PyErr_BadInternalCall", 0x9bb50, ft__PyErr_BadInternalCall },
    { "PyMemoryView_GetContiguous", 0x9bbfc, ft_PyMemoryView_GetContiguous },
    { "PyGen_NewWithQualName", 0x9bf6c, ft_PyGen_NewWithQualName },
    { "PyGen_New", 0x9bf8c, ft_PyGen_New },
    { "PyAsyncGen_New", 0x9bfa4, ft_PyAsyncGen_New },
    { "_PyCrossInterpreterData_Lookup", 0x9c720, ft__PyCrossInterpreterData_Lookup },
    { "_PyObject_GetCrossInterpreterData", 0x9c810, ft__PyObject_GetCrossInterpreterData },
    { "_PyObject_CheckCrossInterpreterData", 0x9c948, ft__PyObject_CheckCrossInterpreterData },
    { "PyUnicode_Resize", 0x9c964, ft_PyUnicode_Resize },
    { "_PyUnicode_WideCharString_Converter", 0x9ca80, ft__PyUnicode_WideCharString_Converter },
    { "_PyUnicode_WideCharString_Opt_Converter", 0x9cafc, ft__PyUnicode_WideCharString_Opt_Converter },
    { "PyCode_GetVarnames", 0x9d294, ft_PyCode_GetVarnames },
    { "PyCode_GetCellvars", 0x9d2e4, ft_PyCode_GetCellvars },
    { "PyCode_GetFreevars", 0x9d334, ft_PyCode_GetFreevars },
    { "_PyTraceMalloc_GetTraceback", 0x9da44, ft__PyTraceMalloc_GetTraceback },
    { "_PyTraceMalloc_GetTracedMemory", 0x9dc20, ft__PyTraceMalloc_GetTracedMemory },
    { "PyCoro_New", 0x9ddbc, ft_PyCoro_New },
    { "PySys_AddAuditHook", 0x9e02c, ft_PySys_AddAuditHook },
    { "_Py_DumpExtensionModules", 0x9e4b8, ft__Py_DumpExtensionModules },
    { "PyCFunction_GetSelf", 0x9e930, ft_PyCFunction_GetSelf },
    { "PyCFunction_GetFlags", 0x9e980, ft_PyCFunction_GetFlags },
    { "PySlice_GetIndices", 0x9eac0, ft_PySlice_GetIndices },
    { "_PyLong_UnsignedInt_Converter", 0x9ec98, ft__PyLong_UnsignedInt_Converter },
    { "_PyLong_Size_t_Converter", 0x9f148, ft__PyLong_Size_t_Converter },
    { "_PyTraceMalloc_GetTraces", 0x9f774, ft__PyTraceMalloc_GetTraces },
    { "PyDict_Values", 0xa0990, ft_PyDict_Values },
    { "_PyState_AddModule", 0xa0bf8, ft__PyState_AddModule },
    { "PyState_RemoveModule", 0xa0cc4, ft_PyState_RemoveModule },
    { "PyFunction_GetCode", 0xa19cc, ft_PyFunction_GetCode },
    { "PyFunction_GetGlobals", 0xa1a0c, ft_PyFunction_GetGlobals },
    { "PyFunction_GetDefaults", 0xa1a4c, ft_PyFunction_GetDefaults },
    { "PyFunction_SetDefaults", 0xa1a8c, ft_PyFunction_SetDefaults },
    { "PyFunction_GetKwDefaults", 0xa1b50, ft_PyFunction_GetKwDefaults },
    { "PyFunction_SetKwDefaults", 0xa1b90, ft_PyFunction_SetKwDefaults },
    { "PyFunction_GetClosure", 0xa1c54, ft_PyFunction_GetClosure },
    { "PyFunction_SetClosure", 0xa1c94, ft_PyFunction_SetClosure },
    { "PyFunction_SetAnnotations", 0xa1d3c, ft_PyFunction_SetAnnotations },
    { "PyUnstable_Code_GetExtra", 0xa1de4, ft_PyUnstable_Code_GetExtra },
    { "PyUnstable_Code_SetExtra", 0xa1e54, ft_PyUnstable_Code_SetExtra },
    { "PyMethod_Function", 0xa207c, ft_PyMethod_Function },
    { "PyMethod_Self", 0xa20bc, ft_PyMethod_Self },
    { "PyInstanceMethod_Function", 0xa2120, ft_PyInstanceMethod_Function },
    { "PyCell_Get", 0xa2160, ft_PyCell_Get },
    { "_PyBytes_DecodeEscape", 0xa222c, ft__PyBytes_DecodeEscape },
    { "PyContext_Enter", 0xa2510, ft_PyContext_Enter },
    { "PyErr_SetInterruptEx", 0xa2970, ft_PyErr_SetInterruptEx },
    { "PyErr_SetInterrupt", 0xa29ec, ft_PyErr_SetInterrupt },
    { "PyDict_GetItemString", 0xa2e74, ft_PyDict_GetItemString },
    { "_PySys_GetAttr", 0xa2ee4, ft__PySys_GetAttr },
    { "PySys_HasWarnOptions", 0xa2f38, ft_PySys_HasWarnOptions },
    { "PyEval_EvalCodeEx", 0xa2fe8, ft_PyEval_EvalCodeEx },
    { "_PyUnicode_FromId", 0xa3348, ft__PyUnicode_FromId },
    { "_PyUnicode_EqualToASCIIId", 0xa3490, ft__PyUnicode_EqualToASCIIId },
    { "_PyObject_GetAttrId", 0xa3528, ft__PyObject_GetAttrId },
    { "_PyObject_SetAttrId", 0xa3564, ft__PyObject_SetAttrId },
    { "_PyObject_LookupAttrId", 0xa35ac, ft__PyObject_LookupAttrId },
    { "_PyDict_GetItemIdWithError", 0xa35f8, ft__PyDict_GetItemIdWithError },
    { "_PyDict_DelItemId", 0xa3638, ft__PyDict_DelItemId },
    { "PyUnicode_InternImmortal", 0xa3678, ft_PyUnicode_InternImmortal },
    { "PyStructSequence_InitType2", 0xa3768, ft_PyStructSequence_InitType2 },
    { "PyStructSequence_InitType", 0xa3900, ft_PyStructSequence_InitType },
    { "_PyDict_SetItemId", 0xa39d0, ft__PyDict_SetItemId },
    { "PySys_GetXOptions", 0xa3b00, ft_PySys_GetXOptions },
    { "PySys_AddWarnOptionUnicode", 0xa3b40, ft_PySys_AddWarnOptionUnicode },
    { "PySys_AddWarnOption", 0xa3cfc, ft_PySys_AddWarnOption },
    { "PySys_AddXOption", 0xa3d88, ft_PySys_AddXOption },
    { "_PyThread_CurrentFrames", 0xa3f18, ft__PyThread_CurrentFrames },
    { "_PyThread_CurrentExceptions", 0xa4074, ft__PyThread_CurrentExceptions },
    { "PyFunction_GetAnnotations", 0xa43d0, ft_PyFunction_GetAnnotations },
    { "_PyType_LookupId", 0xa440c, ft__PyType_LookupId },
    { "_PyObject_LookupSpecialId", 0xa4480, ft__PyObject_LookupSpecialId },
    { "PyVectorcall_Call", 0xa62b4, ft_PyVectorcall_Call },
    { "_PyExc_CreateExceptionGroup", 0xa6694, ft__PyExc_CreateExceptionGroup },
    { "_PyErr_CheckSignals", 0xa69b4, ft__PyErr_CheckSignals },
    { "PyEval_CallObjectWithKeywords", 0xa69dc, ft_PyEval_CallObjectWithKeywords },
    { "PyCodec_Decoder", 0xa6c80, ft_PyCodec_Decoder },
    { "PyCodec_Encoder", 0xa6c88, ft_PyCodec_Encoder },
    { "PyCodec_KnownEncoding", 0xa6c90, ft_PyCodec_KnownEncoding },
    { "PyByteArray_FromObject", 0xa74a0, ft_PyByteArray_FromObject },
    { "PyIter_Send", 0xa8d90, ft_PyIter_Send },
    { "PySlice_GetIndicesEx", 0xa9678, ft_PySlice_GetIndicesEx },
    { "_Py_Uid_Converter", 0xaa668, ft__Py_Uid_Converter },
    { "_Py_Gid_Converter", 0xaa80c, ft__Py_Gid_Converter },
    { "_PyInterpreterID_LookUp", 0xab5c0, ft__PyInterpreterID_LookUp },
    { "PyEval_GetFuncName", 0xabf94, ft_PyEval_GetFuncName },
    { "PyModule_GetFilename", 0xac1f4, ft_PyModule_GetFilename },
    { "_PyImport_ClearExtension", 0xac24c, ft__PyImport_ClearExtension },
    { "_Py_UTF8_Edit_Cost", 0xac850, ft__Py_UTF8_Edit_Cost },
    { "PyUnicode_AsUTF32String", 0xacb18, ft_PyUnicode_AsUTF32String },
    { "PyUnicode_AsUTF16String", 0xacb54, ft_PyUnicode_AsUTF16String },
    { "PyUnicode_DecodeLocaleAndSize", 0xacb60, ft_PyUnicode_DecodeLocaleAndSize },
    { "_Py_get_inheritable", 0xad470, ft__Py_get_inheritable },
    { "_Py_set_inheritable_async_safe", 0xad58c, ft__Py_set_inheritable_async_safe },
    { "_Py_fstat", 0xad598, ft__Py_fstat },
    { "_Py_get_blocking", 0xad5f4, ft__Py_get_blocking },
    { "_Py_set_blocking", 0xad6a8, ft__Py_set_blocking },
    { "PyObject_Print", 0xad810, ft_PyObject_Print },
    { "_PyErr_SetLocaleString", 0xaecf0, ft__PyErr_SetLocaleString },
    { "PyErr_SetFromErrnoWithFilename", 0xaf530, ft_PyErr_SetFromErrnoWithFilename },
    { "_Py_stat", 0xafbf8, ft__Py_stat },
    { "PyCodec_StreamWriter", 0xaffd0, ft_PyCodec_StreamWriter },
    { "PyCodec_StreamReader", 0xaffd8, ft_PyCodec_StreamReader },
    { "_Py_GetConfigsAsDict", 0xb07a4, ft__Py_GetConfigsAsDict },
    { "PySys_SetPath", 0xb1290, ft_PySys_SetPath },
    { "PySys_SetArgvEx", 0xb13e4, ft_PySys_SetArgvEx },
    { "PySys_SetArgv", 0xb1674, ft_PySys_SetArgv },
    { "PyUnicode_RSplit", 0xb2cd8, ft_PyUnicode_RSplit },
    { "PyUnicode_Find", 0xb2f5c, ft_PyUnicode_Find },
    { "PyMapping_Values", 0xb8678, ft_PyMapping_Values },
    { "PyObject_Length", 0xb8f04, ft_PyObject_Length },
    { "_Py_strhex_bytes", 0xb8f08, ft__Py_strhex_bytes },
    { "PyMapping_Length", 0xb90d8, ft_PyMapping_Length },
    { "PySequence_DelSlice", 0xb9414, ft_PySequence_DelSlice },
    { "PySequence_SetSlice", 0xb94c0, ft_PySequence_SetSlice },
    { "PyObject_DelItemString", 0xb9570, ft_PyObject_DelItemString },
    { "PySequence_Length", 0xb971c, ft_PySequence_Length },
    { "PyBytes_ConcatAndDel", 0xbd8f8, ft_PyBytes_ConcatAndDel },
    { "_PyEval_SetProfile", 0xbd91c, ft__PyEval_SetProfile },
    { "_PyErr_ChainExceptions", 0xbdc54, ft__PyErr_ChainExceptions },
    { "PyErr_SetImportErrorSubclass", 0xbdd74, ft_PyErr_SetImportErrorSubclass },
    { "PyErr_SetImportError", 0xbdd90, ft_PyErr_SetImportError },
    { "PyMapping_HasKeyString", 0xc2504, ft_PyMapping_HasKeyString },
    { "_PyInterpreterState_GetMainModule", 0xc2544, ft__PyInterpreterState_GetMainModule },
    { "PyMapping_HasKey", 0xc2584, ft_PyMapping_HasKey },
    { "PyUnicode_AsCharmapString", 0xc2bc8, ft_PyUnicode_AsCharmapString },
    { "_PyImport_GetModuleId", 0xc3594, ft__PyImport_GetModuleId },
    { "PyUnstable_Code_New", 0xc5140, ft_PyUnstable_Code_New },
    { "_PyCompile_OptimizeCfg", 0xc5448, ft__PyCompile_OptimizeCfg },
    { "_PyDictView_Intersect", 0xc58d8, ft__PyDictView_Intersect },
    { "_PyExc_PrepReraiseStar", 0xc5c68, ft__PyExc_PrepReraiseStar },
    { "PyUnstable_Exc_PrepReraiseStar", 0xc5f84, ft_PyUnstable_Exc_PrepReraiseStar },
    { "_PyDict_ContainsId", 0xc62d4, ft__PyDict_ContainsId },
    { "PyFrame_GetLocals", 0xc6b30, ft_PyFrame_GetLocals },
    { "PyFrame_FastToLocalsWithError", 0xc6b38, ft_PyFrame_FastToLocalsWithError },
    { "PyFrame_FastToLocals", 0xc6b84, ft_PyFrame_FastToLocals },
    { "PyEval_GetLocals", 0xc6c34, ft_PyEval_GetLocals },
    { "PyImport_ExecCodeModuleObject", 0xc725c, ft_PyImport_ExecCodeModuleObject },
    { "PyImport_ExecCodeModuleWithPathnames", 0xc73b0, ft_PyImport_ExecCodeModuleWithPathnames },
    { "PyImport_ExecCodeModuleEx", 0xc7578, ft_PyImport_ExecCodeModuleEx },
    { "PyImport_ExecCodeModule", 0xc7580, ft_PyImport_ExecCodeModule },
    { "_PyType_CheckConsistency", 0xc758c, ft__PyType_CheckConsistency },
    { "_PyObject_CheckConsistency", 0xc7778, ft__PyObject_CheckConsistency },
    { "_PyCompile_Assemble", 0xc7b40, ft__PyCompile_Assemble },
    { "PyUnicode_DecodeUTF7", 0xc7ce0, ft_PyUnicode_DecodeUTF7 },
    { "PyUnicode_Translate", 0xc8118, ft_PyUnicode_Translate },
    { "PyUnicode_DecodeUnicodeEscape", 0xc889c, ft_PyUnicode_DecodeUnicodeEscape },
    { "_PyUnicode_DecodeUnicodeEscapeInternal", 0xc88a4, ft__PyUnicode_DecodeUnicodeEscapeInternal },
    { "PyFile_FromFd", 0xc8a0c, ft_PyFile_FromFd },
    { "PyFile_OpenCode", 0xc8ae4, ft_PyFile_OpenCode },
    { "PyUnicode_AsDecodedObject", 0xc9604, ft_PyUnicode_AsDecodedObject },
    { "PyUnicode_AsDecodedUnicode", 0xc9690, ft_PyUnicode_AsDecodedUnicode },
    { "PyUnicode_AsEncodedObject", 0xc9778, ft_PyUnicode_AsEncodedObject },
    { "PyInterpreterState_Clear", 0xcd2f8, ft_PyInterpreterState_Clear },
    { "PyErr_Print", 0xcd33c, ft_PyErr_Print },
    { "PyErr_PrintEx", 0xcd368, ft_PyErr_PrintEx },
    { "_PyErr_Print", 0xcd394, ft__PyErr_Print },
    { "_PyInterpreterState_IDDecref", 0xcd39c, ft__PyInterpreterState_IDDecref },
    { "_PyInterpreterID_New", 0xcd588, ft__PyInterpreterID_New },
    { "_PyInterpreterState_GetIDObject", 0xcd59c, ft__PyInterpreterState_GetIDObject },
    { "PyEval_SetProfile", 0xcd5ec, ft_PyEval_SetProfile },
    { "PyEval_SetProfileAllThreads", 0xcd63c, ft_PyEval_SetProfileAllThreads },
    { "PyEval_SetTrace", 0xcd730, ft_PyEval_SetTrace },
    { "_Py_open", 0xcf128, ft__Py_open },
    { "PyErr_ProgramText", 0xcf25c, ft_PyErr_ProgramText },
    { "PyErr_SyntaxLocationEx", 0xcf2c4, ft_PyErr_SyntaxLocationEx },
    { "PyErr_SyntaxLocation", 0xcf344, ft_PyErr_SyntaxLocation },
    { "PyRun_SimpleString", 0xcf8e0, ft_PyRun_SimpleString },
    { "PyRun_String", 0xcf8e8, ft_PyRun_String },
    { "Py_CompileString", 0xcf8f0, ft_Py_CompileString },
    { "Py_CompileStringFlags", 0xcf8fc, ft_Py_CompileStringFlags },
    { "PyMarshal_ReadLastObjectFromFile", 0xd1018, ft_PyMarshal_ReadLastObjectFromFile },
    { "Py_NewInterpreterFromConfig", 0xd12fc, ft_Py_NewInterpreterFromConfig },
    { "_PyCompile_CodeGen", 0xd16e0, ft__PyCompile_CodeGen },
    { "PyFile_SetOpenCodeHook", 0xd2080, ft_PyFile_SetOpenCodeHook },
    { "PyRun_InteractiveOneObject", 0xd2478, ft_PyRun_InteractiveOneObject },
    { "PyRun_InteractiveOneFlags", 0xd24c8, ft_PyRun_InteractiveOneFlags },
    { "PyRun_InteractiveOne", 0xd255c, ft_PyRun_InteractiveOne },
    { "PyRun_InteractiveLoopFlags", 0xd2770, ft_PyRun_InteractiveLoopFlags },
    { "PyRun_InteractiveLoop", 0xd2804, ft_PyRun_InteractiveLoop },
    { "PyRun_SimpleFileExFlags", 0xd280c, ft_PyRun_SimpleFileExFlags },
    { "PyRun_SimpleFile", 0xd2888, ft_PyRun_SimpleFile },
    { "PyRun_SimpleFileEx", 0xd2894, ft_PyRun_SimpleFileEx },
    { "PyRun_AnyFileExFlags", 0xd289c, ft_PyRun_AnyFileExFlags },
    { "PyRun_AnyFile", 0xd292c, ft_PyRun_AnyFile },
    { "PyRun_AnyFileEx", 0xd2938, ft_PyRun_AnyFileEx },
    { "PyRun_AnyFileFlags", 0xd2940, ft_PyRun_AnyFileFlags },
    { "PyRun_FileExFlags", 0xd294c, ft_PyRun_FileExFlags },
    { "PyRun_File", 0xd29f4, ft_PyRun_File },
    { "PyRun_FileEx", 0xd2a00, ft_PyRun_FileEx },
    { "Py_ExitStatusException", 0xd68d4, ft_Py_ExitStatusException },
    { "Py_Initialize", 0xd69f0, ft_Py_Initialize },
    { "PyOS_AfterFork", 0xd6e94, ft_PyOS_AfterFork },
    { "Py_Main", 0xd6ff4, ft_Py_Main },
    { "_PyErr_DisplayException", 0xd7278, ft__PyErr_DisplayException },
    { "PyOS_InterruptOccurred", 0xd7688, ft_PyOS_InterruptOccurred },
    { "_PyOS_IsMainThread", 0xd76b0, ft__PyOS_IsMainThread },
    { "_Py_Get_Getpath_CodeObject", 0xd76dc, ft__Py_Get_Getpath_CodeObject },
    { "PyMem_RawMalloc", 0xd7700, ft_PyMem_RawMalloc },
    { "PyThread_get_thread_ident", 0xd7750, ft_PyThread_get_thread_ident },
    { "PyMem_RawFree", 0xd7784, ft_PyMem_RawFree },
    { "PyObject_Hash", 0xd7ea0, ft_PyObject_Hash },
    { "_Py_HashBytes", 0xd7f88, ft__Py_HashBytes },
    { "PyMem_RawCalloc", 0xd83a0, ft_PyMem_RawCalloc },
    { "_Py_hashtable_get", 0xd88a4, ft__Py_hashtable_get },
    { "_Py_hashtable_set", 0xd8a64, ft__Py_hashtable_set },
    { "PyList_New", 0xd8bc0, ft_PyList_New },
    { "_PyObject_GC_New", 0xd8d60, ft__PyObject_GC_New },
    { "_Py_NewReference", 0xd9440, ft__Py_NewReference },
    { "PyTuple_New", 0xdb480, ft_PyTuple_New },
    { "_PyUnicode_InternImmortal", 0xdb740, ft__PyUnicode_InternImmortal },
    { "PyMem_Malloc", 0xdbd90, ft_PyMem_Malloc },
    { "PyMem_Calloc", 0xdbdc0, ft_PyMem_Calloc },
    { "PyMem_Free", 0xdc0e4, ft_PyMem_Free },
    { "_PyUnicode_InternMortal", 0xdc100, ft__PyUnicode_InternMortal },
    { "PySequence_Tuple", 0xdc3e0, ft_PySequence_Tuple },
    { "PyList_AsTuple", 0xdc740, ft_PyList_AsTuple },
    { "_PyObject_GC_NewVar", 0xdc988, ft__PyObject_GC_NewVar },
    { "_Py_Dealloc", 0xdcac8, ft__Py_Dealloc },
    { "PyObject_GC_UnTrack", 0xdcd00, ft_PyObject_GC_UnTrack },
    { "_PyTrash_cond", 0xdcd40, ft__PyTrash_cond },
    { "_PyThreadState_GetCurrent", 0xdcd60, ft__PyThreadState_GetCurrent },
    { "_PyThreadState_UncheckedGet", 0xdcd88, ft__PyThreadState_UncheckedGet },
    { "_PyTrash_begin", 0xdcdb0, ft__PyTrash_begin },
    { "_PyTrash_end", 0xdce80, ft__PyTrash_end },
    { "PyType_IsSubtype", 0xdd1a8, ft_PyType_IsSubtype },
    { "PyDict_Contains", 0xdd250, ft_PyDict_Contains },
    { "PyCMethod_New", 0xddd20, ft_PyCMethod_New },
    { "PyObject_IS_GC", 0xde660, ft_PyObject_IS_GC },
    { "PyType_GenericAlloc", 0xde828, ft_PyType_GenericAlloc },
    { "PyUnicode_InternFromString", 0xde9e0, ft_PyUnicode_InternFromString },
    { "PyUnicode_New", 0xdf5a4, ft_PyUnicode_New },
    { "PyObject_Free", 0xdfce0, ft_PyObject_Free },
    { "PyTuple_Pack", 0xe0f0c, ft_PyTuple_Pack },
    { "PyLong_FromVoidPtr", 0xe1560, ft_PyLong_FromVoidPtr },
    { "PyLong_FromUnsignedLong", 0xe1564, ft_PyLong_FromUnsignedLong },
    { "_PyLong_New", 0xe1608, ft__PyLong_New },
    { "PyWeakref_NewRef", 0xe1700, ft_PyWeakref_NewRef },
    { "PyObject_GC_Track", 0xe1984, ft_PyObject_GC_Track },
    { "PyObject_GC_Del", 0xe1dc0, ft_PyObject_GC_Del },
    { "PyUnicode_FromStringAndSize", 0xe1ec0, ft_PyUnicode_FromStringAndSize },
    { "PyErr_Occurred", 0xe1f30, ft_PyErr_Occurred },
    { "PyObject_GetItemData", 0xe1f68, ft_PyObject_GetItemData },
    { "_PyType_GetDict", 0xe1fb0, ft__PyType_GetDict },
    { "PyLong_FromSsize_t", 0xe1fc0, ft_PyLong_FromSsize_t },
    { "PyLong_FromLong", 0xe2620, ft_PyLong_FromLong },
    { "PyDict_GetItemWithError", 0xe27c8, ft_PyDict_GetItemWithError },
    { "PyObject_SetAttr", 0xe28a0, ft_PyObject_SetAttr },
    { "PyObject_GenericSetAttr", 0xe2acc, ft_PyObject_GenericSetAttr },
    { "_PyType_Lookup", 0xe31cc, ft__PyType_Lookup },
    { "_PyDict_GetItem_KnownHash", 0xe35f0, ft__PyDict_GetItem_KnownHash },
    { "_PyObject_New", 0xe3a2c, ft__PyObject_New },
    { "PyObject_GetItem", 0xe3ac0, ft_PyObject_GetItem },
    { "PyStructSequence_New", 0xe51ac, ft_PyStructSequence_New },
    { "PyLong_AsSsize_t", 0xe5240, ft_PyLong_AsSsize_t },
    { "PyList_Append", 0xe548c, ft_PyList_Append },
    { "PyMem_Realloc", 0xe5680, ft_PyMem_Realloc },
    { "PyObject_GetIter", 0xe7e88, ft_PyObject_GetIter },
    { "_Py_CheckFunctionResult", 0xe8888, ft__Py_CheckFunctionResult },
    { "_PyInterpreterState_GetConfig", 0xe97c0, ft__PyInterpreterState_GetConfig },
    { "PyBool_FromLong", 0xe97c8, ft_PyBool_FromLong },
    { "PyObject_SetItem", 0xe97e4, ft_PyObject_SetItem },
    { "PyUnicode_CompareWithASCIIString", 0xe9950, ft_PyUnicode_CompareWithASCIIString },
    { "PyUnicode_AsUTF8AndSize", 0xe9aa4, ft_PyUnicode_AsUTF8AndSize },
    { "_PyUnicode_FromASCII", 0xe9b80, ft__PyUnicode_FromASCII },
    { "PyBytes_FromStringAndSize", 0xe9c70, ft_PyBytes_FromStringAndSize },
    { "PyInterpreterState_Get", 0xecf64, ft_PyInterpreterState_Get },
    { "PyDict_Next", 0xecfc8, ft_PyDict_Next },
    { "_PyDict_Next", 0xecfd0, ft__PyDict_Next },
    { "_PyObject_LookupSpecial", 0xed124, ft__PyObject_LookupSpecial },
    { "PyObject_GetAttr", 0xed3cc, ft_PyObject_GetAttr },
    { "_PyObject_FastCallDictTstate", 0xeda60, ft__PyObject_FastCallDictTstate },
    { "_PyDict_GetItemStringWithError", 0xedfe0, ft__PyDict_GetItemStringWithError },
    { "_PyArena_AddPyObject", 0xf7220, ft__PyArena_AddPyObject },
    { "PyUnicode_DecodeUTF8", 0x108264, ft_PyUnicode_DecodeUTF8 },
    { "_PyArena_Malloc", 0x1085d0, ft__PyArena_Malloc },
    { "_PyToken_TwoChars", 0x108780, ft__PyToken_TwoChars },
    { "_PyUnicode_IsPrintable", 0x10a1d0, ft__PyUnicode_IsPrintable },
    { "_PyToken_OneChar", 0x10a2c0, ft__PyToken_OneChar },
    { "PyFunction_New", 0x10de40, ft_PyFunction_New },
    { "PyFunction_NewWithQualName", 0x10de48, ft_PyFunction_NewWithQualName },
    { "PyTuple_Size", 0x10e664, ft_PyTuple_Size },
    { "PyTuple_GetItem", 0x10eeac, ft_PyTuple_GetItem },
    { "PyObject_Vectorcall", 0x11028c, ft_PyObject_Vectorcall },
    { "_PyObject_LookupAttr", 0x112290, ft__PyObject_LookupAttr },
    { "PyDescr_IsData", 0x112aa0, ft_PyDescr_IsData },
    { "PyType_GenericNew", 0x1156a0, ft_PyType_GenericNew },
    { "_PyObject_GenericGetAttrWithDict", 0x1157e0, ft__PyObject_GenericGetAttrWithDict },
    { "_PyArg_CheckPositional", 0x116fa0, ft__PyArg_CheckPositional },
    { "PyNumber_Add", 0x11a700, ft_PyNumber_Add },
    { "PyOS_strtol", 0x11bce0, ft_PyOS_strtol },
    { "PyOS_strtoul", 0x11be30, ft_PyOS_strtoul },
    { "_PyUnicode_DecodeUnicodeEscapeInternal2", 0x11c52c, ft__PyUnicode_DecodeUnicodeEscapeInternal2 },
    { "_PyUnicodeWriter_Finish", 0x11ce48, ft__PyUnicodeWriter_Finish },
    { "PyObject_Realloc", 0x11d0e4, ft_PyObject_Realloc },
    { "_Py_NewReferenceNoTotal", 0x11d140, ft__Py_NewReferenceNoTotal },
    { "_PyUnicode_EqualToASCIIString", 0x11d180, ft__PyUnicode_EqualToASCIIString },
    { "PyObject_GetAttrString", 0x11d200, ft_PyObject_GetAttrString },
    { "PyModule_GetState", 0x11d2a0, ft_PyModule_GetState },
    { "PyCallable_Check", 0x11d7ac, ft_PyCallable_Check },
    { "_PyFunction_Vectorcall", 0x11d7cc, ft__PyFunction_Vectorcall },
    { "_PyBytesWriter_Prepare", 0x11db70, ft__PyBytesWriter_Prepare },
    { "_PyBytesWriter_Finish", 0x11dec4, ft__PyBytesWriter_Finish },
    { "PyObject_GetBuffer", 0x11e5cc, ft_PyObject_GetBuffer },
    { "PySequence_Contains", 0x11e710, ft_PySequence_Contains },
    { "PyBuffer_FillInfo", 0x11eae4, ft_PyBuffer_FillInfo },
    { "PyObject_RichCompareBool", 0x11ebb0, ft_PyObject_RichCompareBool },
    { "PyBuffer_Release", 0x11ec60, ft_PyBuffer_Release },
    { "PyObject_RichCompare", 0x11ed08, ft_PyObject_RichCompare },
    { "PyUnicode_RichCompare", 0x11f084, ft_PyUnicode_RichCompare },
    { "_PyUnicodeWriter_WriteASCIIString", 0x1200e8, ft__PyUnicodeWriter_WriteASCIIString },
    { "_PyUnicodeWriter_WriteStr", 0x120700, ft__PyUnicodeWriter_WriteStr },
    { "_PyErr_SetObject", 0x120824, ft__PyErr_SetObject },
    { "PyObject_CallOneArg", 0x120dcc, ft_PyObject_CallOneArg },
    { "PyException_GetTraceback", 0x121b20, ft_PyException_GetTraceback },
    { "_PyErr_Restore", 0x121b40, ft__PyErr_Restore },
    { "PyErr_ExceptionMatches", 0x121d30, ft_PyErr_ExceptionMatches },
    { "_PyErr_ExceptionMatches", 0x121d80, ft__PyErr_ExceptionMatches },
    { "PyErr_GivenExceptionMatches", 0x121d90, ft_PyErr_GivenExceptionMatches },
    { "PyErr_GetRaisedException", 0x121f0c, ft_PyErr_GetRaisedException },
    { "PyErr_SetRaisedException", 0x121f40, ft_PyErr_SetRaisedException },
    { "PyErr_Clear", 0x121fa0, ft_PyErr_Clear },
    { "_PyModuleSpec_IsInitializing", 0x121ff0, ft__PyModuleSpec_IsInitializing },
    { "PyTraceBack_Here", 0x1221c4, ft_PyTraceBack_Here },
    { "_PyTraceBack_FromFrame", 0x122448, ft__PyTraceBack_FromFrame },
    { "PyException_SetTraceback", 0x122464, ft_PyException_SetTraceback },
    { "PyObject_IsTrue", 0x1227a0, ft_PyObject_IsTrue },
    { "_PyObject_Call_Prepend", 0x122b8c, ft__PyObject_Call_Prepend },
    { "PyNumber_AsSsize_t", 0x123dd0, ft_PyNumber_AsSsize_t },
    { "_PyNumber_Index", 0x123ed0, ft__PyNumber_Index },
    { "_PyDict_MergeEx", 0x126590, ft__PyDict_MergeEx },
    { "PyObject_Call", 0x1265d0, ft_PyObject_Call },
    { "_PyObject_Call", 0x12660c, ft__PyObject_Call },
    { "PyLong_AsLong", 0x129680, ft_PyLong_AsLong },
    { "PyLong_AsLongAndOverflow", 0x129708, ft_PyLong_AsLongAndOverflow },
    { "PySet_New", 0x12a000, ft_PySet_New },
    { "PySet_Add", 0x12b468, ft_PySet_Add },
    { "PySet_Discard", 0x12b580, ft_PySet_Discard },
    { "_PyUnicode_Equal", 0x12b670, ft__PyUnicode_Equal },
    { "PySet_Contains", 0x12ba40, ft_PySet_Contains },
    { "PyNumber_InPlaceOr", 0x12bb0c, ft_PyNumber_InPlaceOr },
    { "PyObject_Calloc", 0x12c1a0, ft_PyObject_Calloc },
    { "PyObject_Format", 0x12c3a0, ft_PyObject_Format },
    { "PyNumber_Lshift", 0x12c640, ft_PyNumber_Lshift },
    { "PyObject_Str", 0x12cb88, ft_PyObject_Str },
    { "PyErr_CheckSignals", 0x12cde0, ft_PyErr_CheckSignals },
    { "_PyUnicode_JoinArray", 0x12ed60, ft__PyUnicode_JoinArray },
    { "PyNumber_Negative", 0x1347c0, ft_PyNumber_Negative },
    { "PyUnicode_FindChar", 0x1348cc, ft_PyUnicode_FindChar },
    { "PyObject_IsSubclass", 0x136260, ft_PyObject_IsSubclass },
    { "_PyList_Extend", 0x136920, ft__PyList_Extend },
    { "PySequence_Fast", 0x136da0, ft_PySequence_Fast },
    { "PyObject_SelfIter", 0x137380, ft_PyObject_SelfIter },
    { "PyObject_CallFinalizerFromDealloc", 0x1379e0, ft_PyObject_CallFinalizerFromDealloc },
    { "PyObject_CallFinalizer", 0x137b00, ft_PyObject_CallFinalizer },
    { "_PyGen_Finalize", 0x137b84, ft__PyGen_Finalize },
    { "_PyLong_AsInt", 0x13ae00, ft__PyLong_AsInt },
    { "PyImport_ImportModuleLevelObject", 0x13b400, ft_PyImport_ImportModuleLevelObject },
    { "_PyBytes_Resize", 0x13e868, ft__PyBytes_Resize },
    { "_Py_HashPointer", 0x13ebf0, ft__Py_HashPointer },
    { "PyObject_ClearWeakRefs", 0x13f6ec, ft_PyObject_ClearWeakRefs },
    { "PyObject_CheckBuffer", 0x141ae0, ft_PyObject_CheckBuffer },
    { "PyObject_LengthHint", 0x141b04, ft_PyObject_LengthHint },
    { "_PyObject_HasLen", 0x141d0c, ft__PyObject_HasLen },
    { "PyObject_Size", 0x141d48, ft_PyObject_Size },
    { "_PyObject_VisitManagedDict", 0x142e00, ft__PyObject_VisitManagedDict },
    { "PyEval_GetGlobals", 0x144470, ft_PyEval_GetGlobals },
    { "_Py_HashPointerRaw", 0x14470c, ft__Py_HashPointerRaw },
    { "_Py_hashtable_destroy", 0x144810, ft__Py_hashtable_destroy },
    { "PyObject_DelItem", 0x144960, ft_PyObject_DelItem },
    { "PyUnicode_Join", 0x144c60, ft_PyUnicode_Join },
    { "_PyLong_AsByteArray", 0x144d80, ft__PyLong_AsByteArray },
    { "_PyLong_FromByteArray", 0x14556c, ft__PyLong_FromByteArray },
    { "PyImport_Import", 0x145e2c, ft_PyImport_Import },
    { "PySlice_Unpack", 0x146840, ft_PySlice_Unpack },
    { "_PyEval_SliceIndex", 0x146a64, ft__PyEval_SliceIndex },
    { "PySlice_AdjustIndices", 0x146b24, ft_PySlice_AdjustIndices },
    { "PyUnicode_AsEncodedString", 0x146d68, ft_PyUnicode_AsEncodedString },
    { "_PyBytesWriter_Init", 0x1474c0, ft__PyBytesWriter_Init },
    { "_PyBytesWriter_Alloc", 0x1474d0, ft__PyBytesWriter_Alloc },
    { "PyObject_VectorcallMethod", 0x147564, ft_PyObject_VectorcallMethod },
    { "PyIndex_Check", 0x1476e8, ft_PyIndex_Check },
    { "PyLong_FromUnsignedLongLong", 0x1485e0, ft_PyLong_FromUnsignedLongLong },
    { "PyLong_FromLongLong", 0x148684, ft_PyLong_FromLongLong },
    { "PyNumber_Multiply", 0x148688, ft_PyNumber_Multiply },
    { "_PyLong_Sign", 0x149e08, ft__PyLong_Sign },
    { "PyType_GetModuleByDef", 0x14b8f0, ft_PyType_GetModuleByDef },
    { "PyBuffer_IsContiguous", 0x14cdc4, ft_PyBuffer_IsContiguous },
    { "PySequence_GetItem", 0x14d028, ft_PySequence_GetItem },
    { "_PyUnicode_IsAlpha", 0x14d100, ft__PyUnicode_IsAlpha },
    { "_PyUnicode_IsDecimalDigit", 0x14d120, ft__PyUnicode_IsDecimalDigit },
    { "_PyUnicode_ToDecimalDigit", 0x14d140, ft__PyUnicode_ToDecimalDigit },
    { "_PyUnicode_IsDigit", 0x14d168, ft__PyUnicode_IsDigit },
    { "_PyUnicode_ToDigit", 0x14d184, ft__PyUnicode_ToDigit },
    { "_PyUnicode_IsNumeric", 0x14d1ac, ft__PyUnicode_IsNumeric },
    { "_PyUnicode_AsASCIIString", 0x14d360, ft__PyUnicode_AsASCIIString },
    { "PySequence_List", 0x14d3ac, ft_PySequence_List },
    { "PyObject_Repr", 0x14d650, ft_PyObject_Repr },
    { "PyNumber_Or", 0x14e480, ft_PyNumber_Or },
    { "PyNumber_Index", 0x14e5a0, ft_PyNumber_Index },
    { "PyNumber_FloorDivide", 0x1508a0, ft_PyNumber_FloorDivide },
    { "PyIter_Check", 0x152da0, ft_PyIter_Check },
    { "PyUnicode_FromEncodedObject", 0x153800, ft_PyUnicode_FromEncodedObject },
    { "PyNumber_Remainder", 0x154008, ft_PyNumber_Remainder },
    { "_PyUnicodeWriter_WriteSubstring", 0x155510, ft__PyUnicodeWriter_WriteSubstring },
    { "_PyLong_FormatWriter", 0x155640, ft__PyLong_FormatWriter },
    { "_Py_convert_optional_to_ssize_t", 0x155680, ft__Py_convert_optional_to_ssize_t },
    { "_PyDict_MaybeUntrack", 0x158d30, ft__PyDict_MaybeUntrack },
    { "PyDict_MergeFromSeq2", 0x15b7a0, ft_PyDict_MergeFromSeq2 },
    { "PyMapping_Size", 0x15bc60, ft_PyMapping_Size },
    { "PyBytes_Repr", 0x15d140, ft_PyBytes_Repr },
    { "_PyCode_CheckLineNumber", 0x164600, ft__PyCode_CheckLineNumber },
    { "_PyUnicode_TransformDecimalAndSpaceToASCII", 0x1647a4, ft__PyUnicode_TransformDecimalAndSpaceToASCII },
    { "_PyLong_Format", 0x1685a4, ft__PyLong_Format },
    { "_PyUnicode_InsertThousandsGrouping", 0x1697e8, ft__PyUnicode_InsertThousandsGrouping },
    { "PyLong_AsDouble", 0x16a5e0, ft_PyLong_AsDouble },
    { "PyNumber_Rshift", 0x16a70c, ft_PyNumber_Rshift },
    { "PyNumber_InPlaceLshift", 0x16aea0, ft_PyNumber_InPlaceLshift },
    { "PyNumber_Absolute", 0x170960, ft_PyNumber_Absolute },
    { "_PyLong_Copy", 0x170a04, ft__PyLong_Copy },
    { "PyNumber_Divmod", 0x170b08, ft_PyNumber_Divmod },
    { "PyThreadState_EnterTracing", 0x1719c0, ft_PyThreadState_EnterTracing },
    { "_PyLong_GCD", 0x17712c, ft__PyLong_GCD },
    { "PyUnicode_AsUnicodeEscapeString", 0x177804, ft_PyUnicode_AsUnicodeEscapeString },
    { "_PyUnicode_EncodeUTF7", 0x177c04, ft__PyUnicode_EncodeUTF7 },
    { "PyUnicode_DecodeUTF7Stateful", 0x17804c, ft_PyUnicode_DecodeUTF7Stateful },
    { "Py_NewRef", 0x179520, ft_Py_NewRef },
    { "_PyUnicode_InternInPlace", 0x179524, ft__PyUnicode_InternInPlace },
    { "PyCFunction_Call", 0x179528, ft_PyCFunction_Call },
    { "Py_BytesMain", 0x179f60, ft_Py_BytesMain },
    { "_PyRuntime_Initialize", 0x17a300, ft__PyRuntime_Initialize },
    { "PyConfig_SetBytesArgv", 0x17a380, ft_PyConfig_SetBytesArgv },
    { "_PyRuntimeState_Init", 0x17a3e8, ft__PyRuntimeState_Init },
    { "_PyMem_SetDefaultAllocator", 0x17a7a8, ft__PyMem_SetDefaultAllocator },
    { "PyThread_allocate_lock", 0x17aba0, ft_PyThread_allocate_lock },
    { "PyThread_init_thread", 0x17ac10, ft_PyThread_init_thread },
    { "PyMem_SetAllocator", 0x17ac80, ft_PyMem_SetAllocator },
    { "PyThread_tss_create", 0x17ace0, ft_PyThread_tss_create },
    { "_PyMem_RawStrdup", 0x17b700, ft__PyMem_RawStrdup },
    { "_Py_SetLocaleFromEnv", 0x17b780, ft__Py_SetLocaleFromEnv },
    { "_Py_ResetForceASCII", 0x17b7ac, ft__Py_ResetForceASCII },
    { "_PyArgv_AsWstrList", 0x17b7c0, ft__PyArgv_AsWstrList },
    { "Py_DecodeLocale", 0x17b960, ft_Py_DecodeLocale },
    { "_PyWideStringList_Clear", 0x17c2e0, ft__PyWideStringList_Clear },
    { "_Py_get_xoption", 0x17c324, ft__Py_get_xoption },
    { "_Py_GetEnv", 0x17c3c4, ft__Py_GetEnv },
    { "PyWideStringList_Append", 0x17c80c, ft_PyWideStringList_Append },
    { "PyWideStringList_Insert", 0x17c864, ft_PyWideStringList_Insert },
    { "_PyMem_RawWcsdup", 0x17c9c0, ft__PyMem_RawWcsdup },
    { "PyStatus_Exception", 0x17ca4c, ft_PyStatus_Exception },
    { "_Py_LegacyLocaleDetected", 0x17ca60, ft__Py_LegacyLocaleDetected },
    { "PyConfig_Clear", 0x17d720, ft_PyConfig_Clear },
    { "PyConfig_Read", 0x17f4c0, ft_PyConfig_Read },
    { "PyThread_acquire_lock", 0x17f520, ft_PyThread_acquire_lock },
    { "PyThread_acquire_lock_timed", 0x17f5e8, ft_PyThread_acquire_lock_timed },
    { "_PyTime_FromNanoseconds", 0x17f800, ft__PyTime_FromNanoseconds },
    { "Py_GetBuildInfo", 0x181580, ft_Py_GetBuildInfo },
    { "_Py_IsLocaleCoercionTarget", 0x181ac0, ft__Py_IsLocaleCoercionTarget },
    { "PyStatus_Ok", 0x181b10, ft_PyStatus_Ok },
    { "PyInterpreterState_New", 0x181cf0, ft_PyInterpreterState_New },
    { "_PyTraceMalloc_Init", 0x182384, ft__PyTraceMalloc_Init },
    { "PyMem_GetAllocator", 0x182540, ft_PyMem_GetAllocator },
    { "_PyThreadState_New", 0x182840, ft__PyThreadState_New },
    { "_PyThreadState_Bind", 0x1829a0, ft__PyThreadState_Bind },
    { "PyThread_get_thread_native_id", 0x182a20, ft_PyThread_get_thread_native_id },
    { "PyThread_tss_get", 0x182a60, ft_PyThread_tss_get },
    { "Py_GETENV", 0x187bc4, ft_Py_GETENV },
    { "PyGILState_Check", 0x188028, ft_PyGILState_Check },
    { "PyThread_tss_is_created", 0x18c7d0, ft_PyThread_tss_is_created },
    { "PyDescr_NewWrapper", 0x18ce40, ft_PyDescr_NewWrapper },
    { "PyDescr_NewMethod", 0x18d030, ft_PyDescr_NewMethod },
    { "PyDescr_NewClassMethod", 0x18d124, ft_PyDescr_NewClassMethod },
    { "PyDescr_NewGetSet", 0x18d160, ft_PyDescr_NewGetSet },
    { "PyDescr_NewMember", 0x18d340, ft_PyDescr_NewMember },
    { "PyStaticMethod_New", 0x18d670, ft_PyStaticMethod_New },
    { "PyType_FromSpec", 0x18d78c, ft_PyType_FromSpec },
    { "_PyType_CalculateMetaclass", 0x18e1e4, ft__PyType_CalculateMetaclass },
    { "PyType_Ready", 0x18e404, ft_PyType_Ready },
    { "PyType_Modified", 0x18e42c, ft_PyType_Modified },
    { "PyDict_SetItemString", 0x18eaf0, ft_PyDict_SetItemString },
    { "_PyModule_CreateInitialized", 0x18f42c, ft__PyModule_CreateInitialized },
    { "PyModuleDef_Init", 0x18f580, ft_PyModuleDef_Init },
    { "PyModule_New", 0x18f660, ft_PyModule_New },
    { "PyModule_AddFunctions", 0x18f8a8, ft_PyModule_AddFunctions },
    { "PyModule_GetNameObject", 0x18f920, ft_PyModule_GetNameObject },
    { "PyObject_SetAttrString", 0x18fab0, ft_PyObject_SetAttrString },
    { "PyModule_SetDocString", 0x18fba0, ft_PyModule_SetDocString },
    { "PyModule_GetDict", 0x18fc40, ft_PyModule_GetDict },
    { "PyDict_Copy", 0x18fc80, ft_PyDict_Copy },
    { "PyFile_NewStdPrinter", 0x18ff40, ft_PyFile_NewStdPrinter },
    { "PyMapping_GetItemString", 0x190008, ft_PyMapping_GetItemString },
    { "Py_GetVersion", 0x190080, ft_Py_GetVersion },
    { "_Py_gitversion", 0x1900a0, ft__Py_gitversion },
    { "_Py_gitidentifier", 0x1900ac, ft__Py_gitidentifier },
    { "Py_GetCopyright", 0x1900c0, ft_Py_GetCopyright },
    { "Py_GetPlatform", 0x1900d0, ft_Py_GetPlatform },
    { "PyFloat_GetInfo", 0x1900e0, ft_PyFloat_GetInfo },
    { "PyLong_GetInfo", 0x190270, ft_PyLong_GetInfo },
    { "PyHash_GetFuncDef", 0x190300, ft_PyHash_GetFuncDef },
    { "PyList_Sort", 0x190310, ft_PyList_Sort },
    { "_PyNamespace_New", 0x1903e0, ft__PyNamespace_New },
    { "PyDict_Update", 0x1904c0, ft_PyDict_Update },
    { "PyThread_GetInfo", 0x1907cc, ft_PyThread_GetInfo },
    { "_PyImport_FixupBuiltin", 0x190940, ft__PyImport_FixupBuiltin },
    { "PyModule_GetDef", 0x190ccc, ft_PyModule_GetDef },
    { "PyList_SetItem", 0x190da0, ft_PyList_SetItem },
    { "PyDict_GetItem", 0x190fa8, ft_PyDict_GetItem },
    { "_Py_GetConfig", 0x1915a0, ft__Py_GetConfig },
    { "_PyObject_NewVar", 0x1915ec, ft__PyObject_NewVar },
    { "PyErr_NewException", 0x191650, ft_PyErr_NewException },
    { "_PyObject_FastCall", 0x192928, ft__PyObject_FastCall },
    { "PyObject_VectorcallDict", 0x192f90, ft_PyObject_VectorcallDict },
    { "_Py_fstat_noraise", 0x193100, ft__Py_fstat_noraise },
    { "Py_CompileStringExFlags", 0x193104, ft_Py_CompileStringExFlags },
    { "PyUnicode_DecodeFSDefault", 0x1931a0, ft_PyUnicode_DecodeFSDefault },
    { "PyUnicode_DecodeFSDefaultAndSize", 0x1931c8, ft_PyUnicode_DecodeFSDefaultAndSize },
    { "Py_CompileStringObject", 0x1939e8, ft_Py_CompileStringObject },
    { "_PyArena_New", 0x193da0, ft__PyArena_New },
    { "PyImport_ImportFrozenModule", 0x1941a0, ft_PyImport_ImportFrozenModule },
    { "PyUnicode_AsUTF8", 0x1947a0, ft_PyUnicode_AsUTF8 },
    { "_PyCode_Validate", 0x196288, ft__PyCode_Validate },
    { "PyEval_EvalCode", 0x1964c0, ft_PyEval_EvalCode },
    { "PyUnicode_DecodeUTF8Stateful", 0x197268, ft_PyUnicode_DecodeUTF8Stateful },
    { "_PyDict_GetItemWithError", 0x1977e4, ft__PyDict_GetItemWithError },
    { "PyMapping_Check", 0x197f40, ft_PyMapping_Check },
    { "PyDict_DelItem", 0x197f6c, ft_PyDict_DelItem },
    { "_PyDict_DelItem_KnownHash", 0x197fe0, ft__PyDict_DelItem_KnownHash },
    { "PyObject_Type", 0x19878c, ft_PyObject_Type },
    { "_PyToken_ThreeChars", 0x19d120, ft__PyToken_ThreeChars },
    { "PyImport_AddModule", 0x1a1c00, ft_PyImport_AddModule },
    { "PyImport_AddModuleObject", 0x1a1d48, ft_PyImport_AddModuleObject },
    { "PyWeakref_GetObject", 0x1a1dec, ft_PyWeakref_GetObject },
    { "PyInit__imp", 0x1a29a0, ft_PyInit__imp },
    { "PyModule_FromDefAndSpec2", 0x1a2a20, ft_PyModule_FromDefAndSpec2 },
    { "PyModule_ExecDef", 0x1a2e60, ft_PyModule_ExecDef },
    { "PyModule_GetName", 0x1a2fa0, ft_PyModule_GetName },
    { "PyModule_AddObjectRef", 0x1a3300, ft_PyModule_AddObjectRef },
    { "_PyImport_SetModuleString", 0x1a33d0, ft__PyImport_SetModuleString },
    { "PyMapping_SetItemString", 0x1a340c, ft_PyMapping_SetItemString },
    { "_PyDictView_New", 0x1a3d00, ft__PyDictView_New },
    { "_PyBytes_DecodeEscape2", 0x1a42a0, ft__PyBytes_DecodeEscape2 },
    { "PyBytes_FromString", 0x1a4b90, ft_PyBytes_FromString },
    { "_PyStack_AsDict", 0x1a6ed0, ft__PyStack_AsDict },
    { "_PyDict_Pop", 0x1a9724, ft__PyDict_Pop },
    { "PyArg_ValidateKeywordArguments", 0x1aa424, ft_PyArg_ValidateKeywordArguments },
    { "_PyDict_HasOnlyStringKeys", 0x1aa488, ft__PyDict_HasOnlyStringKeys },
    { "PyModule_AddType", 0x1ab080, ft_PyModule_AddType },
    { "_PyType_Name", 0x1ab164, ft__PyType_Name },
    { "PyType_FromModuleAndSpec", 0x1ab1a0, ft_PyType_FromModuleAndSpec },
    { "PyStructSequence_NewType", 0x1ab22c, ft_PyStructSequence_NewType },
    { "_PyStructSequence_NewType", 0x1ab240, ft__PyStructSequence_NewType },
    { "PyType_FromSpecWithBases", 0x1ab408, ft_PyType_FromSpecWithBases },
    { "_PyModule_Add", 0x1ab4d0, ft__PyModule_Add },
    { "_PyWarnings_Init", 0x1ab800, ft__PyWarnings_Init },
    { "PyInit__weakref", 0x1abd60, ft_PyInit__weakref },
    { "PyModule_AddObject", 0x1abf4c, ft_PyModule_AddObject },
    { "PyList_SetSlice", 0x1ac20c, ft_PyList_SetSlice },
    { "PyUnicode_IsIdentifier", 0x1ac3a0, ft_PyUnicode_IsIdentifier },
    { "_PyUnicode_ScanIdentifier", 0x1ac3d0, ft__PyUnicode_ScanIdentifier },
    { "_PyUnicode_IsXidStart", 0x1ac48c, ft__PyUnicode_IsXidStart },
    { "_PyUnicode_IsXidContinue", 0x1ac4a8, ft__PyUnicode_IsXidContinue },
    { "_PyConfig_AsDict", 0x1add60, ft__PyConfig_AsDict },
    { "_PyWideStringList_AsList", 0x1af424, ft__PyWideStringList_AsList },
    { "PySymtable_Lookup", 0x1afb84, ft_PySymtable_Lookup },
    { "_PyLong_NumBits", 0x1affa0, ft__PyLong_NumBits },
    { "PyList_Size", 0x1b0088, ft_PyList_Size },
    { "PyLong_AsSize_t", 0x1b00c0, ft_PyLong_AsSize_t },
    { "PyDict_Keys", 0x1b01a4, ft_PyDict_Keys },
    { "_Py_wfopen", 0x1b2080, ft__Py_wfopen },
    { "PyFrozenSet_New", 0x1b2528, ft_PyFrozenSet_New },
    { "PyErr_SetFromErrno", 0x1b2720, ft_PyErr_SetFromErrno },
    { "PyErr_SetFromErrnoWithFilenameObjects", 0x1b2740, ft_PyErr_SetFromErrnoWithFilenameObjects },
    { "PyUnicode_DecodeLocale", 0x1b28d0, ft_PyUnicode_DecodeLocale },
    { "PyException_GetContext", 0x1b3890, ft_PyException_GetContext },
    { "PyNumber_Invert", 0x1b38b0, ft_PyNumber_Invert },
    { "_Py_wreadlink", 0x1b4f44, ft__Py_wreadlink },
    { "PyNumber_InPlaceAdd", 0x1b50a0, ft_PyNumber_InPlaceAdd },
    { "PyCapsule_New", 0x1b52c0, ft_PyCapsule_New },
    { "_Py_DecodeUTF8_surrogateescape", 0x1b5668, ft__Py_DecodeUTF8_surrogateescape },
    { "PyCapsule_GetPointer", 0x1b6a4c, ft_PyCapsule_GetPointer },
    { "PySet_Size", 0x1b6b10, ft_PySet_Size },
    { "_PyTime_FromMicrosecondsClamp", 0x1bde28, ft__PyTime_FromMicrosecondsClamp },
    { "_PyErr_SetKeyError", 0x1bdee0, ft__PyErr_SetKeyError },
    { "_PyImport_ReleaseLock", 0x1be1c0, ft__PyImport_ReleaseLock },
    { "PyWrapper_New", 0x1be364, ft_PyWrapper_New },
    { "_PyTime_FromSeconds", 0x1be960, ft__PyTime_FromSeconds },
    { "PySequence_DelItem", 0x1bf2a0, ft_PySequence_DelItem },
    { "_PyArena_Free", 0x1c12ac, ft__PyArena_Free },
    { "PyInit__io", 0x1c1300, ft_PyInit__io },
    { "PyDict_Clear", 0x1c17e0, ft_PyDict_Clear },
    { "PyModule_AddIntConstant", 0x1c1904, ft_PyModule_AddIntConstant },
    { "_Py_hashtable_hash_ptr", 0x1c1b40, ft__Py_hashtable_hash_ptr },
    { "PyThread_free_lock", 0x1c208c, ft_PyThread_free_lock },
    { "PyMarshal_Init", 0x1c2150, ft_PyMarshal_Init },
    { "PyInit_posix", 0x1c2184, ft_PyInit_posix },
    { "Py_Finalize", 0x1c3560, ft_Py_Finalize },
    { "Py_FinalizeEx", 0x1c3564, ft_Py_FinalizeEx },
    { "_PyObject_GC_Resize", 0x1c39b0, ft__PyObject_GC_Resize },
    { "PyList_GetItem", 0x1c4a00, ft_PyList_GetItem },
    { "PyObject_Bytes", 0x1c53c0, ft_PyObject_Bytes },
    { "_PyImport_GetModuleAttrString", 0x1c5aa0, ft__PyImport_GetModuleAttrString },
    { "_PyImport_GetModuleAttr", 0x1c5b60, ft__PyImport_GetModuleAttr },
    { "PyImport_ImportModuleLevel", 0x1c5bc0, ft_PyImport_ImportModuleLevel },
    { "PyInit_time", 0x1c6000, ft_PyInit_time },
    { "_PyTime_localtime", 0x1c63c8, ft__PyTime_localtime },
    { "PyList_Insert", 0x1c65a8, ft_PyList_Insert },
    { "_PyBytesWriter_Resize", 0x1c6c40, ft__PyBytesWriter_Resize },
    { "PyInit_faulthandler", 0x1c6fc0, ft_PyInit_faulthandler },
    { "_Py_EncodeUTF8Ex", 0x1c6fd0, ft__Py_EncodeUTF8Ex },
    { "PyObject_CallNoArgs", 0x1c7228, ft_PyObject_CallNoArgs },
    { "_PyCodec_Lookup", 0x1c7344, ft__PyCodec_Lookup },
    { "PyCodec_RegisterError", 0x1c7960, ft_PyCodec_RegisterError },
    { "PyImport_ImportModule", 0x1c7c60, ft_PyImport_ImportModule },
    { "PyUnicode_EncodeFSDefault", 0x1c85e0, ft_PyUnicode_EncodeFSDefault },
    { "PyThreadState_GetInterpreter", 0x1c8680, ft_PyThreadState_GetInterpreter },
    { "_Py_EncodeLocaleEx", 0x1c8820, ft__Py_EncodeLocaleEx },
    { "PyEval_SaveThread", 0x1c8ae8, ft_PyEval_SaveThread },
    { "_PySet_NextEntry", 0x1c8b60, ft__PySet_NextEntry },
    { "PyEval_RestoreThread", 0x1c8c40, ft_PyEval_RestoreThread },
    { "PyErr_SetFromErrnoWithFilenameObject", 0x1c8ce0, ft_PyErr_SetFromErrnoWithFilenameObject },
    { "_PyLong_FromUid", 0x1c8fd0, ft__PyLong_FromUid },
    { "_PyUnicode_EQ", 0x1c9ee0, ft__PyUnicode_EQ },
    { "PyFile_OpenCodeObject", 0x1ca540, ft_PyFile_OpenCodeObject },
    { "PyNumber_Check", 0x1cb0b0, ft_PyNumber_Check },
    { "PyUnicode_FSConverter", 0x1cb820, ft_PyUnicode_FSConverter },
    { "_Py_read", 0x1ccfec, ft__Py_read },
    { "_Py_SourceAsString", 0x1d22e0, ft__Py_SourceAsString },
    { "PyInit__codecs", 0x1d2690, ft_PyInit__codecs },
    { "PyMapping_Keys", 0x1d2d70, ft_PyMapping_Keys },
    { "PyErr_SetObject", 0x1d2ec0, ft_PyErr_SetObject },
    { "_PyErr_Clear", 0x1d2f00, ft__PyErr_Clear },
    { "PyCodec_LookupError", 0x1d3208, ft_PyCodec_LookupError },
    { "PyCodec_Register", 0x1d32e0, ft_PyCodec_Register },
    { "PyInit__abc", 0x1d3680, ft_PyInit__abc },
    { "PyOS_setsig", 0x1d3690, ft_PyOS_setsig },
    { "PyOS_getsig", 0x1d3dc8, ft_PyOS_getsig },
    { "PyDictProxy_New", 0x1d4468, ft_PyDictProxy_New },
    { "PyMapping_Items", 0x1d4560, ft_PyMapping_Items },
    { "_PyObject_IsAbstract", 0x1d47c8, ft__PyObject_IsAbstract },
    { "PyImport_GetModule", 0x1d5800, ft_PyImport_GetModule },
    { "PyModule_GetFilenameObject", 0x1d58a8, ft_PyModule_GetFilenameObject },
    { "PyErr_SetString", 0x1d5940, ft_PyErr_SetString },
    { "_PyErr_SetString", 0x1d5980, ft__PyErr_SetString },
    { "_Py_IsValidFD", 0x1d6020, ft__Py_IsValidFD },
    { "_PyCodec_LookupTextEncoding", 0x1d6a40, ft__PyCodec_LookupTextEncoding },
    { "_PyCodecInfo_GetIncrementalDecoder", 0x1d6f20, ft__PyCodecInfo_GetIncrementalDecoder },
    { "PySys_SetObject", 0x1d742c, ft_PySys_SetObject },
    { "_PyCodecInfo_GetIncrementalEncoder", 0x1d79e8, ft__PyCodecInfo_GetIncrementalEncoder },
    { "_Py_ClearStandardStreamEncoding", 0x1d7ac0, ft__Py_ClearStandardStreamEncoding },
    { "Py_GenericAlias", 0x1d8300, ft_Py_GenericAlias },
    { "PyVectorcall_Function", 0x1d8420, ft_PyVectorcall_Function },
    { "_PyInterpreterState_SetRunningMain", 0x1d9b88, ft__PyInterpreterState_SetRunningMain },
    { "_PyType_GetDocFromInternalDoc", 0x1daee4, ft__PyType_GetDocFromInternalDoc },
    { "PyObject_Dir", 0x1db1b0, ft_PyObject_Dir },
    { "PyException_SetCause", 0x1dbc8c, ft_PyException_SetCause },
    { "_PyUnicode_FindMaxChar", 0x1dbe60, ft__PyUnicode_FindMaxChar },
    { "PyFrame_GetCode", 0x1dc120, ft_PyFrame_GetCode },
    { "_Py_wrealpath", 0x1dd124, ft__Py_wrealpath },
    { "_Py_fopen_obj", 0x1dd228, ft__Py_fopen_obj },
    { "Py_MakePendingCalls", 0x1dd400, ft_Py_MakePendingCalls },
    { "_PyEval_MakePendingCalls", 0x1dd46c, ft__PyEval_MakePendingCalls },
    { "PyUnicode_AsUTF8String", 0x1dd680, ft_PyUnicode_AsUTF8String },
    { "PyRun_SimpleStringFlags", 0x1dd960, ft_PyRun_SimpleStringFlags },
    { "_PyRun_AnyFileObject", 0x1dda00, ft__PyRun_AnyFileObject },
    { "PyRun_StringFlags", 0x1ddb00, ft_PyRun_StringFlags },
    { "_Py_FdIsInteractive", 0x1ddbac, ft__Py_FdIsInteractive },
    { "_PyRun_SimpleFileObject", 0x1ddc20, ft__PyRun_SimpleFileObject },
    { "PyUnicode_Tailmatch", 0x1de1e0, ft_PyUnicode_Tailmatch },
    { "PyImport_GetMagicNumber", 0x1de260, ft_PyImport_GetMagicNumber },
    { "_PyWeakref_ClearRef", 0x1ded20, ft__PyWeakref_ClearRef },
    { "PyDict_Size", 0x1df090, ft_PyDict_Size },
    { "_Py_UniversalNewlineFgetsWithSize", 0x1df280, ft__Py_UniversalNewlineFgetsWithSize },
    { "PyInit_itertools", 0x1df380, ft_PyInit_itertools },
    { "PyInit__operator", 0x1df390, ft_PyInit__operator },
    { "PyType_FromMetaclass", 0x1dfb60, ft_PyType_FromMetaclass },
    { "PyEval_MergeCompilerFlags", 0x1e0620, ft_PyEval_MergeCompilerFlags },
    { "PyErr_WarnExplicitObject", 0x1e15c8, ft_PyErr_WarnExplicitObject },
    { "PyUnicode_GetLength", 0x1e2680, ft_PyUnicode_GetLength },
    { "_PySys_GetOptionalAttr", 0x1e3100, ft__PySys_GetOptionalAttr },
    { "PyFile_WriteObject", 0x1e31c0, ft_PyFile_WriteObject },
    { "_PyUnicode_AsUTF8String", 0x1e332c, ft__PyUnicode_AsUTF8String },
    { "PyFile_WriteString", 0x1e3340, ft_PyFile_WriteString },
    { "_Py_write", 0x1e4200, ft__Py_write },
    { "PyObject_AsFileDescriptor", 0x1e42c0, ft_PyObject_AsFileDescriptor },
    { "_Py_dup", 0x1e46c0, ft__Py_dup },
    { "PyLong_AsUnsignedLongLongMask", 0x1e59c0, ft_PyLong_AsUnsignedLongLongMask },
    { "_PyErr_ProgramDecodedTextObject", 0x1e5ba0, ft__PyErr_ProgramDecodedTextObject },
    { "PyErr_Fetch", 0x1e6824, ft_PyErr_Fetch },
    { "_PyErr_Fetch", 0x1e6860, ft__PyErr_Fetch },
    { "PyErr_Restore", 0x1e68c0, ft_PyErr_Restore },
    { "PyByteArray_Resize", 0x1e6c20, ft_PyByteArray_Resize },
    { "_Py_WriteIndentedMargin", 0x1e7c40, ft__Py_WriteIndentedMargin },
    { "_Py_WriteIndent", 0x1e7d30, ft__Py_WriteIndent },
    { "PyDict_DelItemString", 0x1e9304, ft_PyDict_DelItemString },
    { "_PyInterpreterState_SetNotRunningMain", 0x1e9368, ft__PyInterpreterState_SetNotRunningMain },
    { "_PyThreadState_DeleteExcept", 0x1e9908, ft__PyThreadState_DeleteExcept },
    { "PyGC_Collect", 0x1e9c0c, ft_PyGC_Collect },
    { "Py_Exit", 0x1eaec4, ft_Py_Exit },
    { "_PyModule_Clear", 0x1eb350, ft__PyModule_Clear },
    { "_PyModule_ClearDict", 0x1eb360, ft__PyModule_ClearDict },
    { "_PyTraceMalloc_Stop", 0x1ebbe8, ft__PyTraceMalloc_Stop },
    { "PyThreadState_Clear", 0x1ef260, ft_PyThreadState_Clear },
    { "_PyObject_ClearManagedDict", 0x1ef630, ft__PyObject_ClearManagedDict },
    { "_PyInterpreterState_HasFeature", 0x1f4180, ft__PyInterpreterState_HasFeature },
    { "PyImport_GetModuleDict", 0x1f4390, ft_PyImport_GetModuleDict },
    { "_PyImport_FixupExtensionObject", 0x1f46a4, ft__PyImport_FixupExtensionObject },
    { "PyNumber_Power", 0x1f5d40, ft_PyNumber_Power },
    { "PyThread_tss_delete", 0x1f5fa0, ft_PyThread_tss_delete },
    { "PyInterpreterState_Delete", 0x1f61c8, ft_PyInterpreterState_Delete },
    { "PyInit__sre", 0x1f684c, ft_PyInit__sre },
    { "PyModule_AddStringConstant", 0x1f6a80, ft_PyModule_AddStringConstant },
    { "_PyRuntimeState_Fini", 0x1f6c24, ft__PyRuntimeState_Fini },
    { "PySlice_New", 0x1f6d44, ft_PySlice_New },
    { "_PyPathConfig_ClearGlobal", 0x1f6f60, ft__PyPathConfig_ClearGlobal },
    { "_Py_ClearArgcArgv", 0x1f7040, ft__Py_ClearArgcArgv },
    { "_PyRuntime_Finalize", 0x1f70c0, ft__PyRuntime_Finalize },
    { "PyNumber_InPlaceAnd", 0x1f72c0, ft_PyNumber_InPlaceAnd },
    { "PyInit__tokenize", 0x1f9080, ft_PyInit__tokenize },
    { "PyUnicode_AsASCIIString", 0x1f98a0, ft_PyUnicode_AsASCIIString },
    { "_PyObject_RealIsInstance", 0x1f98a8, ft__PyObject_RealIsInstance },
    { "_PyBytesWriter_Dealloc", 0x1fa1e0, ft__PyBytesWriter_Dealloc },
    { "PyErr_WriteUnraisable", 0x1fa20c, ft_PyErr_WriteUnraisable },
    { "_PyErr_WriteUnraisableMsg", 0x1fa220, ft__PyErr_WriteUnraisableMsg },
    { "PySeqIter_New", 0x1fa944, ft_PySeqIter_New },
    { "PyNumber_Xor", 0x1fbdc8, ft_PyNumber_Xor },
    { "PyNumber_InPlaceXor", 0x1fc0c8, ft_PyNumber_InPlaceXor },
    { "_PyGen_FetchStopIterationValue", 0x1fc170, ft__PyGen_FetchStopIterationValue },
    { "_PyUnicode_FormatAdvancedWriter", 0x1fc3ec, ft__PyUnicode_FormatAdvancedWriter },
    { "PyByteArray_FromStringAndSize", 0x1fc8e0, ft_PyByteArray_FromStringAndSize },
    { "PyUnicode_Partition", 0x1fca24, ft_PyUnicode_Partition },
    { "_PyLong_FromBytes", 0x1fce40, ft__PyLong_FromBytes },
    { "PySequence_Size", 0x1fd1e8, ft_PySequence_Size },
    { "PyClassMethod_New", 0x1fe028, ft_PyClassMethod_New },
    { "PyLong_FromUnicodeObject", 0x1fe06c, ft_PyLong_FromUnicodeObject },
    { "_Py_string_to_number_with_underscores", 0x1fe810, ft__Py_string_to_number_with_underscores },
    { "_PySet_Update", 0x1ffce0, ft__PySet_Update },
    { "PySequence_GetSlice", 0x200220, ft_PySequence_GetSlice },
    { "_PySlice_FromIndices", 0x2002ec, ft__PySlice_FromIndices },
    { "PyInit__locale", 0x201700, ft_PyInit__locale },
    { "_PyDict_SetItem_KnownHash", 0x202dc0, ft__PyDict_SetItem_KnownHash },
    { "PyInit_errno", 0x203380, ft_PyInit_errno },
    { "PyUnicode_CopyCharacters", 0x20736c, ft_PyUnicode_CopyCharacters },
    { "_Py_IsInterpreterFinalizing", 0x2076a0, ft__Py_IsInterpreterFinalizing },
    { "PyBytes_FromObject", 0x2078e0, ft_PyBytes_FromObject },
    { "PyOS_mystrnicmp", 0x208a28, ft_PyOS_mystrnicmp },
    { "PyGILState_Ensure", 0x208c80, ft_PyGILState_Ensure },
    { "PyObject_CallObject", 0x208e6c, ft_PyObject_CallObject },
    { "_PyDict_Contains_KnownHash", 0x20afe8, ft__PyDict_Contains_KnownHash },
    { "PyErr_NewExceptionWithDoc", 0x20b164, ft_PyErr_NewExceptionWithDoc },
    { "PyGILState_Release", 0x20b604, ft_PyGILState_Release },
    { "PyThreadState_GetDict", 0x215100, ft_PyThreadState_GetDict },
    { "_PyThreadState_GetDict", 0x21530c, ft__PyThreadState_GetDict },
    { "_Py_GetLocaleEncodingObject", 0x21720c, ft__Py_GetLocaleEncodingObject },
    { "_PyUnicode_ToLowercase", 0x21a820, ft__PyUnicode_ToLowercase },
    { "_PyUnicode_IsLowercase", 0x21d0e8, ft__PyUnicode_IsLowercase },
    { "_PyUnicode_IsTitlecase", 0x21d104, ft__PyUnicode_IsTitlecase },
    { "PyUnicode_Splitlines", 0x21d800, ft_PyUnicode_Splitlines },
    { "PyUnicodeDecodeError_Create", 0x21e488, ft_PyUnicodeDecodeError_Create },
    { "PyCodec_StrictErrors", 0x21e720, ft_PyCodec_StrictErrors },
    { "_PyErr_GetTopmostException", 0x21eda0, ft__PyErr_GetTopmostException },
    { "PyList_Reverse", 0x220364, ft_PyList_Reverse },
    { "Py_GetRecursionLimit", 0x220880, ft_Py_GetRecursionLimit },
    { "_PyLong_FromDigits", 0x221360, ft__PyLong_FromDigits },
    { "PyODict_SetItem", 0x2216cc, ft_PyODict_SetItem },
    { "_PyTime_GetPerfCounterWithInfo", 0x223508, ft__PyTime_GetPerfCounterWithInfo },
    { "PyCapsule_Import", 0x2236a0, ft_PyCapsule_Import },
    { "PyOS_double_to_string", 0x225020, ft_PyOS_double_to_string },
    { "_PyImport_SetModule", 0x225624, ft__PyImport_SetModule },
    { "_PyUnicode_FormatLong", 0x225760, ft__PyUnicode_FormatLong },
    { "_PyEval_GetBuiltin", 0x225b60, ft__PyEval_GetBuiltin },
    { "PyNumber_ToBase", 0x225bf0, ft_PyNumber_ToBase },
    { "_PyUnicode_FastFill", 0x225f00, ft__PyUnicode_FastFill },
    { "_PyMem_Strdup", 0x2264c0, ft__PyMem_Strdup },
    { "PyThread_start_new_thread", 0x2267e0, ft_PyThread_start_new_thread },
    { "PyErr_WarnEx", 0x226a20, ft_PyErr_WarnEx },
    { "_PyDeadline_Init", 0x226be4, ft__PyDeadline_Init },
    { "_PyTime_GetMonotonicClock", 0x227088, ft__PyTime_GetMonotonicClock },
    { "_PyTime_GetSystemClock", 0x227108, ft__PyTime_GetSystemClock },
    { "PyThreadState_GetFrame", 0x227188, ft_PyThreadState_GetFrame },
    { "_PyTime_Add", 0x2271e0, ft__PyTime_Add },
    { "_PyTime_AsTimespec_clamp", 0x227200, ft__PyTime_AsTimespec_clamp },
    { "PyFrame_GetBack", 0x227330, ft_PyFrame_GetBack },
    { "PyFrame_GetLineNumber", 0x2273a0, ft_PyFrame_GetLineNumber },
    { "PyUnstable_InterpreterFrame_GetLine", 0x2273c0, ft_PyUnstable_InterpreterFrame_GetLine },
    { "PyLong_AsUnsignedLongLong", 0x2283d0, ft_PyLong_AsUnsignedLongLong },
    { "PyLong_AsLongLong", 0x2284c0, ft_PyLong_AsLongLong },
    { "_PyCodec_EncodeText", 0x228b60, ft__PyCodec_EncodeText },
    { "_PyUnicode_EncodeUTF16", 0x228fc0, ft__PyUnicode_EncodeUTF16 },
    { "PyUnicode_DecodeUTF16Stateful", 0x229620, ft_PyUnicode_DecodeUTF16Stateful },
    { "PyErr_BadArgument", 0x22aba0, ft_PyErr_BadArgument },
    { "PyNumber_InPlaceMultiply", 0x22aec0, ft_PyNumber_InPlaceMultiply },
    { "_PyObject_FunctionStr", 0x22b084, ft__PyObject_FunctionStr },
    { "PyInterpreterState_ThreadHead", 0x22baa0, ft_PyInterpreterState_ThreadHead },
    { "PyThreadState_Next", 0x22baa8, ft_PyThreadState_Next },
    { "_PyEval_SliceIndexNotNone", 0x22bab0, ft__PyEval_SliceIndexNotNone },
    { "PyUnicode_Split", 0x22c930, ft_PyUnicode_Split },
    { "PyUnicode_DecodeRawUnicodeEscape", 0x22c9a4, ft_PyUnicode_DecodeRawUnicodeEscape },
    { "_PySys_GetSizeOf", 0x22d18c, ft__PySys_GetSizeOf },
    { "PyWeakref_NewProxy", 0x22d370, ft_PyWeakref_NewProxy },
    { "PyErr_NoMemory", 0x22d780, ft_PyErr_NoMemory },
    { "_PyErr_NoMemory", 0x22d7a8, ft__PyErr_NoMemory },
    { "_Py_strhex_bytes_with_sep", 0x22f264, ft__Py_strhex_bytes_with_sep },
    { "_PySequence_BytesToCharpArray", 0x232060, ft__PySequence_BytesToCharpArray },
    { "_Py_RestoreSignals", 0x232220, ft__Py_RestoreSignals },
    { "_Py_open_noraise", 0x232244, ft__Py_open_noraise },
    { "_Py_FreeCharPArray", 0x2322a0, ft__Py_FreeCharPArray },
    { "_PyLong_FileDescriptor_Converter", 0x232a84, ft__PyLong_FileDescriptor_Converter },
    { "PyLong_AsUnsignedLongMask", 0x232da8, ft_PyLong_AsUnsignedLongMask },
    { "_Py_strhex_with_sep", 0x233050, ft__Py_strhex_with_sep },
    { "Py_EnterRecursiveCall", 0x234580, ft_Py_EnterRecursiveCall },
    { "_PyObject_GetState", 0x23a1c0, ft__PyObject_GetState },
    { "_PyBytes_FromHex", 0x23aa28, ft__PyBytes_FromHex },
    { "_PyArg_BadArgument", 0x23b310, ft__PyArg_BadArgument },
    { "PyNumber_InPlaceRemainder", 0x23b980, ft_PyNumber_InPlaceRemainder },
    { "_PyBytes_FormatEx", 0x23ba00, ft__PyBytes_FormatEx },
    { "_PyLong_FormatBytesWriter", 0x23cb24, ft__PyLong_FormatBytesWriter },
    { "PyCodec_Encode", 0x23d080, ft_PyCodec_Encode },
    { "PySequence_SetItem", 0x23d38c, ft_PySequence_SetItem },
    { "_PyUnicode_EncodeCharmap", 0x23f680, ft__PyUnicode_EncodeCharmap },
    { "PyLong_AsVoidPtr", 0x23fec0, ft_PyLong_AsVoidPtr },
    { "PyBytes_FromFormatV", 0x23ffc0, ft_PyBytes_FromFormatV },
    { "_PyArg_NoPositional", 0x240d80, ft__PyArg_NoPositional },
    { "_PyThreadState_DeleteCurrent", 0x242c80, ft__PyThreadState_DeleteCurrent },
    { "PyComplex_FromDoubles", 0x245600, ft_PyComplex_FromDoubles },
    { "PyNumber_InPlaceFloorDivide", 0x245604, ft_PyNumber_InPlaceFloorDivide },
    { "_PyType_GetTextSignatureFromInternalDoc", 0x245920, ft__PyType_GetTextSignatureFromInternalDoc },
    { "PyCodec_BackslashReplaceErrors", 0x247528, ft_PyCodec_BackslashReplaceErrors },
    { "PyUnicodeDecodeError_GetStart", 0x2479e0, ft_PyUnicodeDecodeError_GetStart },
    { "PyUnicodeDecodeError_GetEnd", 0x247ae0, ft_PyUnicodeDecodeError_GetEnd },
    { "PyUnicodeDecodeError_GetObject", 0x247b50, ft_PyUnicodeDecodeError_GetObject },
    { "PyUnicodeEncodeError_SetStart", 0x247b60, ft_PyUnicodeEncodeError_SetStart },
    { "PyUnicodeDecodeError_SetStart", 0x247b70, ft_PyUnicodeDecodeError_SetStart },
    { "PyUnicodeEncodeError_SetEnd", 0x247b80, ft_PyUnicodeEncodeError_SetEnd },
    { "PyUnicodeDecodeError_SetEnd", 0x247b90, ft_PyUnicodeDecodeError_SetEnd },
    { "PyUnicodeEncodeError_SetReason", 0x247ba0, ft_PyUnicodeEncodeError_SetReason },
    { "PyUnicodeDecodeError_SetReason", 0x247ba8, ft_PyUnicodeDecodeError_SetReason },
    { "PyUnicodeEncodeError_GetStart", 0x248268, ft_PyUnicodeEncodeError_GetStart },
    { "PyUnicodeEncodeError_GetEnd", 0x248364, ft_PyUnicodeEncodeError_GetEnd },
    { "PyType_GetModuleState", 0x249f00, ft_PyType_GetModuleState },
    { "PyUnicode_DecodeCharmap", 0x249f20, ft_PyUnicode_DecodeCharmap },
    { "PyUnicode_AsRawUnicodeEscapeString", 0x24a7e0, ft_PyUnicode_AsRawUnicodeEscapeString },
    { "PyCodec_IncrementalEncoder", 0x24adc0, ft_PyCodec_IncrementalEncoder },
    { "PyCodec_IncrementalDecoder", 0x24ae40, ft_PyCodec_IncrementalDecoder },
    { "PyCodec_ReplaceErrors", 0x24bae8, ft_PyCodec_ReplaceErrors },
    { "PyCodec_IgnoreErrors", 0x24bd0c, ft_PyCodec_IgnoreErrors },
    { "PyCodec_Unregister", 0x24be48, ft_PyCodec_Unregister },
    { "PyBytes_DecodeEscape", 0x24d0a0, ft_PyBytes_DecodeEscape },
    { "_PyUnicode_ToLowerFull", 0x24da24, ft__PyUnicode_ToLowerFull },
    { "PyUnicodeEncodeError_GetEncoding", 0x24e1e0, ft_PyUnicodeEncodeError_GetEncoding },
    { "PyUnicodeDecodeError_GetEncoding", 0x24e1f0, ft_PyUnicodeDecodeError_GetEncoding },
    { "PyCodec_NameReplaceErrors", 0x24eaa8, ft_PyCodec_NameReplaceErrors },
    { "PyDict_Items", 0x2500c0, ft_PyDict_Items },
    { "_PyGen_SetStopIterationValue", 0x252128, ft__PyGen_SetStopIterationValue },
    { "_PyTime_gmtime", 0x2592e0, ft__PyTime_gmtime },
    { "PyUnicode_Fill", 0x259760, ft_PyUnicode_Fill },
    { "_PyTime_AsTimespec", 0x259a00, ft__PyTime_AsTimespec },
    { "_PyLong_DivmodNear", 0x259f24, ft__PyLong_DivmodNear },
    { "_PyTime_AsTimevalTime_t", 0x25a18c, ft__PyTime_AsTimevalTime_t },
    { "PyUnicode_AsLatin1String", 0x25a24c, ft_PyUnicode_AsLatin1String },
    { "_PyUnicode_Copy", 0x25a260, ft__PyUnicode_Copy },
    { "PyUnicode_WriteChar", 0x25a380, ft_PyUnicode_WriteChar },
    { "_Py_GetLocaleconvNumeric", 0x25bb28, ft__Py_GetLocaleconvNumeric },
    { "PyObject_ASCII", 0x25bc90, ft_PyObject_ASCII },
    { "_PyEval_SetSwitchInterval", 0x26be70, ft__PyEval_SetSwitchInterval },
    { "_PyObject_GetDictPtr", 0x26becc, ft__PyObject_GetDictPtr },
    { "PyDict_Merge", 0x26bf44, ft_PyDict_Merge },
    { "_Py_strhex", 0x26d3ac, ft__Py_strhex },
    { "_PyLong_UnsignedLong_Converter", 0x26d3c0, ft__PyLong_UnsignedLong_Converter },
    { "_PyLong_UnsignedLongLong_Converter", 0x26d440, ft__PyLong_UnsignedLongLong_Converter },
    { "_PyTime_FromTimespec", 0x26dbc0, ft__PyTime_FromTimespec },
    { "PyThreadState_Swap", 0x26de88, ft_PyThreadState_Swap },
    { "_PyThreadState_Swap", 0x26dea0, ft__PyThreadState_Swap },
    { "PyCFunction_GetFunction", 0x272b20, ft_PyCFunction_GetFunction },
    { "_PyLong_Lshift", 0x273880, ft__PyLong_Lshift },
    { "_PySequence_IterSearch", 0x276a88, ft__PySequence_IterSearch },
    { "PySequence_Count", 0x276e44, ft_PySequence_Count },
    { "PySequence_Index", 0x276ec0, ft_PySequence_Index },
    { "PyNumber_MatrixMultiply", 0x276f20, ft_PyNumber_MatrixMultiply },
    { "PyObject_Not", 0x276fa0, ft_PyObject_Not },
    { "_PyDict_SizeOf", 0x277dc4, ft__PyDict_SizeOf },
    { "PyEval_GetFrame", 0x279ea0, ft_PyEval_GetFrame },
    { "PyFrame_LocalsToFast", 0x27a144, ft_PyFrame_LocalsToFast },
    { "_PyUnicode_ToUpperFull", 0x27cd40, ft__PyUnicode_ToUpperFull },
    { "_PyUnicode_ToTitleFull", 0x27e2e0, ft__PyUnicode_ToTitleFull },
    { "_PyTime_FromNanosecondsObject", 0x27e524, ft__PyTime_FromNanosecondsObject },
    { "_PyTime_AsNanosecondsObject", 0x27e5c0, ft__PyTime_AsNanosecondsObject },
    { "_PyTime_AsTimeval", 0x27e5c4, ft__PyTime_AsTimeval },
    { "_PyUnicode_IsCaseIgnorable", 0x27f190, ft__PyUnicode_IsCaseIgnorable },
    { "_PyUnicode_IsCased", 0x27f1ac, ft__PyUnicode_IsCased },
    { "PyUnicodeTranslateError_SetStart", 0x2807a0, ft_PyUnicodeTranslateError_SetStart },
    { "PyUnicodeTranslateError_SetEnd", 0x2807b0, ft_PyUnicodeTranslateError_SetEnd },
    { "_PyTime_AsNanoseconds", 0x2808c4, ft__PyTime_AsNanoseconds },
    { "PyUnicodeTranslateError_SetReason", 0x2808c8, ft_PyUnicodeTranslateError_SetReason },
    { "_PyThreadState_Prealloc", 0x280a40, ft__PyThreadState_Prealloc },
    { "_PyTime_GetPerfCounter", 0x280a44, ft__PyTime_GetPerfCounter },
    { "_fini", 0x281874, ft__fini },
};
/* Functions that must NOT be offloaded regardless of translation correctness:
 * the allocator family is called by the iSH core itself while holding the
 * asbestos lock; offloading re-enters the JIT → deadlock. Architectural, not a
 * translation bug (see PYYAML_OPTIMIZATION.md). Extend as bisect finds more. */
#include <string.h>
static int ft_blacklisted(const char *n) {
    static const char *bl[] = {
        "PyMem_RawMalloc","PyMem_RawCalloc","PyMem_RawRealloc","PyMem_RawFree",
        "PyMem_Malloc","PyMem_Calloc","PyMem_Realloc","PyMem_Free",
        "PyObject_Malloc","PyObject_Calloc","PyObject_Realloc","PyObject_Free",
        "_PyObject_Malloc","_PyObject_Calloc","_PyObject_Realloc","_PyObject_Free",
        NULL };
    for (int i=0; bl[i]; i++) if (strcmp(n, bl[i])==0) return 1;
    return 0;
}
void fulltrans_register(void) {
    const char *b = getenv("ISH_FULLTRANS");
    if (!b) return;
    g_ft_base = (unsigned long)strtoull(b, NULL, 0);
    int lim = (int)(sizeof(ft_rows)/sizeof(ft_rows[0]));
    const char *L = getenv("ISH_FT_LIMIT");
    if (L) { int n=atoi(L); if (n<lim) lim=n; }
    for (int i=0;i<lim;i++) {
        if (ft_blacklisted(ft_rows[i].name)) continue;
        native_offload_add_prebuilt("libpython3.12.so.1.0", ft_rows[i].name,
            g_ft_base + ft_rows[i].off, ft_rows[i].fn);
    }
}
