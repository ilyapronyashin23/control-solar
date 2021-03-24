#ifndef _REGULATORPI_
#define _REGULATORPI_

#include "DSP280x_Device.h"
#include "DSP280x_Examples.h"
#include "Global.h"

#define KDIV 50

#define S16_MAX (32767)
#define S16_MIN (-32768)

#define Kp (0.25)
#define KiVout (0.25)
#define KiImppt1 (75)
#define KiImppt2 (75)

#define LIMIT_MAX_VOUT 350	//���������� �� x1
#define LIMIT_MIN_VOUT 0
//#define LIMIT_MAX_IMPPT1 20	//���������� �� x10
//#define LIMIT_MIN_IMPPT1 0
#define LIMIT_MAX_UMPPT1 150	//���������� �� x10
#define LIMIT_MIN_UMPPT1 0
#define LIMIT_MAX_UMPPT2 150	//���������� �� x10
#define LIMIT_MIN_UMPPT2 0
#define LIMIT_MAX_UBAT 60	//���������� �� x10
#define LIMIT_MIN_UBAT 0


#define PITYPE_DIRECT 0
#define PITYPE_INVERS 1

typedef struct
{
  _iq15 Reference;		// �������
  _iq15 Kp_Gain;		// ����������������� ����� P
  _iq15 Ki_Gain;		// ������������ �����
  _iq15 Integral_Sum;	// ����������
  _iq15 KDiv;			// ��������/������� ������ � ������� (�������� ���� ����.���������� � ������� �
						// �������� 50 ��, �� KDiv = 50 )
  
  _iq15 Upper_Limit;	// ������� ����������� ����������� (�� ������ ��� ������� ����, 32767 ��� Int16)
  _iq15 Lower_Limit;	// ������ ����������� ����������� (�� ������ ��� ������� ����, -32768 ��� Int16)
  
  _iq15 OutLimitMax;	// ����������� ������ (������ �������� Limiter � PSIM)
  _iq15 OutLimitMin;	// ����������� ������ (������ �������� Limiter � PSIM)
  
  bool Max_PI_Output;	// ���� ����������� �����������
  bool Min_PI_Output;	// ���� ����������� �����������
  
  bool Reset;			//����� ����������� � ����������� ������ //������
  Uint16 PiType;		//��� ��������� (���� �������, ��� �� ���� ����������)	
  
} RegulatorPi_t;

typedef struct
{
	_iq15 Reference1;	// ������� 1-�� ���������
	_iq15 Reference2;	// ������� 2-�� ���������
	_iq15 Kp_Gain;		// ����������������� ����� P
	_iq15 Ki_Gain;		// ������������ �����
	_iq15 Integral_Sum;	// ����������
	_iq15 KDiv;			// ��������/������� ������ � ������� (�������� ���� ����.���������� � ������� �
						// �������� 50 ��, �� KDiv = 50 )
						
	_iq15 Upper_Limit1;	// ������� ����������� ����������� (�� ������ ��� ������� ����, 32767 ��� Int16)
	_iq15 Lower_Limit1;	// ������ ����������� ����������� (�� ������ ��� ������� ����, -32768 ��� Int16)
	_iq15 Upper_Limit2;	// ������� ����������� ����������� (�� ������ ��� ������� ����, 32767 ��� Int16)
	_iq15 Lower_Limit2;	// ������ ����������� ����������� (�� ������ ��� ������� ����, -32768 ��� Int16)
	
	_iq15 OutLimitMax1;	// ����������� ������ (����� ��� ����������� �����������)
	_iq15 OutLimitMin1;	// ����������� ������ (������ �������� Limiter � PSIM)
	_iq15 OutLimitMax2;	// ����������� ������ (����� ��� ����������� �����������)
	_iq15 OutLimitMin2;	// ����������� ������ (������ �������� Limiter � PSIM)
  
	bool Max_PI_Output;	// ���� ����������� �����������
	bool Min_PI_Output;	// ���� ����������� �����������
  
} RegulatorPi2Params_t;

_iq15 RegulatorPI(RegulatorPi_t* regul, _iq15 input);

#endif
