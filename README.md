# Tox-WeeChat
Tox-WeeChat is a [Tox][1] protocol plugin for [WeeChat][2]. It is functional,
but lacks certain features that might be expected of a full-fledged Tox client.
Originally from the abandonned https://github.com/haavard/tox-weechat

Tox-WeeChat is compliant with all "Required" points in the 
[Tox Client Standard][3]. There is no support for NGC groups.

## Features

 - One-to-one chats
 - Conference chats (text only)
 - Proxy support
 - Multiple profiles
 - Encrypted save files
 - File transfer

No NGC groups yet.

## Installation

Tox-WeeChat requires [WeeChat][2] (tested with version 4.1.2) and [TokTok
c-toxcore][4] (tested with version 0.2.18). CMake 2.8.12 or newer is also
required to build. 

Installation is fairly simple; after getting the source code, compile
and install using CMake:

    $ mkdir build && cd build
    $ cmake -DPLUGIN_PATH=~/.cache/weechat/plugins ..
    $ make install

This installs the plugin binary `tox.so` to the recommended location
`~/.cache/weechat/plugins`. The default location is `/usr/local/lib/weechat/plugins`.

If WeeChat or toxcore are installed in a non-standard location, you can try
specifying `CMAKE_PREFIX_PATH` to find them; see [.travis.yml](.travis.yml) for
an example.

## Usage
 - If the plugin does not load automatically, load it with `/plugin load tox`.
   You may have to specify the full path to the plugin binary if you installed
   it to a non-standard location.
 - Create a new profile with `/tox create <profile name>`. The data file is
   stored in `~/.cache/weechat/tox/` by default.
 - Load your profile and connect to the Tox network with
   `/tox load <profile name>` (see also /bootstrap,  /conf, /friend, /invite, 
   /me, /msg, /myid, /name, /names, /nospam, /part, /send,
   /status, /statusmsg, /topic, /tox).
 - Run `/help -listfull tox` to get a list of all available commands, and
   `/set tox.*` for a list of options, including proxies.

### Common issues

#### Long Tox names messing up WeeChat layout

Tox allows names up to 128 bytes long. To prevent long names from taking all
your screen space, you can set the following options in WeeChat:
 - `weechat.bar.nicklist.size_max`
 - `weechat.look.prefix_align_max`
 - `buffers.look.name_size_max` (if using buffers.pl)

#### Tox won't connect through my proxy

Make sure the proxy type, address and port is correct, and that UDP is
disabled (`/set tox.profile.*.udp`) and it is required to disable IPv6
(`/set tox.profile.*.ipv6`).

## License
Copyright (c) 2018 Håvard Pettersson <mail@haavard.me>

This file is part of Tox-WeeChat.

Tox-WeeChat is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Tox-WeeChat is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tox-WeeChat.  If not, see <http://www.gnu.org/licenses/>.

[1]: http://tox.chat
[2]: http://weechat.org
[3]: https://github.com/Tox/Tox-Client-Standard
[4]: https://github.com/TokTok/c-toxcore

---

This is a hard fork of https://github.com/haavard/tox-weechat/
now at https://git.plastiras.org/emdee/tox-weechat You can also run weechat under
toxygen https://git.plastiras.org/emdee/toxygen using qweechat 
https://git.plastiras.org/emdee/qweechat
