/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY


#include <Base/Struct.hpp>

///// ���Ńe�X�g���C�u���� /////

/*�@�\���s�\���Ȋ֐���N���X�������B
(���� "STL, Normal, Array, LayerSTL, LayerNormal"�̒��̈ꕔ�̏o�͋@�\�������Ă���ꍇ������)*/

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA

///// �֘A�c�[�� /////

#include <Beta/DungeonBinarization.hpp>
#include <Beta/DungeonNoise.hpp>
#include <Beta/DungeonOutput.hpp>
#include <Beta/DungeonRandom.hpp>
#include <Beta/DungeonFile.hpp>
#include <Beta/DungeonMatrix.hpp>

#include <Storage/FileCSV.hpp>
#include <Storage/FileTerrainOBJ.hpp>

///// �_���W���� /////

#include <Beta/FractalIsland.hpp>
#include <Beta/MazeDig.hpp>
#include <Beta/RogueLike.hpp>
#include <Beta/SimpleRogueLike.hpp>
#include <Beta/SimpleVoronoiIsland.hpp>
#include <Beta/BoardGame.hpp>
#include <Beta/HorizontalScroll.hpp>
//�y�C���g
#include <Beta/DungeonPaint.hpp>
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA


///// �R���\�[���o�� /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
//�w��}�X�̒l�𐔒l�ŏo�͂���B
#include <Console/OutputNumber.hpp>
//�w��}�X�̒l���w�肵�������ŏo�͂���B
#include <Console/OutputString.hpp>
//�w��}�X�̒l(2�l)���w�肵�������ŏo�͂���B
#include <Console/OutputStringBool.hpp>
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE


///// �֗��ȋ@�\ /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#include <Utility/Binarization.hpp>
#include <Utility/Binarization_Over.hpp>
#include <Utility/Copy.hpp>
#include <Utility/Init.hpp>
#include <Utility/NoiseBool.hpp>
#include <Utility/NoiseShoreBool.hpp>
#include <Utility/Replace.hpp>
#include <Utility/SetItem.hpp>
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY


///// �G���e�B�e�B /////

#include <Entity/MobManager.hpp>


///// �C�� /////

#include <Retouch/BuryPoint.hpp>
#include <Retouch/RemovePoint.hpp>


///// ���� /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
//��������
#include <Random/MersenneTwister32bit.hpp>
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM


///// �W������ /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON
//�w��}�X�̎���1�}�X�ɔC�ӂ̒l(1)��ݒu����B
#include <Shape/Border.hpp>
//Shape_Border + �܂��A�w��}�X�̗񐔂������̎�[��-2���]��ݒu���A�s���������̎�[�s��-2�s��]�̃}�X�ɔC�ӂ̒l(1)��ݒu����(���s/���0���琔����)�B
#include <Shape/BorderOdd.hpp>
//
#include <Shape/CellularAutomatonIsland.hpp>
//
#include <Shape/MixRect.hpp>
//�w��}�X�̑S�ĂɔC�ӂ̒l(1)��ݒu����B
#include <Shape/Rect.hpp>
//[�폜�\��]
#include <Shape/OneLine.hpp>
//�w��}�X�̋�����ڂ������s�ڂɔC�ӂ̒l(1)��ݒu����B
#include <Shape/PointGrid.hpp>
//Shape_BorderOdd + Shape_PointGrid
#include <Shape/PointGridWithBorder.hpp>
//Shape_BorderOdd + Shape_PointGrid + Shape_RandomRect
#include <Shape/PointGridAndSomeBlocksWithBorder.hpp>
//�w��}�X�Ɉ��̊m���ŔC�ӂ̒l(1)��ݒu����B
#include <Shape/RandomRect.hpp>

#include <Shape/MazeDig.hpp>

#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON

//
#include <Shape/CellularAutomatonMixIsland.hpp>

#include <DiamondSquareAverage.hpp>
//


//
#include <Shape/Point.hpp>

#include <Camera/MatrixView.hpp>

#endif //Included Dungeon Template Library