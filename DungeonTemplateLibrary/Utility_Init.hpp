/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_INIT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_INIT

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include "Shape_Rect.hpp"

namespace dtl::utility {

	template<typename Matrix_>
	using Init = dtl::shape::Rect<Matrix_>;

}





//STL�f�[�^
namespace dtl::utility::stl {

	//�_���W�������̒l������������
	template<typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col] = value_;
	}
	//�N���X��
	class Init {
	public:
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col] = value_;
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_) const noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col] = value_;
		}
	};

} //namespace

//�ʏ�f�[�^
namespace dtl::utility::normal {

	template<typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = value_;
	}

	//�N���X��
	class Init {
	public:
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col] = value_;
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col] = value_;
		}
	};

} //namespace

//�z��f�[�^
namespace dtl::utility::array {

	template<typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row*x_ + col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row*x_ + col] = value_;
	}

	//�N���X��
	class Init {
	public:
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row*x_ + col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row*x_ + col] = value_;
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row*x_ + col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row*x_ + col] = value_;
		}
	};

} //namespace

//�͈�for�f�[�^
namespace dtl::utility::rangeBasedFor {

	//2�l������
	template<typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row)
				col = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row)
				col = value_;
	}
	//�N���X��
	class Init {
	public:
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_) noexcept {
			for (auto&& row : matrix_)
				for (auto&& col : row)
					col = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
			for (auto&& row : matrix_)
				for (auto&& col : row)
					col = value_;
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_) const noexcept {
			for (auto&& row : matrix_)
				for (auto&& col : row)
					col = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const Matrix_Int_ value_) const noexcept {
			for (auto&& row : matrix_)
				for (auto&& col : row)
					col = value_;
		}
	};

} //namespace

//���C���[STL�f�[�^
namespace dtl::utility::layer::stl {

	//�_���W�������̒l������������
	template<typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col][layer_] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col][layer_] = value_;
	}
	//�N���X��
	class Init {
	public:
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const std::size_t layer_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col][layer_] = value_;
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const std::size_t layer_) const noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col][layer_] = value_;
		}
	};


} //namespace

//���C���[�ʏ�f�[�^
namespace dtl::utility::layer::normal {

	template<typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col][layer_] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::utility::Init class")]] constexpr void init(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col][layer_] = value_;
	}
	//�N���X��
	class Init {
	public:
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr explicit Init(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col][layer_] = value_;
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		[[deprecated("please use dtl::utility::Init class")]] constexpr void operator()(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col][layer_] = value_;
		}
	};

} //namespace

#endif //Included Dungeon Template Library