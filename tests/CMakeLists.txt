include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

# If pkg-config is not installed on the system, then the
# CHECK_INSTALL_DIR variable must be set to the install
# location of Check. For example, on Windows, this may
# be: C:/Program Files/check
# set(CHECK_INSTALL_DIR "C:/Program Files/check")

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})

set(TEST_SOURCES
  checkRomanNumCalc.c
)

add_executable(checkRomanNumCalc ${TEST_SOURCES})
target_link_libraries(checkRomanNumCalc romanNumeralCalculator ${CHECK_LIBRARIES})
