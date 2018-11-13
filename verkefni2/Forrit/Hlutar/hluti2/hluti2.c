/*----------------------------------------------------------------------------------------------------*\
|*                                            - Bip  -                                                *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  Í hluta 2 á vélmennið að gera það nákvæmlega sama og í hluta 1 en núna er vélmennið að keyra      *|
|*  eftir vegalengd en ekki tíma. Einnig erum við með fall sem lætur robotinn keyra beint.            *|
\*-----------------------------------------------------------------------------------------------4246-*/

#include "../../../../program_connector/Functions.c"

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

void hluti_2()
{
	for (int i = 1;i <= 5; i++){
			MoveForward_cm(50*i);
			wait1Msec(2000);
			MoveBackward_cm(50*i);
			wait1Msec(2000);
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
