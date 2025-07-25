/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2024 xiphonics, inc.
 *
 * This file is part of the picoTracker firmware
 */

#ifndef _ETL_PROFILE_H_
#define _ETL_PROFILE_H_

#define ETL_TARGET_DEVICE_GENERIC
#define ETL_TARGET_OS_NONE
#define ETL_CPP11_SUPPORTED 1
#define ETL_CPP14_SUPPORTED 1
#define ETL_CPP17_SUPPORTED 1
#define ETL_CHECK_PUSH_POP

#ifdef ETL_DEBUG
#define ETL_LOG_ERRORS
#define ETL_VERBOSE_ERRORS
#endif

#endif
