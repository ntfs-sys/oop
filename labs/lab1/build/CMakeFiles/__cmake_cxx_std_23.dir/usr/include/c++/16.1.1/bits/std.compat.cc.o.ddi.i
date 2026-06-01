# 0 "/usr/include/c++/16.1.1/bits/std.compat.cc"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3
# 0 "<command-line>" 2
# 1 "/usr/include/c++/16.1.1/bits/std.compat.cc"
# 24 "/usr/include/c++/16.1.1/bits/std.compat.cc"
module;

# 1 "/usr/include/c++/16.1.1/stdbit.h" 1 3
# 33 "/usr/include/c++/16.1.1/stdbit.h" 3
# 1 "/usr/include/c++/16.1.1/bits/version.h" 1 3
# 51 "/usr/include/c++/16.1.1/bits/version.h" 3
# 1 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 1 3
# 37 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 3
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"

#pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma GCC diagnostic ignored "-Wc++23-extensions"
# 342 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 3
namespace std
{
  typedef long unsigned int size_t;
  typedef long int ptrdiff_t;


  typedef decltype(nullptr) nullptr_t;


#pragma GCC visibility push(default)


  extern "C++" __attribute__ ((__noreturn__, __always_inline__))
  inline void __terminate() noexcept
  {
    void terminate() noexcept __attribute__ ((__noreturn__,__cold__));
    terminate();
  }
#pragma GCC visibility pop
}
# 375 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 3
namespace std
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
namespace __gnu_cxx
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
# 579 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 3
namespace std
{
#pragma GCC visibility push(default)




  __attribute__((__always_inline__))
  constexpr inline bool
  __is_constant_evaluated() noexcept
  {


    if consteval { return true; } else { return false; }






  }
#pragma GCC visibility pop
}
# 623 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 3
namespace std
{
#pragma GCC visibility push(default)

  extern "C++" __attribute__ ((__noreturn__)) __attribute__((__cold__))
  void
  __glibcxx_assert_fail
    (const char* __file, int __line, const char* __function,
     const char* __condition)
  noexcept;
#pragma GCC visibility pop
}
# 733 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 3
# 1 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/os_defines.h" 1 3
# 39 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/os_defines.h" 3
# 1 "/usr/include/features.h" 1 3
# 431 "/usr/include/features.h" 3
# 1 "/usr/include/features-time64.h" 1 3
# 20 "/usr/include/features-time64.h" 3
# 1 "/usr/include/bits/wordsize.h" 1 3
# 21 "/usr/include/features-time64.h" 2 3
# 1 "/usr/include/bits/timesize.h" 1 3
# 19 "/usr/include/bits/timesize.h" 3
# 1 "/usr/include/bits/wordsize.h" 1 3
# 20 "/usr/include/bits/timesize.h" 2 3
# 22 "/usr/include/features-time64.h" 2 3
# 432 "/usr/include/features.h" 2 3
# 540 "/usr/include/features.h" 3
# 1 "/usr/include/sys/cdefs.h" 1 3
# 730 "/usr/include/sys/cdefs.h" 3
# 1 "/usr/include/bits/wordsize.h" 1 3
# 731 "/usr/include/sys/cdefs.h" 2 3
# 1 "/usr/include/bits/long-double.h" 1 3
# 732 "/usr/include/sys/cdefs.h" 2 3
# 541 "/usr/include/features.h" 2 3
# 564 "/usr/include/features.h" 3
# 1 "/usr/include/gnu/stubs.h" 1 3
# 10 "/usr/include/gnu/stubs.h" 3
# 1 "/usr/include/gnu/stubs-64.h" 1 3
# 11 "/usr/include/gnu/stubs.h" 2 3
# 565 "/usr/include/features.h" 2 3
# 40 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/os_defines.h" 2 3
# 734 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 2 3


# 1 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/cpu_defines.h" 1 3
# 737 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 2 3
# 893 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 3
namespace __gnu_cxx
{
  typedef __decltype(0.0bf16) __bfloat16_t;
}
# 962 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 3
# 1 "/usr/include/c++/16.1.1/pstl/pstl_config.h" 1 3
# 963 "/usr/include/c++/16.1.1/x86_64-pc-linux-gnu/bits/c++config.h" 2 3



