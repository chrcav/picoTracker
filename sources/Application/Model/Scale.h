/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2018 Discodirt
 * Copyright (c) 2024 xiphonics, inc.
 *
 * This file is part of the picoTracker firmware
 */

#ifndef SCALE_VIEW_H
#define SCALE_VIEW_H

#include "Application/Utils/char.h"
#include <cstdint>

const int numScales = 44;
extern const char *scaleNames[numScales];
extern const bool scaleSteps[numScales][12];

// Function that calculates semitone offset based on scale, position in scale,
// and root note
uint8_t getSemitonesOffset(uint8_t scale, uint8_t number, uint8_t root);

#endif
