/*
    OrangeLine.hpp

    Include file containing all #defines for constants and macros
	common to all OrangeLine moduls

	Should not included in <module_name>.cpp because this is done in OrangeLineCommon.hpp

Copyright (C) 2019 Dieter Stubler

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef ORANGE_LINE_HPP
#define ORANGE_LINE_HPP

#include "plugin.hpp"

#define ORANGE			nvgRGB(255, 102, 0)
#define WHITE			nvgRGB(255, 255, 255)

#define STYLE_ORANGE	0
#define STYLE_BRIGHT	1
#define STYLE_DARK		2

#define STATE_TYPE_VALUE   0
#define STATE_TYPE_VOLTAGE 0
#define STATE_TYPE_TRIGGER 1

#define POLY_CHANNELS	  16

#define LIGHT_TYPE_SINGLE  0
#define LIGHT_TYPE_RGB     1

#define NUM_STATES					(NUM_JSONS + NUM_PARAMS + NUM_INPUTS + NUM_OUTPUTS + NUM_LIGHTS)
#define NUM_TRIGGERS				(NUM_PARAMS + NUM_INPUTS)

//#define PRECISION       0.0000000001f
#define PRECISION       0.000001f

#define MAX_TEXT_SIZE  64
#define TEXT_SCROLL_DELAY   22050
#define TEXT_SCROLL_PRE_DELAY   TEXT_SCROLL_DELAY * 4

#define stateIdxJson(i)				(i)
#define stateIdxParam(i)			(NUM_JSONS + (i))
#define stateIdxInput(i)			(NUM_JSONS + NUM_PARAMS + (i))
#define stateIdxOutput(i)			(NUM_JSONS + NUM_PARAMS + NUM_INPUTS + (i))
#define stateIdxLight(i)			(NUM_JSONS + NUM_PARAMS + NUM_INPUTS + NUM_OUTPUTS + (i))

#define changeJson(i)				OL_outStateChange[stateIdxJson   (i)]
#define inChangeParam(i)			OL_inStateChange [stateIdxParam  (i)]
#define changeParam(i)				OL_outStateChange[stateIdxParam  (i)]
#define changeInput(i)				OL_inStateChange [stateIdxInput  (i)]
#define changeOutput(i)				OL_outStateChange[stateIdxOutput (i)]
#define changeLight(i)				OL_outStateChange[stateIdxLight  (i)]

#define getStateJson(i)   			OL_state[stateIdxJson   (i)]
#define getStateParam(i)			OL_state[stateIdxParam  (i)]
#define getStateInput(i)			OL_state[stateIdxInput  (i)]
#define getStateOutput(i)			OL_state[stateIdxOutput (i)]
#define getStateLight(i)			OL_state[stateIdxLight  (i)]

#define setStateJson(i, v)			OL_setOutState (stateIdxJson   (i), v)
#define setInStateParam(i, v)		OL_setInState  (stateIdxParam  (i), v)
#define setStateParam(i, v)			OL_setOutState (stateIdxParam  (i), v)
#define setStateInput(i, v)			OL_setInState  (stateIdxInput  (i), v)
#define setStateOutput(i, v)		OL_setOutState (stateIdxOutput (i), v)
#define setStateLight(i, v)			OL_setOutState (stateIdxLight  (i), v) 

#define getStateTypeParam(i)		OL_stateType[stateIdxParam  (i)]
#define getStateTypeInput(i)		OL_stateType[stateIdxInput  (i)]
#define getStateTypeOutput(i)		OL_stateType[stateIdxOutput (i)]
#define getStateTypeLight(i)		OL_stateType[stateIdxLight  (i)]

#define setStateTypeParam(i, t)		(OL_stateType[stateIdxParam  (i)] = (t))
#define setStateTypeInput(i, t)		(OL_stateType[stateIdxInput  (i)] = (t))
#define setStateTypeOutput(i, t)	(OL_stateType[stateIdxOutput (i)] = (t))
#define setStateTypeLight(i, t)		(OL_stateType[stateIdxLight  (i)] = (t))

#define maxStateIdxJson				(stateIdxParam  (0) - 1)
#define maxStateIdxParam			(stateIdxInput  (0) - 1)
#define maxStateIdxInput			(stateIdxOutput (0) - 1)
#define maxStateIdxOutput			(stateIdxLight  (0) - 1)
#define maxStateIdxLight			(NUM_STATES - 1)

#define getCustomChangeMask(i)		OL_customChangeMask[i]
#define getCustomChangeMaskParam(i)	getCustomChangeMask(i)
#define getCustomChangeMaskInput(i)	getCustomChangeMask(NUM_PARAMS + (i))

#define setCustomChangeMask(i, v)	(OL_customChangeMask[i] = (v))
#define setCustomChangeMaskParam(i, v)	setCustomChangeMask((i), (v))
#define setCustomChangeMaskInput(i, v)	setCustomChangeMask(NUM_PARAMS + (i), (v))

#define setInPoly(i, v)				(OL_isPoly[i] = (v))
#define setOutPoly(i, v)			(OL_isPoly[NUM_INPUTS + i] = (v))
#define getInPoly(i)				OL_isPoly[i]
#define getOutPoly(i)				OL_isPoly[NUM_INPUTS + i]

#define setOutPolyChannels(i, v)	(OL_polyChannels[i] = (v))
#define getOutPolyChannels(i)		OL_polyChannels[i]

#define customChangeBits			OL_customChangeBits

#define isGate(i)                   OL_isGate[i]
#define getInputConnected(i)		OL_inputConnected[i]
#define initialized					OL_initialized

#define quantize(CV) 				(round (CV * 12.f) / 12.f)
#define octave(CV)					int(floor (quantize (CV)))
#define note(CV)					(int(round ((CV + 10) * 12)) % 12)

#define reConfigParam(paramId, minVal, maxVal, defaultVal, pLabel) { \
	ParamQuantity *pq = paramQuantities[paramId]; \
	pq->minValue = minVal; \
	pq->maxValue = maxVal; \
	pq->defaultValue = defaultVal; \
	pq->label = pLabel; \
}

#define reConfigParamDefault(paramId, defaultVal) { \
	ParamQuantity *pq = paramQuantities[paramId]; \
	pq->defaultValue = defaultVal; \
}

#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

// ********************************************************************************************************************************
/**
	Widgets
*/