#pragma GCC diagnostic pop
# 52 "/usr/include/c++/16.1.1/bits/version.h" 2 3
# 34 "/usr/include/c++/16.1.1/stdbit.h" 2 3
# 27 "/usr/include/c++/16.1.1/bits/std.compat.cc" 2
# 1 "/usr/include/c++/16.1.1/stdckdint.h" 1 3
# 33 "/usr/include/c++/16.1.1/stdckdint.h" 3
# 1 "/usr/include/c++/16.1.1/bits/version.h" 1 3
# 34 "/usr/include/c++/16.1.1/stdckdint.h" 2 3
# 28 "/usr/include/c++/16.1.1/bits/std.compat.cc" 2


# 29 "/usr/include/c++/16.1.1/bits/std.compat.cc"
export module std.compat;
export import std;
# 89 "/usr/include/c++/16.1.1/bits/std.compat.cc"
export
{
  using std::isalnum;
  using std::isalpha;

  using std::isblank;

  using std::iscntrl;
  using std::isdigit;
  using std::isgraph;
  using std::islower;
  using std::isprint;
  using std::ispunct;
  using std::isspace;
  using std::isupper;
  using std::isxdigit;
  using std::tolower;
  using std::toupper;
}





export
{

  using std::feclearexcept;
  using std::fegetenv;
  using std::fegetexceptflag;
  using std::fegetround;
  using std::feholdexcept;
  using std::fenv_t;
  using std::feraiseexcept;
  using std::fesetenv;
  using std::fesetexceptflag;
  using std::fesetround;
  using std::fetestexcept;
  using std::feupdateenv;
  using std::fexcept_t;

}





export
{

  using std::imaxabs;
  using std::imaxdiv;
  using std::imaxdiv_t;
  using std::strtoimax;
  using std::strtoumax;

  using std::wcstoimax;
  using std::wcstoumax;


}





export
{
  using std::lconv;
  using std::localeconv;
  using std::setlocale;

}


export
{
  using std::abs;
  using std::acos;
  using std::acosf;
  using std::acosh;
  using std::acoshf;
  using std::acoshl;
  using std::acosl;
  using std::asin;
  using std::asinf;
  using std::asinh;
  using std::asinhf;
  using std::asinhl;
  using std::asinl;
  using std::atan;
  using std::atan2;
  using std::atan2f;
  using std::atan2l;
  using std::atanf;
  using std::atanh;
  using std::atanhf;
  using std::atanhl;
  using std::atanl;
  using std::cbrt;
  using std::cbrtf;
  using std::cbrtl;
  using std::ceil;
  using std::ceilf;
  using std::ceill;
  using std::copysign;
  using std::copysignf;
  using std::copysignl;
  using std::cos;
  using std::cosf;
  using std::cosh;
  using std::coshf;
  using std::coshl;
  using std::cosl;
  using std::double_t;
  using std::erf;
  using std::erfc;
  using std::erfcf;
  using std::erfcl;
  using std::erff;
  using std::erfl;
  using std::exp;
  using std::exp2;
  using std::exp2f;
  using std::exp2l;
  using std::expf;
  using std::expl;
  using std::expm1;
  using std::expm1f;
  using std::expm1l;
  using std::fabs;
  using std::fabsf;
  using std::fabsl;
  using std::fdim;
  using std::fdimf;
  using std::fdiml;
  using std::float_t;
  using std::floor;
  using std::floorf;
  using std::floorl;
  using std::fma;
  using std::fmaf;
  using std::fmal;
  using std::fmax;
  using std::fmaxf;
  using std::fmaxl;
  using std::fmin;
  using std::fminf;
  using std::fminl;
  using std::fmod;
  using std::fmodf;
  using std::fmodl;
  using std::fpclassify;
  using std::frexp;
  using std::frexpf;
  using std::frexpl;
  using std::hypot;
  using std::hypotf;
  using std::hypotl;
  using std::ilogb;
  using std::ilogbf;
  using std::ilogbl;
  using std::isfinite;
  using std::isgreater;
  using std::isgreaterequal;
  using std::isinf;
  using std::isless;
  using std::islessequal;
  using std::islessgreater;
  using std::isnan;
  using std::isnormal;
  using std::isunordered;
  using std::ldexp;
  using std::ldexpf;
  using std::ldexpl;



  using std::lgamma;
  using std::lgammaf;
  using std::lgammal;
  using std::llrint;
  using std::llrintf;
  using std::llrintl;
  using std::llround;
  using std::llroundf;
  using std::llroundl;
  using std::log;
  using std::log10;
  using std::log10f;
  using std::log10l;
  using std::log1p;
  using std::log1pf;
  using std::log1pl;
  using std::log2;
  using std::log2f;
  using std::log2l;
  using std::logb;
  using std::logbf;
  using std::logbl;
  using std::logf;
  using std::logl;
  using std::lrint;
  using std::lrintf;
  using std::lrintl;
  using std::lround;
  using std::lroundf;
  using std::lroundl;
  using std::modf;
  using std::modff;
  using std::modfl;
  using std::nan;
  using std::nanf;
  using std::nanl;
  using std::nearbyint;
  using std::nearbyintf;
  using std::nearbyintl;
  using std::nextafter;
  using std::nextafterf;
  using std::nextafterl;
  using std::nexttoward;
  using std::nexttowardf;
  using std::nexttowardl;
  using std::pow;
  using std::powf;
  using std::powl;
  using std::remainder;
  using std::remainderf;
  using std::remainderl;
  using std::remquo;
  using std::remquof;
  using std::remquol;
  using std::rint;
  using std::rintf;
  using std::rintl;
  using std::round;
  using std::roundf;
  using std::roundl;
  using std::scalbln;
  using std::scalblnf;
  using std::scalblnl;
  using std::scalbn;
  using std::scalbnf;
  using std::scalbnl;
  using std::signbit;
  using std::sin;
  using std::sinf;
  using std::sinh;
  using std::sinhf;
  using std::sinhl;
  using std::sinl;
  using std::sqrt;
  using std::sqrtf;
  using std::sqrtl;
  using std::tan;
  using std::tanf;
  using std::tanh;
  using std::tanhf;
  using std::tanhl;
  using std::tanl;
  using std::tgamma;
  using std::tgammaf;
  using std::tgammal;
  using std::trunc;
  using std::truncf;
  using std::truncl;
# 421 "/usr/include/c++/16.1.1/bits/std.compat.cc"
}


