#include "slrtappmapping.h"
#include "./maps/FingerStrokeAssistance.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <FingerStrokeAssistance> */
		{ /* SignalMapInfo */
			FingerStrokeAssistance_BIOMAP,
			FingerStrokeAssistance_LBLMAP,
			FingerStrokeAssistance_SIDMAP,
			FingerStrokeAssistance_SBIO,
			FingerStrokeAssistance_SLBL,
			{0,200},
			129,
		},
		{ /* ParamMapInfo */
			FingerStrokeAssistance_PTIDSMAP,
			FingerStrokeAssistance_PTNAMESMAP,
			FingerStrokeAssistance_SPTMAP,
			{0,130},
			131,
		},
		"FingerStrokeAssistance",
		"",
		"FingerStrokeAssistance",
		3,
		FingerStrokeAssistance_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}