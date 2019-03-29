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

	//�}�X���w�肵�����l�Ŗ��߂�
	template<typename Matrix_Int_>
	class Init {
	private:


		///// �G�C���A�X /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;


		///// �����o�ϐ� /////

		Index_Size point_x{};
		Index_Size point_y{};
		Index_Size width{};
		Index_Size height{};
		Matrix_Int_ draw_value{};


		///// ������� /////

		template<typename Matrix_>
		constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			matrix_[point_y_][point_x_] = draw_value;
		}
		template<typename Matrix_>
		constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			matrix_[point_y_ * max_x_ + point_x_] = draw_value;
		}
		template<typename Matrix_>
		constexpr inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			matrix_[point_y_][point_x_][layer_] = draw_value;
		}

		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
			if (function_(matrix_[point_y_][point_x_])) matrix_[point_y_][point_x_] = draw_value;
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
			if (function_(matrix_[point_y_ * max_x_ + point_x_])) matrix_[point_y_ * max_x_ + point_x_] = draw_value;
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
			if (function_(matrix_[point_y_][point_x_][layer_])) matrix_[point_y_][point_x_][layer_] = draw_value;
		}


		///// ��{���� /////

		//STL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawSTL(Matrix_&& matrix_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionSTL(matrix_, col, row, std::forward<Args_>(args_)...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawWidthSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row, std::forward<Args_>(args_)...);
			return true;
		}

		//LayerSTL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, row, std::forward<Args_>(args_)...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerWidthSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, std::forward<Args_>(args_)...);
			return true;
		}

		//Normal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawNormal(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row, std::forward<Args_>(args_)...);
			return true;
		}

		//LayerNormal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, std::forward<Args_>(args_)...);
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionArray(matrix_, col, row, max_x_, std::forward<Args_>(args_)...);
			return true;
		}

	public:


		///// ���擾 /////

		[[nodiscard]] constexpr Index_Size getPointX() const noexcept {
			return this->point_x;
		}
		[[nodiscard]] constexpr Index_Size getPointY() const noexcept {
			return this->point_y;
		}
		[[nodiscard]] constexpr Index_Size getWidth() const noexcept {
			return this->width;
		}
		[[nodiscard]] constexpr Index_Size getHeight() const noexcept {
			return this->height;
		}
		[[nodiscard]] constexpr Matrix_Int_ getValue() const noexcept {
			return this->draw_value;
		}


		///// �����Ăяo�� /////

		//STL
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_) const noexcept {
			return (width == 0) ? this->drawSTL(matrix_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, Function_&& function_) const noexcept {
			return (width == 0) ? this->drawSTL(matrix_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
		}

		//LayerSTL
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(matrix_, layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, const Index_Size layer_, Function_&& function_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(matrix_, layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
		}

		//Normal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawNormal(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawNormal(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
		}

		//LayerNormal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawLayerNormal(matrix_, layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawLayerNormal(matrix_, layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
		}

		//Array
		template<typename Matrix_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawArray(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperatorArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawArray(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_, function_);
		}


		///// �_���W�����s�񐶐� /////

		template<typename Matrix_, typename ...Args_>
		constexpr auto create(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->draw(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawArray(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperator(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperator(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperatorArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}


		///// �R���X�g���N�^ /////

		constexpr Init() noexcept = default;
		constexpr explicit Init(const Matrix_Int_& draw_value_) noexcept
			:draw_value(draw_value_) {}
		constexpr explicit Init(const PairSize& length_) noexcept
			:width(length_.first), height(length_.second) {}
		constexpr explicit Init(const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:width(length_.first), height(length_.second),
			draw_value(draw_value_) {}
		constexpr explicit Init(const PairSize& position_, const PairSize& length_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second) {}
		constexpr explicit Init(const PairSize& position_, const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second),
			draw_value(draw_value_) {}
		constexpr explicit Init(const Index_Size width_, const Index_Size height_) noexcept
			:width(width_), height(height_) {}
		constexpr explicit Init(const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:width(width_), height(height_),
			draw_value(draw_value_) {}
		constexpr explicit Init(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {}
		constexpr explicit Init(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			draw_value(draw_value_) {}
	};
	using InitU8 = dtl::utility::Init<std::uint_fast8_t>;
	using InitU16 = dtl::utility::Init<std::uint_fast16_t>;
	using InitU32 = dtl::utility::Init<std::uint_fast32_t>;
	using InitU64 = dtl::utility::Init<std::uint_fast64_t>;
	using InitI8 = dtl::utility::Init<std::int_fast8_t>;
	using InitI16 = dtl::utility::Init<std::int_fast16_t>;
	using InitI32 = dtl::utility::Init<std::int_fast32_t>;
	using InitI64 = dtl::utility::Init<std::int_fast64_t>;
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
		constexpr explicit Init(Matrix_& matrix_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
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
		constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
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
		constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row*x_ + col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
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
		constexpr explicit Init(Matrix_& matrix_) noexcept {
			for (auto&& row : matrix_)
				for (auto&& col : row)
					col = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
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
		constexpr explicit Init(Matrix_& matrix_, const std::size_t layer_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
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
		constexpr explicit Init(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
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