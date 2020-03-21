#pragma once
#include "vec.h"

template <> 
class vec<3> {
public:
  float x;
  float y;
  float z;

  vec() = default;

  explicit vec(float value) {
    x = value;
    y = value;
    z = value;
  }

  vec(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  vec(std::initializer_list<float> args) {
    int i = 0;
    for (float arg : args) {
      this->operator()(i++) = arg;
      if (i > 3)
        break;
    }
  }

  template <int m> 
  vec(const vec<m> &other) {
    for (int i = 0; i < 3; i++) {
		this->operator()(i) = (i < m) ? other[i] : 0.0f;
    }
  }

  constexpr float &operator[](const size_t i) { 
	  return this->operator()(i); 
  }

  constexpr float operator[](const size_t i) const {
    return this->operator()(i);
  }

  constexpr float &operator()(const size_t i) {
    switch (i) {
    default:
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    }
  }

  constexpr float operator()(const size_t i) const {
    switch (i) {
    default:
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    }
  }

  bool operator==(const vec<3> &other) const {
	  return x == other.x && y == other.y && z == other.z;
  }

  // elementwise addition
  vec<3> operator+(const vec<3> &other) const {
    return vec<3>(x + other.x, 
                  y + other.y, 
                  z + other.z);
  }

  // elementwise multiplication
  vec<3> operator*(const vec<3> &other) const {
    return vec<3>(x * other.x, 
                  y * other.y, 
                  z * other.z);
  }

  // in-place elementwise addition
  vec<3> &operator+=(const vec<3> &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  // unary minus
  vec<3> operator-() const { 
    return vec<3>(-x, -y, -z); 
  }

  // elementwise subtraction
  vec<3> operator-(const vec<3> &other) const {
    return vec<3>(x - other.x, 
                  y - other.y, 
                  z - other.z);
  }

  // in-place elementwise subtraction
  vec<3> &operator-=(const vec<3> &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  // in-place scalar addition
  vec<3> &operator+=(const float other) {
    x += other;
    y += other;
    z += other;
    return *this;
  }

  // in-place scalar multiplication
  vec<3> &operator*=(const float other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
  }

  // in-place scalar division
  vec<3> &operator/=(const float other) {
    x /= other;
    y /= other;
    z /= other;
    return *this;
  }
};

inline vec<3> cross(const vec<3> &a, const vec<3> &b) {
  return vec<3>(a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x);
}

inline vec<3> cross(const vec<3> &a) {
  return vec<3>(-a(1), a(0), 0.0f);
}

inline float dot(const vec<3> &u, const vec<3> &v) {
  return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline vec<3> operator*(const vec<3> &v, const float other) {
  return vec<3>(v.x * other, v.y * other, v.z * other);
}

inline vec<3> operator*(const float other, const vec<3> &v) {
  return vec<3>(other * v.x, other * v.y, other * v.z);
}

inline vec<3> operator/(const vec<3> &v, const float other) {
  return vec<3>(v.x / other, v.y / other, v.z / other);
}

inline vec<3> operator/(const float other, const vec<3> &v) {
  return vec<3>(other / v.x, other / v.y, other / v.z);
}

inline vec<3> clamp(const vec<3> &v, const float min_value,
                    const float max_value) {
  return vec<3>(std::clamp(v.x, min_value, max_value), 
                std::clamp(v.y, min_value, max_value), 
                std::clamp(v.z, min_value, max_value));
}

typedef vec<3> vec3;