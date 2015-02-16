GTEST_SOURCE_DIR=../gtest/gtest-1.7.0/
GTEST_INCLUDE_DIR=$(GTEST_SOURCE_DIR)/include/
GTEST_LIB_DIR=$(GTEST_SOURCE_DIR)lib/.libs/

all:
	g++ -g -I. -o mul.out main.c 
unittest:
	g++ -g -L$(GTEST_LIB_DIR) -lgtest -lpthread -I. -I$(GTEST_INCLUDE_DIR) -o test.out testfun.c
	./test.out
