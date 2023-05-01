#pragma once

#include "Core.h"
#include "Vector.h"

namespace MWATH {
	template<typename T>
	class Matrix4x4 {
	public:
		inline Matrix4x4(T d) {
			for (uint8 x = 0; x < 4; x++) {
				for (uint8 y = 0; y < 4; y++) {
					data[x][y] = d;
				}
			}
		}

		inline Vec4<T>& GetRow(uint8 index) {
			return Vec4<T>(data[index]);
		}

		inline Vec4<T>& GetColumn(uint8 index) {
			Vec4<T> result(static_cast<T>(0));

			result.x = data[index][0];
			result.y = data[index][1];
			result.z = data[index][2];
			result.w = data[index][3];

			return result;
		}

		inline T* operator [](uint8 x) {
			return data[x];
		}

		inline Matrix4x4<T>& operator*(T scaler) {
			Matrix4x4<T> result(static_cast<T>(0));

			for (uint8 x = 0; x < 4; x++) {
				for (uint8 y = 0; y < 4; y++) {
					result[x][y] = data[x][y] * scaler;
				}
			}

			return result;
		}

		inline Matrix4x4<T>& operator*(Matrix4x4<T>& other) {
			Matrix4x4<T> result(0);

			for (uint8 x = 0; x < 4; x++) {
				for (uint8 y = 0; y < 4; y++) {
					Vec4<T> row = GetRow(x);
					Vec4<T> column = GetColumn(y);

					result[x][y] = Dot(row, column);
				}
			}

			return result;
		}
	private:
		T data[4][4];
	};

	typedef Matrix4x4<float> Float4x4;
}