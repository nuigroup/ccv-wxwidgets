/***********************************************************************
 ** Copyright (C) 2010 Movid Authors.  All rights reserved.
 **
 ** This file is part of the Movid Software.
 **
 ** This file may be distributed under the terms of the Q Public License
 ** as defined by Trolltech AS of Norway and appearing in the file
 ** LICENSE included in the packaging of this file.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** Contact info@movid.org if any conditions of this licensing are
 ** not clear to you.
 **
 **********************************************************************/


#include "moDoNothingModule.h"
#include "../moLog.h"
#include "cv.h"

MODULE_DECLARE(DoNothing, "native", "Pass everything.");

moDoNothingModule::moDoNothingModule() : moImageFilterModule(){
	MODULE_INIT();

    this->declareInput(1, &this->input, new moDataStreamInfo(
				"data", "blob", "Data stream of type 'blob'"));
	this->declareInput(2, &this->output, new moDataStreamInfo(
				"data", "trackedblob", "Data stream of type 'trackedblob'"));
}

moDoNothingModule::~moDoNothingModule() {
}

moModule *moDoNothingModule::createModule()
{
     return new moDoNothingModule();
}

void moDoNothingModule::applyFilter(IplImage *src) 
{
    cvCopy(src, this->output_buffer);
}
