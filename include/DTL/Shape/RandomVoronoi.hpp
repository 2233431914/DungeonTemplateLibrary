﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_RANDOM_VORONOI_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_RANDOM_VORONOI_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/::dtl::shape::RandomVoronoi-(形状クラス)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Random/MersenneTwister32bit.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>
#include <DTL/Utility/VoronoiDiagram.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_, typename UniquePair_ = DTL_TYPE_UNIQUE_PTR<std::pair<::dtl::type::ssize, ::dtl::type::ssize>[]>, typename UniqueInt_ = DTL_TYPE_UNIQUE_PTR<Matrix_Int_[]>>
		class RandomVoronoi {
		private:


			///// エイリアス /////

			using Index_Size = ::dtl::type::size;
			
			


			///// メンバ変数 /////

			::dtl::utility::VoronoiDiagram<Matrix_Int_, UniquePair_, UniqueInt_> voronoiDiagram{};
			double probability_value{ 0.5 };
			Matrix_Int_ true_color{};
			Matrix_Int_ false_color{};

		public:


			///// 情報取得 /////

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->voronoiDiagram.getPointX();
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->voronoiDiagram.getPointY();
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->voronoiDiagram.getWidth();
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->voronoiDiagram.getHeight();
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr ::dtl::type::size getValue() const noexcept {
				return this->voronoiDiagram.getValue();
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_) const noexcept {
				return this->voronoiDiagram.draw(matrix_,
					[this](const std::pair<::dtl::type::ssize, ::dtl::type::ssize>&, Matrix_Int_ & color_, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize) {
						if (::dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, layer_,
					[this](const std::pair<::dtl::type::ssize, ::dtl::type::ssize>&, Matrix_Int_ & color_, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize) {
						if (::dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, max_x_, max_y_,
					[this](const std::pair<::dtl::type::ssize, ::dtl::type::ssize>&, Matrix_Int_ & color_, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize) {
						if (::dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, layer_, max_x_, max_y_,
					[this](const std::pair<::dtl::type::ssize, ::dtl::type::ssize>&, Matrix_Int_ & color_, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize) {
						if (::dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.drawArray(matrix_, max_x_, max_y_,
					[this](const std::pair<::dtl::type::ssize, ::dtl::type::ssize>&, Matrix_Int_ & color_, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize, const ::dtl::type::ssize) {
						if (::dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperator(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperatorArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& clearPointX() noexcept {
				this->voronoiDiagram.clearPointX();
				return *this;
			}
			//始点座標Yを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& clearPointY() noexcept {
				this->voronoiDiagram.clearPointY();
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& clearWidth() noexcept {
				this->voronoiDiagram.clearWidth();
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& clearHeight() noexcept {
				this->voronoiDiagram.clearHeight();
				return *this;
			}
			//塗り値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& clearValue() noexcept {
				this->voronoiDiagram.clearValue();
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setPointX(const Index_Size end_x_) noexcept {
				this->voronoiDiagram.setPointX(end_x_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setPointY(const Index_Size end_y_) noexcept {
				this->voronoiDiagram.setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setWidth(const Index_Size width_) noexcept {
				this->voronoiDiagram.setWidth(width_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setHeight(const Index_Size height_) noexcept {
				this->voronoiDiagram.setHeight(height_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setValue(const ::dtl::type::size draw_value_) noexcept {
				this->voronoiDiagram.setValue(draw_value_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setRange(const ::dtl::base::MatrixRange& matrix_range_) noexcept {
				this->voronoiDiagram.setRange(matrix_range_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				RandomVoronoi& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// コンストラクタ /////

			constexpr RandomVoronoi() noexcept = default;
			constexpr explicit RandomVoronoi(const ::dtl::type::size draw_value_) noexcept
				:voronoiDiagram(draw_value_) {}
			constexpr explicit RandomVoronoi(const ::dtl::type::size draw_value_, const double probability_value_) noexcept
				:voronoiDiagram(draw_value_), probability_value(probability_value_) {}
			constexpr explicit RandomVoronoi(const ::dtl::type::size draw_value_, const double probability_value_, const Matrix_Int_& true_color_) noexcept
				:voronoiDiagram(draw_value_), probability_value(probability_value_), true_color(true_color_) {}
			constexpr explicit RandomVoronoi(const ::dtl::type::size draw_value_, const double probability_value_, const Matrix_Int_& true_color_, const Matrix_Int_& false_color_) noexcept
				:voronoiDiagram(draw_value_), probability_value(probability_value_), true_color(true_color_), false_color(false_color_) {}

			constexpr explicit RandomVoronoi(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:voronoiDiagram(matrix_range_) {}
			constexpr explicit RandomVoronoi(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::type::size draw_value_) noexcept
				:voronoiDiagram(matrix_range_, draw_value_) {}
			constexpr explicit RandomVoronoi(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::type::size draw_value_, const double probability_value_) noexcept
				:voronoiDiagram(matrix_range_, draw_value_), probability_value(probability_value_) {}
			constexpr explicit RandomVoronoi(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::type::size draw_value_, const double probability_value_, const Matrix_Int_& true_color_) noexcept
				:voronoiDiagram(matrix_range_, draw_value_), probability_value(probability_value_), true_color(true_color_) {}
			constexpr explicit RandomVoronoi(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::type::size draw_value_, const double probability_value_, const Matrix_Int_& true_color_, const Matrix_Int_& false_color_) noexcept
				:voronoiDiagram(matrix_range_, draw_value_), probability_value(probability_value_), true_color(true_color_), false_color(false_color_) {}
		};
	}
}

#endif //Included Dungeon Template Library