add_library(platform_timer
  advTimer.h advTimer.cpp
)

target_link_libraries(platform_timer
  PUBLIC system_timer
  PUBLIC foundation
)

target_include_directories(platform_timer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
  ${PROJECT_SOURCE_DIR}
)

