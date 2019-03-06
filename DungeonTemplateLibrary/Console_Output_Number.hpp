#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_NUMBER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_NUMBER
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : already checked */

#include <cstddef>
#include <iostream>
#include <string>

//���L�f�[�^
namespace dtl::console::output::tool {

	template<typename Matrix_Int_>
	[[nodiscard]] constexpr auto getOutputNumber(const Matrix_Int_ value_) noexcept {
		return value_;
	}
	template<>
	[[nodiscard]] constexpr auto getOutputNumber<char>(const char value_) noexcept {
		return static_cast<int>(value_);
	}
	template<>
	[[nodiscard]] constexpr auto getOutputNumber<signed char>(const signed char value_) noexcept {
		return static_cast<int>(value_);
	}
	template<>
	[[nodiscard]] constexpr auto getOutputNumber<unsigned char>(const unsigned char value_) noexcept {
		return static_cast<int>(value_);
	}

}

//STL�f�[�^
namespace dtl::console::output::stl {

	//���l�o��
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row][col]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row][col]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//�ʏ�f�[�^
namespace dtl::console::output::normal {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row][col]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row][col]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//�z��f�[�^
namespace dtl::console::output::array {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row * x_ + col]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row * x_ + col]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//�͈�for�f�[�^
namespace dtl::console::output::rangeBasedFor {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_) noexcept {
		for (const auto& row : matrix_) {
			for (const auto& col : row)
				std::cout << dtl::console::output::tool::getOutputNumber(col);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::string& string_) noexcept {
		for (const auto& row : matrix_) {
			for (const auto& col : row)
				std::cout << dtl::console::output::tool::getOutputNumber(col) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//���C���[STL�f�[�^
namespace dtl::console::output::layer::stl {

	//���l�o��
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row][col][layer_]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row][col][layer_]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//���C���[�ʏ�f�[�^
namespace dtl::console::output::layer::normal {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row][col][layer_]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::console::output::tool::getOutputNumber(matrix_[row][col][layer_]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

#endif //Included Dungeon Template Library