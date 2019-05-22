/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_RECT_BASE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_RECT_BASE_HPP

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>

//���L�f�[�^
namespace dtl {
	inline namespace utility {

		//�l�p�`�N���X
		template<typename Derived_>
		class RectBase {
		private:

			///// �G�C���A�X /////

			using Index_Size = ::dtl::type::size;


		protected:


			///// �����o�ϐ� /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};


			///// �v�Z�⏕ /////

			constexpr Index_Size calcEndX(const Index_Size max_x_) const noexcept {
				return (this->width == 0 || this->start_x + this->width >= max_x_)
					? max_x_
					: this->start_x + this->width;
			}

			constexpr Index_Size calcEndY(const Index_Size max_y_) const noexcept {
				return (this->height == 0 || this->start_y + this->height >= max_y_)
					? max_y_
					: this->start_y + this->height;
			}


		public:


			///// ���擾 /////

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}


			///// ���� /////

			//�n�_���WX�������l�ɖ߂�
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearPointX() noexcept {
				this->start_x = 0;
				return static_cast<Derived_&>(*this);
			}
			//�n�_���WY�������l�ɖ߂�
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearPointY() noexcept {
				this->start_y = 0;
				return static_cast<Derived_&>(*this);
			}
			//�͈͂̑傫��(X������)�������l�ɖ߂�
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearWidth() noexcept {
				this->width = 0;
				return static_cast<Derived_&>(*this);
			}
			//�͈͂̑傫��(Y������)�������l�ɖ߂�
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearHeight() noexcept {
				this->height = 0;
				return static_cast<Derived_&>(*this);
			}
			//�n�_���W(X,Y)�������l�ɖ߂�
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return static_cast<Derived_&>(*this);
			}
			//�`��͈͂������l�ɖ߂�
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return static_cast<Derived_&>(*this);
			}
			//�S�Ă̒l�������l�ɖ߂�
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clear() noexcept {
				this->clearRange();
				return static_cast<Derived_&>(*this);
			}


			///// ��� /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPointX(const Index_Size start_x_) noexcept {
				this->start_x = start_x_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPointY(const Index_Size start_y_) noexcept {
				this->start_y = start_y_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPoint(const Index_Size start_x_, const Index_Size start_y_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size length_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = length_;
				this->height = length_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = width_;
				this->height = height_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRange(const ::dtl::base::MatrixRange & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return static_cast<Derived_&>(*this);
			}


			///// �R���X�g���N�^ /////

			constexpr RectBase() = default;
			constexpr explicit RectBase(const ::dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit RectBase(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_) {}
		};
	}
}

#endif //Included Dungeon Template Library
