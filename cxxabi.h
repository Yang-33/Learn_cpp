00001 // new abi support -*- C++ -*-
00002   
00003 // Copyright (C) 2000, 2002, 2003, 2004, 2006, 2007, 2009
00004 // Free Software Foundation, Inc.
00005 //
00006 // This file is part of GCC.
00007 //
00008 // GCC is free software; you can redistribute it and/or modify
00009 // it under the terms of the GNU General Public License as published by
00010 // the Free Software Foundation; either version 3, or (at your option)
00011 // any later version.
00012 // 
00013 // GCC is distributed in the hope that it will be useful,
00014 // but WITHOUT ANY WARRANTY; without even the implied warranty of
00015 // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
00016 // GNU General Public License for more details.
00017 // 
00018 // Under Section 7 of GPL version 3, you are granted additional
00019 // permissions described in the GCC Runtime Library Exception, version
00020 // 3.1, as published by the Free Software Foundation.
00021 
00022 // You should have received a copy of the GNU General Public License and
00023 // a copy of the GCC Runtime Library Exception along with this program;
00024 // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
00025 // <http://www.gnu.org/licenses/>.
00026 
00027 // Written by Nathan Sidwell, Codesourcery LLC, <nathan@codesourcery.com>
00028  
00029 /* This file declares the new abi entry points into the runtime. It is not
00030    normally necessary for user programs to include this header, or use the
00031    entry points directly. However, this header is available should that be
00032    needed.
00033    
00034    Some of the entry points are intended for both C and C++, thus this header
00035    is includable from both C and C++. Though the C++ specific parts are not
00036    available in C, naturally enough.  */
00037 
00038 /** @file cxxabi.h
00039  *  The header provides an interface to the C++ ABI.
00040  */
00041 
00042 #ifndef _CXXABI_H
00043 #define _CXXABI_H 1
00044 
00045 #pragma GCC visibility push(default)
00046 
00047 #include <stddef.h>
00048 #include <bits/cxxabi_tweaks.h>
00049 #include <cxxabi-forced.h>
00050  
00051 #ifdef __cplusplus
00052 #define _GLIBCXX_NOTHROW throw() 
00053 #else
00054 #define _GLIBCXX_NOTHROW __attribute__((nothrow))
00055 #endif
00056 
00057 #ifdef __cplusplus
00058 namespace __cxxabiv1
00059 {  
00060   extern "C" 
00061   {
00062 #endif
00063 
00064   typedef __cxa_cdtor_return_type (*__cxa_cdtor_type)(void *);
00065 
00066   // Allocate array.
00067   void* 
00068   __cxa_vec_new(size_t __element_count, size_t __element_size, 
00069         size_t __padding_size, __cxa_cdtor_type constructor,
00070         __cxa_cdtor_type destructor);
00071 
00072   void*
00073   __cxa_vec_new2(size_t __element_count, size_t __element_size,
00074          size_t __padding_size, __cxa_cdtor_type constructor,
00075          __cxa_cdtor_type destructor, void *(*__alloc) (size_t), 
00076          void (*__dealloc) (void*));
00077 
00078   void*
00079   __cxa_vec_new3(size_t __element_count, size_t __element_size,
00080          size_t __padding_size, __cxa_cdtor_type constructor,
00081          __cxa_cdtor_type destructor, void *(*__alloc) (size_t), 
00082          void (*__dealloc) (void*, size_t));
00083 
00084   // Construct array.
00085   __cxa_vec_ctor_return_type
00086   __cxa_vec_ctor(void* __array_address, size_t __element_count,
00087          size_t __element_size, __cxa_cdtor_type constructor,
00088          __cxa_cdtor_type destructor);
00089 
00090   __cxa_vec_ctor_return_type
00091   __cxa_vec_cctor(void* dest_array, void* src_array, size_t element_count, 
00092           size_t element_size, 
00093           __cxa_cdtor_return_type (*constructor) (void*, void*), 
00094           __cxa_cdtor_type destructor);
00095  
00096   // Destruct array.
00097   void 
00098   __cxa_vec_dtor(void* __array_address, size_t __element_count,
00099          size_t __element_size, __cxa_cdtor_type destructor);
00100   
00101   void 
00102   __cxa_vec_cleanup(void* __array_address, size_t __element_count,
00103             size_t __element_size, __cxa_cdtor_type destructor);
00104   
00105   // Destruct and release array.
00106   void 
00107   __cxa_vec_delete(void* __array_address, size_t __element_size,
00108            size_t __padding_size, __cxa_cdtor_type destructor);
00109 
00110   void 
00111   __cxa_vec_delete2(void* __array_address, size_t __element_size,
00112             size_t __padding_size, __cxa_cdtor_type destructor,
00113             void (*__dealloc) (void*));
00114                   
00115   void 
00116   __cxa_vec_delete3(void* __array_address, size_t __element_size,
00117             size_t __padding_size, __cxa_cdtor_type destructor,
00118             void (*__dealloc) (void*, size_t));
00119 
00120   int 
00121   __cxa_guard_acquire(__guard*);
00122 
00123   void 
00124   __cxa_guard_release(__guard*);
00125 
00126   void 
00127   __cxa_guard_abort(__guard*);
00128 
00129   // Pure virtual functions.
00130   void
00131   __cxa_pure_virtual(void);
00132 
00133   // Exception handling.
00134   void
00135   __cxa_bad_cast();
00136 
00137   void
00138   __cxa_bad_typeid();
00139 
00140   // DSO destruction.
00141   int
00142   __cxa_atexit(void (*)(void*), void*, void*) _GLIBCXX_NOTHROW;
00143 
00144   int
00145   __cxa_finalize(void*);
00146 
00147 
00148   /**
00149    *  @brief Demangling routine. 
00150    *  ABI-mandated entry point in the C++ runtime library for demangling.
00151    *
00152    *  @param __mangled_name A NUL-terminated character string
00153    *  containing the name to be demangled.
00154    *
00155    *  @param __output_buffer A region of memory, allocated with
00156    *  malloc, of @a *__length bytes, into which the demangled name is
00157    *  stored.  If @a __output_buffer is not long enough, it is
00158    *  expanded using realloc.  @a __output_buffer may instead be NULL;
00159    *  in that case, the demangled name is placed in a region of memory
00160    *  allocated with malloc.
00161    *
00162    *  @param __length If @a __length is non-NULL, the length of the
00163    *  buffer containing the demangled name is placed in @a *__length.
00164    *
00165    *  @param __status @a *__status is set to one of the following values:
00166    *   0: The demangling operation succeeded.
00167    *  -1: A memory allocation failiure occurred.
00168    *  -2: @a mangled_name is not a valid name under the C++ ABI mangling rules.
00169    *  -3: One of the arguments is invalid.
00170    *
00171    *  @return A pointer to the start of the NUL-terminated demangled
00172    *  name, or NULL if the demangling fails.  The caller is
00173    *  responsible for deallocating this memory using @c free.
00174    *
00175    *  The demangling is performed using the C++ ABI mangling rules,
00176    *  with GNU extensions. For example, this function is used in
00177    *  __gnu_cxx::__verbose_terminate_handler.
00178    * 
00179    *  See http://gcc.gnu.org/onlinedocs/libstdc++/manual/bk01pt12ch39.html
00180    *  for other examples of use.
00181    *
00182    *  @note The same demangling functionality is available via
00183    *  libiberty (@c <libiberty/demangle.h> and @c libiberty.a) in GCC
00184    *  3.1 and later, but that requires explicit installation (@c
00185    *  --enable-install-libiberty) and uses a different API, although
00186    *  the ABI is unchanged.
00187    */
00188   char*
00189   __cxa_demangle(const char* __mangled_name, char* __output_buffer,
00190          size_t* __length, int* __status);
00191 #ifdef __cplusplus
00192   }
00193 } // namespace __cxxabiv1
00194 #endif
00195 
00196 #ifdef __cplusplus
00197 
00198 #include <typeinfo>
00199 
00200 namespace __cxxabiv1
00201 {
00202   // Type information for int, float etc.
00203   class __fundamental_type_info : public std::type_info
00204   {
00205   public:
00206     explicit 
00207     __fundamental_type_info(const char* __n) : std::type_info(__n) { }
00208 
00209     virtual 
00210     ~__fundamental_type_info();
00211   };
00212 
00213   // Type information for array objects.
00214   class __array_type_info : public std::type_info
00215   {
00216   public:
00217     explicit 
00218     __array_type_info(const char* __n) : std::type_info(__n) { }
00219 
00220     virtual 
00221     ~__array_type_info();
00222   };
00223 
00224   // Type information for functions (both member and non-member).
00225   class __function_type_info : public std::type_info
00226   {
00227   public:
00228     explicit 
00229     __function_type_info(const char* __n) : std::type_info(__n) { }
00230 
00231     virtual 
00232     ~__function_type_info();
00233 
00234   protected:
00235     // Implementation defined member function.
00236     virtual bool 
00237     __is_function_p() const;
00238   };
00239 
00240   // Type information for enumerations.
00241   class __enum_type_info : public std::type_info
00242   {
00243   public:
00244     explicit 
00245     __enum_type_info(const char* __n) : std::type_info(__n) { }
00246 
00247     virtual 
00248     ~__enum_type_info();
00249   };
00250 
00251   // Common type information for simple pointers and pointers to member.
00252   class __pbase_type_info : public std::type_info
00253   {
00254   public:
00255     unsigned int        __flags; // Qualification of the target object.
00256     const std::type_info*   __pointee; // Type of pointed to object.
00257 
00258     explicit 
00259     __pbase_type_info(const char* __n, int __quals, 
00260               const std::type_info* __type)
00261     : std::type_info(__n), __flags(__quals), __pointee(__type)
00262     { }
00263     
00264     virtual 
00265     ~__pbase_type_info();
00266 
00267     // Implementation defined type.
00268     enum __masks 
00269       {
00270     __const_mask = 0x1,
00271     __volatile_mask = 0x2,
00272     __restrict_mask = 0x4,
00273     __incomplete_mask = 0x8,
00274     __incomplete_class_mask = 0x10
00275       };
00276 
00277   protected:
00278     __pbase_type_info(const __pbase_type_info&);
00279 
00280     __pbase_type_info&
00281     operator=(const __pbase_type_info&);
00282 
00283     // Implementation defined member functions.
00284     virtual bool 
00285     __do_catch(const std::type_info* __thr_type, void** __thr_obj, 
00286            unsigned int __outer) const;
00287 
00288     inline virtual bool 
00289     __pointer_catch(const __pbase_type_info* __thr_type, void** __thr_obj,
00290             unsigned __outer) const;
00291   };
00292 
00293   // Type information for simple pointers.
00294   class __pointer_type_info : public __pbase_type_info
00295   {
00296   public:
00297     explicit 
00298     __pointer_type_info(const char* __n, int __quals, 
00299             const std::type_info* __type)
00300     : __pbase_type_info (__n, __quals, __type) { }
00301 
00302 
00303     virtual 
00304     ~__pointer_type_info();
00305 
00306   protected:
00307     // Implementation defined member functions.
00308     virtual bool 
00309     __is_pointer_p() const;
00310 
00311     virtual bool 
00312     __pointer_catch(const __pbase_type_info* __thr_type, void** __thr_obj, 
00313             unsigned __outer) const;
00314   };
00315 
00316   class __class_type_info;
00317 
00318   // Type information for a pointer to member variable.
00319   class __pointer_to_member_type_info : public __pbase_type_info
00320   {
00321   public:
00322     __class_type_info* __context;   // Class of the member.
00323 
00324     explicit 
00325     __pointer_to_member_type_info(const char* __n, int __quals,
00326                   const std::type_info* __type, 
00327                   __class_type_info* __klass)
00328     : __pbase_type_info(__n, __quals, __type), __context(__klass) { }
00329 
00330     virtual 
00331     ~__pointer_to_member_type_info();
00332 
00333   protected:
00334     __pointer_to_member_type_info(const __pointer_to_member_type_info&);
00335 
00336     __pointer_to_member_type_info&
00337     operator=(const __pointer_to_member_type_info&);
00338 
00339     // Implementation defined member function.
00340     virtual bool 
00341     __pointer_catch(const __pbase_type_info* __thr_type, void** __thr_obj,
00342             unsigned __outer) const;
00343   };
00344 
00345   // Helper class for __vmi_class_type.
00346   class __base_class_type_info
00347   {
00348   public:
00349     const __class_type_info*    __base_type;  // Base class type.
00350     long            __offset_flags;  // Offset and info.
00351 
00352     enum __offset_flags_masks 
00353       {
00354     __virtual_mask = 0x1,
00355     __public_mask = 0x2,
00356     __hwm_bit = 2,
00357     __offset_shift = 8          // Bits to shift offset.
00358       };
00359   
00360     // Implementation defined member functions.
00361     bool 
00362     __is_virtual_p() const
00363     { return __offset_flags & __virtual_mask; }
00364 
00365     bool 
00366     __is_public_p() const
00367     { return __offset_flags & __public_mask; }
00368 
00369     ptrdiff_t 
00370     __offset() const
00371     { 
00372       // This shift, being of a signed type, is implementation
00373       // defined. GCC implements such shifts as arithmetic, which is
00374       // what we want.
00375       return static_cast<ptrdiff_t>(__offset_flags) >> __offset_shift;
00376     }
00377   };
00378 
00379   // Type information for a class.
00380   class __class_type_info : public std::type_info
00381   {
00382   public:
00383     explicit 
00384     __class_type_info (const char *__n) : type_info(__n) { }
00385 
00386     virtual 
00387     ~__class_type_info ();
00388 
00389     // Implementation defined types.
00390     // The type sub_kind tells us about how a base object is contained
00391     // within a derived object. We often do this lazily, hence the
00392     // UNKNOWN value. At other times we may use NOT_CONTAINED to mean
00393     // not publicly contained.
00394     enum __sub_kind
00395       {
00396     // We have no idea.
00397     __unknown = 0, 
00398 
00399     // Not contained within us (in some circumstances this might
00400     // mean not contained publicly)
00401     __not_contained, 
00402 
00403     // Contained ambiguously.
00404     __contained_ambig, 
00405     
00406     // Via a virtual path.
00407     __contained_virtual_mask = __base_class_type_info::__virtual_mask, 
00408 
00409     // Via a public path.
00410     __contained_public_mask = __base_class_type_info::__public_mask,   
00411 
00412     // Contained within us.
00413     __contained_mask = 1 << __base_class_type_info::__hwm_bit,
00414     
00415     __contained_private = __contained_mask,
00416     __contained_public = __contained_mask | __contained_public_mask
00417       };
00418 
00419     struct __upcast_result;
00420     struct __dyncast_result;
00421 
00422   protected:
00423     // Implementation defined member functions.
00424     virtual bool 
00425     __do_upcast(const __class_type_info* __dst_type, void**__obj_ptr) const;
00426 
00427     virtual bool 
00428     __do_catch(const type_info* __thr_type, void** __thr_obj, 
00429            unsigned __outer) const;
00430 
00431   public:
00432     // Helper for upcast. See if DST is us, or one of our bases. 
00433     // Return false if not found, true if found. 
00434     virtual bool 
00435     __do_upcast(const __class_type_info* __dst, const void* __obj,
00436         __upcast_result& __restrict __result) const;
00437 
00438     // Indicate whether SRC_PTR of type SRC_TYPE is contained publicly
00439     // within OBJ_PTR. OBJ_PTR points to a base object of our type,
00440     // which is the destination type. SRC2DST indicates how SRC
00441     // objects might be contained within this type.  If SRC_PTR is one
00442     // of our SRC_TYPE bases, indicate the virtuality. Returns
00443     // not_contained for non containment or private containment.
00444     inline __sub_kind 
00445     __find_public_src(ptrdiff_t __src2dst, const void* __obj_ptr,
00446               const __class_type_info* __src_type, 
00447               const void* __src_ptr) const;
00448 
00449     // Helper for dynamic cast. ACCESS_PATH gives the access from the
00450     // most derived object to this base. DST_TYPE indicates the
00451     // desired type we want. OBJ_PTR points to a base of our type
00452     // within the complete object. SRC_TYPE indicates the static type
00453     // started from and SRC_PTR points to that base within the most
00454     // derived object. Fill in RESULT with what we find. Return true
00455     // if we have located an ambiguous match.
00456     virtual bool 
00457     __do_dyncast(ptrdiff_t __src2dst, __sub_kind __access_path,
00458          const __class_type_info* __dst_type, const void* __obj_ptr, 
00459          const __class_type_info* __src_type, const void* __src_ptr, 
00460          __dyncast_result& __result) const;
00461     
00462     // Helper for find_public_subobj. SRC2DST indicates how SRC_TYPE
00463     // bases are inherited by the type started from -- which is not
00464     // necessarily the current type. The current type will be a base
00465     // of the destination type.  OBJ_PTR points to the current base.
00466     virtual __sub_kind 
00467     __do_find_public_src(ptrdiff_t __src2dst, const void* __obj_ptr,
00468              const __class_type_info* __src_type,
00469              const void* __src_ptr) const;
00470   };
00471 
00472   // Type information for a class with a single non-virtual base.
00473   class __si_class_type_info : public __class_type_info
00474   {
00475   public:
00476     const __class_type_info* __base_type;
00477 
00478     explicit 
00479     __si_class_type_info(const char *__n, const __class_type_info *__base)
00480     : __class_type_info(__n), __base_type(__base) { }
00481 
00482     virtual 
00483     ~__si_class_type_info();
00484 
00485   protected:
00486     __si_class_type_info(const __si_class_type_info&);
00487 
00488     __si_class_type_info&
00489     operator=(const __si_class_type_info&);
00490 
00491     // Implementation defined member functions.
00492     virtual bool 
00493     __do_dyncast(ptrdiff_t __src2dst, __sub_kind __access_path,
00494          const __class_type_info* __dst_type, const void* __obj_ptr,
00495          const __class_type_info* __src_type, const void* __src_ptr,
00496          __dyncast_result& __result) const;
00497 
00498     virtual __sub_kind 
00499     __do_find_public_src(ptrdiff_t __src2dst, const void* __obj_ptr,
00500              const __class_type_info* __src_type,
00501              const void* __sub_ptr) const;
00502 
00503     virtual bool 
00504     __do_upcast(const __class_type_info*__dst, const void*__obj,
00505         __upcast_result& __restrict __result) const;
00506   };
00507 
00508   // Type information for a class with multiple and/or virtual bases.
00509   class __vmi_class_type_info : public __class_type_info 
00510   {
00511   public:
00512     unsigned int        __flags;  // Details about the class hierarchy.
00513     unsigned int        __base_count;  // Number of direct bases.
00514 
00515     // The array of bases uses the trailing array struct hack so this
00516     // class is not constructable with a normal constructor. It is
00517     // internally generated by the compiler.
00518     __base_class_type_info  __base_info[1];  // Array of bases.
00519 
00520     explicit 
00521     __vmi_class_type_info(const char* __n, int ___flags)
00522     : __class_type_info(__n), __flags(___flags), __base_count(0) { }
00523 
00524     virtual 
00525     ~__vmi_class_type_info();
00526 
00527     // Implementation defined types.
00528     enum __flags_masks 
00529       {
00530     __non_diamond_repeat_mask = 0x1, // Distinct instance of repeated base.
00531     __diamond_shaped_mask = 0x2, // Diamond shaped multiple inheritance.
00532     __flags_unknown_mask = 0x10
00533       };
00534 
00535   protected:
00536     // Implementation defined member functions.
00537     virtual bool 
00538     __do_dyncast(ptrdiff_t __src2dst, __sub_kind __access_path,
00539          const __class_type_info* __dst_type, const void* __obj_ptr,
00540          const __class_type_info* __src_type, const void* __src_ptr,
00541          __dyncast_result& __result) const;
00542 
00543     virtual __sub_kind 
00544     __do_find_public_src(ptrdiff_t __src2dst, const void* __obj_ptr, 
00545              const __class_type_info* __src_type,
00546              const void* __src_ptr) const;
00547     
00548     virtual bool 
00549     __do_upcast(const __class_type_info* __dst, const void* __obj,
00550         __upcast_result& __restrict __result) const;
00551   };
00552 
00553   // Dynamic cast runtime.
00554   // src2dst has the following possible values
00555   //  >-1: src_type is a unique public non-virtual base of dst_type
00556   //       dst_ptr + src2dst == src_ptr
00557   //   -1: unspecified relationship
00558   //   -2: src_type is not a public base of dst_type
00559   //   -3: src_type is a multiple public non-virtual base of dst_type
00560   extern "C" void*
00561   __dynamic_cast(const void* __src_ptr, // Starting object.
00562          const __class_type_info* __src_type, // Static type of object.
00563          const __class_type_info* __dst_type, // Desired target type.
00564          ptrdiff_t __src2dst); // How src and dst are related.
00565 
00566 
00567   // Returns the type_info for the currently handled exception [15.3/8], or
00568   // null if there is none.
00569   extern "C" std::type_info*
00570   __cxa_current_exception_type();
00571 
00572   // A magic placeholder class that can be caught by reference
00573   // to recognize foreign exceptions.
00574   class __foreign_exception
00575   {
00576     virtual ~__foreign_exception() throw();
00577     virtual void __pure_dummy() = 0; // prevent catch by value
00578   };
00579 
00580 } // namespace __cxxabiv1
00581 
00582 /** @namespace abi
00583  *  @brief The cross-vendor C++ Application Binary Interface. A
00584  *  namespace alias to __cxxabiv1, but user programs should use the
00585  *  alias `abi'.
00586  *
00587  *  A brief overview of an ABI is given in the libstdc++ FAQ, question
00588  *  5.8 (you may have a copy of the FAQ locally, or you can view the online
00589  *  version at http://gcc.gnu.org/onlinedocs/libstdc++/faq/index.html#5_8).
00590  *
00591  *  GCC subscribes to a cross-vendor ABI for C++, sometimes
00592  *  called the IA64 ABI because it happens to be the native ABI for that
00593  *  platform.  It is summarized at http://www.codesourcery.com/cxx-abi/
00594  *  along with the current specification.
00595  *
00596  *  For users of GCC greater than or equal to 3.x, entry points are
00597  *  available in <cxxabi.h>, which notes, <em>"It is not normally
00598  *  necessary for user programs to include this header, or use the
00599  *  entry points directly.  However, this header is available should
00600  *  that be needed."</em>
00601 */
00602 namespace abi = __cxxabiv1;
00603 
00604 #endif // __cplusplus
00605 
00606 #pragma GCC visibility pop
00607 
00608 #endif // __CXXABI_H 