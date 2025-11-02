
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-break-next.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-break-next.cpp2"
[[nodiscard]] auto main() -> int;
#line 13 "pure2-bugfix-for-break-next.cpp2"

#line 1 "pure2-bugfix-for-break-next.cpp2"

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-break-next.cpp2"
[[nodiscard]] auto main() -> int{
#line 2 "pure2-bugfix-for-break-next.cpp2"
    std::array<cpp2::i32,4> myarray {0, 1, 2, 3}; 
    auto i {0}; 
    for ( auto const& member : cpp2::move(myarray) )  { do {
        if (member == 0) {
            break;
        }
    } while (false); ++i; }

    std::cout << "i = " << i << std::endl;
    return i; 
}

