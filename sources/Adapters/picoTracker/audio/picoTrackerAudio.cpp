/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2024 xiphonics, inc.
 *
 * This file is part of the picoTracker firmware
 */

#include "picoTrackerAudio.h"
#include "Services/Audio/AudioOutDriver.h"
#include "System/Console/Trace.h"
#include "picoTrackerAudioDriver.h"

picoTrackerAudio::picoTrackerAudio(AudioSettings &hints) : Audio(hints) {
  hints_ = hints;
}

picoTrackerAudio::~picoTrackerAudio() {}

void picoTrackerAudio::Init() {
  AudioSettings settings;
  settings.audioAPI_ = GetAudioAPI();

  settings.bufferSize_ = GetAudioBufferSize();
  settings.preBufferCount_ = GetAudioPreBufferCount();

  alignas(picoTrackerAudioDriver) static char
      audioDriver[sizeof(picoTrackerAudioDriver)];
  picoTrackerAudioDriver *drv =
      new (audioDriver) picoTrackerAudioDriver(settings);
  alignas(AudioOutDriver) static char audioOutDriver[sizeof(AudioOutDriver)];
  AudioOutDriver *out = new (audioOutDriver) AudioOutDriver(*drv);
  Insert(out);
};

void picoTrackerAudio::Close() {
  for (Begin(); !IsDone(); Next()) {
    AudioOut &current = CurrentItem();
    current.Close();
  }
};

void picoTrackerAudio::SetMixerVolume(int v) {
  AudioOutDriver *out = (AudioOutDriver *)GetFirst();
  if (out) {
    picoTrackerAudioDriver *drv = (picoTrackerAudioDriver *)out->GetDriver();
    drv->SetVolume(v);
  }
}

int picoTrackerAudio::GetMixerVolume() {
  AudioOutDriver *out = (AudioOutDriver *)GetFirst();
  if (out) {
    picoTrackerAudioDriver *drv = (picoTrackerAudioDriver *)out->GetDriver();
    return drv->GetVolume();
  }
  return 0;
}
