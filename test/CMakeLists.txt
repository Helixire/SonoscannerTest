cmake_minimum_required(VERSION 3.14)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  sono_test
  ""
)

message("${PROJECT_SOURCE_DIR}/test/data")

add_custom_command(TARGET sono_test POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${PROJECT_SOURCE_DIR}/test/data"
	"$<TARGET_FILE_DIR:sono_test>/data")

target_sources(sono_test
	PRIVATE
	ParserFileTest.cpp
	ParserFolderTest.cpp
)

target_link_libraries(
  sono_test
  PUBLIC
	gtest_main
	sono_lib
)

include(GoogleTest)
gtest_discover_tests(sono_test)