export
{
  using std::jmp_buf;
  using std::longjmp;

}


export
{
  using std::raise;
  using std::sig_atomic_t;
  using std::signal;

}


export
{
  using std::va_list;

}


export
{
  using std::max_align_t;
  using std::nullptr_t;
  using std::ptrdiff_t;
  using std::size_t;
# 470 "/usr/include/c++/16.1.1/bits/std.compat.cc"
}


export
{
  using std::int8_t;
  using std::int16_t;
  using std::int32_t;
  using std::int64_t;
  using std::int_fast16_t;
  using std::int_fast32_t;
  using std::int_fast64_t;
  using std::int_fast8_t;
  using std::int_least16_t;
  using std::int_least32_t;
  using std::int_least64_t;
  using std::int_least8_t;
  using std::intmax_t;
  using std::intptr_t;
  using std::uint8_t;
  using std::uint16_t;
  using std::uint32_t;
  using std::uint64_t;
  using std::uint_fast16_t;
  using std::uint_fast32_t;
  using std::uint_fast64_t;
  using std::uint_fast8_t;
  using std::uint_least16_t;
  using std::uint_least32_t;
  using std::uint_least64_t;
  using std::uint_least8_t;
  using std::uintmax_t;
  using std::uintptr_t;
}


export
{
  using std::clearerr;
  using std::fclose;
  using std::feof;
  using std::ferror;
  using std::fflush;
  using std::fgetc;
  using std::fgetpos;
  using std::fgets;
  using std::FILE;
  using std::fopen;
  using std::fpos_t;
  using std::fprintf;
  using std::fputc;
  using std::fputs;
  using std::fread;
  using std::freopen;
  using std::fscanf;
  using std::fseek;
  using std::fsetpos;
  using std::ftell;
  using std::fwrite;
  using std::getc;
  using std::getchar;
  using std::perror;
  using std::printf;
  using std::putc;
  using std::putchar;
  using std::puts;
  using std::remove;
  using std::rename;
  using std::rewind;
  using std::scanf;
  using std::setbuf;
  using std::setvbuf;
  using std::size_t;
  using std::snprintf;
  using std::sprintf;
  using std::sscanf;
  using std::tmpfile;

  using std::tmpnam;

  using std::ungetc;
  using std::vfprintf;
  using std::vfscanf;
  using std::vprintf;
  using std::vscanf;
  using std::vsnprintf;
  using std::vsprintf;
  using std::vsscanf;
}


