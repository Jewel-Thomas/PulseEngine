#pragma once
#include "Event.h"

namespace Pulse {

	class MouseButtonEvent : public Event
	{
	protected:
		int m_MouseButton;

	public:

		MouseButtonEvent(int mouseButton)
			: m_MouseButton(mouseButton) {}

		inline int GetMouseButton() const { return m_MouseButton; }
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouseButton)
	};

	class Pulse_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonPressedEvent(int mouseButton)
			: MouseButtonEvent(mouseButton) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent : " << GetMouseButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class Pulse_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonReleasedEvent(int mouseButton)
			: MouseButtonEvent(mouseButton) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent : " << GetMouseButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class Pulse_API MouseMovedEvent : public Event
	{
	private:
		float m_MouseX, m_MouseY;

	public:

		MouseMovedEvent(float mouseX, float mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent : " << "(" << GetX() << ", " << GetY() << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		
		EVENT_CLASS_TYPE(MouseMoved)
	};

	class Pulse_API MouseScrolledEvent : public Event
	{
	private:
		float m_OffsetX, m_OffsetY;

	public:

		MouseScrolledEvent(float offsetX, float offsetY)
			: m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		inline float GetOffsetX() const { return m_OffsetX; }
		inline float GetOffsetY() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent : " << "(" << GetOffsetX() << ", " << GetOffsetY() << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

		EVENT_CLASS_TYPE(MouseScrolled)
	};

}
