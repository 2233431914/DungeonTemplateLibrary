/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_HPP

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/BasicRect.hpp>

//���L�f�[�^
namespace dtl {
	inline namespace utility {

		//�l�p�`�N���X
		template<typename Derived_>
		class RectBase : public ::dtl::utility::BasicRect<Derived_> {
		private:

			///// �G�C���A�X /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::utility::BasicRect<Derived_>;


		public:


			///// ���� /////

			//�S�Ă̒l�������l�ɖ߂�
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clear() noexcept {
				this->clearRange();
				return static_cast<Derived_&>(*this);
			}


			///// �R���X�g���N�^ /////

			constexpr RectBase() = default;
			constexpr explicit RectBase(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:RectBase_t(matrix_range_) {}
			constexpr explicit RectBase(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_) {}
		};
	}
}

#endif //Included Dungeon Template Library
