# TODO 14: Remove mysqrt.cxx from the list of sources


add_library(MathFunctions MathFunctions.cxx)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

if (USE_MYMATH)
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()
