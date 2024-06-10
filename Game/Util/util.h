/*
创建人：神数不神
创建日期：2024-6-10
无修正
*/
#pragma once
namespace GameUtil {
#define ContainAny(x,y) ((x)&(y))
	class Util {
	public:
        template<typename T>
        static void ReleasePointer(T*& point, bool isArray = false) {
            if (point == nullptr) return;
            try {
                isArray ? delete[] point : delete point;
                point = nullptr;
            }
            catch (...) {}
        }

        static void ReleasePointer(void**& point,int size) {
            if (point == nullptr) return;
            for (int i = 0; i < size; ++i) ReleasePointer(point[i]);
            ReleasePointer(point, true);
        }

        template<typename T, typename... Args>
        static T Or(T first, Args... args) {
            return first | Or(args...);
        }
    private:
        template<typename T>
        static T Or(T value) {
            return value;
        }
    };
}