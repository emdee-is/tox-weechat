/*
 * Copyright (c) 2018 Håvard Pettersson <mail@haavard.me>
 *
 * This file is part of Tox-WeeChat.
 *
 * Tox-WeeChat is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tox-WeeChat is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Tox-WeeChat.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TOX_WEECHAT_BOOTSTRAP_H
#define TOX_WEECHAT_BOOTSTRAP_H

#include <tox/tox.h>

int
twc_bootstrap_dht(Tox *tox, const char *address, uint16_t port,
                  const char *public_key);

int
twc_bootstrap_random_dht(Tox *tox);

int
twc_bootstrap_relay(Tox *tox, const char *address, uint16_t port,
                  const char *public_key);

int
twc_bootstrap_random_relay(Tox *tox);

#endif /* TOX_WEECHAT_BOOTSTRAP_H */
