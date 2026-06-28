/**
 * @file ArmMatrix.hpp
 * @brief CMSIS-DSP 矩阵运算封装接口
 */

#pragma once

#include <cstddef>

#include <array>
#include <initializer_list>

#include "arm_math.h"

#include "emdevif/core/concepts.hpp"
#include "rmdev/matrix/matrix_base.hpp"
#include "ArmMatrixTraits.hpp"

namespace rmdev {

/**
 * ArmMatrix 矩阵类，用于封装 CMSIS-DSP 的矩阵操作。
 * @tparam Type 数据类型
 * @tparam row 行数
 * @tparam col 列数
 */
template<typename Type, std::size_t row, std::size_t col>
    requires emdevif::ArithmeticType<Type>
class ArmMatrix
{
public:
    ArmMatrix& operator+(const ArmMatrix& other) = delete;
    ArmMatrix& operator-(const ArmMatrix& other) = delete;
    ArmMatrix& operator*(const ArmMatrix& other) = delete;
    ArmMatrix& operator/(const ArmMatrix& other) = delete;

    ArmMatrix&& trans() = delete;

    constexpr ArmMatrix();

    constexpr ArmMatrix(const ArmMatrix& other);

    explicit constexpr ArmMatrix(MatrixBase type);

    explicit constexpr ArmMatrix(const Type mat_data[row * col]);

    explicit constexpr ArmMatrix(const Type mat_data[row][col]);

    constexpr ArmMatrix(std::initializer_list<Type> mat_data);

    constexpr ArmMatrix(std::initializer_list<std::initializer_list<Type>> mat_data);

    [[nodiscard]] constexpr Type* at(std::size_t r, std::size_t c);

    [[nodiscard]] constexpr const Type* at(std::size_t r, std::size_t c) const;

    [[nodiscard]] constexpr Type& operator()(std::size_t r, std::size_t c);

    [[nodiscard]] constexpr const Type& operator()(std::size_t r, std::size_t c) const;

    [[nodiscard]] constexpr Type det() const;

    constexpr void fill(Type value);

    constexpr void clear();

    constexpr ArmMatrix& operator=(const ArmMatrix& other);

    constexpr ArmMatrix& operator=(std::initializer_list<Type> mat_data);

    constexpr ArmMatrix& operator=(std::initializer_list<std::initializer_list<Type>> mat_data);

    constexpr bool operator==(const ArmMatrix& other) const;

    constexpr bool operator==(std::initializer_list<Type> mat_data) const;

    constexpr bool operator==(std::initializer_list<std::initializer_list<Type>> mat_data) const;

    constexpr bool equ(const ArmMatrix& other) const;

    constexpr bool equ(std::initializer_list<Type> mat_data) const;

    constexpr bool equ(std::initializer_list<std::initializer_list<Type>> mat_data) const;

    constexpr bool equ(const ArmMatrix& other, Type error) const;

    constexpr bool equ(std::initializer_list<Type> mat_data, Type error) const;

    constexpr bool equ(std::initializer_list<std::initializer_list<Type>> mat_data, Type error) const;

    constexpr bool operator!=(const ArmMatrix& other) const;

    constexpr bool operator!=(std::initializer_list<Type> mat_data) const;

    constexpr bool operator!=(std::initializer_list<std::initializer_list<Type>> mat_data) const;

    constexpr bool notequ(const ArmMatrix& other) const;

    constexpr bool notequ(std::initializer_list<Type> mat_data) const;

    constexpr bool notequ(std::initializer_list<std::initializer_list<Type>> mat_data) const;

    constexpr bool notequ(const ArmMatrix& other, Type error) const;

    constexpr bool notequ(std::initializer_list<Type> mat_data, Type error) const;

    constexpr bool notequ(std::initializer_list<std::initializer_list<Type>> mat_data, Type error) const;

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_>
    friend ArmMatrix<Type_, row_, col_>& add(ArmMatrix<Type_, row_, col_>& result,
                                             const ArmMatrix<Type_, row_, col_>& a,
                                             const ArmMatrix<Type_, row_, col_>& b);

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_>
    friend ArmMatrix<Type_, row_, col_>& sub(ArmMatrix<Type_, row_, col_>& result,
                                             const ArmMatrix<Type_, row_, col_>& a,
                                             const ArmMatrix<Type_, row_, col_>& b);

