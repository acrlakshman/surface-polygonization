///////////////////////////////////////////////////////////////////////////////
// Copyright 2019 Lakshman Anumolu.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///////////////////////////////////////////////////////////////////////////////

#include "marching_cubes/vec3.h"
#include "marching_cubes/utilities.h"

template <typename T>
MARCHING_CUBES::Vec3<T>::Vec3(const T a, const T b, const T c)
{
  m_data[0] = a;
  m_data[1] = b;
  m_data[2] = c;
}

template <typename T>
MARCHING_CUBES::Vec3<T>::Vec3(const std::vector<T> a)
{
  if (a.size() != 3) MARCHING_CUBES_ABORT("While constructing Vec3 object using std::vector, input must be of size 3.");

  m_data[0] = a[0];
  m_data[1] = a[1];
  m_data[2] = a[2];
}

template <typename T>
MARCHING_CUBES::Vec3<T>::Vec3() : Vec3(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0))
{
}

template <typename T>
MARCHING_CUBES::Vec3<T>::~Vec3()
{
}

template <typename T>
const int MARCHING_CUBES::Vec3<T>::size() const
{
  return SIZE;
}

template <typename T>
const double MARCHING_CUBES::Vec3<T>::mag() const
{
  return sqrt(m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2]);
}

template <typename T>
void MARCHING_CUBES::Vec3<T>::normalize()
{
  const auto magnitude = this->mag();

  if (magnitude > 0.)
    for (int i = 0; i < SIZE; ++i) m_data[i] /= magnitude;
}

template <typename T>
const T MARCHING_CUBES::Vec3<T>::min() const
{
  if (m_data[0] < m_data[1] && m_data[0] < m_data[2]) return m_data[0];
  if (m_data[1] < m_data[0] && m_data[1] < m_data[2]) return m_data[1];
  return m_data[2];
}

template <typename T>
const T MARCHING_CUBES::Vec3<T>::operator[](const int idx) const
{
  return m_data[idx];
}

template <typename T>
T& MARCHING_CUBES::Vec3<T>::operator[](const int idx)
{
  return m_data[idx];
}

template <typename T>
void MARCHING_CUBES::Vec3<T>::operator=(const Vec3<T>& vec)
{
  for (int i = 0; i < SIZE; ++i) m_data[i] = vec[i];
}

template <typename T>
bool MARCHING_CUBES::Vec3<T>::operator==(const Vec3<T>& vec) const
{
  return (MARCHING_CUBES::is_equal(m_data[0], vec[0]) && MARCHING_CUBES::is_equal(m_data[1], vec[1]) &&
          MARCHING_CUBES::is_equal(m_data[2], vec[2]));
}

template <typename T>
const MARCHING_CUBES::Vec3<T> MARCHING_CUBES::Vec3<T>::operator+(const Vec3<T>& vec) const
{
  return Vec3<T>(m_data[0] + vec[0], m_data[1] + vec[1], m_data[2] + vec[2]);
}

template <typename T>
const MARCHING_CUBES::Vec3<T> MARCHING_CUBES::Vec3<T>::operator-(const Vec3<T>& vec) const
{
  return Vec3<T>(m_data[0] - vec[0], m_data[1] - vec[1], m_data[2] - vec[2]);
}

template <typename T>
const MARCHING_CUBES::Vec3<T> MARCHING_CUBES::Vec3<T>::operator*(const Vec3<T>& vec) const
{
  return Vec3<T>(m_data[0] * vec[0], m_data[1] * vec[1], m_data[2] * vec[2]);
}

template <typename T>
const MARCHING_CUBES::Vec3<T> MARCHING_CUBES::Vec3<T>::operator*(const T var) const
{
  return Vec3<T>(m_data[0] * var, m_data[1] * var, m_data[2] * var);
}

template <typename T>
const MARCHING_CUBES::Vec3<T> MARCHING_CUBES::Vec3<T>::operator/(const Vec3<T>& vec) const
{
  return Vec3<T>(m_data[0] / vec[0], m_data[1] / vec[1], m_data[2] / vec[2]);
}

template class MARCHING_CUBES::Vec3<int>;
template class MARCHING_CUBES::Vec3<float>;
template class MARCHING_CUBES::Vec3<double>;
template class MARCHING_CUBES::Vec3<size_t>;