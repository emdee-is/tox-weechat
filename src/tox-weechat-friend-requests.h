/*
 * Copyright (c) 2014 Håvard Pettersson <haavard.pettersson@gmail.com>
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

#ifndef TOX_WEECHAT_FRIEND_REQUESTS_H
#define TOX_WEECHAT_FRIEND_REQUESTS_H

#include <stdint.h>

#include <tox/tox.h>

/**
 * Represents a friend request with a Tox ID and a message.
 */
struct t_tox_weechat_friend_request
{
    uint8_t tox_id[TOX_CLIENT_ID_SIZE];
    char *message;

    struct t_tox_weechat_identity *identity;

    struct t_tox_weechat_friend_request *next_request;
    struct t_tox_weechat_friend_request *prev_request;
};

int
tox_weechat_friend_request_add(struct t_tox_weechat_identity *identity,
                               const uint8_t *client_id,
                               const char *message);

void
tox_weechat_accept_friend_request(struct t_tox_weechat_friend_request *request);

struct t_tox_weechat_friend_request *
tox_weechat_friend_request_with_num(struct t_tox_weechat_identity *identity,
                                    unsigned int num);

void
tox_weechat_friend_request_free(struct t_tox_weechat_friend_request *request);

void
tox_weechat_friend_request_free_identity(struct t_tox_weechat_identity *identity);

#endif // TOX_WEECHAT_FRIEND_REQUESTS_H
