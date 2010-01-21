/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define LOG_TAG "Netd"

#include <cutils/log.h>

#include <sysutils/NetlinkEvent.h>
#include "NetlinkHandler.h"

NetlinkHandler::NetlinkHandler(int listenerSocket) :
                NetlinkListener(listenerSocket) {
}

NetlinkHandler::~NetlinkHandler() {
}

int NetlinkHandler::start() {
    return this->startListener();
}

int NetlinkHandler::stop() {
    return this->stopListener();
}

void NetlinkHandler::onEvent(NetlinkEvent *evt) {
    const char *subsys = evt->getSubsystem();

    if (!subsys) {
        LOGW("No subsystem found in netlink event");
        return;
    }

    if (!strcmp(subsys, "block")) {
    } else if (!strcmp(subsys, "switch")) {
    } else if (!strcmp(subsys, "battery")) {
    } else if (!strcmp(subsys, "power_supply")) {
    } else {
        LOGE("Dropping %s netlink event", subsys);
    }
}