export
{
  using std::_Exit;
  using std::abort;
  using std::abs;

  using std::aligned_alloc;


  using std::at_quick_exit;

  using std::atexit;
  using std::atof;
  using std::atoi;
  using std::atol;
  using std::atoll;
  using std::bsearch;
  using std::calloc;
  using std::div;
  using std::div_t;
  using std::exit;
  using std::free;
  using std::getenv;
  using std::labs;
  using std::ldiv;
  using std::ldiv_t;
  using std::llabs;
  using std::lldiv;
  using std::lldiv_t;
  using std::malloc;

  using std::mblen;
  using std::mbstowcs;
  using std::mbtowc;

  using std::qsort;

  using std::quick_exit;

  using std::rand;
  using std::realloc;
  using std::size_t;
  using std::srand;
  using std::strtod;
  using std::strtof;
  using std::strtol;
  using std::strtold;
  using std::strtoll;
  using std::strtoul;
  using std::strtoull;
  using std::system;

  using std::wcstombs;
  using std::wctomb;

}


export
{
  using std::memchr;
  using std::memcmp;
  using std::memcpy;
  using std::memmove;
  using std::memset;
  using std::size_t;
  using std::strcat;
  using std::strchr;
  using std::strcmp;
  using std::strcoll;
  using std::strcpy;
  using std::strcspn;
  using std::strerror;
  using std::strlen;
  using std::strncat;
  using std::strncmp;
  using std::strncpy;
  using std::strpbrk;
  using std::strrchr;
  using std::strspn;
  using std::strstr;
  using std::strtok;
  using std::strxfrm;
}


export
{
  using std::asctime;
  using std::clock;
  using std::clock_t;
  using std::ctime;
  using std::difftime;
  using std::gmtime;
  using std::localtime;
  using std::mktime;
  using std::size_t;
  using std::strftime;
  using std::time;
  using std::time_t;
  using std::tm;

  using std::timespec;
  using std::timespec_get;

}


export
{

  using std::mbrtoc8;
  using std::c8rtomb;


  using std::mbrtoc16;
  using std::c16rtomb;
  using std::mbrtoc32;
  using std::c32rtomb;

}



export
{
  using std::btowc;
  using std::fgetwc;
  using std::fgetws;
  using std::fputwc;
  using std::fputws;
  using std::fwide;
  using std::fwprintf;
  using std::fwscanf;
  using std::getwc;
  using std::getwchar;
  using std::mbrlen;
  using std::mbrtowc;
  using std::mbsinit;
  using std::mbsrtowcs;
  using std::mbstate_t;
  using std::putwc;
  using std::putwchar;
  using std::size_t;
  using std::swprintf;
  using std::swscanf;
  using std::tm;
  using std::ungetwc;
  using std::vfwprintf;

  using std::vfwscanf;


  using std::vswprintf;


  using std::vswscanf;

  using std::vwprintf;

  using std::vwscanf;

  using std::wcrtomb;
  using std::wcscat;
  using std::wcschr;
  using std::wcscmp;
  using std::wcscoll;
  using std::wcscpy;
  using std::wcscspn;
  using std::wcsftime;
  using std::wcslen;
  using std::wcsncat;
  using std::wcsncmp;
  using std::wcsncpy;
  using std::wcspbrk;
  using std::wcsrchr;
  using std::wcsrtombs;
  using std::wcsspn;
  using std::wcsstr;
  using std::wcstod;

  using std::wcstof;

  using std::wcstok;
  using std::wcstol;

  using std::wcstold;
  using std::wcstoll;

  using std::wcstoul;

  using std::wcstoull;

  using std::wcsxfrm;
  using std::wctob;
  using std::wint_t;
  using std::wmemchr;
  using std::wmemcmp;
  using std::wmemcpy;
  using std::wmemmove;
  using std::wmemset;
  using std::wprintf;
  using std::wscanf;
}




export
{
  using std::iswalnum;
  using std::iswalpha;

  using std::iswblank;

  using std::iswcntrl;
  using std::iswctype;
  using std::iswdigit;
  using std::iswgraph;
  using std::iswlower;
  using std::iswprint;
  using std::iswpunct;
  using std::iswspace;
  using std::iswupper;
  using std::iswxdigit;
  using std::towctrans;
  using std::towlower;
  using std::towupper;
  using std::wctrans;
  using std::wctrans_t;
  using std::wctype;
  using std::wctype_t;
  using std::wint_t;
}
