#pragma once

#include "Event.h"

#include <sstream>

namespace GameEngine {

    class GAME_ENGINE_API KeyEvent : public Event {
    public:
        inline int32_t GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(int32_t keycode) : m_KeyCode(keycode) {}

        int m_KeyCode;
    };

    class GAME_ENGINE_API KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int32_t keycode, int32_t repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        inline int32_t GetRepeatCout() const { return m_RepeatCount; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << GetKeyCode() << " (" << GetRepeatCout() << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int32_t m_RepeatCount;
    };

    class GAME_ENGINE_API KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int32_t keycode) : KeyEvent(keycode) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << GetKeyCode();
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}
