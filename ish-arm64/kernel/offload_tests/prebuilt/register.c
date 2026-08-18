/*
 * Pre-built gadget offload test registration (dev only).
 *
 * Compiled only with -Doffload_test_prebuilt=true. Self-registers the auto-
 * translated spec_fns as prebuilt-gadget targets via a constructor at startup —
 * the product core (native_offload_prebuilt.c) has NO test hook at all. When this
 * file isn't compiled, nothing is registered.
 */
#include <stdlib.h>   /* getenv, strtoull */
#include "kernel/native_offload.h"

/* Auto-translated spec_fns (kernel/offload_tests/prebuilt/spec_*.c). */
void spec_mix(struct cpu_state *cpu, struct tlb *tlb);
void spec_outer(struct cpu_state *cpu, struct tlb *tlb);
void spec_inner(struct cpu_state *cpu, struct tlb *tlb);
/* Real libpython3.12 hash chain (translated from /tmp/pyroot debug symbols).
 * Runtime addrs assume no-ASLR load base 0xef924000; override via env below. */
void spec_hashtable_unicode_hash(struct cpu_state *cpu, struct tlb *tlb);
void spec__Py_HashBytes(struct cpu_state *cpu, struct tlb *tlb);
void spec_pysiphash(struct cpu_state *cpu, struct tlb *tlb);
void spec_siphash13(struct cpu_state *cpu, struct tlb *tlb);
/* Hashtable lookup cluster (read side): get → get_entry_generic → compare,
 * with get_entry_generic's hash blr hitting the unicode_hash chain via IC. */
void spec__Py_hashtable_get(struct cpu_state *cpu, struct tlb *tlb);
void spec__Py_hashtable_get_entry_generic(struct cpu_state *cpu, struct tlb *tlb);
void spec__Py_hashtable_compare_direct(struct cpu_state *cpu, struct tlb *tlb);
void spec__Py_hashtable_set(struct cpu_state *cpu, struct tlb *tlb);   /* write side (#1 hotspot) */
void spec_unicodekeys_lookup_unicode(struct cpu_state *cpu, struct tlb *tlb);  /* dict str-key probe (39%% steady) */
void spec_memcmp_plt(struct cpu_state *cpu, struct tlb *tlb);  /* memcmp@plt: keep key-compare in host */
void spec_long_hash(struct cpu_state *cpu, struct tlb *tlb);        /* int hash (pure) */
void spec_PyErr_Occurred(struct cpu_state *cpu, struct tlb *tlb);
/* musl libc string/memory primitives — the #1 iSH hotspot cluster (~21%). */
void spec_musl_strlen(struct cpu_state *cpu, struct tlb *tlb);
void spec_musl_memcpy(struct cpu_state *cpu, struct tlb *tlb);
void spec_musl_memmove(struct cpu_state *cpu, struct tlb *tlb);
void spec_musl_memset(struct cpu_state *cpu, struct tlb *tlb);
void spec_musl_memchr(struct cpu_state *cpu, struct tlb *tlb);
void spec_unicode_compare_eq(struct cpu_state *cpu, struct tlb *tlb);  /* str == via host memcmp */
void spec_bytes_hash(struct cpu_state *cpu, struct tlb *tlb);          /* bytes hash via chain */
void spec_ascii_decode(struct cpu_state *cpu, struct tlb *tlb);              /* ascii decode via host memcpy */
void spec__PyUnicode_EqualToASCIIString(struct cpu_state *cpu, struct tlb *tlb);  /* via host memcmp+strlen */
void spec__PyUnicode_EQ(struct cpu_state *cpu, struct tlb *tlb);
void spec__PyUnicode_Equal(struct cpu_state *cpu, struct tlb *tlb);
void spec_PyUnicode_CompareWithASCIIString(struct cpu_state *cpu, struct tlb *tlb);
void spec__PyDict_Next(struct cpu_state *cpu, struct tlb *tlb);
void spec__PyUnicode_ToLowerFull(struct cpu_state *cpu, struct tlb *tlb);
void spec__PyUnicode_ToUpperFull(struct cpu_state *cpu, struct tlb *tlb);
void spec_scan_eol(struct cpu_state *cpu, struct tlb *tlb);
void spec_frozenset_hash(struct cpu_state *cpu, struct tlb *tlb);
void spec__PyBytes_Repeat(struct cpu_state *cpu, struct tlb *tlb);
void spec_long_compare(struct cpu_state *cpu, struct tlb *tlb);
void spec_PyIndex_Check(struct cpu_state *cpu, struct tlb *tlb);
void spec_encoding_map_lookup(struct cpu_state *cpu, struct tlb *tlb);
void spec_bool_repr(struct cpu_state *cpu, struct tlb *tlb);
void spec__PyToken_OneChar(struct cpu_state *cpu, struct tlb *tlb);
void spec__PyPegen_expect_token(struct cpu_state*, struct tlb*);
void spec__PyOpcode_num_popped(struct cpu_state *cpu, struct tlb *tlb);
void spec__Py_normalize_encoding(struct cpu_state *cpu, struct tlb *tlb);
void spec_build_indices_generic(struct cpu_state *cpu, struct tlb *tlb);
void spec_build_indices_unicode(struct cpu_state *cpu, struct tlb *tlb);
void spec_delete_index_from_values(struct cpu_state *cpu, struct tlb *tlb);
void spec_hashtable_unicode_compare(struct cpu_state *cpu, struct tlb *tlb);

void spec__PyDict_SizeOf(struct cpu_state*, struct tlb*);
void spec__PyDict_KeysSize(struct cpu_state*, struct tlb*);
void spec_init_shape_strides(struct cpu_state*, struct tlb*);
void spec__PyObject_ComputedDictPointer(struct cpu_state*, struct tlb*);
void spec_PySlice_AdjustIndices(struct cpu_state*, struct tlb*);
void spec__PyCompile_InstrSize(struct cpu_state*, struct tlb*);
void spec_eliminate_empty_basic_blocks(struct cpu_state*, struct tlb*);
void spec__PyCfg_BasicblockLastInstr(struct cpu_state*, struct tlb*);
void spec__PyEval_ThreadsInitialized(struct cpu_state*, struct tlb*);
void spec_PyEval_ThreadsInitialized(struct cpu_state*, struct tlb*);
void spec_hamt_iterator_next(struct cpu_state*, struct tlb*);
void spec_instruction_length(struct cpu_state*, struct tlb*);
void spec_de_instrument_line(struct cpu_state*, struct tlb*);
void spec_de_instrument_per_instruction(struct cpu_state*, struct tlb*);
void spec_remove_line_tools(struct cpu_state*, struct tlb*);
void spec_remove_per_instruction_tools(struct cpu_state*, struct tlb*);
void spec__Py_GetBaseOpcode(struct cpu_state*, struct tlb*);
void spec_pytime_divide(struct cpu_state*, struct tlb*);
void spec__PyTime_MulDiv(struct cpu_state*, struct tlb*);
void spec__PyTime_AsTimespec_clamp(struct cpu_state*, struct tlb*);
void spec__PyTime_AsTimespec(struct cpu_state*, struct tlb*);
void spec_hashtable_compare_traceback(struct cpu_state*, struct tlb*);
void spec_lo0bits(struct cpu_state*, struct tlb*);
void spec_quorem(struct cpu_state*, struct tlb*);
void spec_parse_number(struct cpu_state*, struct tlb*);
void spec__PySignal_AfterFork(struct cpu_state*, struct tlb*);

