/* Copyright 2013-2015 Matt Tytel
 *
 * twytch is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * twytch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with twytch.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "synth_gui_interface.h"

#include "twytch_load_save.h"

void SynthGuiInterface::valueChanged(std::string name, mopo::mopo_float value) {
  ScopedLock lock(getCriticalSection());
  getSynth()->getControls()[name]->set(value);
}

void SynthGuiInterface::connectModulation(mopo::ModulationConnection* connection) {
  ScopedLock lock(getCriticalSection());
  getSynth()->connectModulation(connection);
}

void SynthGuiInterface::disconnectModulation(mopo::ModulationConnection* connection) {
  ScopedLock lock(getCriticalSection());
  getSynth()->disconnectModulation(connection);
}

int SynthGuiInterface::getNumActiveVoices() {
  ScopedLock lock(getCriticalSection());
  return getSynth()->getNumActiveVoices();
}

mopo::Processor::Output* SynthGuiInterface::getModSource(std::string name) {
  ScopedLock lock(getCriticalSection());
  return getSynth()->getModulationSource(name);
}

var SynthGuiInterface::saveToVar() {
  return TwytchLoadSave::stateToVar(getSynth(), getCriticalSection());
}

void SynthGuiInterface::loadFromVar(juce::var state) {
  TwytchLoadSave::varToState(getSynth(), getCriticalSection(), state);
  updateFullGui();
}

void SynthGuiInterface::armMidiLearn(std::string name, mopo::mopo_float min, mopo::mopo_float max) {
  getMidiManager()->armMidiLearn(name, min, max);
}

void SynthGuiInterface::cancelMidiLearn() {
  getMidiManager()->cancelMidiLearn();
}

void SynthGuiInterface::clearMidiLearn(std::string name) {
  getMidiManager()->clearMidiLearn(name);
}