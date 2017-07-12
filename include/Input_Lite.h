#pragma once
#include <string>

namespace SL {
    namespace Input_Lite {
        //use already existing codes for special keys
        //https://developer.mozilla.org/en-US/docs/Web/API/KeyboardEvent/keyCode#Constants_for_keyCode_value

        enum SpecialKeyCodes {
            ALTLEFT = 18,
            ALTRIGHT = 18,
            CAPSLOCK = 20,
            CONTROLLEFT = 17,
            CONTROLRIGHT = 17,
            OSLEFT = 91,
            OSRIGHT = 92,
            SHIFTLEFT = 16,
            SHIFTRIGHT = 16,
            CONTEXTMENU = 93,
            ENTER = 13,
            SPACE = 32,
            TAB = 9,
            DELETE = 46,
            END = 35,
            HOME = 36,
            INSERT = 45,
            PAGEDOWN = 34,
            PAGEUP = 33,
            ARROWDOWN = 40,
            ARROWLEFT = 37,
            ARROWRIGHT = 39,
            ARROWUP = 38,
            ESCAPE = 27,
#ifdef WIN32
            PRINTSCREEN = 44,
#elif __APPLE__
            PRINTSCREEN = 124,
#elif __linux__
            PRINTSCREEN = 42,
#endif 
#if  __APPLE__
            SCROLLLOCK = 125,
#else 
            SCROLLLOCK = 145,
#endif 
#if  __APPLE__
            PAUSE = 19,
#else 
            PAUSE = 126,
#endif 
            F1 = 112,
            F2 = 113,
            F3 = 114,
            F4 = 115,
            F5 = 116,
            F6 = 117,
            F7 = 118,
            F8 = 119,
            F9 = 120,
            F10 = 121,
            F11 = 122,
            F12 = 123,
            F13 = 124,
            F14 = 125,
            F15 = 126,
            F16 = 127,
            F17 = 128,
            F18 = 129,

#if  !__linux__
            F19 = 130,
            F20 = 131,
#endif 
#if  WIN32
            F21 = 132,
            F22 = 133,
            F23 = 134,
            F24 = 135
#endif 

        };























        void SendKeyUp(char key);
        void SendKeyUp(wchar_t key);
        template <class T> void SendKeyUp(T) = delete;

        void SendKeyDown(char key);
        void SendKeyDown(wchar_t key);
        template <class T> void SendKeyDown(T) = delete;

        inline void SendKey(char key) {
            SendKeyDown(key);
            SendKeyUp(key);
        }
        inline void SendKey(wchar_t key) {
            SendKeyDown(key);
            SendKeyUp(key);
        }
        template <class T> void SendKey(T) = delete;

        inline void SendKeys(std::string keys) {
            for (auto k : keys) {
                SendKey(k);
            }
        }

        inline void SendKeys(std::wstring keys) {
            for (auto k : keys) {
                SendKey(k);
            }
        }
        template<typename T, size_t ELEMENTSIZE>inline void SendKeys(T(&keys)[ELEMENTSIZE]) {
            for (auto k : keys) {
                SendKey(k);
            }
        }
        template <class T> void SendKeys(T) = delete;
    }
}