#!/bin/bash
# works only when target binary is compiled with -finstrument-functions

export DYLD_FORCE_FLAT_NAMESPACE=1
export DYLD_INSERT_LIBRARIES=./preload_test.dylib

exec $*