    template<typename Type_, std::size_t rowa, std::size_t cola, std::size_t rowb, std::size_t colb>
        requires emdevif::ArithmeticType<Type_> && MatrixCouldMultiplied<rowa, cola, rowb, colb>
    friend ArmMatrix<Type_, rowa, colb>& mul(ArmMatrix<Type_, rowa, colb>& result,
                                             const ArmMatrix<Type_, rowa, cola>& a,
                                             const ArmMatrix<Type_, rowb, colb>& b);

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_>
    friend ArmMatrix<Type_, row_, col_>& mul(ArmMatrix<Type_, row_, col_>& result,
                                             const ArmMatrix<Type_, row_, col_>& a,
                                             Type_ scalar);

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_>
    friend ArmMatrix<Type_, row_, col_>& mul(ArmMatrix<Type_, row_, col_>& result,
                                             Type_ scalar,
                                             const ArmMatrix<Type_, row_, col_>& a);

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_>
    friend ArmMatrix<Type_, col_, row_>& trans(ArmMatrix<Type_, col_, row_>& result,
                                               const ArmMatrix<Type_, row_, col_>& a);

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_> && SquareMatrix<row_, col_>
    friend ArmMatrix<Type_, row_, col_>* inv(ArmMatrix<Type_, row_, col_>& result, ArmMatrix<Type_, row_, col_>& a);

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_> && SquareMatrix<row_, col_>
    friend ArmMatrix<Type_, row_, col_>* invKeep(ArmMatrix<Type_, row_, col_>& result,
                                                 const ArmMatrix<Type_, row_, col_>& a);

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_>
    friend ArmMatrix<Type_, row_, col_>* div(ArmMatrix<Type_, row_, col_>& result,
                                             const ArmMatrix<Type_, row_, col_>& a,
                                             Type_ scalar);

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_> && SquareMatrix<row_, col_>
    friend ArmMatrix<Type_, row_, col_>* div(ArmMatrix<Type_, row_, col_>& result,
                                             Type_ scalar,
                                             ArmMatrix<Type_, row_, col_>& a);

    template<typename Type_, std::size_t row_, std::size_t col_>
        requires emdevif::ArithmeticType<Type_> && SquareMatrix<row_, col_>
    friend ArmMatrix<Type_, row_, col_>* divKeep(ArmMatrix<Type_, row_, col_>& result,
                                                 Type_ scalar,
                                                 const ArmMatrix<Type_, row_, col_>& a);

    template<typename Type_, std::size_t rowa, std::size_t cola, std::size_t rowb, std::size_t colb>
        requires emdevif::ArithmeticType<Type_> && SquareMatrix<rowb, colb> &&
                 MatrixCouldMultiplied<rowa, cola, rowb, colb>
    friend ArmMatrix<Type_, rowa, colb>* div(ArmMatrix<Type_, rowa, colb>& result,
                                             const ArmMatrix<Type_, rowa, cola>& a,
                                             ArmMatrix<Type_, rowb, colb>& b);

    template<typename Type_, std::size_t rowa, std::size_t cola, std::size_t rowb, std::size_t colb>
        requires emdevif::ArithmeticType<Type_> && SquareMatrix<rowb, colb> &&
                 MatrixCouldMultiplied<rowa, cola, rowb, colb>
    friend ArmMatrix<Type_, rowa, colb>* divKeep(ArmMatrix<Type_, rowa, colb>& result,
                                                 const ArmMatrix<Type_, rowa, cola>& a,
                                                 const ArmMatrix<Type_, rowb, colb>& b);

private:
    std::array<Type, row * col> data{};
    typename ArmMatrixTraits<Type>::ArmMatrixInstance matrix{};
};

}  // namespace rmdev

#include "ArmMatrix.inl"
