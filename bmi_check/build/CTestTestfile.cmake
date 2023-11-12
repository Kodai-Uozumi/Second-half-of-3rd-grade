# CMake generated Testfile for 
# Source directory: /media/sf_share/bmi_check
# Build directory: /media/sf_share/bmi_check/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unittest "/media/sf_share/bmi_check/build/tests/bmi_check_test.out")
set_tests_properties(unittest PROPERTIES  _BACKTRACE_TRIPLES "/media/sf_share/bmi_check/CMakeLists.txt;56;add_test;/media/sf_share/bmi_check/CMakeLists.txt;0;")
subdirs("src")
subdirs("tests")