/* Mass golden-rule batch (auto-translated pure leaves + host-call leaves). */
void spec__PyToken_TwoChars(struct cpu_state*, struct tlb*);
void spec__PyToken_ThreeChars(struct cpu_state*, struct tlb*);
void spec_compute_parser_flags(struct cpu_state*, struct tlb*);
void spec__PyPegen_interactive_exit(struct cpu_state*, struct tlb*);
void spec__PyPegen_get_last_nonnwhitespace_token(struct cpu_state*, struct tlb*);
void spec__PyPegen_seq_last_item(struct cpu_state*, struct tlb*);
void spec__PyPegen_seq_count_dots(struct cpu_state*, struct tlb*);
void spec__PyPegen_get_last_comprehension_item(struct cpu_state*, struct tlb*);
void spec__Py_add_one_to_index_F(struct cpu_state*, struct tlb*);
void spec__Py_add_one_to_index_C(struct cpu_state*, struct tlb*);
void spec__PyObject_HasLen(struct cpu_state*, struct tlb*);
void spec_PyObject_CheckBuffer(struct cpu_state*, struct tlb*);
void spec_PyBuffer_GetPointer(struct cpu_state*, struct tlb*);
void spec_PySequence_Check(struct cpu_state*, struct tlb*);
void spec_PyMapping_Check(struct cpu_state*, struct tlb*);
void spec_PyIter_Check(struct cpu_state*, struct tlb*);
void spec_PyAIter_Check(struct cpu_state*, struct tlb*);
void spec_PyBool_FromLong(struct cpu_state*, struct tlb*);
void spec_bool_or(struct cpu_state*, struct tlb*);
void spec_bool_xor(struct cpu_state*, struct tlb*);
void spec_bool_and(struct cpu_state*, struct tlb*);
void spec_stringlib__two_way(struct cpu_state*, struct tlb*);
void spec__Py_bytes_isspace(struct cpu_state*, struct tlb*);
void spec__Py_bytes_isalpha(struct cpu_state*, struct tlb*);
void spec__Py_bytes_isalnum(struct cpu_state*, struct tlb*);
void spec__Py_bytes_isascii(struct cpu_state*, struct tlb*);
void spec__Py_bytes_isdigit(struct cpu_state*, struct tlb*);
void spec__Py_bytes_islower(struct cpu_state*, struct tlb*);
void spec__Py_bytes_isupper(struct cpu_state*, struct tlb*);
void spec__Py_bytes_istitle(struct cpu_state*, struct tlb*);
void spec__Py_bytes_lower(struct cpu_state*, struct tlb*);
void spec__Py_bytes_upper(struct cpu_state*, struct tlb*);
void spec__Py_bytes_title(struct cpu_state*, struct tlb*);
void spec__Py_bytes_capitalize(struct cpu_state*, struct tlb*);
void spec__Py_bytes_swapcase(struct cpu_state*, struct tlb*);
void spec_stringlib__two_way(struct cpu_state*, struct tlb*);
void spec_bytearray_reverse(struct cpu_state*, struct tlb*);
void spec_bytearrayiter_traverse(struct cpu_state*, struct tlb*);
void spec_stringlib_isupper(struct cpu_state*, struct tlb*);
void spec_stringlib_istitle(struct cpu_state*, struct tlb*);
void spec_stringlib_isspace(struct cpu_state*, struct tlb*);
void spec_stringlib_islower(struct cpu_state*, struct tlb*);
void spec_stringlib_isdigit(struct cpu_state*, struct tlb*);
void spec_stringlib_isascii(struct cpu_state*, struct tlb*);
void spec_stringlib_isalpha(struct cpu_state*, struct tlb*);
void spec_stringlib_isalnum(struct cpu_state*, struct tlb*);
void spec_PyByteArray_AsString(struct cpu_state*, struct tlb*);
void spec_stringlib__two_way(struct cpu_state*, struct tlb*);
void spec_striter_traverse(struct cpu_state*, struct tlb*);
void spec_cell_traverse(struct cpu_state*, struct tlb*);
void spec_instancemethod_traverse(struct cpu_state*, struct tlb*);
void spec__Py_set_localsplus_info(struct cpu_state*, struct tlb*);
void spec_descr_traverse(struct cpu_state*, struct tlb*);
void spec_mappingproxy_traverse(struct cpu_state*, struct tlb*);
void spec_wrapper_objclass(struct cpu_state*, struct tlb*);
void spec_member_get_doc(struct cpu_state*, struct tlb*);
void spec_getset_get_doc(struct cpu_state*, struct tlb*);
void spec_wrapper_richcompare(struct cpu_state*, struct tlb*);
void spec_reversed_traverse(struct cpu_state*, struct tlb*);
void spec_BaseException_get_args(struct cpu_state*, struct tlb*);
void spec_BaseException_get_tb(struct cpu_state*, struct tlb*);
void spec_PyException_GetTraceback(struct cpu_state*, struct tlb*);
void spec_PyException_GetCause(struct cpu_state*, struct tlb*);
void spec_PyException_GetContext(struct cpu_state*, struct tlb*);
void spec_PyException_GetArgs(struct cpu_state*, struct tlb*);
void spec_ga_iter_traverse(struct cpu_state*, struct tlb*);
void spec_ga_unpacked_tuple_args(struct cpu_state*, struct tlb*);
void spec_gen_get_name(struct cpu_state*, struct tlb*);
void spec_gen_get_qualname(struct cpu_state*, struct tlb*);
void spec_gen_getrunning(struct cpu_state*, struct tlb*);
void spec_cr_getsuspended(struct cpu_state*, struct tlb*);
void spec_cr_getrunning(struct cpu_state*, struct tlb*);
void spec_coro_wrapper_traverse(struct cpu_state*, struct tlb*);
void spec_ag_getsuspended(struct cpu_state*, struct tlb*);
void spec_async_gen_wrapped_val_traverse(struct cpu_state*, struct tlb*);
void spec_PyGen_GetCode(struct cpu_state*, struct tlb*);
void spec__PyFloat_InitState(struct cpu_state*, struct tlb*);
void spec_frame_getglobals(struct cpu_state*, struct tlb*);
void spec_frame_getbuiltins(struct cpu_state*, struct tlb*);
void spec_frame_gettrace_opcodes(struct cpu_state*, struct tlb*);
void spec_frame_gettrace(struct cpu_state*, struct tlb*);
void spec_frame_init_get_vars(struct cpu_state*, struct tlb*);
void spec_PyFrame_GetLineNumber(struct cpu_state*, struct tlb*);
void spec__PyFrame_IsEntryFrame(struct cpu_state*, struct tlb*);
void spec_PyFrame_GetCode(struct cpu_state*, struct tlb*);
void spec_PyFrame_GetGlobals(struct cpu_state*, struct tlb*);
void spec_PyFrame_GetBuiltins(struct cpu_state*, struct tlb*);
void spec_PyFrame_GetLasti(struct cpu_state*, struct tlb*);
void spec_PyFrame_GetGenerator(struct cpu_state*, struct tlb*);
void spec_func_get_name(struct cpu_state*, struct tlb*);
void spec_func_get_qualname(struct cpu_state*, struct tlb*);
void spec_iter_traverse(struct cpu_state*, struct tlb*);
void spec_unsafe_long_compare(struct cpu_state*, struct tlb*);
void spec_list_reverse(struct cpu_state*, struct tlb*);
void spec_listreviter_traverse(struct cpu_state*, struct tlb*);
void spec_unsafe_latin_compare(struct cpu_state*, struct tlb*);
void spec_long_dealloc(struct cpu_state*, struct tlb*);
void spec_long_long(struct cpu_state*, struct tlb*);
void spec_long_long_meth(struct cpu_state*, struct tlb*);
void spec_PyUnstable_Long_CompactValue(struct cpu_state*, struct tlb*);
void spec_dictview_traverse(struct cpu_state*, struct tlb*);
void spec_lookdict_index(struct cpu_state*, struct tlb*);
void spec__PyDictKeys_GetVersionForCurrentState(struct cpu_state*, struct tlb*);
void spec__odict_remove_node(struct cpu_state*, struct tlb*);
void spec_PyODict_New(struct cpu_state*, struct tlb*);
void spec_mbuf_traverse(struct cpu_state*, struct tlb*);
void spec_memory_traverse(struct cpu_state*, struct tlb*);
void spec_memoryiter_traverse(struct cpu_state*, struct tlb*);
void spec_copy_base(struct cpu_state*, struct tlb*);
void spec_meth_get__self__(struct cpu_state*, struct tlb*);
void spec_namespace_traverse(struct cpu_state*, struct tlb*);
void spec_Py_IncRef(struct cpu_state*, struct tlb*);
void spec__PyObject_IsFreed(struct cpu_state*, struct tlb*);
void spec_PyCallable_Check(struct cpu_state*, struct tlb*);
void spec_Py_XNewRef(struct cpu_state*, struct tlb*);
void spec_arena_map_is_used(struct cpu_state*, struct tlb*);
void spec__PyObject_VirtualAlloc(struct cpu_state*, struct tlb*);
void spec__PyObject_VirtualFree(struct cpu_state*, struct tlb*);
void spec_PyMem_RawMalloc(struct cpu_state*, struct tlb*);
void spec_PyMem_RawRealloc(struct cpu_state*, struct tlb*);
void spec_PyMem_RawFree(struct cpu_state*, struct tlb*);
void spec_PyMem_Malloc(struct cpu_state*, struct tlb*);
void spec_PyMem_Realloc(struct cpu_state*, struct tlb*);
void spec_PyMem_Free(struct cpu_state*, struct tlb*);
void spec_PyObject_Malloc(struct cpu_state*, struct tlb*);
void spec_PyObject_Realloc(struct cpu_state*, struct tlb*);
void spec_PyObject_Free(struct cpu_state*, struct tlb*);
void spec_picklebuf_traverse(struct cpu_state*, struct tlb*);
void spec_longrangeiter_len(struct cpu_state*, struct tlb*);
void spec_set_insert_clean(struct cpu_state*, struct tlb*);
void spec_setiter_traverse(struct cpu_state*, struct tlb*);
void spec_tupleiter_traverse(struct cpu_state*, struct tlb*);
void spec_type_get_bases(struct cpu_state*, struct tlb*);
void spec_type_get_mro(struct cpu_state*, struct tlb*);
void spec_object_str(struct cpu_state*, struct tlb*);
void spec_object_get_class(struct cpu_state*, struct tlb*);
void spec_slotptr(struct cpu_state*, struct tlb*);
void spec__PyStaticType_GetState(struct cpu_state*, struct tlb*);
void spec__PyType_InitCache(struct cpu_state*, struct tlb*);
void spec_PyType_IsSubtype(struct cpu_state*, struct tlb*);
void spec_PyObject_GetTypeData(struct cpu_state*, struct tlb*);
void spec_PyType_GetTypeDataSize(struct cpu_state*, struct tlb*);
void spec_typevar_reduce(struct cpu_state*, struct tlb*);
void spec_paramspec_reduce(struct cpu_state*, struct tlb*);
void spec_typevartuple_reduce(struct cpu_state*, struct tlb*);
void spec_typealias_reduce(struct cpu_state*, struct tlb*);
void spec_paramspecattr_traverse(struct cpu_state*, struct tlb*);
void spec_typevartuple_repr(struct cpu_state*, struct tlb*);
void spec_typealias_repr(struct cpu_state*, struct tlb*);
void spec_generic_traverse(struct cpu_state*, struct tlb*);
void spec_asciilib__two_way(struct cpu_state*, struct tlb*);
void spec_ucs1lib__two_way(struct cpu_state*, struct tlb*);
void spec_ucs2lib__two_way(struct cpu_state*, struct tlb*);
void spec_ucs4lib__two_way(struct cpu_state*, struct tlb*);
void spec_unicodeiter_traverse(struct cpu_state*, struct tlb*);
void spec_unicode_kind_name(struct cpu_state*, struct tlb*);
void spec_unicode_hash(struct cpu_state*, struct tlb*);
void spec_unicode_copy_as_widechar(struct cpu_state*, struct tlb*);
void spec_tailmatch(struct cpu_state*, struct tlb*);
void spec__PyUnicode_FastFill(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsWhitespace(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsLinebreak(struct cpu_state*, struct tlb*);
void spec__PyUnicode_ToTitlecase(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsTitlecase(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsXidStart(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsXidContinue(struct cpu_state*, struct tlb*);
void spec__PyUnicode_ToDecimalDigit(struct cpu_state*, struct tlb*);
void spec__PyUnicode_ToDigit(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsNumeric(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsPrintable(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsLowercase(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsUppercase(struct cpu_state*, struct tlb*);
void spec__PyUnicode_ToUppercase(struct cpu_state*, struct tlb*);
void spec__PyUnicode_ToLowercase(struct cpu_state*, struct tlb*);
void spec__PyUnicode_ToTitleFull(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsCased(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsCaseIgnorable(struct cpu_state*, struct tlb*);
void spec__PyUnicode_IsAlpha(struct cpu_state*, struct tlb*);
void spec_gc_traverse(struct cpu_state*, struct tlb*);
void spec__PyWeakref_GetWeakrefCount(struct cpu_state*, struct tlb*);
void spec_assemble_emit_exception_table_item(struct cpu_state*, struct tlb*);
void spec__PyAST_GetDocString(struct cpu_state*, struct tlb*);
void spec__PyEval_GetBuiltins(struct cpu_state*, struct tlb*);
void spec_infer_type(struct cpu_state*, struct tlb*);
void spec_token_get_var(struct cpu_state*, struct tlb*);
void spec_token_get_old_value(struct cpu_state*, struct tlb*);
void spec__PyErr_GetTopmostException(struct cpu_state*, struct tlb*);
void spec__PyErr_Fetch(struct cpu_state*, struct tlb*);
void spec__PyOpcode_num_pushed(struct cpu_state*, struct tlb*);
void spec__PyFrame_Copy(struct cpu_state*, struct tlb*);
void spec_PyUnstable_InterpreterFrame_GetCode(struct cpu_state*, struct tlb*);
void spec__PyEval_InitState(struct cpu_state*, struct tlb*);
void spec_hamt_baseiter_tp_traverse(struct cpu_state*, struct tlb*);
void spec_hamt_iter_yield_values(struct cpu_state*, struct tlb*);
void spec_hamt_tp_traverse(struct cpu_state*, struct tlb*);
void spec_hashtable_hash_str(struct cpu_state*, struct tlb*);
void spec_PyStatus_Error(struct cpu_state*, struct tlb*);
void spec_PyStatus_Exit(struct cpu_state*, struct tlb*);
void spec_Py_GetArgcArgv(struct cpu_state*, struct tlb*);
void spec_Py_GetPath(struct cpu_state*, struct tlb*);
void spec__Py_GetStdlibDir(struct cpu_state*, struct tlb*);
void spec__PyPreConfig_GetConfig(struct cpu_state*, struct tlb*);
void spec_init_interp_settings(struct cpu_state*, struct tlb*);
void spec__Py_IsFinalizing(struct cpu_state*, struct tlb*);
void spec__Py_IsInterpreterFinalizing(struct cpu_state*, struct tlb*);
void spec__new_none_object(struct cpu_state*, struct tlb*);
void spec__PyGILState_Init(struct cpu_state*, struct tlb*);
void spec__PyGILState_Fini(struct cpu_state*, struct tlb*);
void spec__PyCrossInterpreterData_Init(struct cpu_state*, struct tlb*);
void spec__PyInterpreterState_GetEvalFrameFunc(struct cpu_state*, struct tlb*);
void spec__PyInterpreterState_SetEvalFrameFunc(struct cpu_state*, struct tlb*);
void spec__PyTime_Add(struct cpu_state*, struct tlb*);
void spec__PyTime_FromMicrosecondsClamp(struct cpu_state*, struct tlb*);
void spec_write_obj(struct cpu_state*, struct tlb*);
void spec_write_u32(struct cpu_state*, struct tlb*);
void spec__Py_Specialize_LoadSuperAttr(struct cpu_state*, struct tlb*);
void spec__Py_Specialize_StoreSubscr(struct cpu_state*, struct tlb*);
void spec__Py_Specialize_BinaryOp(struct cpu_state*, struct tlb*);
void spec__Py_Specialize_CompareOp(struct cpu_state*, struct tlb*);
void spec__Py_Specialize_UnpackSequence(struct cpu_state*, struct tlb*);
void spec__PyST_IsFunctionLike(struct cpu_state*, struct tlb*);
void spec_sys_getdefaultencoding(struct cpu_state*, struct tlb*);
void spec_tb_next_get(struct cpu_state*, struct tlb*);
void spec_raw_free(struct cpu_state*, struct tlb*);
void spec__PyOS_ResetGetOpt(struct cpu_state*, struct tlb*);
void spec_hi0bits(struct cpu_state*, struct tlb*);
void spec_referrersvisit(struct cpu_state*, struct tlb*);
void spec__PyGC_InitState(struct cpu_state*, struct tlb*);
void spec_PyObject_GC_UnTrack(struct cpu_state*, struct tlb*);
void spec__Py_ScheduleGC(struct cpu_state*, struct tlb*);
void spec_os_DirEntry___fspath__(struct cpu_state*, struct tlb*);
void spec_PySignal_SetWakeupFd(struct cpu_state*, struct tlb*);
void spec_deque_reverse(struct cpu_state*, struct tlb*);
void spec_mode_string(struct cpu_state*, struct tlb*);
void spec_get_mode(struct cpu_state*, struct tlb*);
void spec_bytesio_get_closed(struct cpu_state*, struct tlb*);
void spec_find_control_char(struct cpu_state*, struct tlb*);
void spec_repeat_next(struct cpu_state*, struct tlb*);
void spec__validate_charset(struct cpu_state*, struct tlb*);
void spec_match_lastgroup_get(struct cpu_state*, struct tlb*);
void spec_lock_traverse(struct cpu_state*, struct tlb*);
void spec_rlock_traverse(struct cpu_state*, struct tlb*);
void spec_time_module_traverse(struct cpu_state*, struct tlb*);
void spec__typing__idfunc(struct cpu_state*, struct tlb*);
void spec__abcmodule_traverse(struct cpu_state*, struct tlb*);
void spec__tscmp(struct cpu_state*, struct tlb*);
void spec__Py_get_importlib__bootstrap_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_importlib__bootstrap_external_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_zipimport_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_abc_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_codecs_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_io_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get__collections_abc_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get__sitebuiltins_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_genericpath_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_ntpath_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_posixpath_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_os_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_site_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_stat_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_importlib_util_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_importlib_machinery_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_runpy_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get___hello___toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get___phello___toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get___phello___ham_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get___phello___ham_eggs_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get___phello___spam_toplevel(struct cpu_state*, struct tlb*);
void spec__Py_get_frozen_only_toplevel(struct cpu_state*, struct tlb*);


/* Basic-block-JIT PoC: register the hot asm loop (spec_bbjit_poc.c) at its guest
 * address. Loop body is at file offset 0x7b0, fall-through at 0x7d0; PIE load
 * base supplied via ISH_BBJIT_BASE=0x… (from /proc/self/maps). */
void spec_bbjit_poc(struct cpu_state *cpu, struct tlb *tlb);
extern uint64_t g_bbjit_fallthrough_pc;
void spec_twochars_poc_fn(struct cpu_state *cpu, struct tlb *tlb);
extern uint64_t g_twochars_pb_base;

__attribute__((constructor))
static void offload_test_prebuilt_register(void) {
    extern void fulltrans_register(void);
    fulltrans_register();

    const char *bb = getenv("ISH_BBJIT_BASE");
    if (bb) {
        addr_t base = (addr_t)strtoull(bb, NULL, 0);
        g_bbjit_fallthrough_pc = base + 0x7d0;
        native_offload_add_prebuilt("al2", "bbjit_loop", base + 0x7b0, spec_bbjit_poc);
    }

    /* PoC: real libpython leaf _PyToken_TwoChars @ file offset 0x108780.
     * Supply libpython .text load base via ISH_TWOCHARS_BASE=0x… */
    const char *tc = getenv("ISH_TWOCHARS_BASE");
    if (tc) {
        addr_t pybase = (addr_t)strtoull(tc, NULL, 0);
        g_twochars_pb_base = pybase;
        native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyToken_TwoChars",
                                    pybase + 0x108780, spec_twochars_poc_fn);
    }

    /* tests/offload/prebuilt/mixbench.c, non-PIE, mix @ 0x400314 */
    native_offload_add_prebuilt("mixbench", "mix", 0x400314, spec_mix);
    /* callbench.c, non-PIE: outer @ 0x400338 calls inner @ 0x40031c.
     * Registering BOTH lets outer's blr hit inner's spec via inline cache
     * (native_offload_prebuilt_lookup), instead of round-tripping the
     * interpreter. This is the inline-cache path. */
    native_offload_add_prebuilt("callbench", "outer", 0x400338, spec_outer);
    native_offload_add_prebuilt("callbench", "inner", 0x40031c, spec_inner);

    /* Real libpython3.12 hash chain. The library is PIE, so its load base is a
     * runtime value; supply it via ISH_PYLIB_BASE=0x… (from /proc/self/maps or a
     * pc_trace). File offsets are fixed. When unset, the chain stays unregistered
     * so a normal build is unaffected. */
    const char *pb = getenv("ISH_PYLIB_BASE");
    if (pb) {
        addr_t base = (addr_t)strtoull(pb, NULL, 0);
        native_offload_add_prebuilt("libpython3.12.so.1.0", "hashtable_unicode_hash",
                                    base + 0x152ab0, spec_hashtable_unicode_hash);
        native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_HashBytes",
                                    base + 0x2124e0, spec__Py_HashBytes);
        /* ISH_HASHCHAIN_MAX: how many of the chain to register (isolation).
         * 2 = only unicode_hash + _Py_HashBytes (pysiphash/siphash13 interpreted);
         * 3 = + pysiphash; 4 (default) = full chain. */
        int nmax = 4;
        const char *nm = getenv("ISH_HASHCHAIN_MAX");
        if (nm) nmax = (int)strtol(nm, NULL, 0);
        if (nmax >= 3)
            native_offload_add_prebuilt("libpython3.12.so.1.0", "pysiphash",
                                        base + 0x212300, spec_pysiphash);
        if (nmax >= 4)
            native_offload_add_prebuilt("libpython3.12.so.1.0", "siphash13",
                                        base + 0x212080, spec_siphash13);

        /* Hashtable lookup cluster. Gated separately so it can be A/B-isolated
         * from the hash chain; on by default when the chain is registered. */
        if (getenv("ISH_HASHTBL_OFF") == NULL) {
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_hashtable_get",
                                        base + 0x1f67a0, spec__Py_hashtable_get);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_hashtable_get_entry_generic",
                                        base + 0x1f634c, spec__Py_hashtable_get_entry_generic);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_hashtable_compare_direct",
                                        base + 0x1f6340, spec__Py_hashtable_compare_direct);
            /* _Py_hashtable_set: the #1 hotspot, but its translation still causes
             * a malloc/free spin during runtime init (wrong entry state feeds a
             * caller retry loop — under debug). Gated OFF until the divergence is
             * root-caused; opt in with ISH_HASHTBL_SET=1 to reproduce. */
            if (getenv("ISH_HASHTBL_SET"))
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_hashtable_set",
                                            base + 0x1f66c0, spec__Py_hashtable_set);
        }
        /* Dict string-key lookup — the #1 steady-state hotspot (~39%). Pure probe
         * loop; only external call is memcmp@plt (rare, IC-falls back). */
        if (getenv("ISH_DICTLOOKUP_OFF") == NULL) {
            native_offload_add_prebuilt("libpython3.12.so.1.0", "unicodekeys_lookup_unicode",
                                        base + 0x870a0, spec_unicodekeys_lookup_unicode);
            /* memcmp@plt: the dict-lookup spec calls it on every key compare;
             * register a host memcmp so the IC stays in host instead of round-
             * tripping the interpreter (which would negate the offload). */
            native_offload_add_prebuilt("libpython3.12.so.1.0", "memcmp@plt",
                                        base + 0x81720, spec_memcmp_plt);
            /* long_hash: pure-integer hash of a Python int. No calls. */
            native_offload_add_prebuilt("libpython3.12.so.1.0", "long_hash",
                                        base + 0x100ea0, spec_long_hash);
            /* String equality/hash whose only call is an already-host function:
             * unicode_compare_eq → host memcmp; bytes_hash → translated hash chain.
             * These IC-hit existing specs, avoiding the fallback trap. */
            native_offload_add_prebuilt("libpython3.12.so.1.0", "unicode_compare_eq",
                                        base + 0x0000000000154450, spec_unicode_compare_eq);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "bytes_hash",
                                        base + 0x00000000000ca460, spec_bytes_hash);
            /* Register host memcmp ALSO at libpython's own memcmp PLT stub so
             * callers landing on the stub hit host memcmp (it's the same fn). */
            native_offload_add_prebuilt("libpython3.12.so.1.0", "memcmp_plt2",
                                        base + 0x81720, spec_memcmp_plt);
            /* Host memory primitives ALSO at libpython's own PLT stubs, so callers
             * landing there (ascii_decode→memcpy, EqualToASCII→strlen, etc.) hit
             * the host spec instead of jumping through the stub to musl. Same fn,
             * same ABI — spec_musl_* work verbatim at these addresses. */
            {
                native_offload_add_prebuilt("libpython3.12.so.1.0", "memcpy_pltL",  base + 0x86a50, spec_musl_memcpy);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "strlen_pltL",  base + 0x86bd0, spec_musl_strlen);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "memset_pltL",  base + 0x825b0, spec_musl_memset);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "memmove_pltL", base + 0x82a20, spec_musl_memmove);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "memchr_pltL",  base + 0x86310, spec_musl_memchr);
            }
            /* Unicode fast paths whose only calls are the now-host memcpy/memcmp/
             * strlen (registered above). Safe by the golden rule. */
            native_offload_add_prebuilt("libpython3.12.so.1.0", "ascii_decode",
                                        base + 0x000000000014f780, spec_ascii_decode);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_EqualToASCIIString",
                                        base + 0x000000000016b0e0, spec__PyUnicode_EqualToASCIIString);
            /* Golden-rule batch: leaves whose only calls are host mem/str primitives. */
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_EQ",
                                        base + 0x16b150, spec__PyUnicode_EQ);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_Equal",
                                        base + 0x16aea0, spec__PyUnicode_Equal);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyUnicode_CompareWithASCIIString",
                                        base + 0x16afa0, spec_PyUnicode_CompareWithASCIIString);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyDict_Next",
                                        base + 0x111720, spec__PyDict_Next);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_ToLowerFull",
                                        base + 0x17f300, spec__PyUnicode_ToLowerFull);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_ToUpperFull",
                                        base + 0x17f448, spec__PyUnicode_ToUpperFull);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "scan_eol",
                                        base + 0x26fc60, spec_scan_eol);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "frozenset_hash",
                                        base + 0x12d440, spec_frozenset_hash);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyBytes_Repeat",
                                        base + 0xd4f20, spec__PyBytes_Repeat);
            /* Golden-rule batch 2: pip-install hotspot pure leaves. */
            native_offload_add_prebuilt("libpython3.12.so.1.0", "long_compare",
                                        base + 0x100d8c, spec_long_compare);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyIndex_Check",
                                        base + 0xba8e0, spec_PyIndex_Check);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "encoding_map_lookup",
                                        base + 0x14f6e0, spec_encoding_map_lookup);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "bool_repr",
                                        base + 0xbe0e0, spec_bool_repr);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyToken_OneChar",
                                        base + 0x874e0, spec__PyToken_OneChar);
            if (getenv("ISH_MASSBATCH") == NULL) {
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyDict_SizeOf", base + 0x112020, spec__PyDict_SizeOf);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyDict_KeysSize", base + 0x1120c0, spec__PyDict_KeysSize);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "init_shape_strides", base + 0x11d3e0, spec_init_shape_strides);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyObject_ComputedDictPointer", base + 0x1238e0, spec__PyObject_ComputedDictPointer);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "PySlice_AdjustIndices", base + 0x1315a8, spec_PySlice_AdjustIndices);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyCompile_InstrSize", base + 0x1d0248, spec__PyCompile_InstrSize);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "eliminate_empty_basic_blocks", base + 0x1e74c0, spec_eliminate_empty_basic_blocks);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyCfg_BasicblockLastInstr", base + 0x1e8464, spec__PyCfg_BasicblockLastInstr);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyEval_ThreadsInitialized", base + 0x1f28a4, spec__PyEval_ThreadsInitialized);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "PyEval_ThreadsInitialized", base + 0x1f28e0, spec_PyEval_ThreadsInitialized);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "hamt_iterator_next", base + 0x1f3b4c, spec_hamt_iterator_next);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "instruction_length", base + 0x204e00, spec_instruction_length);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "de_instrument_line", base + 0x204e64, spec_de_instrument_line);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "de_instrument_per_instruction", base + 0x204ee0, spec_de_instrument_per_instruction);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "remove_line_tools", base + 0x204f4c, spec_remove_line_tools);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "remove_per_instruction_tools", base + 0x204f80, spec_remove_per_instruction_tools);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_GetBaseOpcode", base + 0x205b88, spec__Py_GetBaseOpcode);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "pytime_divide", base + 0x21e840, spec_pytime_divide);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyTime_MulDiv", base + 0x21e920, spec__PyTime_MulDiv);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyTime_AsTimespec_clamp", base + 0x21f2c0, spec__PyTime_AsTimespec_clamp);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyTime_AsTimespec", base + 0x21f304, spec__PyTime_AsTimespec);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "hashtable_compare_traceback", base + 0x2324a8, spec_hashtable_compare_traceback);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "lo0bits", base + 0x2358e0, spec_lo0bits);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "quorem", base + 0x236024, spec_quorem);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "parse_number", base + 0x23a650, spec_parse_number);
                native_offload_add_prebuilt("libpython3.12.so.1.0", "_PySignal_AfterFork", base + 0x25ed28, spec__PySignal_AfterFork);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyToken_TwoChars", base + 0x87504, spec__PyToken_TwoChars);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyToken_ThreeChars", base + 0x87690, spec__PyToken_ThreeChars);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "compute_parser_flags", base + 0x87740, spec_compute_parser_flags);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyPegen_interactive_exit", base + 0x879c0, spec__PyPegen_interactive_exit);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyPegen_get_last_nonnwhitespace_token", base + 0x886c0, spec__PyPegen_get_last_nonnwhitespace_token);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyPegen_seq_last_item", base + 0x8a8b0, spec__PyPegen_seq_last_item);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyPegen_seq_count_dots", base + 0x8aac0, spec__PyPegen_seq_count_dots);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyPegen_get_last_comprehension_item", base + 0x8c010, spec__PyPegen_get_last_comprehension_item);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_add_one_to_index_F", base + 0xb7180, spec__Py_add_one_to_index_F);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_add_one_to_index_C", base + 0xb71c4, spec__Py_add_one_to_index_C);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyObject_HasLen", base + 0xb8260, spec__PyObject_HasLen);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyObject_CheckBuffer", base + 0xb82a0, spec_PyObject_CheckBuffer);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyBuffer_GetPointer", base + 0xb83a0, spec_PyBuffer_GetPointer);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PySequence_Check", base + 0xbb760, spec_PySequence_Check);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyMapping_Check", base + 0xbca80, spec_PyMapping_Check);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyIter_Check", base + 0xbd188, spec_PyIter_Check);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyAIter_Check", base + 0xbd728, spec_PyAIter_Check);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyBool_FromLong", base + 0xbe1a0, spec_PyBool_FromLong);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "bool_or", base + 0xbe320, spec_bool_or);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "bool_xor", base + 0xbe370, spec_bool_xor);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "bool_and", base + 0xbe3cc, spec_bool_and);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib__two_way", base + 0xbe420, spec_stringlib__two_way);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_isspace", base + 0xbf580, spec__Py_bytes_isspace);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_isalpha", base + 0xbf5e8, spec__Py_bytes_isalpha);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_isalnum", base + 0xbf660, spec__Py_bytes_isalnum);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_isascii", base + 0xbf6d0, spec__Py_bytes_isascii);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_isdigit", base + 0xbf748, spec__Py_bytes_isdigit);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_islower", base + 0xbf7b0, spec__Py_bytes_islower);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_isupper", base + 0xbf82c, spec__Py_bytes_isupper);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_istitle", base + 0xbf8b0, spec__Py_bytes_istitle);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_lower", base + 0xbf960, spec__Py_bytes_lower);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_upper", base + 0xbf9a0, spec__Py_bytes_upper);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_title", base + 0xbf9e0, spec__Py_bytes_title);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_capitalize", base + 0xbfa68, spec__Py_bytes_capitalize);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_bytes_swapcase", base + 0xbfac0, spec__Py_bytes_swapcase);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib__two_way", base + 0xc03e0, spec_stringlib__two_way);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "bytearray_reverse", base + 0xc0600, spec_bytearray_reverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "bytearrayiter_traverse", base + 0xc0660, spec_bytearrayiter_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib_isupper", base + 0xc0970, spec_stringlib_isupper);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib_istitle", base + 0xc098c, spec_stringlib_istitle);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib_isspace", base + 0xc09a8, spec_stringlib_isspace);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib_islower", base + 0xc09c4, spec_stringlib_islower);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib_isdigit", base + 0xc09e0, spec_stringlib_isdigit);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib_isascii", base + 0xc0a00, spec_stringlib_isascii);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib_isalpha", base + 0xc0a20, spec_stringlib_isalpha);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib_isalnum", base + 0xc0a40, spec_stringlib_isalnum);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyByteArray_AsString", base + 0xc7388, spec_PyByteArray_AsString);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "stringlib__two_way", base + 0xc97c0, spec_stringlib__two_way);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "striter_traverse", base + 0xc99e8, spec_striter_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "cell_traverse", base + 0xd87a0, spec_cell_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "instancemethod_traverse", base + 0xd8d0c, spec_instancemethod_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_set_localsplus_info", base + 0xdb570, spec__Py_set_localsplus_info);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "descr_traverse", base + 0xe0aa0, spec_descr_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "mappingproxy_traverse", base + 0xe0ac0, spec_mappingproxy_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "wrapper_objclass", base + 0xe0ae0, spec_wrapper_objclass);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "member_get_doc", base + 0xe1000, spec_member_get_doc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "getset_get_doc", base + 0xe1020, spec_getset_get_doc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "wrapper_richcompare", base + 0xe18ac, spec_wrapper_richcompare);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "reversed_traverse", base + 0xe41c0, spec_reversed_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "BaseException_get_args", base + 0xe4ef0, spec_BaseException_get_args);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "BaseException_get_tb", base + 0xe4f20, spec_BaseException_get_tb);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyException_GetTraceback", base + 0xe8e04, spec_PyException_GetTraceback);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyException_GetCause", base + 0xe8f4c, spec_PyException_GetCause);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyException_GetContext", base + 0xe9050, spec_PyException_GetContext);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyException_GetArgs", base + 0xe9bc0, spec_PyException_GetArgs);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "ga_iter_traverse", base + 0xeb700, spec_ga_iter_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "ga_unpacked_tuple_args", base + 0xeb9e0, spec_ga_unpacked_tuple_args);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "gen_get_name", base + 0xed480, spec_gen_get_name);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "gen_get_qualname", base + 0xed4a0, spec_gen_get_qualname);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "gen_getrunning", base + 0xed4c0, spec_gen_getrunning);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "cr_getsuspended", base + 0xed4e0, spec_cr_getsuspended);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "cr_getrunning", base + 0xed504, spec_cr_getrunning);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "coro_wrapper_traverse", base + 0xed524, spec_coro_wrapper_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "ag_getsuspended", base + 0xed540, spec_ag_getsuspended);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "async_gen_wrapped_val_traverse", base + 0xed5e4, spec_async_gen_wrapped_val_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyGen_GetCode", base + 0xeed40, spec_PyGen_GetCode);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyFloat_InitState", base + 0xf4944, spec__PyFloat_InitState);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "frame_getglobals", base + 0xf56c0, spec_frame_getglobals);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "frame_getbuiltins", base + 0xf56ec, spec_frame_getbuiltins);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "frame_gettrace_opcodes", base + 0xf5720, spec_frame_gettrace_opcodes);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "frame_gettrace", base + 0xf5750, spec_frame_gettrace);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "frame_init_get_vars", base + 0xf5780, spec_frame_init_get_vars);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyFrame_GetLineNumber", base + 0xf6a88, spec_PyFrame_GetLineNumber);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyFrame_IsEntryFrame", base + 0xf7500, spec__PyFrame_IsEntryFrame);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyFrame_GetCode", base + 0xf7524, spec_PyFrame_GetCode);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyFrame_GetGlobals", base + 0xf76a4, spec_PyFrame_GetGlobals);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyFrame_GetBuiltins", base + 0xf76d0, spec_PyFrame_GetBuiltins);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyFrame_GetLasti", base + 0xf7700, spec_PyFrame_GetLasti);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyFrame_GetGenerator", base + 0xf7724, spec_PyFrame_GetGenerator);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "func_get_name", base + 0xf7a00, spec_func_get_name);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "func_get_qualname", base + 0xf7a20, spec_func_get_qualname);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "iter_traverse", base + 0xfaa60, spec_iter_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "unsafe_long_compare", base + 0xfb9e0, spec_unsafe_long_compare);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "list_reverse", base + 0xfba40, spec_list_reverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "listreviter_traverse", base + 0xfbb20, spec_listreviter_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "unsafe_latin_compare", base + 0xfcc60, spec_unsafe_latin_compare);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "long_dealloc", base + 0x100e28, spec_long_dealloc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "long_long", base + 0x104660, spec_long_long);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "long_long_meth", base + 0x104760, spec_long_long_meth);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyUnstable_Long_CompactValue", base + 0x10cf70, spec_PyUnstable_Long_CompactValue);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "dictview_traverse", base + 0x10d1c0, spec_dictview_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "lookdict_index", base + 0x10d8cc, spec_lookdict_index);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyDictKeys_GetVersionForCurrentState", base + 0x112a60, spec__PyDictKeys_GetVersionForCurrentState);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_odict_remove_node", base + 0x116de0, spec__odict_remove_node);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyODict_New", base + 0x119380, spec_PyODict_New);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "mbuf_traverse", base + 0x1198a0, spec_mbuf_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "memory_traverse", base + 0x1198c0, spec_memory_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "memoryiter_traverse", base + 0x1198f0, spec_memoryiter_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "copy_base", base + 0x119da4, spec_copy_base);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "meth_get__self__", base + 0x11ffa0, spec_meth_get__self__);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "namespace_traverse", base + 0x122ee0, spec_namespace_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "Py_IncRef", base + 0x123730, spec_Py_IncRef);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyObject_IsFreed", base + 0x1237c4, spec__PyObject_IsFreed);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyCallable_Check", base + 0x123b00, spec_PyCallable_Check);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "Py_XNewRef", base + 0x1269c0, spec_Py_XNewRef);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "arena_map_is_used", base + 0x126b0c, spec_arena_map_is_used);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyObject_VirtualAlloc", base + 0x128a8c, spec__PyObject_VirtualAlloc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyObject_VirtualFree", base + 0x128aa4, spec__PyObject_VirtualFree);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyMem_RawMalloc", base + 0x128ac0, spec_PyMem_RawMalloc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyMem_RawRealloc", base + 0x128d40, spec_PyMem_RawRealloc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyMem_RawFree", base + 0x128d68, spec_PyMem_RawFree);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyMem_Malloc", base + 0x128ff0, spec_PyMem_Malloc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyMem_Realloc", base + 0x129060, spec_PyMem_Realloc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyMem_Free", base + 0x129088, spec_PyMem_Free);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyObject_Malloc", base + 0x129220, spec_PyObject_Malloc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyObject_Realloc", base + 0x129280, spec_PyObject_Realloc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyObject_Free", base + 0x1292a8, spec_PyObject_Free);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "picklebuf_traverse", base + 0x129e60, spec_picklebuf_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "longrangeiter_len", base + 0x12a240, spec_longrangeiter_len);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "set_insert_clean", base + 0x12c200, spec_set_insert_clean);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "setiter_traverse", base + 0x12c280, spec_setiter_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "tupleiter_traverse", base + 0x133340, spec_tupleiter_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "type_get_bases", base + 0x135660, spec_type_get_bases);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "type_get_mro", base + 0x135688, spec_type_get_mro);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "object_str", base + 0x1356e0, spec_object_str);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "object_get_class", base + 0x135700, spec_object_get_class);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "slotptr", base + 0x1357ec, spec_slotptr);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyStaticType_GetState", base + 0x13a2e4, spec__PyStaticType_GetState);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyType_InitCache", base + 0x13a9d0, spec__PyType_InitCache);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyType_IsSubtype", base + 0x13bcc4, spec_PyType_IsSubtype);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyObject_GetTypeData", base + 0x13cea8, spec_PyObject_GetTypeData);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyType_GetTypeDataSize", base + 0x13cec0, spec_PyType_GetTypeDataSize);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "typevar_reduce", base + 0x14bb00, spec_typevar_reduce);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "paramspec_reduce", base + 0x14bb20, spec_paramspec_reduce);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "typevartuple_reduce", base + 0x14bb40, spec_typevartuple_reduce);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "typealias_reduce", base + 0x14bb60, spec_typealias_reduce);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "paramspecattr_traverse", base + 0x14bb80, spec_paramspecattr_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "typevartuple_repr", base + 0x14bba0, spec_typevartuple_repr);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "typealias_repr", base + 0x14bbc0, spec_typealias_repr);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "generic_traverse", base + 0x14bc68, spec_generic_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "asciilib__two_way", base + 0x14eb00, spec_asciilib__two_way);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "ucs1lib__two_way", base + 0x14ed20, spec_ucs1lib__two_way);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "ucs2lib__two_way", base + 0x14ef40, spec_ucs2lib__two_way);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "ucs4lib__two_way", base + 0x14f160, spec_ucs4lib__two_way);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "unicodeiter_traverse", base + 0x14f760, spec_unicodeiter_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "unicode_kind_name", base + 0x150580, spec_unicode_kind_name);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "unicode_hash", base + 0x152b10, spec_unicode_hash);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "unicode_copy_as_widechar", base + 0x154c08, spec_unicode_copy_as_widechar);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "tailmatch", base + 0x155864, spec_tailmatch);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_FastFill", base + 0x16a500, spec__PyUnicode_FastFill);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsWhitespace", base + 0x17ed80, spec__PyUnicode_IsWhitespace);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsLinebreak", base + 0x17ee30, spec__PyUnicode_IsLinebreak);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_ToTitlecase", base + 0x17ee80, spec__PyUnicode_ToTitlecase);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsTitlecase", base + 0x17eee8, spec__PyUnicode_IsTitlecase);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsXidStart", base + 0x17ef40, spec__PyUnicode_IsXidStart);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsXidContinue", base + 0x17ef90, spec__PyUnicode_IsXidContinue);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_ToDecimalDigit", base + 0x17efe0, spec__PyUnicode_ToDecimalDigit);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_ToDigit", base + 0x17f060, spec__PyUnicode_ToDigit);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsNumeric", base + 0x17f0e0, spec__PyUnicode_IsNumeric);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsPrintable", base + 0x17f130, spec__PyUnicode_IsPrintable);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsLowercase", base + 0x17f180, spec__PyUnicode_IsLowercase);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsUppercase", base + 0x17f1d0, spec__PyUnicode_IsUppercase);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_ToUppercase", base + 0x17f220, spec__PyUnicode_ToUppercase);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_ToLowercase", base + 0x17f28c, spec__PyUnicode_ToLowercase);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_ToTitleFull", base + 0x17f3a4, spec__PyUnicode_ToTitleFull);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsCased", base + 0x17f590, spec__PyUnicode_IsCased);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsCaseIgnorable", base + 0x17f5e0, spec__PyUnicode_IsCaseIgnorable);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyUnicode_IsAlpha", base + 0x17f630, spec__PyUnicode_IsAlpha);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "gc_traverse", base + 0x180320, spec_gc_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyWeakref_GetWeakrefCount", base + 0x1844a0, spec__PyWeakref_GetWeakrefCount);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "assemble_emit_exception_table_item", base + 0x1adc60, spec_assemble_emit_exception_table_item);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyAST_GetDocString", base + 0x1b18e0, spec__PyAST_GetDocString);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyEval_GetBuiltins", base + 0x1ca6a0, spec__PyEval_GetBuiltins);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "infer_type", base + 0x1ce260, spec_infer_type);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "token_get_var", base + 0x1e1d00, spec_token_get_var);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "token_get_old_value", base + 0x1e2720, spec_token_get_old_value);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyErr_GetTopmostException", base + 0x1e3ac0, spec__PyErr_GetTopmostException);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyErr_Fetch", base + 0x1e3ca0, spec__PyErr_Fetch);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyOpcode_num_pushed", base + 0x1e8160, spec__PyOpcode_num_pushed);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyFrame_Copy", base + 0x1eb168, spec__PyFrame_Copy);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyUnstable_InterpreterFrame_GetCode", base + 0x1eb448, spec_PyUnstable_InterpreterFrame_GetCode);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyEval_InitState", base + 0x1f360c, spec__PyEval_InitState);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "hamt_baseiter_tp_traverse", base + 0x1f3c64, spec_hamt_baseiter_tp_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "hamt_iter_yield_values", base + 0x1f3ca0, spec_hamt_iter_yield_values);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "hamt_tp_traverse", base + 0x1f3cc0, spec_hamt_tp_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "hashtable_hash_str", base + 0x1f6c44, spec_hashtable_hash_str);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyStatus_Error", base + 0x1fdc8c, spec_PyStatus_Error);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyStatus_Exit", base + 0x1fde24, spec_PyStatus_Exit);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "Py_GetArgcArgv", base + 0x1fe9e0, spec_Py_GetArgcArgv);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "Py_GetPath", base + 0x210588, spec_Py_GetPath);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_GetStdlibDir", base + 0x2105a4, spec__Py_GetStdlibDir);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyPreConfig_GetConfig", base + 0x211100, spec__PyPreConfig_GetConfig);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "init_interp_settings", base + 0x212540, spec_init_interp_settings);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_IsFinalizing", base + 0x213fc8, spec__Py_IsFinalizing);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_IsInterpreterFinalizing", base + 0x215ec0, spec__Py_IsInterpreterFinalizing);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_new_none_object", base + 0x216ca0, spec__new_none_object);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyGILState_Init", base + 0x218f6c, spec__PyGILState_Init);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyGILState_Fini", base + 0x218fa0, spec__PyGILState_Fini);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyCrossInterpreterData_Init", base + 0x219180, spec__PyCrossInterpreterData_Init);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyInterpreterState_GetEvalFrameFunc", base + 0x219b80, spec__PyInterpreterState_GetEvalFrameFunc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyInterpreterState_SetEvalFrameFunc", base + 0x219ba0, spec__PyInterpreterState_SetEvalFrameFunc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyTime_Add", base + 0x21e8e4, spec__PyTime_Add);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyTime_FromMicrosecondsClamp", base + 0x21ee00, spec__PyTime_FromMicrosecondsClamp);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "write_obj", base + 0x2201a0, spec_write_obj);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "write_u32", base + 0x2201e4, spec_write_u32);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_Specialize_LoadSuperAttr", base + 0x220630, spec__Py_Specialize_LoadSuperAttr);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_Specialize_StoreSubscr", base + 0x2211cc, spec__Py_Specialize_StoreSubscr);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_Specialize_BinaryOp", base + 0x2215c8, spec__Py_Specialize_BinaryOp);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_Specialize_CompareOp", base + 0x221740, spec__Py_Specialize_CompareOp);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_Specialize_UnpackSequence", base + 0x221808, spec__Py_Specialize_UnpackSequence);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyST_IsFunctionLike", base + 0x223d80, spec__PyST_IsFunctionLike);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "sys_getdefaultencoding", base + 0x2286e0, spec_sys_getdefaultencoding);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "tb_next_get", base + 0x22faa0, spec_tb_next_get);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "raw_free", base + 0x232488, spec_raw_free);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyOS_ResetGetOpt", base + 0x234400, spec__PyOS_ResetGetOpt);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "hi0bits", base + 0x235840, spec_hi0bits);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "referrersvisit", base + 0x2423c0, spec_referrersvisit);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyGC_InitState", base + 0x2444c4, spec__PyGC_InitState);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PyObject_GC_UnTrack", base + 0x244a4c, spec_PyObject_GC_UnTrack);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_ScheduleGC", base + 0x244ac8, spec__Py_ScheduleGC);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "os_DirEntry___fspath__", base + 0x247708, spec_os_DirEntry___fspath__);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "PySignal_SetWakeupFd", base + 0x25dd40, spec_PySignal_SetWakeupFd);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "deque_reverse", base + 0x263480, spec_deque_reverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "mode_string", base + 0x26dc0c, spec_mode_string);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "get_mode", base + 0x26f764, spec_get_mode);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "bytesio_get_closed", base + 0x26f8c0, spec_bytesio_get_closed);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "find_control_char", base + 0x278d40, spec_find_control_char);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "repeat_next", base + 0x28138c, spec_repeat_next);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_validate_charset", base + 0x289760, spec__validate_charset);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "match_lastgroup_get", base + 0x289ee8, spec_match_lastgroup_get);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "lock_traverse", base + 0x299ae0, spec_lock_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "rlock_traverse", base + 0x29b380, spec_rlock_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "time_module_traverse", base + 0x29bf40, spec_time_module_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_typing__idfunc", base + 0x29e3c0, spec__typing__idfunc);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_abcmodule_traverse", base + 0x29ea48, spec__abcmodule_traverse);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_tscmp", base + 0x2a4a80, spec__tscmp);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_importlib__bootstrap_toplevel", base + 0x2a95c0, spec__Py_get_importlib__bootstrap_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_importlib__bootstrap_external_toplevel", base + 0x2a95e0, spec__Py_get_importlib__bootstrap_external_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_zipimport_toplevel", base + 0x2a9604, spec__Py_get_zipimport_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_abc_toplevel", base + 0x2a9628, spec__Py_get_abc_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_codecs_toplevel", base + 0x2a964c, spec__Py_get_codecs_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_io_toplevel", base + 0x2a9670, spec__Py_get_io_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get__collections_abc_toplevel", base + 0x2a96a0, spec__Py_get__collections_abc_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get__sitebuiltins_toplevel", base + 0x2a96c4, spec__Py_get__sitebuiltins_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_genericpath_toplevel", base + 0x2a96e8, spec__Py_get_genericpath_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_ntpath_toplevel", base + 0x2a970c, spec__Py_get_ntpath_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_posixpath_toplevel", base + 0x2a9730, spec__Py_get_posixpath_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_os_toplevel", base + 0x2a9760, spec__Py_get_os_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_site_toplevel", base + 0x2a9784, spec__Py_get_site_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_stat_toplevel", base + 0x2a97a8, spec__Py_get_stat_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_importlib_util_toplevel", base + 0x2a97cc, spec__Py_get_importlib_util_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_importlib_machinery_toplevel", base + 0x2a97f0, spec__Py_get_importlib_machinery_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_runpy_toplevel", base + 0x2a9820, spec__Py_get_runpy_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get___hello___toplevel", base + 0x2a9844, spec__Py_get___hello___toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get___phello___toplevel", base + 0x2a9868, spec__Py_get___phello___toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get___phello___ham_toplevel", base + 0x2a988c, spec__Py_get___phello___ham_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get___phello___ham_eggs_toplevel", base + 0x2a98b0, spec__Py_get___phello___ham_eggs_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get___phello___spam_toplevel", base + 0x2a98e0, spec__Py_get___phello___spam_toplevel);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_get_frozen_only_toplevel", base + 0x2a9904, spec__Py_get_frozen_only_toplevel);
            }
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyPegen_expect_token",
                                        base + 0x0000000000088500, spec__PyPegen_expect_token);
            /* Golden-rule batch 3: more pure-leaf + host-call hotspots. */
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_PyOpcode_num_popped",
                                        base + 0x1e7ef0, spec__PyOpcode_num_popped);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "_Py_normalize_encoding",
                                        base + 0x1652c0, spec__Py_normalize_encoding);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "build_indices_generic",
                                        base + 0x10d960, spec_build_indices_generic);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "build_indices_unicode",
                                        base + 0x10da80, spec_build_indices_unicode);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "delete_index_from_values",
                                        base + 0x10cfa0, spec_delete_index_from_values);
            native_offload_add_prebuilt("libpython3.12.so.1.0", "hashtable_unicode_compare",
                                        base + 0x154b60, spec_hashtable_unicode_compare);
            /* NOTE: _PyPegen_expect_token (PEG parser, hot in compile()) was tried
             * but REVERTED — its slow path calls _PyPegen_fill_token, and that bl
             * fallback to the interpreter corrupts parser state, hanging compile.
             * Same slow-path-fallback trap as _Py_dict_lookup / GC cluster. */
            /* PyErr_Occurred: host-native via direct TLS read (TP+8), solving the
             * TLSDESC-blr blocker. This unblocks the many callers (PEG parser,
             * every C-API op checks it). Gated for A/B. */
            if (getenv("ISH_PYERR_OFF") == NULL)
                native_offload_add_prebuilt("libpython3.12.so.1.0", "PyErr_Occurred",
                                            base + 0x1e3af0, spec_PyErr_Occurred);
            /* NOTE: GC traverse cluster (visit_decref + *_traverse) tried & REVERTED.
             * GC traverse is a mutually-recursive polymorphic call graph over ALL
             * object types; translating a few nodes leaves the rest as interpreter
             * fallbacks that dominate (measured 2x SLOWER). Same recursive-fallback
             * trap as the PEG parser. */
            /* NOTE: the GC/PyErr cluster (~10%, _PyObject_GC_Link etc.) is BLOCKED
             * on the TLSDESC blr that resolves _PyRuntime's TLS offset. Both the
             * per-call interpreter fallback (diverges GC state + slower) and a
             * hardcoded TP-relative offset guess failed correctness. Unblocking it
             * needs faithful TLSDESC-resolver emulation in the nested-call ABI —
             * deferred as high-risk/low-confidence. */
            /* NOTE: _Py_dict_lookup was tried but REVERTED — for non-string keys
             * it calls PyObject_RichCompareBool on every probe, and that call
             * IC-falls back to the interpreter each time, costing more than the
             * offload saves (measured: int-key dict 2.7s→3.1s). A host replacement
             * for RichCompareBool (polymorphic) isn't cheap, so this stays out. */
        }
    }

    /* musl libc string/memory primitives — the biggest single iSH hotspot
     * cluster (~21% of a mixed workload, ~44x slower than native). Pure leaf
     * functions with standard semantics → host-native specs (no fallback risk).
     * musl is PIE; supply its load base via ISH_MUSL_BASE=0x… (from
     * /proc/self/maps; the r-xp segment of /lib/ld-musl-aarch64.so.1).
     * File offsets are for this rootfs's ld-musl-aarch64.so.1. */
    const char *mb = getenv("ISH_MUSL_BASE");
    if (mb && getenv("ISH_MUSL_OFF") == NULL) {
        addr_t m = (addr_t)strtoull(mb, NULL, 0);
        /* Per-function bitmask gate: 1 strlen, 2 memcpy, 4 memmove, 8 memset,
         * 16 memchr. Default 31 = all (strlen's page-overrun bug is now fixed —
         * it reads byte-at-a-time). ISH_MUSL_MASK overrides for isolation. */
        const char *mk = getenv("ISH_MUSL_MASK");
        unsigned mask = mk ? (unsigned)strtoul(mk, NULL, 0) : 31;
        if (mask & 1)  native_offload_add_prebuilt("ld-musl-aarch64.so.1", "strlen",  m + 0x5ecfc, spec_musl_strlen);
        if (mask & 2)  native_offload_add_prebuilt("ld-musl-aarch64.so.1", "memcpy",  m + 0x18290, spec_musl_memcpy);
        if (mask & 4)  native_offload_add_prebuilt("ld-musl-aarch64.so.1", "memmove", m + 0x5e46c, spec_musl_memmove);
        if (mask & 8)  native_offload_add_prebuilt("ld-musl-aarch64.so.1", "memset",  m + 0x18420, spec_musl_memset);
        if (mask & 16) native_offload_add_prebuilt("ld-musl-aarch64.so.1", "memchr",  m + 0x5df50, spec_musl_memchr);

    }
}
