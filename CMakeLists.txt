CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)


SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(test
        unit_test.cpp	
	sub.hpp
        op.hpp
        add.hpp
        mult.hpp
	div.hpp
	pow.hpp
)

ADD_EXECUTABLE(calculator
        main.cpp
	sub.hpp
        op.hpp
        add.hpp
        mult.hpp
	div.hpp
	pow.hpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
