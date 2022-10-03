# Copyright 2022 Cantab Research Ltd.
# Licensed under the MIT license. See LICENSE.txt in the project root for details.

.PHONY: all
all:
	cd build/; \
	cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++; \
	cmake --build .

.PHONY: clean
clean:
	rm -rf build/
