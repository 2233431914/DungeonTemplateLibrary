﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA_RECT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA_RECT

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include "Base_Struct.hpp"

namespace dtl::beta {

	//マスを指定した数値で埋める
	template<typename Matrix_Int_>
	class Rect {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;


		///// メンバ変数 /////

		dtl::base::MatrixRange range{};
		Matrix_Int_ draw_value{};


		///// 代入処理 /////

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
		constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
			if (function_(matrix_[point_y_][point_x_][layer_])) matrix_[point_y_][point_x_][layer_] = draw_value;
		}


		///// 基本処理 /////

		//STL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawSTL(Matrix_ && matrix_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ range.y }; row < point_y_; ++row)
				for (Index_Size col{ range.x }; col < matrix_[row].size(); ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawWidthSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ range.y }; row < point_y_; ++row)
				for (Index_Size col{ range.x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}

		//LayerSTL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ range.y }; row < point_y_; ++row)
				for (Index_Size col{ range.x }; col < matrix_[row].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ range.y }; row < point_y_; ++row)
				for (Index_Size col{ range.x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}

		//Normal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawNormal(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ range.y }; row < point_y_; ++row)
				for (Index_Size col{ range.x }; col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}

		//LayerNormal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ range.y }; row < point_y_; ++row)
				for (Index_Size col{ range.x }; col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ range.y }; row < point_y_; ++row)
				for (Index_Size col{ range.x }; col < point_x_; ++col)
					this->substitutionArray(matrix_, col, row, max_x_, args_...);
			return true;
		}

	public:


		///// 情報取得 /////

		[[nodiscard]] constexpr Index_Size getPointX() const noexcept {
			return this->range.x;
		}
		[[nodiscard]] constexpr Index_Size getPointY() const noexcept {
			return this->range.y;
		}
		[[nodiscard]] constexpr Index_Size getWidth() const noexcept {
			return this->range.w;
		}
		[[nodiscard]] constexpr Index_Size getHeight() const noexcept {
			return this->range.h;
		}
		[[nodiscard]] constexpr Matrix_Int_ getValue() const noexcept {
			return this->draw_value;
		}


		///// 生成呼び出し /////

		//STL
		template<typename Matrix_>
		constexpr bool draw(Matrix_ && matrix_) const noexcept {
			return (range.w == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (range.h == 0 || range.y + range.h >= matrix_.size()) ? matrix_.size() : range.y + range.h) : this->drawWidthSTL(matrix_, range.x + range.w, (range.h == 0 || range.y + range.h >= matrix_.size()) ? matrix_.size() : range.y + range.h);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
			return (range.w == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (range.h == 0 || range.y + range.h >= matrix_.size()) ? matrix_.size() : range.y + range.h, function_) : this->drawWidthSTL(matrix_, range.x + range.w, (range.h == 0 || range.y + range.h >= matrix_.size()) ? matrix_.size() : range.y + range.h, function_);
		}

		//LayerSTL
		template<typename Matrix_>
		constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
			return (range.w == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (range.h == 0 || range.y + range.h >= matrix_.size()) ? matrix_.size() : range.y + range.h) : this->drawLayerWidthSTL(matrix_, layer_, range.x + range.w, (range.h == 0 || range.y + range.h >= matrix_.size()) ? matrix_.size() : range.y + range.h);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
			return (range.w == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (range.h == 0 || range.y + range.h >= matrix_.size()) ? matrix_.size() : range.y + range.h, function_) : this->drawLayerWidthSTL(matrix_, layer_, range.x + range.w, (range.h == 0 || range.y + range.h >= matrix_.size()) ? matrix_.size() : range.y + range.h, function_);
		}

		//Normal
		template<typename Matrix_>
		constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawNormal(std::forward<Matrix_>(matrix_), (range.w == 0 || range.x + range.w >= max_x_) ? max_x_ : range.x + range.w, (range.h == 0 || range.y + range.h >= max_y_) ? max_y_ : range.y + range.h);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
			return this->drawNormal(std::forward<Matrix_>(matrix_), (range.w == 0 || range.x + range.w >= max_x_) ? max_x_ : range.x + range.w, (range.h == 0 || range.y + range.h >= max_y_) ? max_y_ : range.y + range.h, function_);
		}

		//LayerNormal
		template<typename Matrix_>
		constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (range.w == 0 || range.x + range.w >= max_x_) ? max_x_ : range.x + range.w, (range.h == 0 || range.y + range.h >= max_y_) ? max_y_ : range.y + range.h);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
			return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (range.w == 0 || range.x + range.w >= max_x_) ? max_x_ : range.x + range.w, (range.h == 0 || range.y + range.h >= max_y_) ? max_y_ : range.y + range.h, function_);
		}

		//Array
		template<typename Matrix_>
		constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawArray(std::forward<Matrix_>(matrix_), (range.w == 0 || range.x + range.w >= max_x_) ? max_x_ : range.x + range.w, (range.h == 0 || range.y + range.h >= max_y_) ? max_y_ : range.y + range.h, max_x_);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
			return this->drawArray(std::forward<Matrix_>(matrix_), (range.w == 0 || range.x + range.w >= max_x_) ? max_x_ : range.x + range.w, (range.h == 0 || range.y + range.h >= max_y_) ? max_y_ : range.y + range.h, max_x_, function_);
		}


		///// ダンジョン行列生成 /////

		template<typename Matrix_, typename ...Args_>
		constexpr auto create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
			this->draw(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
			this->drawArray(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
			this->drawOperator(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
			this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}


		///// コンストラクタ /////

		constexpr Rect() noexcept = default;
		constexpr explicit Rect(const Matrix_Int_ & draw_value_) noexcept
			:draw_value(draw_value_) {}
		constexpr explicit Rect(const dtl::base::MatrixRange & matrix_range_) noexcept
			:range(matrix_range_) {}
		constexpr explicit Rect(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_) noexcept
			:range(matrix_range_), draw_value(draw_value_) {}
		constexpr explicit Rect(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:range(point_x_, point_y_, width_, height_) {}
		constexpr explicit Rect(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:range(point_x_, point_y_, width_, height_), draw_value(draw_value_) {}
	};
}

#endif //Included Dungeon Template Library