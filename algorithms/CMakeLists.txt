include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BUILD_DIR})


set(CMAKE_C_FLAGS "-std=c99")

ADD_EXECUTABLE(two-sum two-sum.c)
ADD_EXECUTABLE(power-of-two power-of-two.c)
ADD_EXECUTABLE(27-remove-element 27-remove-element.c)
