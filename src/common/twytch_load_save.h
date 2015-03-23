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

#ifndef TWYTCH_LOAD_SAVE_H
#define TWYTCH_LOAD_SAVE_H

#include "JuceHeader.h"

#include "twytch_engine.h"

class TwytchLoadSave {
  public:
    static var stateToVar(mopo::TwytchEngine* synth,
                          const CriticalSection& critical_section);
  
    static void varToState(mopo::TwytchEngine* synth,
                           const CriticalSection& critical_section,
                           var state);
};

#endif  // TWYTCH_LOAD_SAVE_H
