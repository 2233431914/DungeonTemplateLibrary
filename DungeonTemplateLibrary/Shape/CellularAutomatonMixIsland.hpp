#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_MIX_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_MIX_ISLAND
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Shape/Border.hpp>
#include <Shape/HalfMixRect.hpp>
#include <Utility/CellularAutomaton.hpp>
#include <Base/Struct.hpp>

namespace dtl {
	inline namespace shape {

		//�}�b�v�̊O�g���w�肵�����l�Ŗ��߁A�����}�X���w�肵�����l�Ŗ��߂�
		template<typename Matrix_Int_>
		class CellularAutomatonMixIsland {
		private:


			///// �G�C���A�X /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;
			using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


			///// �����o�ϐ� /////

			dtl::shape::Border<Matrix_Int_> border{};
			dtl::shape::HalfMixRect<Matrix_Int_> mixRect{};
			dtl::utility::CellularAutomation<Matrix_Int_> cellularAutomation{};
			Index_Size loop_num{ 1 };

		public:


			///// ���擾 /////

			[[nodiscard]] constexpr Index_Size getPointX() const noexcept {
				return this->border.getPointX();
			}
			[[nodiscard]] constexpr Index_Size getPointY() const noexcept {
				return this->border.getPointY();
			}
			[[nodiscard]] constexpr Index_Size getWidth() const noexcept {
				return this->border.getWidth();
			}
			[[nodiscard]] constexpr Index_Size getHeight() const noexcept {
				return this->border.getHeight();
			}
			[[nodiscard]] constexpr Matrix_Int_ getValue() const noexcept {
				return this->border.getValue();
			}


			///// �����Ăяo�� /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool draw(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				mixRect.draw(matrix_, args_...);
				border.draw(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					cellularAutomation.draw(matrix_, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				mixRect.drawOperator(matrix_, args_...);
				border.drawOperator(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					cellularAutomation.draw(matrix_, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				mixRect.drawArray(matrix_, args_...);
				border.drawArray(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					cellularAutomation.drawArray(matrix_, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				mixRect.drawOperatorArray(matrix_, args_...);
				border.drawOperatorArray(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					cellularAutomation.drawArray(matrix_, args_...);
				return true;
			}


			///// �����Ăяo���t�@���N�^ /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// �_���W�����s�񐶐� /////

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


			///// ���� /////

			//�n�_���WX�������l�ɖ߂�
			constexpr auto clearPointX() noexcept {
				this->mixRect.clearPointX();
				this->border.clearPointX();
				this->cellularAutomation.clearPointX();
				return *this;
			}
			//�n�_���WY�������l�ɖ߂�
			constexpr auto clearPointY() noexcept {
				this->mixRect.clearPointY();
				this->border.clearPointY();
				this->cellularAutomation.clearPointY();
				return *this;
			}
			//�͈͂̑傫��(X������)�������l�ɖ߂�
			constexpr auto clearWidth() noexcept {
				this->mixRect.clearWidth();
				this->border.clearWidth();
				this->cellularAutomation.clearWidth();
				return *this;
			}
			//�͈͂̑傫��(Y������)�������l�ɖ߂�
			constexpr auto clearHeight() noexcept {
				this->mixRect.clearHeight();
				this->border.clearHeight();
				this->cellularAutomation.clearHeight();
				return *this;
			}
			//�h��l�������l�ɖ߂�
			constexpr auto clearValue() noexcept {
				this->mixRect.clearValue();
				this->border.clearValue();
				this->cellularAutomation.clearValue();
				return *this;
			}
			//�n�_���W(X,Y)�������l�ɖ߂�
			constexpr auto clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//�`��͈͂������l�ɖ߂�
			constexpr auto clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//�S�Ă̒l�������l�ɖ߂�
			constexpr auto clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// ��� /////

			constexpr auto setPointX(const Index_Size point_x_) noexcept {
				this->mixRect.setPointX(point_x_);
				this->border.setPointX(point_x_);
				this->cellularAutomation.setPointX(point_x_);
				return *this;
			}
			constexpr auto setPointY(const Index_Size point_y_) noexcept {
				this->mixRect.setPointY(point_y_);
				this->border.setPointY(point_y_);
				this->cellularAutomation.setPointY(point_y_);
				return *this;
			}
			constexpr auto setWidth(const Index_Size width_) noexcept {
				this->mixRect.setWidth(width_);
				this->border.setWidth(width_);
				this->cellularAutomation.setWidth(width_);
				return *this;
			}
			constexpr auto setHeight(const Index_Size height_) noexcept {
				this->mixRect.setHeight(height_);
				this->border.setHeight(height_);
				this->cellularAutomation.setHeight(height_);
				return *this;
			}
			constexpr auto setValue(const Matrix_Int_& draw_value_) noexcept {
				this->mixRect.setValue(draw_value_);
				this->border.setValue(draw_value_);
				this->cellularAutomation.setValue(draw_value_);
				return *this;
			}
			constexpr auto setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->mixRect.setRange(matrix_range_);
				this->border.setRange(matrix_range_);
				this->cellularAutomation.setRange(matrix_range_);
				return *this;
			}
			constexpr auto setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			constexpr auto setPoint(const Index_Size point_x_, const Index_Size point_y_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				return *this;
			}
			constexpr auto setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size length_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			constexpr auto setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// �R���X�g���N�^ /////

			constexpr CellularAutomatonMixIsland() noexcept = default;
			template<typename ...Args_>
			explicit CellularAutomatonMixIsland(const Index_Size & loop_num_, const Matrix_Int_ & first_, const Args_ & ... args_) noexcept
				:border(first_), mixRect(first_, args_...), loop_num(loop_num_) {}
			template<typename ...Args_>
			constexpr explicit CellularAutomatonMixIsland(const dtl::base::MatrixRange & matrix_range_, const Index_Size & loop_num_, const Matrix_Int_ & first_, const Args_ & ... args_) noexcept
				:border(matrix_range_, first_), mixRect(matrix_range_, first_, args_...), cellularAutomation(matrix_range_), loop_num(loop_num_) {}
		};
	}
}

#endif //Included Dungeon Template Library