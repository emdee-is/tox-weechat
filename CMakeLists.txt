#
# Copyright (c) 2018 Håvard Pettersson <mail@haavard.me>.
#
# This file is part of Tox-WeeChat.
#
# Tox-WeeChat is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Tox-WeeChat is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Tox-WeeChat.  If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 2.8.12)
project(tox-weechat C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I/usr/local/src/c-toxcore/toxcore -I/var/local/src/c-toxcore/toxav -I/usr/local/src/c-toxcore/toxencryptsave")
set(LD_FLAGS "${LD_FLAGS} -I/usr/local/src/c-toxcore/_build")

add_library(tox MODULE
    src/twc.c
    src/twc-bootstrap.c
    src/twc-chat.c
    src/twc-commands.c
    src/twc-completion.c
    src/twc-config.c
    src/twc-friend-request.c
    src/twc-gui.c
    src/twc-conf-invite.c
    src/twc-list.c
    src/twc-message-queue.c
    src/twc-profile.c
    src/twc-tox-callbacks.c
    src/twc-tfer.c
    src/twc-utils.c)

set_target_properties(tox PROPERTIES
    PREFIX ""  # remove lib prefix (libtox.so -> tox.so)
    C_STANDARD 99)
target_compile_options(tox PRIVATE -Wall -Wextra -Wno-unused-parameter)

# find include and shared library locations
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(WeeChat REQUIRED)
find_package(Tox REQUIRED CORE OPTIONAL_COMPONENTS AV ENCRYPTSAVE)

target_include_directories(tox PRIVATE
    "${WeeChat_INCLUDE_DIRS}"
    "${Tox_INCLUDE_DIRS}")
target_link_libraries(tox "${Tox_LIBRARIES}")

if(Tox_AV_FOUND)
    target_compile_definitions(tox PRIVATE TOXAV_ENABLED)
endif()

if(Tox_ENCRYPTSAVE_FOUND)
    target_compile_definitions(tox PRIVATE TOXENCRYPTSAVE_ENABLED)
endif()

# install plugin binary
set(PLUGIN_PATH "lib/weechat/plugins" CACHE PATH
    "Path to install the plugin binary to.")
install(TARGETS tox DESTINATION "${PLUGIN_PATH}")

