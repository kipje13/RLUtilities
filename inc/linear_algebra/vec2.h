#pragma once
#include "vec.h"

template <> 
class vec<2> {
public:
  float x;
  float y;

  vec() = default;

  explicit vec(float value) {
    x = value;
    y = value;
  }

  vec(float x, float y) {
    this->x = x;
    this->y = y;
  }

  vec(std::initializer_list<float> args) {
    int i = 0;
    for (float arg : args) {
      this->operator()(i++) = arg;
      if (i > 2)
        break;
    }
  }

  template <int m> 
  vec(const vec<m> &other) {
    for (int i = 0; i < 2; i++) {
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
    }
  }

  constexpr float operator()(const size_t i) const {
    switch (i) {
    default:
    case 0:
      return x;
    case 1:
      return y;
    }
  }

  bool operator==(const vec<2> &other) const {
	  return x == other.x && y == other.y;
  }

  // elementwise addition
  vec<2> operator+(const vec<2> &other) const {
    return vec<2>(x + other.x, 
                  y + other.y);
  }

  // elementwise multiplication
  vec<2> operator*(const vec<2> &other) const {
    return vec<2>(x * other.x, 
                  y * other.y);
  }

  // in-place elementwise addition
  vec<2> &operator+=(const vec<2> &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  // unary minus
  vec<2> operator-() const { 
    return vec<2>(-x, -y); 
  }

  // elementwise subtraction
  vec<2> operator-(const vec<2> &other) const {
    return vec<2>(x - other.x, 
                  y - other.y);
  }

  // in-place elementwise subtraction
  vec<2> &operator-=(const vec<2> &other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  // in-place scalar addition
  vec<2> &operator+=(const float other) {
    x += other;
    y += other;
    return *this;
  }

  // in-place scalar multiplication
  vec<2> &operator*=(const float other) {
    x *= other;
    y *= other;
    return *this;
  }

  // in-place scalar division
  vec<2> &operator/=(const float other) {
    x /= other;
    y /= other;
    return *this;
  }
};

inline vec<2> cross(const vec<2> &a) {
  return vec<2>(-a(1), a(0));
}

inline float dot(const vec<2> &u, const vec<2> &v) {
  return u.x * v.x + u.y * v.y;
}

inline vec<2> operator*(const vec<2> &v, const float other) {
  return vec<2>(v.x * other, v.y * other);
}

inline vec<2> operator*(const float other, const vec<2> &v) {
  return vec<2>(other * v.x, other * v.y);
}

inline vec<2> operator/(const vec<2> &v, const float other) {
  return vec<2>(v.x / other, v.y / other);
}

inline vec<2> operator/(const float other, const vec<2> &v) {
  return vec<2>(other / v.x, other / v.y);
}

inline vec<2> clamp(const vec<2> &v, const float min_value,
                    const float max_value) {
  return vec<2>(std::clamp(v.x, min_value, max_value),
                std::clamp(v.y, min_value, max_value));
}

typedef vec<2> vec2;
