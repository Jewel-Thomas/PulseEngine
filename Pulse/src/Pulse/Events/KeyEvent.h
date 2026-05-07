#pragma once
#include <sstream>
#include <string>
#include "Event.h"

// All the keyevents are defined here

namespace Pulse {

	class KeyEvent : public Event
	{
	protected:

		int m_KeyCode;

	public:

		KeyEvent(int keyCode)
			: m_KeyCode(keyCode) {} 

		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	};

	class Pulse_API KeyPressedEvent : public KeyEvent
	{
	private:

		int m_RepeatCount;

	public:

		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << GetKeyCode() << " (" << GetRepeatCount() << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	};

	class Pulse_API KeyReleasedEvent : public KeyEvent
	{
	public:

		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << GetKeyCode();
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}