/**
	Widget to display cvOct values as floats or notes
*/
struct NumberWidget : TransparentWidget {

	std::shared_ptr<Font> pFont;

    Module     *module = nullptr;
	float      *pValue = nullptr;
 	const char *format = nullptr;
	char       *buffer = nullptr;
	int         length = 0;
	float       defaultValue = 0.f;
	float	   *pStyle = nullptr;

    static NumberWidget* create (Vec pos, Module *module, float *pValue, float defaultValue, const char *format, char *buffer, int length) {
        NumberWidget *w = new NumberWidget();

		w->pFont    = APP->window->loadFont(asset::plugin(pluginInstance, "res/repetition-scrolling.regular.ttf"));
        w->box.pos  = pos;
        w->box.size = mm2px (Vec (4 * length, 7));
        w->module   = module;
        w->pValue   = pValue;
        w->format   = format;
        w->buffer   = buffer;
        w->length   = length;

        return w;
    }
	/**
		Constructor
	*/
	NumberWidget () {
	}

	void draw (const DrawArgs &drawArgs) override {
		nvgFontFaceId (drawArgs.vg, pFont->handle);
		nvgFontSize (drawArgs.vg, 18);
		nvgFillColor (drawArgs.vg, (pStyle == nullptr || *pStyle == STYLE_ORANGE) ? ORANGE : WHITE);
        float value = pValue != nullptr ? *pValue : defaultValue;
        snprintf (buffer, length + 1, format, value);
        buffer[length] = '\0';
		nvgText (drawArgs.vg, 0, 0, buffer, nullptr);
	}
};

/**
	Widget to display cvOct values as floats or notes
*/
struct TextWidget : TransparentWidget {

	std::shared_ptr<Font> pFont;

    Module     *module = nullptr;
	const char *text   = nullptr;
	int         length = 0;
	int	        scrollPos = 0;
	int        *pTimer;
	const char *defaultText = nullptr;
	float	   *pStyle = nullptr;
	bool		reset = false;

    static TextWidget* create (Vec pos, Module *module, const char *text, const char * defaultText, int length, int *pTimer) {
        TextWidget *w = new TextWidget();

		w->pFont    = APP->window->loadFont(asset::plugin(pluginInstance, "res/repetition-scrolling.regular.ttf"));
        w->box.pos  = pos;
        w->box.pos.y  -= mm2px (5);
        w->box.size = mm2px (Vec (4 * length, 7));
        w->module   = module;
        w->text     = text;
        w->defaultText  = defaultText;
        w->length   = length;
		w->pTimer   = pTimer;

        return w;
    }

	/**
		Constructor
	*/
	TextWidget () {
	}

	void draw (const DrawArgs &drawArgs) override {
		const char *delimiter = " - ";
		char buf[MAX_TEXT_SIZE * 2 + 1 + 3 /* delimiter length */];
        const char* str = (text != nullptr ? text : defaultText);
		int len = strlen(str);
		if (len > MAX_TEXT_SIZE)
			len = MAX_TEXT_SIZE;
		nvgFontFaceId (drawArgs.vg, pFont->handle);
		nvgFontSize (drawArgs.vg, 18);
		nvgFillColor (drawArgs.vg, (pStyle == nullptr || *pStyle == STYLE_ORANGE) ? ORANGE : WHITE);

		if (len <= length) {
			nvgText (drawArgs.vg, 0, mm2px (5), str, nullptr);
		}
		else {
			if (pTimer != nullptr && len > length) {
				if (*pTimer <= 0) {
					*pTimer = TEXT_SCROLL_DELAY;
					scrollPos = (scrollPos + 1) % (len + 3);
				}
				else {
					if (*pTimer > TEXT_SCROLL_DELAY) {
						if (!reset) {
							reset = true;
							scrollPos = 0;
						}
					}
					else {
						reset = false;
					}
				}
			}
			strncpy (buf, str, len);
			strcpy (buf + len, delimiter);
			strncpy (buf + len + 3 /* delimiter length */, str, len);
			buf[MAX_TEXT_SIZE * 2 + 3] = '\0';
			buf[scrollPos + length] = '\0';
			nvgText (drawArgs.vg, 0, mm2px (5), buf + scrollPos, nullptr);
		}
	}
};

#endif
