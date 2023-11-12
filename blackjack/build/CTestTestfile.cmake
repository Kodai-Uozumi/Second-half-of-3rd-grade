# CMake generated Testfile for 
# Source directory: /media/sf_share/blackjack
# Build directory: /media/sf_share/blackjack/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(blackjack_test "/media/sf_share/blackjack/build/tests/judge_test.out")
set_tests_properties(blackjack_test PROPERTIES  _BACKTRACE_TRIPLES "/media/sf_share/blackjack/CMakeLists.txt;56;add_test;/media/sf_share/blackjack/CMakeLists.txt;0;")
subdirs("src")
subdirs("tests")
