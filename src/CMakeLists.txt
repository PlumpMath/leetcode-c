include_directories(
  ${CMOCKA_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BUILD_DIR})

# loop through all c files
file(GLOB files "*.c")
foreach(file ${files})
  get_filename_component (exe ${file} NAME_WE)
  ADD_EXECUTABLE(${exe} ${file})
  TARGET_LINK_LIBRARIES(${exe} cmocka)
  add_test(${exe} ${exe})
endforeach()