/*
  ZynAddSubFX - a software synthesizer

  AlienWah.cpp - DPF + Zyn Plugin for AlienWah
  Copyright (C) 2015 Filipe Coelho
  Author: Filipe Coelho

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2 or later) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

// DPF includes
#include "../AbstractFX.hpp"

// ZynAddSubFX includes
#include "Effects/Alienwah.h"

/* ------------------------------------------------------------------------------------------------------------
 * AlienWah plugin class */

class AlienWahPlugin : public AbstractPluginFX<Alienwah>
{
public:
    AlienWahPlugin()
        : AbstractPluginFX(11, 4) {}

protected:
   /* --------------------------------------------------------------------------------------------------------
    * Information */

   /**
      Get the plugin label.
      This label is a short restricted name consisting of only _, a-z, A-Z and 0-9 characters.
    */
    const char* getLabel() const override
    {
        return "AlienWah";
    }

   /**
      Get an extensive comment/description about the plugin.
    */
    const char* getDescription() const override
    {
        // TODO
        return "";
    }

   /**
      Get the plugin unique Id.
      This value is used by LADSPA, DSSI and VST plugin formats.
    */
    int64_t getUniqueId() const override
    {
        return d_cconst('Z', 'X', 'a', 'w');
    }

   /* --------------------------------------------------------------------------------------------------------
    * Init */

   /**
      Initialize the parameter @a index.
      This function will be called once, shortly after the plugin is created.
    */
    void initParameter(uint32_t index, Parameter& parameter) override
    {
        parameter.hints = kParameterIsInteger;
        parameter.name  = "";
        parameter.unit  = "";
        parameter.ranges.def = 1.0f;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 127.0f;

        switch (index)
        {
        case 0:
            parameter.hints |= kParameterIsAutomable;
            parameter.name = "LFO Frequency";
            parameter.ranges.def = 70.0f;
            break;

        case 1:
            parameter.hints |= kParameterIsAutomable;
            parameter.name = "LFO Randomness";
            parameter.ranges.def = 0.0f;
            break;

        case 2:
            parameter.hints |= kParameterIsAutomable|kParameterIsBoolean;
            parameter.name = "LFO Type";
            parameter.ranges.def = 0.0f;
            parameter.ranges.max = 1.0f;
            /*
            TODO: support for scalePoints in DPF
            scalePoints[0].label  = "Sine";
            scalePoints[1].label  = "Triangle";
            scalePoints[0].value  = 0.0f;
            scalePoints[1].value  = 1.0f;
            */
            break;

        case 3:
            parameter.hints |= kParameterIsAutomable;
            parameter.name = "LFO Stereo";
            parameter.ranges.def = 62.0f;
            break;

        case 4:
            parameter.hints |= kParameterIsAutomable;
            parameter.name = "Depth";
            parameter.ranges.def = 60.0f;
            break;

        case 5:
            parameter.hints |= kParameterIsAutomable;
            parameter.name = "Feedback";
            parameter.ranges.def = 105.0f;
            break;

        case 6:
            parameter.name = "Delay";
            parameter.ranges.def = 25.0f;
            parameter.ranges.min = 1.0f;
            parameter.ranges.max = 100.0f;
            break;

        case 7:
            parameter.hints |= kParameterIsAutomable;
            parameter.name = "L/R Cross";
            parameter.ranges.def = 0.0f;
            break;

        case 8:
            parameter.hints |= kParameterIsAutomable;
            parameter.name = "Phase";
            parameter.ranges.def = 64.0f;
            break;
        }
    }

   /**
      Set the name of the program @a index.
      This function will be called once, shortly after the plugin is created.
    */
    void initProgramName(uint32_t index, String& programName) override
    {
        switch (index)
        {
        case 0:
            programName = "AlienWah1";
            break;
        case 1:
            programName = "AlienWah2";
            break;
        case 2:
            programName = "AlienWah3";
            break;
        case 3:
            programName = "AlienWah4";
            break;
        default:
            programName = nullptr;
            break;
        }
    }

    DISTRHO_DECLARE_NON_COPY_CLASS(AlienWahPlugin)
};

/* ------------------------------------------------------------------------------------------------------------
 * Create plugin, entry point */

Plugin* createPlugin()
{
    return new AlienWahPlugin();
}