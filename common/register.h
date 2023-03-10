/**
 * @file register.h
 * @author Nicolas IRAGNE (nicoragne@hotmail.fr)
 * @brief
 * @date 2022-01-19
 *
 * @copyright Copyright niragne (c) 2022
 */

#pragma once
#include <cstdint>

namespace jacky
{
template <class T>
class Register
{
public:
    Register() = default;
    explicit Register(T value)
        : value(value)
    {
    }
    Register(const Register&)                = default;
    Register(Register&&) noexcept            = default;
    Register& operator=(const Register&)     = default;
    Register& operator=(Register&&) noexcept = default;
    ~Register()                              = default;

    T    get() const { return value; }
    void set(T value) { this->value = value; }

private:
    T value;
};

using Register8  = Register<uint8_t>;
using Register16 = Register<uint16_t>;
using RegisterF  = Register<float>;

} // namespace jacky