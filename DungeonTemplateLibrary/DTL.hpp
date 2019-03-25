/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY

///// ���Ńe�X�g���C�u���� /////

/*�@�\���s�\���Ȋ֐���N���X�������B
(���� "STL, Normal, Array, LayerSTL, LayerNormal"�̒��̈ꕔ�̏o�͋@�\�������Ă���ꍇ������)*/

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA
//�֘A�c�[��
#include "Beta_DungeonBinarization.hpp"
#include "Beta_DungeonNoise.hpp"
#include "Beta_DungeonOutput.hpp"
#include "Beta_DungeonRandom.hpp"
#include "Beta_DungeonFile.hpp"
#include "Beta_DungeonMatrix.hpp"
//�_���W����
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

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT
#include "Console_OutputNumber.hpp"
#include "Console_Output_String.hpp"
#include "Console_OutputStringBool.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT


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


///// ���� /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#include "Random_MersenneTwister32bit.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM


///// �W������ /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON
#include "Shape_Border.hpp"
#include "Generator_Common_BorderOdd.hpp"
#include "Shape_Rect.hpp"
#include "Generator_Common_OneLine.hpp"
#include "Shape_PointGrid.hpp"
#include "Generator_Common_PointGridField.hpp"
#include "Generator_Common_PointGridFieldPutBlock.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON

#include "Generator_Terrain_SimpleBiomeIsland.hpp"
#include "Generator_Terrain_SimpleCellularAutomatonIsland.hpp"


#include "Shape_Point.hpp"

#endif //Included Dungeon Template Library