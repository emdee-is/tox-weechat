#!/bin/sh

mkdir _build || exit 1
cd _build

#  -DTox_INCLUDE_DIRS="/usr/local/src/c-toxcore/toxencryptsave /usr/local/src/c-toxcore/toxav /usr/local/src/c-toxcore/toxcore" 
cmake -DPLUGIN_PATH=~/.cache/weechat/plugins -DCMAKE_PREFIX_PATH=/usr/local \
 -DTox_INCLUDE_DIRS="/usr/local/src/c-toxcore" \
 -DTox_LIBRARIES=/usr/local/src/c-toxcore/_build \
    .. >> cmake.log 2>&1 || exit 2$?
make >> make.log 2>&1  || exit 3$?
