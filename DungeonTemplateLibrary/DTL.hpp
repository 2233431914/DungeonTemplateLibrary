/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY


#include "Base_Struct.hpp"

///// ���Ńe�X�g���C�u���� /////

/*�@�\���s�\���Ȋ֐���N���X�������B
(���� "STL, Normal, Array, LayerSTL, LayerNormal"�̒��̈ꕔ�̏o�͋@�\�������Ă���ꍇ������)*/

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA

///// �֘A�c�[�� /////

#include "Beta_DungeonBinarization.hpp"
#include "Beta_DungeonNoise.hpp"
#include "Beta_DungeonOutput.hpp"
#include "Beta_DungeonRandom.hpp"
#include "Beta_DungeonFile.hpp"
#include "Beta_DungeonMatrix.hpp"

///// �_���W���� /////

#include "Beta_FractalIsland.hpp"
#include "Beta_MazeDig.hpp"
#include "Beta_RogueLike.hpp"
#include "Beta_SimpleRogueLike.hpp"
#include "Beta_SimpleVoronoiIsland.hpp"
#include "Beta_BoardGame.hpp"
#include "Beta_HorizontalScroll.hpp"
//�y�C���g
#include "Beta_DungeonPaint.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA


///// �R���\�[���o�� /////

/* ���S0.4.X�Ή� */

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
//�w��}�X�̒l�𐔒l�ŏo�͂���B
#include "Console_OutputNumber.hpp"
//�w��}�X�̒l���w�肵�������ŏo�͂���B
#include "Console_OutputString.hpp"
//�w��}�X�̒l(2�l)���w�肵�������ŏo�͂���B
#include "Console_OutputStringBool.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE


///// �֗��ȋ@�\ /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#include "Utility_Binarization.hpp"
#include "Utility_Binarization_Over.hpp"
#include "Utility_Copy.hpp"
#include "Utility_Init.hpp"
#include "Utility_NoiseBool.hpp"
#include "Utility_NoiseShoreBool.hpp"
#include "Utility_Replace.hpp"
#include "Utility_SetItem.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY


///// �G���e�B�e�B /////

#include "Entity_MobManager.hpp"


///// �C�� /////

#include "Retouch_RemovePoint.hpp"


///// ���� /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
//��������
#include "Random_MersenneTwister32bit.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM


///// �W������ /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON
//�w��}�X�̎���1�}�X�ɔC�ӂ̒l(1)��ݒu����B
#include "Shape_Border.hpp"
//Shape_Border + �܂��A�w��}�X�̗񐔂������̎�[��-2���]��ݒu���A�s���������̎�[�s��-2�s��]�̃}�X�ɔC�ӂ̒l(1)��ݒu����(���s/���0���琔����)�B
#include "Shape_BorderOdd.hpp"
//
#include "Shape_CellularAutomatonIsland.hpp"
//
#include "Shape_MixRect.hpp"
//�w��}�X�̑S�ĂɔC�ӂ̒l(1)��ݒu����B
#include "Shape_Rect.hpp"
//[�폜�\��]
#include "Shape_OneLine.hpp"
//�w��}�X�̋�����ڂ������s�ڂɔC�ӂ̒l(1)��ݒu����B
#include "Shape_PointGrid.hpp"
//Shape_BorderOdd + Shape_PointGrid
#include "Shape_PointGridWithBorder.hpp"
//Shape_BorderOdd + Shape_PointGrid + Shape_RandomRect
#include "Shape_PointGridAndSomeBlocksWithBorder.hpp"
//�w��}�X�Ɉ��̊m���ŔC�ӂ̒l(1)��ݒu����B
#include "Shape_RandomRect.hpp"

#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON

//
#include "Generator_Terrain_SimpleBiomeIsland.hpp"
//


//
#include "Shape_Point.hpp"

#include "Camera_MatrixView.hpp"

#endif //Included Dungeon Template Library